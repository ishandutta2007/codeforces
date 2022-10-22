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

vector<int> g[MAXN];
struct node{
    int sz;
    int l,r;
    int res;
    vector<pii> faltan;
    vector<int> dsini;
    vector<int> dsfin;
};
node st[4*MAXN];
int n,k;

struct rr{
    int comp;
    vector<int> ds;
    vector<pii> edges;
};

rr m2(vector<int> dsl,vector<int> dsr,vector<pii> edges,int l)
{
    rr res;
    int m=0;
    for(auto y : dsl)
        m=max(m,y+1);
    int mm=0;
    for(int i=0;i<dsr.size();i++)
    {
        dsr[i]+=m;
        mm=max(dsr[i]+1,mm);
    }
    vector<int> gg[mm];
    for(int i=0;i<edges.size();i++)
    {
        edges[i].f-=(l-dsl.size());
        edges[i].s-=(l-dsl.size());
        if(edges[i].s>=0)
        {
            gg[dsr[edges[i].f-dsl.size()]].push_back(dsl[edges[i].s]);
            gg[dsl[edges[i].s]].push_back(dsr[edges[i].f-dsl.size()]);

        }
        else
        {
            edges[i].f+=(l-dsl.size());
            edges[i].s+=(l-dsl.size());
            res.edges.push_back(pii(edges[i].f,edges[i].s));
        }
    }

    res.ds.resize(dsl.size()+dsr.size());
    int cant=0;
    vector<bool> mk(mm);
    vector<int> cc(mm);
    for(int i=0;i<mm;i++)
    {
        if(mk[i])
            continue;

        queue<int> q;
        q.push(i);
        cc[i]=cant;
        mk[i]=1;
        while(!q.empty())
        {
            int u=q.front();
            q.pop();

            for(auto v : gg[u])
            {
                if(mk[v])
                    continue;
                q.push(v);
                cc[v]=cant;
                mk[v]=1;
            }
        }
        cant++;
    }
    for(int i=0;i<dsl.size();i++)
        res.ds[i]=cc[dsl[i]];
    for(int i=dsl.size();i<dsl.size()+dsr.size();i++)
        res.ds[i]=cc[dsr[i-dsl.size()]];
    res.comp=(mm-cant);
    return res;
}

node merge(node l,node r)
{
//    db("")
//    cout << l.l << ' ' << l.r << ' ' << r.l << ' ' << r.r << '\n';
//    cout << l.res << ' ' << r.res << '\n';
//    db("edges")
//    for(auto y : r.faltan)
//        cout << y.f << ' ' << y.s << '\n';
//    for(auto y : l.dsfin)
//        cout << y << ' ';
//    cout << '\n';
//    for(auto y : r.dsini)
//        cout << y << ' ';
//    cout << '\n';

    node res;
    res.l=l.l;
    res.r=r.r;
    res.sz=l.sz+r.sz;
    res.res=l.res+r.res;

    rr x=m2(l.dsfin,r.dsini,r.faltan,r.l);
    res.res-=x.comp;
    res.faltan=l.faltan;
    for(auto y : x.edges)
        res.faltan.push_back(y);
    if(l.dsini.size()>=k)
        res.dsini=l.dsini;
    else
    {
        res.dsini.resize(min(k,(int)x.ds.size()));
        for(int i=0;i<res.dsini.size();i++)
            res.dsini[i]=x.ds[i];
    }
    if(r.dsfin.size()>=k)
        res.dsfin=r.dsfin;
    else
    {
        res.dsfin.resize(min(k,(int)x.ds.size()));
        vector<int> cc(15);
        int cant=1;
        for(int i=0;i<res.dsfin.size();i++)
        {
            if(!cc[x.ds[x.ds.size()-i-1]])
            {
                cc[x.ds[x.ds.size()-i-1]]=cant;
                cant++;
            }
            res.dsfin[res.dsfin.size()-i-1]=cc[x.ds[x.ds.size()-i-1]]-1;
        }
    }

    return res;
}

void build(int p,int l,int r)
{
    if(l==r)
    {
        st[p].sz=1;
        st[p].l=l;
        st[p].r=r;
        st[p].res=1;
        st[p].dsini.push_back(0);
        st[p].dsfin.push_back(0);
        for(auto v : g[l])
            st[p].faltan.push_back(pii(l,v));
        return ;
    }
    int mid=(l+r)>>1;

    build(p<<1,l,mid);
    build((p<<1)+1,mid+1,r);

    st[p]=merge(st[p<<1],st[(p<<1)+1]);
//    cout << p << ' ' << l << ' ' << r << ' ' << st[p].res << '\n';
}

node query(int p,int l,int r,int L,int R)
{
    if(L<=l && r<=R)
        return st[p];
    int mid=(l+r)>>1;

    if(R<=mid)
        return query(p<<1,l,mid,L,R);
    if(L>mid)
        return query((p<<1)+1,mid+1,r,L,R);
    return merge(query(p<<1,l,mid,L,R),query((p<<1)+1,mid+1,r,L,R));
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k;
    int m;
    cin >> m;
    for(int i=0;i<m;i++)
    {
        int u,v;
        cin>> u >> v;
        u--,v--;
        if(u>v)
            swap(u,v);
        g[v].push_back(u);
//        cout << v << ' ' << u << '\n';
    }

    build(1,0,n-1);

    int q;
    cin >> q;
    while(q--)
    {
        int l,r;
        cin >> l >> r;
        l--,r--;
        db(query(1,0,n-1,l,r).res)
    }

    return 0;
}
/**
5 3
3
1 3
2 3
4 5
5
1 1
1 2
2 3
1 3
1 5

1 2 1 1 2
**/