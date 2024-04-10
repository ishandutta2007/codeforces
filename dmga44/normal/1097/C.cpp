#pragma GCC optimize("Ofast","unroll-loops","omit-frame-pointer","inline") //Optimization flags
#pragma GCC option("arch=native","tune=native","no-zero-upper") //Enable AVX
#pragma GCC target("avx2") //Enable AVX
#pragma GCC optimize("03")
#pragma GCC target ("sse4")

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
typedef pair<double,pii> pdp;
typedef pair<string,ll> psi;
typedef pair<ll,string> pls;
typedef pair<string,string> pss;
typedef pair<ll,pii> pip;
typedef pair<pii,pii> ppp;
typedef complex<ld> point;
typedef pair<point,int> ppi;
#define prec(n) cout.precision(n); cout<<fixed
#define mod (ll)(1e9+7)
#define eps (1e-9)
const ll oo=(ll)(1e9);
#define pi acos(-1)
#define MAXN (ll)(5e5+5)

int f[MAXN][2];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    int c0=0;
    for(int i=0;i<n;i++)
    {
        string s;
        cin >> s;
        int mi=0;
        int sum=0;
        for(auto y : s)
        {
            if(y=='(')
                sum++;
            else
            {
                sum--;
                mi=min(mi,sum);
            }
        }
        if(sum==0)
            c0+=(mi==0);
        else
        {
            if(sum>0)
                f[sum][0]+=(mi==0);
            else
                f[-sum][1]+=(sum==mi);
        }
    }

    int res=c0/2;
    for(int i=0;i<MAXN;i++)
        res+=min(f[i][0],f[i][1]);
    db(res)

    return 0;
}