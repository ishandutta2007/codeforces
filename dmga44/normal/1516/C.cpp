#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops","omit-frame-pointer","inline")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,popcnt,abm,mmx,avx,avx2,fma,tune=native")
#pragma GCC option("arch=native","no-zero-upper") //Enable AVX

///UH Top
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
const ll mod=(1e9+7);
const ld eps=(1e-9);
const ll oo=(ll)(1e18+5);
#define pi acos(-1)
#define MAXN (ll)(2e5+5)

void solve(vector<int> a)
{
    int sum=0;
    for(auto x : a)
        sum+=x;
    if(sum&1)
    {
        db(0)
        return;
    }
    for(int i=0;i<a.size();i++)
    {
        if(a[i]&1)
        {
            db(1)
            db(i+1)
            return;
        }
        a[i]/=2;
    }
    solve(a);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    vector<bool> dp(MAXN);
    dp[0]=1;
    int sum=0;
    vector<int> a(n);
    for(int i=0;i<n;i++)
    {
        cin >> a[i];
        sum+=a[i];
        for(int j=MAXN-1;j>=a[i];j--)
            dp[j]=dp[j]|dp[j-a[i]];
    }
    if(dp[sum/2])
        solve(a);
    else
        db(0)

    return 0;
}