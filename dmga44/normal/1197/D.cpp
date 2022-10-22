#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pii;
typedef pair<ll,pii> pip;
typedef pair<pii,ll> ppi;
typedef pair<pii,pii> ppp;
typedef long double ld;
typedef pair<ld,ll> pli;
typedef pair<pii,string> pps;
typedef pair<char,ll> pci;
#define pi (acos(-1))
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<ll, null_type, less<ll>,rb_tree_tag, tree_order_statistics_node_update> ordered_set;
#define MAXN 300005

ll a[MAXN];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll n,m,k;
    cin >> n >> m >> k;
    vector<ll> v(m);
    ll res=0;
    ll ac=0;
    for(ll i=0;i<n;i++)
    {
        cin >> a[i];
        ac+=a[i];
        ll val=ac-(((i/m)+1)*k);
        ll im=i%m;
        for(ll j=0;j<m;j++)
        {
            if(j<im)
                res=max(res,val-v[j]-k);
            else
                res=max(res,val-v[j]);
        }
        v[im]=min(v[im],val);
    }
    db(res)

    return 0;
}