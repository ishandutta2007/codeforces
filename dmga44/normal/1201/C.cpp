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
typedef double ld;
typedef pair<ll,ll> pii;
typedef pair<ld,ll> pdi;
typedef pair<ld,ld> pdd;
typedef pair<double,pii> pdp;
typedef pair<string,ll> psi;
typedef pair<ll,string> pls;
typedef pair<string,string> pss;
typedef pair<ll,pii> pip;
typedef pair<pii,pii> ppp;
typedef complex<ll> point;
typedef pair<point,int> ppi;
#define mod (ll)(1e9+7)
#define eps (1e-9)
#define oo (ll)(1e9)
#define pi acos(-1)
#define MAXN (ll)(1e3+5)

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll n,k;
    cin >> n >> k;
    vector<ll> a(n);
    for(int i=0;i<n;i++)
        cin >> a[i];
    sort(allr(a));

    for(int i=0;i<n/2;i++)
        a.pop_back();
    reverse(all(a));

    ll lim=a[0];
    ll p=0;
    while(1)
    {
        while(p<a.size() && a[p]==lim)
            p++;

        if(p==a.size())
        {
            lim+=k/a.size();
            break;
        }
        ll nextt=a[p];
        ll d=a[p]-lim;
        if(d*p<k)
        {
            k-=d*p;
            lim+=d;
        }
        else
        {
            lim+=k/p;
            break;
        }
    }
    db(lim)

    return 0;
}