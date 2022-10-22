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
#define MAXN 200005

ll a[MAXN];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll h,n;
    cin >> h >> n;
    ll sum=0;
    ll hh=h;
    ll mi=0;
    for(ll i=0;i<n;i++)
    {
        cin >> a[i];
        sum+=a[i];
        hh=hh+a[i];
        mi=min(mi,hh-h);
        if(hh<=0)
        {
            db(i+1)
            return 0;
        }
    }

    if(sum>=0)
        db(-1)
    else
    {
        ll div=(h+mi-1)/(-sum)+1;
        ll res=n*div;
        hh=h+(div*sum);
        for(ll i=0;i<n;i++)
        {
            hh=hh+a[i];
            if(hh<=0)
            {
                db(res+i+1)
                return 0;
            }
        }
    }

    return 0;
}