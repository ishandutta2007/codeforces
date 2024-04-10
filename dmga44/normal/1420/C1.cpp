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
#define mod (int)(1e9+7)
#define eps (1e-9)
#define oo (ll)(1e9)
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
        int n,q;
        cin >> n >> q;
        vector<int> d(n);
        vector<int> a(n+1);
        for(int i=0;i<n;i++)
            cin >> a[i];
        ll res=0;
        for(int i=0;i<n;i++)
        {
            d[i]=max(0,a[i]-a[i+1]);
            res=(res+d[i]);
        }

        db(res)
        while(q--)
        {
            int l,r;
            cin >> l >> r;
            l--,r--;
            if(l==r)
            {
                db(res)
                continue;
            }
            if(l)
                res-=d[l-1];
            res-=d[l];
            res-=d[r];
            if(l!=r-1)
                res-=d[r-1];

            swap(a[l],a[r]);

            if(l)
            {
                d[l-1]=max(0,a[l-1]-a[l]);
                res+=d[l-1];
            }
            d[l]=max(0,a[l]-a[l+1]);
            res+=d[l];
            d[r]=max(0,a[r]-a[r+1]);
            res+=d[r];
            if(l!=r-1)
            {
                d[r-1]=max(0,a[r-1]-a[r]);
                res+=d[r-1];
            }

            db(res)
        }
    }

    return 0;
}