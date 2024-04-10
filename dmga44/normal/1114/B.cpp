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

ll mk[MAXN],a[MAXN];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll n,m,k;
    cin >> n >> m >> k;
    vector<pii> v;
    for(ll i=0;i<n;i++)
    {
        cin >> a[i];
        v.push_back(pii(a[i],i));
    }

    sort(v.rbegin(),v.rend());

    ll sum=0;
    for(int i=0;i<m*k;i++)
    {
        mk[v[i].second]=1;
        sum+=v[i].first;
    }

    db(sum)
    int ac=0,cont=k-1;
    for(int i=0;i<n;i++)
    {
        if(mk[i])
            ac++;
        if(ac==m && cont)
        {
            cout << i+1 << ' ';
            ac=0;
            cont--;
        }
    }
    cout << '\n';

    return 0;
}