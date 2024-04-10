#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
using namespace std;
typedef long long ll;
typedef double ld;
typedef pair<ll,ll> pii;
typedef pair<ll,pii> pip;
typedef pair<pii,ll> ppi;
typedef pair<pii,pii> ppp;
typedef pair<ld,ll> pli;
typedef pair<pii,string> pps;
typedef pair<string,int> psi;
typedef pair<char,ll> pci;
typedef complex<double> point;
typedef vector<point> polygon;
#define pi (acos(-1))
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<ll, null_type, less<ll>,rb_tree_tag, tree_order_statistics_node_update> ordered_set;
#define MAXN 100005

int a[MAXN];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    int ma=0;
    for(int i=0;i<n;i++)
    {
        cin >> a[i];
        ma=max(ma,a[i]);
    }

    int res=0,ant=-1,ac=0;
    for(int i=0;i<n;i++)
    {
        if(a[i]!=ant)
        {
            if(ant==ma)
                res=max(res,ac);
            ant=a[i];
            ac=1;
        }
        else
            ac++;
    }
    if(ant==ma)
        res=max(res,ac);
    db(res)
    return 0;
}