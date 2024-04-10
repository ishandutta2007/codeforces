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
const ll oo=(ll)(1e9);
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
        vector<ll> a(n);
        ll sum=0;
        for(int i=0;i<n;i++)
        {
            cin >> a[i];
            sum+=a[i];
        }

        if(sum%n)
        {
            db(-1)
            continue;
        }

        ll x=sum/n;
        vector<pip> res;
        for(int i=1;i<n;i++)
        {
            ll v=a[i]%(i+1);
            if(v)
            {
                v=i+1-v;
                a[0]-=v;
                a[i]+=v;
                res.push_back(pip(v,pii(1,i+1)));
            }
            v=a[i]/(i+1);
            a[0]+=v*(i+1);
            a[i]-=v*(i+1);
            res.push_back(pip(v,pii(i+1,1)));
        }

        for(int i=1;i<n;i++)
        {
            ll v=x-a[i];
            a[0]-=v;
            a[i]+=v;
            res.push_back(pip(v,pii(1,i+1)));
        }

        db(res.size())
        for(auto y : res)
            cout << y.s.f << ' ' << y.s.s << ' ' << y.f << '\n';
    }

    return 0;
}