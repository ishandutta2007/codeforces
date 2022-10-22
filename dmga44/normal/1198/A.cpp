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

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll n,sz,a;
    cin >> n >> sz;
    sz*=8;
    set<ll> xxx;
    vector<ll> v;
    for(int i=0;i<n;i++)
    {
        cin >> a;
        v.push_back(a);
        xxx.insert(a);
    }

    map<ll,ll> m;
    ll cont=0;
    for(auto y : xxx)
    {
        m[y]=cont;
        cont++;
    }
    sort(v.begin(),v.end());

    for(ll i=0;i<n;i++)
        v[i]=m[v[i]];

    ll res=n;
    for(ll i=0;i<=30;i++)
    {
        if(i*n>sz)
            continue;
        ll l=0,r=0;
        while(l<n)
        {
            while(r<n && v[r]<v[l]+(1<<i))
                r++;
            res=min(res,n-r+l);
            l++;
        }
    }
    db(res)

    return 0;
}