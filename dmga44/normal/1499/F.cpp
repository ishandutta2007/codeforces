#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops","omit-frame-pointer","inline")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,popcnt,abm,mmx,avx,avx2,fma,tune=native")
#pragma GCC option("arch=native","no-zero-upper") //Enable AVX

#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
#define all(v) (v).begin(),(v).end()
#define allr(v) (v).rbegin(),(v).rend()
#define f first
#define s second
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<ll,ll> pii;
typedef pair<ld,ll> pdi;
typedef pair<ld,ld> pdd;
typedef pair<ld,pdd> pdp;
typedef pair<string,ll> psi;
typedef pair<ll,string> pls;
typedef pair<string,string> pss;
typedef pair<ll,pii> pip;
typedef pair<pii,pii> ppp;
typedef complex<ll> point;
typedef vector<point> polygon;
typedef pair<point,int> ppi;
#define prec(n) cout.precision(n); cout<<fixed
const ll mod=(ll)(998244353);
const ld eps=(1e-9);
const ll oo=(ll)(1e18+5);
#define pi acos(-1)
#define MAXN (ll)(5e3+5)

vector<int> g[MAXN];
int dp[MAXN][MAXN];
bool mk[MAXN];
int n,k;

void dfs(int u)
{
    mk[u]=1;
    vector<int> sons;
    for(auto v : g[u])
    {
        if(mk[v])
            continue;
//        cout << u << ' ' << v << '\n';
        dfs(v);
        sons.push_back(v);
    }
    int s=sons.size();
    if(!s)
    {
        dp[u][0]=1;
        return ;
    }
    vector<vector<int>> l(s,vector<int>(k/2+2)),r(s,vector<int>(k/2+2));

//    db("xxx")
//    db(u)
    for(int i=0;i<s;i++)
    {
        ll sum=0;
        vector<int> aux(k/2+2);
        for(int j=0;j<=k;j++)
        {
            sum=(sum+dp[sons[i]][j])%mod;
            if(j+1<k/2+2)
                aux[j+1]=sum;
        }
        for(int j=0;2*j<=k;j++)
            aux[j]=(aux[j]+sum)%mod;
//        db(sum)
        if(!i)
        {
            for(int j=0;2*j<=k;j++)
                l[0][j]=aux[j];
        }
        else
        {
            for(int j=0;2*j<=k;j++)
                l[i][j]=(1ll*aux[j]*1ll*l[i-1][j])%mod;
        }
    }

    for(int i=s-1;i>=0;i--)
    {
        ll sum=0;
        vector<int> aux(k/2+2);
        for(int j=0;j<=k;j++)
        {
            sum=(sum+dp[sons[i]][j])%mod;
            if(j+1<k/2+2)
                aux[j+1]=sum;
        }
        for(int j=0;2*j<=k;j++)
            aux[j]=(aux[j]+sum)%mod;
//        db(sum)
        if(i==s-1)
        {
            for(int j=0;2*j<=k;j++)
                r[s-1][j]=aux[j];
        }
        else
        {
            for(int j=0;2*j<=k;j++)
                r[i][j]=(1ll*aux[j]*1ll*r[i+1][j])%mod;
        }
    }

    for(int i=0;i<=k;i++)
    {
        if(i*2<=k)
        {
            if(!i)
                dp[u][0]=l[s-1][0];
            else
                dp[u][i]=(l[s-1][i]-l[s-1][i-1]+mod)%mod;
        }
        else
        {
            for(int j=0;j<s;j++)
            {
                ll lr=1;
                ll rl=1;
                if(j)
                    lr=l[j-1][k-i];
                if(j+1<s)
                    rl=r[j+1][k-i];
                dp[u][i]=(dp[u][i]+1ll*dp[sons[j]][i-1]*1ll*((lr*rl)%mod))%mod;
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int u,v;
    cin >> n >> k;
    for(int i=0;i<n-1;i++)
    {
        cin >> u >> v;
        u--,v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    dfs(0);

//    for(int i=0;i<n;i++,cout << '\n')
//        for(int j=0;j<=k;j++)
//            cout << dp[i][j] << ' ' ;

    ll res=0;
    for(int i=0;i<=k;i++)
        res=(res+dp[0][i])%mod;
    db(res)

    return 0;
}
/**
4 3
1 2
1 3
1 4
**/