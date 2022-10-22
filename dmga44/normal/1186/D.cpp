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

ll res[MAXN],ok[MAXN];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    ll sum=0;
    for(int i=0;i<n;i++)
    {
        ld x;
        cin >> x;
        ll y=x;
        ok[i]=1;
        if((x-y)==0)
            ok[i]=0;
        if(x<0 && ok[i])
            y--;
        res[i]=y;
        sum+=y;
    }

    for(int i=0;i<n;i++)
    {
        if(sum && ok[i])
        {
            res[i]++;
            sum++;
        }
        db(res[i])
    }


    return 0;
}