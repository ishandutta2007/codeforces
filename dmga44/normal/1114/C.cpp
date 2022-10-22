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
#define MAXN 1000005

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll n,b;
    cin >> n >> b;
    vector<pii> v;
    for(int i=2;i<MAXN;i++)
    {
        if(b%i==0)
        {
            int e=0;
            while(b%i==0)
            {
                e++;
                b/=i;
            }
            v.push_back(pii(i,e));
        }
    }
    if(b!=1)
        v.push_back(pii(b,1));

    ll res=2e18;
    for(auto y : v)
    {
        ll x=y.first;
        ll div=y.second;
        ll nn=n,sum=0;
        while(nn)
        {
            nn/=x;
            sum+=nn;
        }
        res=min(res,sum/div);
    }
    db(res)

    return 0;
}