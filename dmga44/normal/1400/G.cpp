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
typedef double ld;
typedef pair<ll,ll> pii;
typedef pair<ld,ll> pdi;
typedef pair<ld,ld> pdd;
typedef pair<double,pii> pdp;
typedef pair<string,ll> psi;
typedef pair<ll,string> pls;
typedef pair<string,string> pss;
typedef pair<ll,pii> pip;
typedef pair<pii,pii> ppp;
typedef complex<ll> point;
typedef pair<point,int> ppi;
#define mod (ll)(998244353)
#define eps (1e-9)
#define oo (ll)(1e9)
#define pi acos(-1)
#define MAXN (ll)(3e5+5)

int l[MAXN];
int r[MAXN];
vector<int> meter[MAXN];
vector<int> sacar[MAXN];
ll fac[MAXN],ifac[MAXN];
vector<int> g[MAXN];
vector<int> nodes;
int comp[MAXN],id[MAXN];
int cant[25][25];
ll dp1[25][45];
int act[25];
vector<int> oks[25];
bool mk[MAXN];

void dfs(int u)
{
    mk[u]=1;
    nodes.push_back(u);
    for(auto v : g[u])
        if(!mk[v])
            dfs(v);
}

ll qp(ll b,ll e)
{
    if(!e)
        return 1;
    ll x=qp(b,e/2);
    x=(x*x)%mod;
    if(e&1)
        x=(b*x)%mod;
    return x;
}

ll comb(int n,int m)
{
    if(m<0 || m>n)
        return 0;
    ll den=(ifac[m]*ifac[n-m])%mod;
    return (fac[n]*den)%mod;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ifac[0]=fac[0]=1;
    for(int i=1;i<MAXN;i++)
    {
        fac[i]=(fac[i-1]*i)%mod;
        ifac[i]=qp(fac[i],mod-2);
    }

    int n,m;
    cin >> n >> m;
    for(int i=0;i<n;i++)
    {
        cin >> l[i] >> r[i];
        meter[l[i]].push_back(i);
        sacar[r[i]].push_back(i);
    }

    for(int i=0;i<m;i++)
    {
        int u,v;
        cin >> u >> v;
        u--,v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    int c=0;
    for(int i=0;i<n;i++)
    {
        if(!g[i].size())
        {
            comp[i]=-1;
            continue;
        }
        if(mk[i])
            continue;

        dfs(i);
        for(int i=0;i<nodes.size();i++)
        {
            int u=nodes[i];
            comp[u]=c;
            id[u]=i;
        }

        int sz=nodes.size();
        for(int i=0;i<(1<<sz);i++)
        {
            bool ok=1;
            for(int j=0;j<sz;j++)
                if(i&(1<<j))
                    for(auto v : g[nodes[j]])
                        if(i&(1<<id[v]))
                            ok=0;
            if(ok)
                oks[c].push_back(i);
        }

        c++;
        nodes.clear();
    }

    ll res=0;
    int c2=0;
    dp1[c][0]=1;
    for(int i=0;i<c;i++)
        cant[i][0]=1;
    for(int i=1;i<=n;i++)
    {
        for(auto u : meter[i])
        {
            if(comp[u]==-1)
            {
                c2++;
                continue;
            }
//            cout << "meter " << u+1 << "\n";
            int cc=comp[u];
            act[cc]|=(1<<id[u]);
            for(int j=0;j<25;j++)
                cant[cc][j]=0;
            for(auto y : oks[cc])
                if((y&act[cc])==y)
                    cant[cc][__builtin_popcount(y)]++;
//            for(int i=0;i<25;i++)
//                cout << cant[cc][i] << ' ';
//            cout << '\n';

            for(int i=0;i<25;i++)
                for(int j=0;j<45;j++)
                    dp1[i][j]=0;
            dp1[0][0]=1;
            for(int i=0;i<c;i++)
                for(int j=0;j<45;j++)
                    for(int k=0;k<25 && k+j<45;k++)
                        dp1[i+1][k+j]=(dp1[i+1][k+j]+dp1[i][j]*cant[i][k])%mod;
        }

//        db("")
//        cout << i << ' ' << c2 << '\n';
        for(int j=0;j<45;j++)
        {
            res=(res+dp1[c][j]*comb(c2,i-j))%mod;
//            cout << j << ' ' << dp1[c][j] << ' ' << comb(c2,i-j) << '\n';
        }
//        db("")
        for(auto u : sacar[i])
        {
            if(comp[u]==-1)
            {
                c2--;
                continue;
            }
//            cout << "sacar " << u+1 << "\n";
            int cc=comp[u];
            act[cc]-=(1<<id[u]);
            for(int j=0;j<25;j++)
                cant[cc][j]=0;
            for(auto y : oks[cc])
                if((y&act[cc])==y)
                    cant[cc][__builtin_popcount(y)]++;
//            for(int i=0;i<25;i++)
//                cout << cant[cc][i] << ' ';
//            cout << '\n';
            for(int i=0;i<25;i++)
                for(int j=0;j<45;j++)
                    dp1[i][j]=0;
            dp1[0][0]=1;
            for(int i=0;i<c;i++)
                for(int j=0;j<45;j++)
                    for(int k=0;k<25 && k+j<45;k++)
                        dp1[i+1][k+j]=(dp1[i+1][k+j]+dp1[i][j]*cant[i][k])%mod;
        }
    }

    db(res)

    return 0;
}