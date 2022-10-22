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
#define MAXN 105

ll a[MAXN];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    ll sum=0;
    for(int i=0;i<n;i++)
    {
        cin >> a[i];
        sum+=a[i];
    }

    vector<int> res;
    res.push_back(1);
    ll s1=a[0];
    for(int i=1;i<n;i++)
        if(a[i]*2<=a[0])
        {
            res.push_back(i+1);
            s1+=a[i];
        }

    if(s1*2>sum)
    {
        db(res.size())
        for(auto y: res)
            cout << y << ' ';
    }
    else
        db(0)

    return 0;
}