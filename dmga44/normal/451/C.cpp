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
typedef pair<ld,pii> pdp;
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
#define MAXN (ll)(2e5+5)

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--)
    {
        ll n,k,d1,d2;
        cin >> n >> k >> d1 >> d2;
        if(n%3)
        {
            db("no")
            continue;
        }
        if(d1<d2)
            swap(d1,d2);
        ll v[3];
        v[0]=0;
        v[1]=0;
        v[2]=0;
        int res=0;
        for(int i=0;i<2;i++)
            for(int j=0;j<2;j++)
            {
                if(i)
                    v[0]=d1;
                else
                    v[0]=-d1;
                if(j)
                    v[2]=d2;
                else
                    v[2]=-d2;
                ll mi=0;
                for(int i=0;i<3;i++)
                    mi=min(mi,v[i]);
                if(((v[0]+v[1]+v[2]+(ll)(3e13))%3)==(k%3) && ((v[0]+v[1]+v[2])+((max(0ll,-mi))*3))<=k)
                {
                    ll sum=0;
                    ll ma=0;
                    for(int i=0;i<3;i++)
                        ma=max(ma,v[i]);
                    for(int i=0;i<3;i++)
                        sum+=ma-v[i];
//                    cout << i << ' ' << j << ' ' << sum << ' ' << ma << '\n';
                    if(sum<=n-k)
                        res=1;
                }
            }
        if(res)
            db("yes")
        else
            db("no")
    }

    return 0;
}