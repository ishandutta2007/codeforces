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
typedef complex<ld> point;
typedef vector<point> polygon;
typedef pair<point,int> ppi;
#define prec(n) cout.precision(n); cout<<fixed
#define mod (ll)(1e9+7)
#define eps (1e-9)
const ll oo=(ll)(1e18);
#define pi acos(-1)
#define MAXN (ll)(3e5+5)

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        vector<int> a(n);
        map<int,int> f;
        map<int,int> es;
        int x=1;
        for(int i=0;i<n;i++)
        {
            cin >> a[i];
            f[a[i]]++;
            if(i && a[i]==a[i-1])
            {
                es[a[i]]+=2;
                x++;
            }
        }
        es[a[0]]++;
        es[a[n-1]]++;

        int ma=0;
        for(auto y : f)
            ma=max(ma,y.s);
        if(ma>(n+1)/2)
        {
            db(-1)
            continue;
        }
        int me=0;
        for(auto y : es)
            me=max(me,y.s);
        if(x-1>=me-2)
            db(x-1)
        else
        {
            int ad=(me-x-1);
            db(x+ad-1)
        }
    }

    return 0;
}