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
#define eps (1e-6)
#define oo (ll)(1e18)
#define pi acos(-1)
#define MAXN (ll)(2e5+5)

ll sum[MAXN];
vector<pip> res;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n,m;
    cin >> n >> m;
    for(int i=0;i<m;i++)
    {
        int u,v,w;
        cin >> u >> v >> w;
        u--,v--;
        sum[u]+=w;
        sum[v]-=w;
    }

    priority_queue<pii,vector<pii>,greater<pii> > pq1;
    priority_queue<pii,vector<pii>,greater<pii> > pq2;
    for(int i=0;i<n;i++)
    {
        if(sum[i]>0)
            pq1.push(pii(sum[i],i));
        if(sum[i]<0)
            pq2.push(pii(-sum[i],i));
    }

    while(!pq1.empty() && !pq2.empty())
    {
        pii p1=pq1.top();
        pii p2=pq2.top();
        pq1.pop();
        pq2.pop();

        int u=p1.s;
        int v=p2.s;
        ll x=min(p1.f,p2.f);
        res.push_back(pip(x,pii(u,v)));
        if(p1.f!=x)
            pq1.push(pii(p1.f-x,u));
        if(p2.f!=x)
            pq2.push(pii(p2.f-x,v));
    }

    db(res.size())
    for(auto y: res)
        cout << y.s.f+1 << ' ' << y.s.s+1 << ' ' << y.f << '\n';

    return 0;
}