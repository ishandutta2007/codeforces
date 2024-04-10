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
typedef pair<double,ll> pdi;
typedef pair<double,pii> pdp;
typedef pair<string,ll> psi;
typedef pair<ll,string> pls;
typedef pair<string,string> pss;
typedef pair<ll,pii> pip;
typedef pair<pii,pii> ppp;
typedef complex<ld> point;
#define MAXN (ll)(1e3+5)
#define oo (ll)(0x3f3f3f3f3f3f3f3f)
#define eps 1e-9
#define mod (ll)(1e9+7)
#define m2 (ll)(2e9+99)
#define base 331

ll dp[MAXN][15][15],res,n0,dd[15][15],fac[15];
bool mk[MAXN];
vector<int> g0[15],g[MAXN];
vector<int> add;

ll qp(ll b,ll e)
{
    if(!e)
        return 1;
    ll x=qp(b,e/2);
    x=(x*x)%mod;
    if(e&1)
        x=(x*b)%mod;
    return x;
}

pii dfs(int u)
{
    mk[u]=1;
    vector<pii> vals;
    vals.push_back(pii(113,113));
    map<pii,int> fs;
    vector<pip> ss;
    for(auto y : g0[u])
        if(!mk[y])
        {
            vals.push_back(dfs(y));
            fs[vals.back()]++;
            ss.push_back(pip(y,vals.back()));
        }
    sort(all(vals));

    if(vals.size()==g0[u].size()+1)
    {
        dd[u][14]=1;
        for(auto y : fs)
            dd[u][14]=(dd[u][14]*qp(fac[y.s],mod-2))%mod;
        for(auto y : ss)
            dd[u][y.f]=(dd[u][14]*fs[y.s])%mod;
    }
    ll ans1=0;
    ll ans2=0;
    for(int i=0;i<vals.size();i++)
    {
        ans1=(ans1*base+vals[i].f*qp(fac[i],mod-2)+qp(i+1000001,mod-2))%mod;
        ans2=(ans2*base+vals[i].s*qp(fac[i],m2-2)+qp(i+1000001,m2-2))%m2;
    }
    return pii(ans1,ans2);
}

void DP(int u)
{
    mk[u]=1;
    vector<int> sons;
    for(auto y : g[u])
        if(!mk[y])
        {
            DP(y);
            sons.push_back(y);
        }

//    db("")
//    cout << u << '\n';
    int pos=0;
    for(int i=0;i<n0;i++)
    {
        ll dp0[2][(1<<g0[i].size())];
        for(int j=0;j<2;j++)
            for(int k=0;k<(1<<g0[i].size());k++)
                dp0[j][k]=0;
        dp0[0][0]=1;

        for(int j=0;j<sons.size();j++)
        {
            int son=sons[j];
            int act=j&1;
            int nex=1-(j&1);
            for(int k=0;k<(1<<g0[i].size());k++)
                dp0[nex][k]=dp0[act][k];
            for(int ant=0;ant<g0[i].size();ant++)
                for(int mask=(1<<g0[i].size())-1;mask>=0;mask--)
                {
                    if(mask&(1<<ant))
                        continue;
                    dp0[nex][mask|(1<<ant)]=(dp0[nex][mask|(1<<ant)]+dp0[act][mask]*dp[son][g0[i][ant]][i])%mod;
                }
        }

        if(pos<add.size() && i==add[pos])
        {
//            cout << u << ' ' << i << ' ' << dp0[sons.size()&1][(1<<g0[i].size())-1] << '\n';
            res=(res+dp0[sons.size()&1][(1<<g0[i].size())-1]*dd[i][14])%mod;
            pos++;
        }
        for(int ant=0;ant<g0[i].size();ant++)
        {
            dp[u][i][g0[i][ant]]=(dp0[sons.size()&1][(1<<g0[i].size())-1-(1<<ant)]*dd[i][g0[i][ant]])%mod;
//            if(dp0[sons.size()&1][(1<<g0[i].size())-1-(1<<ant)])
//                cout << (dp0[sons.size()&1][(1<<g0[i].size())-1-(1<<ant)]*dd[i][g0[i][ant]])%mod << ' ' << i << ' ' << g0[i][ant] << '\n';
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    mt19937 rng(time(0));

    fac[0]=1;
    for(int i=1;i<15;i++)
        fac[i]=(fac[i-1]*i)%mod;

    int n,u,v;
    cin >> n;
    for(int i=0;i<n-1;i++)
    {
        cin >> u >> v;
        u--,v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    cin >> n0;
    for(int i=0;i<n0-1;i++)
    {
        cin >> u >> v;
        u--,v--;
        g0[u].push_back(v);
        g0[v].push_back(u);
    }

    set<pii> oks;
    for(int i=0;i<n0;i++)
    {
        pii x=dfs(i);
//        cout << i << ' ' << x << '\n';
        if(oks.find(x)==oks.end())
            add.push_back(i);
        oks.insert(x);
        for(int j=0;j<n0;j++)
            mk[j]=0;
    }

    DP(0);

    db(res)

    return 0;
}
/**
5
1 2
2 3
3 4
4 5
3
1 2
2 3

3
2 3
3 1
3
1 2
1 3

7
1 2
1 3
1 4
1 5
1 6
1 7
4
4 1
4 2
4 3

5
1 2
2 3
3 4
4 5
4
4 1
4 2
4 3
**/