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
#define MAXN (ll)(1e6+5)

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    vector<pii> res;
    vector<pii> ord;
    for(int i=0;i<n;i++)
    {
        int x;
        cin >> x;
        ord.push_back(pii(x,i));
    }

    sort(allr(ord));

    vector<int> q;
    for(int i=0;i<n;i++)
    {
        q.push_back(2*(ord[i].s+1));
        if(i)
            res.push_back(pii(2*(ord[i].s+1),2*(ord[i-1].s+1)));
    }

    for(int i=0;i<n;i++)
    {
        int v=2*(ord[i].s+1)-1;
        int u=q[i+ord[i].f-1];
        if(u==q.back())
            q.push_back(v);
        res.push_back(pii(u,v));
    }

    for(int i=0;i<2*n-1;i++)
        cout << res[i].f << ' ' << res[i].s << '\n';

    return 0;
}