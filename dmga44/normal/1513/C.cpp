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
const ll mod=(1e9+7);
const ld eps=(1e-9);
const ll oo=(ll)(1e18);
#define pi acos(-1)
#define MAXN (ll)(2e5+5)

ll m[10][MAXN][10];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    for(int i=0;i<10;i++)
        m[i][0][i]=1;
    for(int i=0;i<10;i++)
        for(int j=0;j<MAXN-1;j++)
            for(int k=0;k<10;k++)
            {
                m[i][j+1][(k+1)%10]=(m[i][j+1][(k+1)%10]+m[i][j][k])%mod;
                if(k==9)
                    m[i][j+1][1]=(m[i][j+1][1]+m[i][j][9])%mod;
            }

    int t;
    cin >> t;
    while(t--)
    {
        int n,mm;
        cin >> n >> mm;
        vector<ll> f(10);
        while(n)
        {
            f[n%10]++;
            n/=10;
        }
        vector<ll> ff(10);
        for(int i=0;i<10;i++)
        {
            for(int j=0;j<10;j++)
                ff[j]=(ff[j]+f[i]*m[i][mm][j])%mod;
        }

        ll res=0;
        for(int i=0;i<10;i++)
            res=(res+ff[i])%mod;
        db(res)
    }

    return 0;
}