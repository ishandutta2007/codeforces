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
#define MAXN 200005

int a[MAXN];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    int ma=0,p=-1;
    for(int i=0;i<n;i++)
    {
        cin >> a[i];
        if(a[i]>ma)
        {
            ma=a[i];
            p=i;
        }
    }

    bool ok=1;
    for(int i=p-1;i>=0;i--)
        ok&=(a[i]<a[i+1]);

    for(int i=p+1;i<n;i++)
        ok&=(a[i]<a[i-1]);

    if(ok)
        db("YES")
    else
        db("NO")

    return 0;
}