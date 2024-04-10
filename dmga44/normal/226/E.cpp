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
#define mod (ll)(1e9+7)
#define eps (1e-9)
#define oo (ll)(0x3f3f3f3f)
#define pi acos(-1)
#define MAXN (ll)(1e5+5)
#define MAXP (ll)(5e6+5)
///up to change
typedef int T;
struct node{
    int l,r;
    T v;
};

node pool[MAXP];
int actual;

int next()
{
    actual++;
    return actual;
}

//template<typename T>
struct pst{
    vector<int> versions;
    int n;
    pst() : n(0) {}
    pst(int n) : n(n) {}
    pst(vector<T> &a) : n(a.size()) { versions.push_back(build(0,n-1,a)); }

    T merge(T v1,T v2)
    {
        return v1+v2;
    }

    void up(int p,T v)
    {
        pool[p].v+=v;
    }

    int build(int l,int r,vector<T> &a)
    {
        int ans=next();
        if(l==r)
        {
            pool[ans].v=a[l];
            return ans;
        }
        int mid=(l+r)>>1;
        pool[ans].l=build(l,mid,a);
        pool[ans].r=build(mid+1,r,a);
        pool[ans].v=merge(pool[pool[ans].l].v,pool[pool[ans].r].v);
        return ans;
    }

    int build(int l,int r,T* a)
    {
        int ans=next();
        if(l==r)
        {
            pool[ans].v=a[l];
            return ans;
        }
        int mid=(l+r)>>1;
        pool[ans].l=build(l,mid,a);
        pool[ans].r=build(mid+1,r,a);
        pool[ans].v=merge(pool[pool[ans].l].v,pool[pool[ans].r].v);
        return ans;
    }

    int clone(int p)
    {
        int ans=next();
        pool[ans].l=pool[p].l;
        pool[ans].r=pool[p].r;
        pool[ans].v=pool[p].v;
        return ans;
    }

    void update(int ver,int pos,T v) { versions.push_back(update(versions[ver],0,n-1,pos,v)); }
    void update(int pos,T v) { versions.push_back(update(versions.back(),0,n-1,pos,v)); }

    int update(int p,int l,int r,int pos,T v)
    {
        p=clone(p);

        if(r==l)
        {
            up(p,v);
            return p;
        }
        int mid=(l+r)>>1;
        if(pos<=mid)
            pool[p].l=update(pool[p].l,l,mid,pos,v);
        else
            pool[p].r=update(pool[p].r,mid+1,r,pos,v);
        pool[p].v=merge(pool[pool[p].l].v,pool[pool[p].r].v);
        return p;
    }

    T query(int t,int l,int r) { return query(versions[t],0,n-1,l,r); }

    T query(int p,int l,int r,int L,int R)
    {
        if(L<=l && r<=R)
            return pool[p].v;

        int mid=(l+r)>>1;
        if(R<=mid)
            return query(pool[p].l,l,mid,L,R);
        if(L>mid)
            return query(pool[p].r,mid+1,r,L,R);
        return merge(query(pool[p].l,l,mid,L,R),query(pool[p].r,mid+1,r,L,R));
    }

    int solve(int y,int l,int r,int k,int ty)
    {
        int x=query(versions.size()-1,l,r)-query(y,l,r);
//        cout << versions.size()-1 << ' ' << y << '\n';
//        cout << l << ' ' << r << '\n';
//        db(x)
//        db("")
        if(r-l+1-x<k)
            return -(k-(r-l+1-x));
        vector<int> p={versions[y],versions.back()};
        vector<int> sg={-1,1};
        int add=0;
        if(l && ty)
            add=l-(query(versions.size()-1,0,l-1)-query(y,0,l-1));
        if(!ty && r<n-1)
            add=(n-1-r)-(query(versions.size()-1,r+1,n-1)-query(y,r+1,n-1));
        return multi_kth(p,sg,0,n-1,k+add,ty);
    }

    int multi_kth(vector<int> &p,vector<int> &sg,int l,int r,int k,int ty)
    {
        if(l==r)
            return l;

        int mid=(l+r)>>1;
        int sl=0;
        if(ty==1)
        {
            for(int i=0;i<p.size();i++)
                sl+=(pool[pool[p[i]].l].v)*(sg[i]);
            sl=(mid-l+1)-sl;
            if(sl>=k)
            {
                vector<int> next;
                for(auto pp : p)
                    next.push_back(pool[pp].l);
                return multi_kth(next,sg,l,mid,k,ty);
            }
            k-=sl;

            vector<int> next;
            for(auto pp : p)
                next.push_back(pool[pp].r);
            return multi_kth(next,sg,mid+1,r,k,ty);
        }
        else
        {
            for(int i=0;i<p.size();i++)
                sl+=(pool[pool[p[i]].r].v)*(sg[i]);
            sl=(r-mid)-sl;
            if(sl>=k)
            {
                vector<int> next;
                for(auto pp : p)
                    next.push_back(pool[pp].r);
                return multi_kth(next,sg,mid+1,r,k,ty);
            }
            k-=sl;

            vector<int> next;
            for(auto pp : p)
                next.push_back(pool[pp].l);
            return multi_kth(next,sg,l,mid,k,ty);
        }
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

    void go(vector<int>* G, int nn,int ROOT=0){
        n = nn;
        depth[ROOT] = 0;
        dfs(ROOT, -1, G);

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

    vector<pip> lca(int u, int v)
    {
        int ok = 1;
        vector<pip> res;
        for (; root[u] != root[v]; v = parent[root[v]])
        {
            if (depth[root[u]] > depth[root[v]])
            {
                swap(u, v);
                ok=1-ok;
            }
            res.push_back(pip(ok,pii(pos[root[v]],pos[v])));
        }
        if (depth[u] > depth[v])
        {
            swap(u, v);
            ok=1-ok;
        }
        res.push_back(pip(ok,pii(pos[u], pos[v])));

        return res;
    }
};

vector<int> g[MAXN];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    int r=0;
    for(int i=0;i<n;i++)
    {
        int p;
        cin >> p;
        if(!p)
            r=i;
        else
        {
            p--;
            g[i].push_back(p);
            g[p].push_back(i);
        }
    }

    heavy_light hld;
    hld.go(g,n,r);
//    for(int i=0;i<n;i++)
//        cout<< pos[i] << ' ';
//    cout << '\n';

    vector<int> ini(n);
    pst st(ini);
    int m;
    cin >> m;
    while(m--)
    {
        int ty;
        cin >> ty;
//        cout << "Case : " << m << '\n';
        if(ty==1)
        {
            int u;
            cin >> u;
            u--;
            st.update(pos[u],1);
//            db(st.query(st.versions.size()-1,0,n-1))
        }
        if(ty==2)
        {
            int u,v,k,y;
            cin >> u >> v >> k >> y;
            u--,v--;
            st.versions.push_back(st.versions.back());
//            db(st.query(st.versions.size()-1,0,n-1))
            vector<pip> lts=hld.lca(u,v);
            sort(all(lts),[](pip a,pip b){
                if(a.f!=b.f)
                    return a<b;
                if(a.f)
                    return a<b;
                return a>b;
            });
            int res=-2;
            for(int i=0;i<lts.size();i++)
            {
                auto p=lts[i];
//                db("")
//                cout << p.f << ' ' << p.s.f << ' ' << p.s.s << '\n';
                if(res!=-2)
                    break;

                int v;
                if(i && i!=lts.size()-1)
                    v=st.solve(y,p.s.f,p.s.s,k,p.f);
                else
                {
                    int l=p.s.f;
                    int r=p.s.s;
                    if(p.f)
                    {
                        if(i==lts.size()-1)
                            r--;
                        if(!i)
                            l++;
                    }
                    else
                    {
                        if(i==lts.size()-1)
                            l++;
                        if(!i)
                            r--;
                    }
                    if(r<l)
                        continue;
                    v=st.solve(y,l,r,k,p.f);
                }
//                db(v)
                if(v>=0)
                    res=v;
                else
                    k=-v;

            }
            if(res>=0)
                res=ipos[res];
            res++;
            db(res)
        }
    }

    return 0;
}
/**
3
0 1 2
5
2 1 3 1 0
1 2
2 1 3 1 0
2 1 3 1 1
2 1 3 1 2

6
2 5 2 2 0 5
3
2 1 6 2 0
1 2
2 4 5 1 0

9
4 1 0 6 3 8 5 7 2
9
2 4 9 4 0
2 4 5 8 0
2 1 2 2 0
2 1 9 3 0
2 4 5 3 2
2 6 5 6 5
2 9 1 6 0
2 6 5 1 1
1 7

7
0 6 5 3 7 4 1
2
1 2
2 2 7 3 0
**/