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
#define MAXN (ll)(1e3+5)

ll dp[MAXN][MAXN];
ll ac[MAXN][MAXN];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--)
    {
        int n,k;
        cin >> n >> k;
        if(k==1)
        {
            db(1)
            continue;
        }
        if(n==1)
        {
            db(2)
            continue;
        }
        ll res=1;
        for(int i=0;i<n;i++)
        {
            dp[k-1][i]=1;
            ac[k-1][i+1]=i+1;
        }

        for(int i=k-2;i>0;i--)
        {
            for(int j=0;j<n;j++)
            {
                if((k-i)&1)
                {
                    dp[i][j]=(ac[i+1][j])%mod;
                }
                else
                {
                    dp[i][j]=(ac[i+1][n]-ac[i+1][j+1]+mod)%mod;
                }
                ac[i][j+1]=(ac[i][j]+dp[i][j])%mod;
            }
        }

        for(int i=1;i<k;i++)
            res=(res+ac[i][n])%mod;
        db(res)
    }

    return 0;
}