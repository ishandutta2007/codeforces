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
const ll oo=(ll)(1e18);
#define pi acos(-1)
#define MAXN (ll)(5e5+5)

int cant[MAXN];
ll w[MAXN];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--)
    {
        int n,u,v;
        cin >> n;
        ll sum=0;
        for(int i=0;i<n;i++)
        {
            cin >> w[i];
            sum+=w[i];
        }
        for(int i=0;i<n-1;i++)
        {
            cin >> u >> v;
            u--,v--;
            cant[u]++;
            cant[v]++;
        }

        vector<ll> ts;
        for(int i=0;i<n;i++)
        {
            cant[i]--;
            for(int j=0;j<cant[i];j++)
                ts.push_back(w[i]);
            cant[i]=0;
        }

        sort(allr(ts));

        cout << sum << ' ';
        for(auto y : ts)
        {
            sum+=y;
            cout << sum << ' ';
        }
        cout << '\n';
    }

    return 0;
}