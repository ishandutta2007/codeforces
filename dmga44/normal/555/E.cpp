#pragma GCC optimize("Ofast","unroll-loops","omit-frame-pointer","inline") //Optimization flags
#pragma GCC option("arch=native","tune=native","no-zero-upper") //Enable AVX
#pragma GCC target("avx2") //Enable AVX
#pragma GCC optimize("03")

#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
#define all(v) (v).begin(),(v).end()
#define allr(v) (v).rbegin(),(v).rend()
#define f first
#define s second
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pii;
typedef pair<ld,ll> pdi;
typedef pair<ld,ld> pdd;
typedef pair<double,pii> pdp;
typedef pair<string,ll> psi;
typedef pair<ll,string> pls;
typedef pair<string,string> pss;
typedef pair<ll,pii> pip;
typedef pair<pii,pii> ppp;
typedef complex<ld> point;
typedef pair<point,int> ppi;
#define mod (ll)(998244353)
#define eps (1e-9)
#define oo (ll)(0x3f3f3f3f)
#define pi acos(-1)
#define MAXN (ll)(2e5+5)

struct graph
{
	int n;
	vector<vector<int>> adj;

	graph(int n) : n(n), adj(n) {}

	void add_edge(int u, int v)
	{
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	vector<int>& operator[](int u) { return adj[u]; }
};

vector<vector<int>> comps;
vector<pii> bridges;

void bridge_blocks(graph &adj)
{
	int n = adj.n;

	vector<int> num(n), low(n), stk;

	function<void(int, int, int&)> dfs = [&](int u, int p, int &t)
	{
		num[u] = low[u] = ++t;
		stk.push_back(u);

		// remove if there isn't parallel edges
		sort(adj[u].begin(), adj[u].end());

		for (int i = 0, sz = adj[u].size(); i < sz; ++i)
		{
			int v = adj[u][i];

			if (v == p)
			{
				if (i + 1 < sz && adj[u][i + 1] == v)
					low[u] = min(low[u], num[v]);
				continue;
			}

			if (!num[v])
			{
				dfs(v, u, t);
				low[u] = min(low[u], low[v]);

				if (low[v] == num[v])
					bridges.push_back({u, v});
			}
			else low[u] = min(low[u], num[v]);
		}

		if (num[u] == low[u])
		{
			comps.push_back({});
			for (int v = -1; v != u; stk.pop_back())
				comps.back().push_back(v = stk.back());
		}
	};

	for (int u = 0, t; u < n; ++u)
		if (!num[u]) dfs(u, -1, t = 0);
}

vector<int> id(MAXN);
vector<int> g[MAXN];

void build_tree()
{
    for (int i = 0; i < (int) comps.size(); ++i)
        for (int u : comps[i])
            id[u] = i;

    for (auto &e : bridges)
    {
        g[id[e.f]].push_back(id[e.s]);
        g[id[e.s]].push_back(id[e.f]);
    }
}

template <typename T>
struct ST{
    vector< T > st,lazy;
    int sz;
    T neutroL;

    ST (int n,T neutrol) : sz(n),st(4*n),lazy(4*n),neutroL(neutrol) {}

    T merge(T v1,T v2)
    {
        return v1+v2;
    }

    void up(int p,int l,int r,T v)
    {
        st[p]=(r-l+1)*v;
        lazy[p]=v;
    }

    void push(int p,int l,int r)
    {
        if(l==r)
        {
            lazy[p]=neutroL;
            return ;
        }
        if(lazy[p]==neutroL)
            return ;
        ///(basic) up to code
        T v=lazy[p];
        up((p<<1),l,(l+r)>>1,v);
        up((p<<1)+1,((l+r)>>1)+1,r,v);
        lazy[p]=neutroL;
    }

    void build(vector<T> &arr) { build(1,0,sz-1,arr); }

    void build(int p,int l,int r,vector<T> &arr)
    {
        if(l==r)
        {
            st[p]=arr[l];
            lazy[p]=neutroL;
            return ;
        }
        int mid=(l+r)>>1;

        build(p<<1,l,mid,arr);
        build((p<<1)+1,mid+1,r,arr);

        st[p]=merge(st[p<<1],st[(p<<1)+1]);
        lazy[p]=neutroL;
    }

    void build(T *arr) { build(1,0,sz-1,arr); }

    void build(int p,int l,int r,T *arr)
    {
        if(l==r)
        {
            st[p]=arr[l];
            lazy[p]=neutroL;
            return ;
        }
        int mid=(l+r)>>1;

        build(p<<1,l,mid,arr);
        build((p<<1)+1,mid+1,r,arr);

        st[p]=merge(st[p<<1],st[(p<<1)+1]);
        lazy[p]=neutroL;
    }

    void update(int L,int R,T v) { update(1,0,sz-1,L,R,v); }

    void update(int p,int l,int r,int L,int R,T v)
    {
        push(p,l,r);
        if(L<=l && r<=R)
        {
            up(p,l,r,v);
            return ;
        }

        int mid=(l+r)>>1;

        if(L<=mid)
            update(p<<1,l,mid,L,R,v);
        if(R>mid)
            update((p<<1)+1,mid+1,r,L,R,v);

        st[p]=merge(st[p<<1],st[(p<<1)+1]);
    }

    T query(int L,int R) { return query(1,0,sz-1,L,R); }

    T query(int p,int l,int r,int L,int R)
    {
        push(p,l,r);
        if(L<=l && r<=R)
            return st[p];

        int mid=(l+r)>>1;

        if(R<=mid)
            return query(p<<1,l,mid,L,R);
        if(L>mid)
            return query((p<<1)+1,mid+1,r,L,R);
        return merge(query(p<<1,l,mid,L,R),query((p<<1)+1,mid+1,r,L,R));
    }
};

int heavy[MAXN], root[MAXN], depth[MAXN];
int pos[MAXN], ipos[MAXN], parent[MAXN];

struct heavy_light{
    int n;

    int dfs(int s, int f,vector<int>* G){
        parent[s] = f, heavy[s] = -1;
        int size = 1, maxSubtree = 0;

        for (auto u : G[s]) if (u != f){
            depth[u] = depth[s] + 1;
            int subtree = dfs(u, s, G);

            if (subtree > maxSubtree)
                heavy[s] = u, maxSubtree = subtree;

            size += subtree;
        }

        return size;
    }

    void go(vector<int>* G, int nn){
        n = nn;
        for(int i=0;i<n;i++)
        {
            if(heavy[i]!=0)
                continue;
            int ROOT=i;
            depth[ROOT] = 0;
            dfs(ROOT, -1, G);
        }
        vector<pii> nodes;
        for(int i=0;i<n;i++)
            if (parent[i] == -1 || heavy[parent[i]] != i)
                nodes.push_back(pii(depth[i],i));

        sort(all(nodes));
        for (int ii = 0, currentPos = 0; ii < nodes.size(); ++ii)
        {
            int i=nodes[ii].s;
            for (int u = i; u != -1; u = heavy[u], currentPos++)
            {
                root[u] = i;
                pos[u] = currentPos;
                ipos[currentPos] = u;
            }
        }
    }

    int lcau(int u, int v, ST<int> &st)
    {
        int add=2;
        for (; root[u] != root[v]; v = parent[root[v]]) {
            if (depth[root[u]] > depth[root[v]])
            {
                swap(u, v);
                add=3-add;
            }
//            cout << pos[root[v]] << ' ' << pos[v] << ' ' << add << '\n';
            st.update(1,0,n-1,pos[root[v]],pos[v],add);
        }
        if (depth[u] > depth[v])
        {
            swap(u, v);
            add=3-add;
        }
        if(pos[u]!=pos[v])
        {
//            cout << root[u]+1 << ' ' << pos[v] << ' ' << add << '\n';
            st.update(1,0,n-1,pos[u]+1,pos[v],add);
        }
        return u;
    }

    int lcaq(int u, int v, ST<int> &st){
        int res=0;
        for (; root[u] != root[v]; v = parent[root[v]]) {
            if (depth[root[u]] > depth[root[v]]) swap(u, v);
            res+=st.query(1, 0, n-1, pos[root[v]], pos[v]);
        }
        if (depth[u] > depth[v]) swap(u, v);
        if(pos[u]!=pos[v])
            res+=st.query(1, 0, n-1, pos[u]+1, pos[v] );

        // LCA at u
        return res;
    }
};

int d[MAXN];

int find(int u)
{
    if(d[u]<0)
        return u;
    d[u]=find(d[u]);
    return d[u];
}

void join(int u,int v)
{
    if(d[u]>d[v])
        swap(u,v);
    d[u]+=d[v];
    d[v]=u;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n,m,q,u,v;
    cin >> n >> m >> q;
    for(int i=0;i<n;i++)
        d[i]=-1;
    graph ini(n);
    for(int i=0;i<m;i++)
    {
        cin >> u >> v;
        u--,v--;
        ini.add_edge(u,v);
        u=find(u);
        v=find(v);
        if(u!=v)
            join(u,v);
    }

    bridge_blocks(ini);
    build_tree();
    int sz=comps.size();

//    for(auto v : comps)
//    {
//        for(auto u : v)
//            cout << u << ' ';
//        cout << '\n';
//    }

    heavy_light hld;
    hld.go(g,sz);

    ST<int> st(sz,0);

    vector<pip> qs;
    bool ok=1;
    while(q--)
    {
        cin >> u >> v;
        u--,v--;
        if(find(u)!=find(v))
        {
            ok=0;
            continue;
        }
        u=id[u];
        v=id[v];
        if(u==v)
            continue;
        int lca=hld.lcau(u,v,st);
//        cout << lca << ' ' << u << ' ' << v << '\n';
        qs.push_back(pip(lca,pii(u,v)));
    }

    for(auto y : qs)
    {
        int lca=y.f;
        int u=y.s.f;
        int v=y.s.s;
        ok&=(hld.lcaq(u,lca,st)==(depth[u]-depth[lca]));
        ok&=(hld.lcaq(v,lca,st)==((depth[v]-depth[lca])*2));
//        cout << hld.lcaq(u,lca,st) << ' ' << hld.lcaq(v,lca,st) << '\n';
    }
    if(ok)
        db("Yes")
    else
        db("No")

    return 0;
}
/**
4 4 2
1 2
1 3
2 3
3 4
1 3
4 2

3 2 2
1 2
3 2
1 3
2 1

3 3 2
1 2
1 2
3 2
1 3
2 1
**/