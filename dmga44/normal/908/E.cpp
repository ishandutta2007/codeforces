#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops","omit-frame-pointer","inline")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,popcnt,abm,mmx,avx,avx2,fma,tune=native")
#pragma GCC option("arch=native","no-zero-upper") //Enable AVX

///UH Top
#include <bits/stdc++.h>
#define db(x) cerr << #x << ':' << (x) << '\n';
#define all(v) (v).begin(),(v).end()
#define allr(v) (v).rbegin(),(v).rend()
// #define int ll
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
// typedef __int128_t int128;
typedef pair<ll,ll> pii;
typedef pair<ld,ll> pdi;
typedef pair<ld,ld> pdd;
typedef pair<ld,pdd> pdp;
typedef pair<string,ll> psi;
typedef pair<ll,string> pls;
typedef pair<string,string> pss;
typedef pair<ll,pii> pip;
typedef pair<pii,pii> ppp;
typedef complex<ld> point;
typedef vector<point> polygon;
typedef vector<ll> vi;
typedef pair<point,int> ppi;
#define prec(n) cout.precision(n); cout<<fixed
const ll mod=(1e9+7);
const ld eps=(1e-9);
const ll oo=(ll)(1e18+5);
#define pi acos(-1)
#define MAXN (ll)(1e3+5)

ll dp[MAXN][MAXN];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);


    int n,m;
    cin >> m >> n;
    dp[1][1]=1;
    for(int i=1;i<m;i++)
        for(int j=1;j<=i;j++)
        {
            dp[i+1][j]=(dp[i+1][j]+dp[i][j]*j)%mod;
            dp[i+1][j+1]=(dp[i+1][j+1]+dp[i][j])%mod;
        }
    vector<int> bs(m+1);
    for(int i=1;i<=m;i++)
        for(int j=0;j<=i;j++)
            bs[i]=(bs[i]+dp[i][j])%mod;
    
    vector<string> a(n);
    for(int i=0;i<n;i++)
        cin >> a[i];
    set<string> s;
    for(int i=0;i<m;i++)
    {
        string act(m,'1');
        for(int j=0;j<n;j++)
            for(int k=0;k<m;k++)
                act[k]='0'+((act[k]-'0')&((a[j][k]=='1')^(a[j][i]=='0')));
        s.insert(act);
    }

    ll ans=1;
    for(auto b : s)
    {
        int x=0;
        for(auto c : b)
            x+=(c=='1');
        ans=(bs[x]*ans)%mod;
    }
    cout << ans << '\n';

    return 0;   
}