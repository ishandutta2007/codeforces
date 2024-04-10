#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pii;
typedef pair<ll,pii> pip;
typedef pair<pii,int> ppi;
typedef pair<pii,pii> ppp;
typedef long double ld;
typedef pair<ld,int> pli;
typedef pair<pii,string> pps;
typedef pair<char,int> pci;
#define pi (acos(-1))
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<ll, null_type, less<ll>,rb_tree_tag, tree_order_statistics_node_update> ordered_set;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll n,x,y;
    cin >> n;
    vector<pii> v;
    set<ll> ys;
    for(ll i=0;i<n;i++)
    {
        cin >> x >> y;
        v.push_back(pii(y,x));
        ys.insert(y);
    }

    sort(v.rbegin(),v.rend());

    vector<ll> yy;
    for(auto y : ys)
        yy.push_back(y);

    sort(yy.rbegin(),yy.rend());

    ordered_set xs;
    ll p=0,res=0;
    for(auto f : yy)
    {
        vector<ll> ps;
        while(p<n && v[p].first>=f)
        {
            ps.push_back(v[p].second);
            xs.insert(v[p].second);
            p++;
        }

        sort(ps.begin(),ps.end());

        for(ll i=0;i<ps.size();i++)
            ps[i]=xs.order_of_key(ps[i]);
        ps.push_back(-1);
        ps.push_back(xs.size());
        sort(ps.begin(),ps.end());
        for(ll i=0;i<ps.size()-1;i++)
        {
            ll dif=ps[i+1]-ps[i]-1;
            res-=(dif*(dif+1))/2;
        }

        ll m=xs.size();
        res+=((m*(m+1))/2);
    }
    db(res)

    return 0;
}