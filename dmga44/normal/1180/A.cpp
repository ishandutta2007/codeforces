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

typedef tree<ll, null_type, less<ll>,
    rb_tree_tag, tree_order_statistics_node_update> ordered_set;
#define MAXN 105

int res[MAXN];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    res[0]=1;
    for(int i=1;i<MAXN;i++)
        res[i]=(res[i-1]+(4*i));
    int n;
    cin >> n;
    db(res[n-1])

    return 0;
}