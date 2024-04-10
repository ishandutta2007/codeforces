#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pii;
typedef pair<ll,pii> pip;
typedef pair<pii,ll> ppi;
typedef pair<pii,pii> ppp;
typedef pair<ld,ll> pli;
typedef pair<pii,string> pps;
typedef pair<char,ll> pci;
typedef complex<double> point;
typedef vector<point> polygon;
#define pi (acos(-1))
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<ll, null_type, less<ll>,rb_tree_tag, tree_order_statistics_node_update> ordered_set;
#define MAXN 100005

ll f[MAXN],c[MAXN];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll n,m;
    cin >> n >> m;
    for(int i=0;i<n;i++)
        cin >> f[i];
    priority_queue<pii,vector<pii>,greater<pii> > pq;
    for(int i=0;i<n;i++)
    {
        cin >> c[i];
        pq.push(pii(c[i],i));
    }

    while(m--)
    {
        ll t,d;
        cin >> t >> d;
        t--;
        ll cost=0,dd=d,ac=0;
        ll mi=min(f[t],d);
        ac+=mi;
        cost+=(mi*c[t]);
        f[t]-=mi;
        while(ac<dd && !pq.empty())
        {
            pii xxx=pq.top();
            ll ty=xxx.second;
            ll cc=xxx.first;
            if(!f[ty])
            {
                pq.pop();
                continue;
            }
            mi=min(f[ty],(dd-ac));
            ac+=mi;
            cost+=(mi*cc);
            f[ty]-=mi;
        }
        if(ac==dd)
            db(cost)
        else
            db(0)
    }

    return 0;
}