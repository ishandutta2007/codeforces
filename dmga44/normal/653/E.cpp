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
#define eps (1e-12)
#define oo (ll)(0x3f3f3f3f)
#define pi acos(-1)
#define MAXN (ll)(3e5+5)

int ma[1005][1005];
int d[MAXN];
vector<int> cs[MAXN];

int find(int u)
{
    if(d[u]<0)
        return u;
    d[u]=find(d[u]);
    return d[u];
}

void join(int u,int v)
{
    u=find(u);
    v=find(v);
    if(u==v)
        return;
    if(d[u]>d[v])
        swap(u,v);
    d[u]+=d[v];
    d[v]=u;
}

void join2(int u,int v)
{
    if(cs[u].size()<cs[v].size())
        swap(u,v);
    for(auto y : cs[v])
        cs[u].push_back(y);
    cs[v].clear();
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n,m,k,u,v;
    cin >> n >> m >> k;
    int max=n-1;
    for(int i=0;i<n;i++)
        d[i]=-1;
    if(n<=1000)
    {
        for(int i=0;i<m;i++)
        {
            cin >> u >> v;
            u--,v--;
            ma[u][v]=1;
            ma[v][u]=1;
            if(!u || !v)
                max--;
        }

        for(int i=1;i<n;i++)
            for(int j=i+1;j<n;j++)
                if(!ma[i][j])
                    join(i,j);
        for(int i=1;i<n;i++)
            cs[find(i)].push_back(i);

        bool ok=1;
        int cant=0;
        for(int i=1;i<n;i++)
        {
            if(!cs[i].size())
                continue;
            bool ko=0;
            for(auto y : cs[i])
                ko|=(!ma[0][y]);
            ok&=ko;
            cant++;
        }
        if(ok && cant<=k && max>=k)
            db("possible")
        else
            db("impossible")

        return 0;
    }
    else
    {
        map<pii,bool> mk;
        vector<int> fs(n);
        for(int i=0;i<m;i++)
        {
            cin >> u >> v;
            u--,v--;
            mk[pii(u,v)]=1;
            mk[pii(v,u)]=1;
            fs[u]++;
            fs[v]++;
            if(!u || !v)
                max--;
        }

        vector<pii> vp;
        for(int i=1;i<n;i++)
            vp.push_back(pii(fs[i],i));

        sort(all(vp));

        for(int i=0;i<1e6/n;i++)
        {
            int u=vp[i].s;
            for(int j=1;j<n;j++)
                if(!mk[pii(u,j)])
                    join(j,u);
        }

        vector<int> rs;
        for(int i=1;i<n;i++)
        {
            if(cs[find(i)].empty())
                rs.push_back(find(i));
            cs[find(i)].push_back(i);
        }
        for(int i=0;i<rs.size();i++)
            for(int j=i+1;j<rs.size();j++)
            {
                int u=rs[i];
                int v=rs[j];
                if(cs[u].empty())
                    continue;
                if(cs[v].empty())
                    continue;
                ll szu=cs[u].size();
                ll szv=cs[v].size();
                if(szu*szv>m)
                    join(u,v);
                else
                {
                    bool ok=0;
                    for(auto yu : cs[u])
                    {
                        if(ok)
                            break;
                        for(auto yv : cs[v])
                        {
                            if(ok)
                                break;
                            if(!mk[pii(yu,yv)])
                            {
                                ok=1;
                                join2(u,v);
                            }
                        }
                    }
                }
            }

            bool ok=1;
            int cant=0;
            for(int i=1;i<n;i++)
            {
                if(!cs[i].size())
                    continue;
                bool ko=0;
                for(auto y : cs[i])
                    ko|=(!mk[pii(0,y)]);
                ok&=ko;
                cant++;
            }
            if(ok && cant<=k && max>=k)
                db("possible")
            else
                db("impossible")

            return 0;
    }

    return 0;
}
/**
5 4 2
1 2
2 3
4 2
4 1
6 5 3
1 2
1 3
1 4
1 5
1 6
**/