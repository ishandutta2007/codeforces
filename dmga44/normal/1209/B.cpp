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
#define oo (ll)(1e9)
#define pi acos(-1)
#define MAXN (ll)(5e5+5)

int a[MAXN];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    string s;
    cin >> s;
    for(int i=0;i<n;i++)
        a[0]+=(s[i]-'0');
    for(int i=0;i<n;i++)
    {
        int x,y;
        cin >> x >> y;
        for(int j=y;j<=100000;j+=x)
        {
            if(((j-y)/x)&1)
                a[j]+=(1-(2*(1-s[i]+'0')));
            else
                a[j]+=(1-(2*(s[i]-'0')));
        }
    }

    for(int i=1;i<=100000;i++)
        a[i]+=a[i-1];

    int res=0;
    for(int i=0;i<=100000;i++)
        res=max(res,a[i]);
    db(res)

    return 0;
}