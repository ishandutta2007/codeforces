#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int N=800005;
int n;
vector<int> tree(4*N,0);
vector<int> lazy(4*N,0);

void apply(int idx,int x)
{
    tree[idx]+=x;
    lazy[idx]+=x;
}

void push(int idx)
{
    for(int i=0;i<2;i++) apply(2*idx+i,lazy[idx]);
    lazy[idx]=0;
}

void update(int idx,int l,int r,int ql,int qr,int x)
{
    if(ql>qr) return;
    if(l==ql&&r==qr) apply(idx,x);
    else
    {
        int m=(l+r)/2;
        push(idx);
        update(2*idx,l,m,ql,min(qr,m),x);
        update(2*idx+1,m+1,r,max(ql,m+1),qr,x);
        tree[idx]=max(tree[2*idx],tree[2*idx+1]);
    }
}

int query(int idx,int l,int r,int ql,int qr)
{
    if(ql>qr) return 0;
    if(l==ql&&r==qr) return tree[idx];
    int m=(l+r)/2;
    push(idx);
    return max(query(2*idx,l,m,ql,min(qr,m)),query(2*idx+1,m+1,r,max(ql,m+1),qr));
}

vector<int> v[N];
vector<int> p(N,0);
vector<int> depth(N,0);
vector<int> sz(N,0);
vector<int> big(N,0);
vector<int> head(N,0);
vector<int> pos(N,0);
int hidx=0;

void dfs(int a)
{
    depth[a]=depth[p[a]]+1;
    sz[a]=1;
    for(int to:v[a])
    {
        if(to==p[a]) continue;
        p[to]=a;
        dfs(to);
        sz[a]+=sz[to];
        if(sz[to]>sz[big[a]]) big[a]=to;
    }
}

void decompose(int a,int h)
{
    head[a]=h;
    pos[a]=++hidx;
    if(big[a]!=0) decompose(big[a],h);
    for(int to:v[a]) if(to!=p[a]&&to!=big[a]) decompose(to,to);
}

void upd(int a,int b)
{
    while(head[a]!=head[b])
    {
        if(depth[head[a]]<depth[head[b]]) swap(a,b);
        update(1,1,n,pos[head[a]],pos[a],1);
        a=p[head[a]];
    }
    if(depth[a]<depth[b]) swap(a,b);
    update(1,1,n,pos[b]+1,pos[a],1);
}

bool qry(int a,int b)
{
    bool ok=1;
    while(head[a]!=head[b])
    {
        if(depth[head[a]]<depth[head[b]]) swap(a,b);
        ok&=(query(1,1,n,pos[head[a]],pos[a])==0);
        a=p[head[a]];
    }
    if(depth[a]<depth[b]) swap(a,b);
    ok&=(query(1,1,n,pos[b]+1,pos[a])==0);
    return ok;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int q;
    cin >> n >> q;
    vector<array<int,3>> edges;
    auto add_edge=[&](int a,int b,int x)
    {
        edges.push_back({a,b,x});
    };
    while(q--)
    {
        int a,b,x;
        cin >> a >> b >> x;
        if(x==1) add_edge(a,b,1);
        else
        {
            n++;
            add_edge(a,n,0);
            add_edge(b,n,1);
        }
    }
    vector<int> dsu_p(n+1,0);
    for(int i=1;i<=n;i++) dsu_p[i]=i;
    vector<int> dsu_sz(n+1,1);
    function<int(int)> find_set=[&](int a)->int
    {
        if(dsu_p[a]==a) return a;
        else return dsu_p[a]=find_set(dsu_p[a]);
    };
    auto merge_sets=[&](int a,int b)->bool
    {
        a=find_set(a);
        b=find_set(b);
        if(a==b) return 0;
        if(dsu_sz[a]<dsu_sz[b]) swap(a,b);
        dsu_p[b]=a;
        dsu_sz[a]+=dsu_sz[b];
        return 1;
    };
    q=edges.size();
    for(int i=0;i<q;i++)
    {
        int a=edges[i][0];
        int b=edges[i][1];
        if(merge_sets(a,b))
        {
            v[a].push_back(b);
            v[b].push_back(a);
        }
    }
    for(int i=1;i<=n;i++)
    {
        if(depth[i]==0)
        {
            dfs(i);
            decompose(i,i);
        }
    }
    for(int i=1;i<=n;i++)
    {
        dsu_p[i]=i;
        dsu_sz[i]=1;
    }
    for(auto [a,b,x]:edges)
    {
        bool res=0;
        if(merge_sets(a,b)) res=1;
        else
        {
            res=((depth[a]&1)==(depth[b]&1)&&qry(a,b));
            if(res) upd(a,b);
        }
        if(x)
        {
            if(res) cout << "YES\n";
            else cout << "NO\n";
        }
    }
    return 0;
}