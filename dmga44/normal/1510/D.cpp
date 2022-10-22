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
#define MAXN (ll)(2e5+5)

ld dp[MAXN][10];
pii pre[MAXN][10];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n,d;
    cin >> n >> d;
    for(int i=0;i<10;i++)
    {
        dp[0][i]=-1e7;
        pre[0][i]={-1,-1};
    }
    dp[0][1]=0;

    vector<int> xs(n);
    for(int i=0;i<n;i++)
    {
        ld a;
        cin >> a;
        int x=a;
        xs[i]=a;
        x%=10;
        a=log(a);
        for(int j=0;j<10;j++)
        {
            dp[i+1][j]=dp[i][j];
            pre[i+1][j]=pre[i][j];
        }
        for(int j=0;j<10;j++)
        {
            int y=(x*j)%10;
            if(dp[i+1][y]<dp[i][j]+a)
            {
                dp[i+1][y]=dp[i][j]+a;
                pre[i+1][y]=pii(i,j);
            }
        }
    }

    vector<int> res;
    pii act=pre[n][d];
    while(act!=pii(-1,-1))
    {
        res.push_back(xs[act.f]);
        act=pre[act.f][act.s];
    }

    if(res.empty() || dp[n][d]<0)
        db(-1)
    else
    {
        db(res.size())
        for(auto x : res)
            cout << x << ' ';
        cout << '\n';
    }

    return 0;
}