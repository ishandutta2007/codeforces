#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pii;
typedef pair<ll,pii> pip;
typedef pair<pii,pii> ppp;
typedef long double ld;
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

    int n;
    cin >> n;
    for(int i=0;i<n;i++)
        cin >> a[i];
    for(int i=0;i<n;i++)
        if(a[i]>=0)
            a[i]=(-a[i]-1);

    if(n&1)
    {
        int ma=-1;
        for(int i=0;i<n;i++)
            ma=max(ma,-a[i]);
        for(int i=0;i<n;i++)
            if(a[i]==-ma)
            {
                a[i]=(-a[i]-1);
                break;
            }
    }

    for(int i=0;i<n;i++)
        cout << a[i] << ' ';
    cout << '\n';

    return 0;
}