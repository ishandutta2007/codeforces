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
const ll mod=(ll)(1e9+7);
const ld eps=(1e-9);
const ll oo=(ll)(1e18+5);
#define pi acos(-1)
#define MAXN (ll)(1e7+5)

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        vector<ll> t(n);
        vector<ll> s(n);
        for(int i=0;i<n;i++)
            cin >> t[i];
        for(int i=0;i<n;i++)
            cin >> s[i];
        vector<ll> dp(n);
        for(int i=1;i<n;i++)
            for(int j=i-1;j>=0;j--)
                if(t[i]!=t[j])
                {
                    ll v1=abs(s[i]-s[j])+dp[j];
                    ll v2=abs(s[i]-s[j])+dp[i];
                    dp[i]=max(dp[i],v1);
                    dp[j]=max(dp[j],v2);
                }
        ll res=0;
        for(int i=0;i<n;i++)
            res=max(res,dp[i]);
        db(res)
    }

    return 0;
}