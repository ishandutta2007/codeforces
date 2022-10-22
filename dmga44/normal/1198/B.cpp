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

int a[MAXN],mk[MAXN];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    for(int i=1;i<=n;i++)
        cin >> a[i];
    int q;
    cin >> q;
    vector<pii> v;
    while(q--)
    {
        int t,x,y;
        cin >> t;
        if(t==1)
        {
            cin >> x >> y;
            v.push_back(pii(y,x));
        }
        else
        {
            cin >> x;
            v.push_back(pii(x,0));
        }
    }

    reverse(v.begin(),v.end());

    ll ma=0;
    for(auto y : v)
    {
        if(y.second && !mk[y.second])
        {
            a[y.second]=max(y.first,ma);
            mk[y.second]=1;
        }
        else if(!y.second)
            ma=max(ma,y.first);
    }

//    for(int i=1;i<=n;i++)
//        cout << a[i] << ' ';
//    db("")

    for(int i=1;i<=n;i++)
        if(!mk[i] && a[i]<ma)
            a[i]=ma;

    for(int i=1;i<=n;i++)
        cout << a[i] << ' ';
    cout << '\n';

    return 0;
}