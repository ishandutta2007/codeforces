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
const ll mod=(998244353);
const ld eps=(1e-9);
const ll oo=(ll)(1e18+5);
#define pi acos(-1)
#define MAXN (ll)(3e5+5)

ll dp[MAXN];
ll dp0[MAXN];
ll dp1[MAXN];
ll p2[MAXN];
string s[MAXN];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    dp0[0]=1;
    p2[0]=1;
    for(int i=1;i<MAXN;i++)
    {
        p2[i]=(2*p2[i-1])%mod;
        dp[i]=(2*dp[i-1]+dp1[i-1])%mod;
        dp0[i]=(dp0[i-1]+2*dp1[i-1])%mod;
        dp1[i]=(dp0[i-1])%mod;
    }

    int n,m;
    cin >> n >> m;
    int cant=0;
    for(int i=0;i<n;i++)
    {
        cin >> s[i];
        for(int j=0;j<m;j++)
            cant+=(s[i][j]=='o');
    }

    ll res=0;
    for(int i=0;i<n;i++)
    {
        int sz=0;
        for(int j=0;j<m;j++)
        {
            if(s[i][j]=='o')
                sz++;
            else
            {
                res=(res+dp[sz]*p2[cant-sz])%mod;
                sz=0;
            }
        }
        res=(res+dp[sz]*p2[cant-sz])%mod;
    }

    for(int j=0;j<m;j++)
    {
        int sz=0;
        for(int i=0;i<n;i++)
        {
            if(s[i][j]=='o')
                sz++;
            else
            {
                res=(res+dp[sz]*p2[cant-sz])%mod;
                sz=0;
            }
        }
        res=(res+dp[sz]*p2[cant-sz])%mod;
    }
    db(res)

    return 0;
}