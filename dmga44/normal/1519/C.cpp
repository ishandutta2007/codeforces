#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops","omit-frame-pointer","inline")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,popcnt,abm,mmx,avx,avx2,fma,tune=native")
#pragma GCC option("arch=native","no-zero-upper") //Enable AVX

///UH Top
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
typedef pair<int,int> pii;
typedef pair<ld,ll> pdi;
typedef pair<ld,ld> pdd;
typedef pair<ld,pdd> pdp;
typedef pair<string,ll> psi;
typedef pair<ll,string> pls;
typedef pair<string,string> pss;
typedef pair<int,pii> pip;
typedef pair<pii,pii> ppp;
typedef complex<ll> point;
typedef vector<point> polygon;
typedef pair<point,int> ppi;
#define prec(n) cout.precision(n); cout<<fixed
const ll mod=(1e9+7);
const ld eps=(1e-9);
const ll oo=(ll)(1e18+5);
#define pi acos(-1)
#define MAXN (ll)(2e5+5)

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        vector<vector<ll>> s(n),ac(n);
        vector<int> f(n),a(n);
        vector<int> tov;
        for(int i=0;i<n;i++)
        {
            tov.push_back(i);
            ac[i].push_back(0);

            cin >> a[i];
            a[i]--;
            f[a[i]]++;
        }

        for(int i=0;i<n;i++)
        {
            int x;
            cin >> x;
            s[a[i]].push_back(x);
        }

        for(int i=0;i<n;i++)
        {
            sort(allr(s[i]));
            for(auto x : s[i])
                ac[i].push_back(ac[i].back()+x);
        }

        for(int k=1;k<=n;k++)
        {
            vector<int> ntv;
            ll ans=0;
            for(auto p : tov)
            {
                int sz=f[p]-(f[p]%k);
                if(!sz)
                    continue;
                ntv.push_back(p);
                ans+=ac[p][sz];
            }
            tov=ntv;
            cout << ans << " \n"[k==n];
        }
    }

    return 0;
}