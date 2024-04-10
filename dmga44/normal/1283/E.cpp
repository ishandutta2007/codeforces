#pragma GCC optimize("Ofast","unroll-loops","omit-frame-pointer","inline") //Optimization flags
#pragma GCC option("arch=native","tune=native","no-zero-upper") //Enable AVX
#pragma GCC target("avx2") //Enable AVX

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
typedef pair<ld,ld> pdd;
typedef pair<double,ll> pdi;
typedef pair<double,pii> pdp;
typedef pair<string,ll> psi;
typedef pair<ll,string> pls;
typedef pair<string,string> pss;
typedef pair<ll,pii> pip;
typedef pair<pii,pii> ppp;
typedef complex<ld> point;
#define mod (ll)(1e9+7)
#define eps (1e-9)
#define oo (ll)(0x3f3f3f3f)
#define pi acos(-1)
#define MAXN (ll)(2e5+5)

bool mk[MAXN];
int dp[MAXN];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> a(n);
    for(int i=0;i<n;i++)
        cin >> a[i];

    sort(all(a));

    for(int i=0;i<n;i++)
        for(int j=-1;j<2;j++)
        {
            if(!mk[a[i]+j])
            {
                mk[a[i]+j]=1;
                break;
            }
        }

    int r2=0;
    for(int i=0;i<MAXN;i++)
        r2+=mk[i];

    dp[0]=0;
    int l=0;
    for(int i=0;i<n;i++)
    {
        while(a[i]-a[l]>2)
            l++;
        dp[i+1]=dp[l]+1;
    }

    cout << dp[n] << ' ' << r2 << '\n';

    return 0;
}