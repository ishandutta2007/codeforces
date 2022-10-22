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
#define mod (ll)(998244353)
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
        int n,k;
        cin >> n >> k;
        vector<int> a(n);
        vector<int> pos(n+1);
        set<pii> s;
        for(int i=0;i<n;i++)
        {
            cin >> a[i];
            pos[a[i]]=i;
            s.insert(pii(i,a[i]));
        }
        vector<bool> mk(n+1);
        vector<int> ks(k);
        for(int i=0;i<k;i++)
        {
            cin >> ks[i];
            mk[ks[i]]=1;
        }
        ll res=1;
        for(int i=0;i<k;i++)
        {
            int x=ks[i];
            auto it=s.find(pii(pos[x],x));
            int l=x;
            int r=x;
            if(it!=s.begin())
            {
                it--;
                l=it->s;
                it++;
            }
            it++;
            if(it!=s.end())
            {
                r=it->s;
            }
//            cout << l << ' ' << r << '\n';
            ll cant=0;
            if(!mk[l])
                cant++;
            if(!mk[r])
                cant++;
            res=(res*cant)%mod;
            mk[x]=0;
            if(cant==1)
            {
                if(!mk[l])
                    s.erase(pii(pos[l],l));
                else
                    s.erase(pii(pos[r],r));
            }
//            db("")
//            for(auto y : s)
//                cout << y.f << ' ' << y.s << '\n';
        }
        db(res)
    }

    return 0;
}