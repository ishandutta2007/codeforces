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

ll a[MAXN],mk[MAXN];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll n,x;
    cin >> n;
    for(int i=0;i<n-1;i++)
    {
        cin >> x;
        a[i+1]=a[i]+x;
    }

    ll mi=0;
    for(int i=0;i<n;i++)
        mi=min(mi,a[i]);

    for(int i=0;i<n;i++)
    {
        a[i]=a[i]-mi;
        if(a[i]<MAXN)
            mk[a[i]]=1;
    }

    int sum=0;
    for(int i=0;i<n;i++)
        sum+=mk[i];
    if(sum==n)
    {
        for(int i=0;i<n;i++)
            cout << a[i]+1 << ' ';
        db("")
    }
    else
        db(-1)

    return 0;
}