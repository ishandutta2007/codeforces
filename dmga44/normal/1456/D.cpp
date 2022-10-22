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
const ll oo=(ll)(1e18+5);
#define pi acos(-1)
#define MAXN (ll)(5e3+5)

ll mt[MAXN];
bool dp[MAXN][MAXN];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll n;
    cin >> n;
    n++;
    vector<ll> ts(n);
    vector<ll> xs(n);
    for(int i=1;i<n;i++)
        cin >> ts[i] >> xs[i];

    for(int i=0;i<n;i++)
        mt[i]=2e9;
    mt[0]=abs(xs[0]);

    for(int i=0;i<n;i++)
    {
        if(mt[i]<=ts[i] && i<n-1)
        {
            mt[i+1]=min(mt[i+1],max(mt[i]+abs(xs[i]-xs[i+1]),ts[i]));
            for(int j=i+1;j<n;j++)
            {
                ll extra=abs(xs[i]-xs[j])+abs(xs[j]-xs[i+1]);
                ll t1=ts[i]+abs(xs[j]-xs[i+1]);
                t1=max(t1,mt[i]+extra);
                if(ts[i+1]>=t1)
                {
//                    if(i+1==1 && j==2)
//                    {
//                        cout << "xxx" << '\n';
//                    }
                    dp[i+1][j]=1;
                }
            }
        }
        for(int j=i+1;j<n;j++)
        {
            if(!dp[i][j])
                continue;
            if(j>i+1)
            {
                if(ts[i]+abs(xs[i]-xs[i+1])<=ts[i+1])
                    dp[i+1][j]=1;
                continue;
            }
            mt[i+2]=min(mt[i+2],max(ts[i+1],ts[i]+abs(xs[i]-xs[i+2])));
//            if(i+2==n-1)
//            {
////                cout << ts[i+1] << ' ' << ts[i]+abs(xs[i]-xs[i+2]) << '\n';
//                db(mt[i+2])
//            }
            for(int k=i+2;k<n;k++)
            {
                ll extra=abs(xs[i]-xs[k])+abs(xs[k]-xs[i+2]);
                ll t1=ts[i+1]+abs(xs[k]-xs[i+2]);
                t1=max(t1,ts[i]+extra);
                if(ts[i+2]>=t1)
                    dp[i+2][k]=1;
            }
        }
    }

//    db(mt[n-1])
    if(mt[n-1]<=ts[n-1] || (n>1 && dp[n-2][n-1]))
        db("YES")
    else
        db("NO")

    return 0;
}