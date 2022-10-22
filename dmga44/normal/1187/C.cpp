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
#define MAXN 1005

int res[MAXN];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n,m;
    cin >> n >> m;
    for(int i=0;i<n;i++)
        res[i]=n-i;
    vector<pii> v,v2;
    for(int i=0;i<m;i++)
    {
        int t,l,r;
        cin >> t >> l >> r;
        l--,r--;
        if(!t)
            v.push_back(pii(l,r));
        else
            v2.push_back(pii(r,l));
    }

    sort(v2.rbegin(),v2.rend());
    for(auto y : v2)
    {
        int l=y.second;
        int r=y.first;
        for(int i=l;i<=r;i++)
            res[i]=res[r];
    }

    bool ok=1;
    for(auto y : v)
    {
        bool yo=0;
        int l=y.first;
        int r=y.second;
        for(int j=l;j<r;j++)
            if(res[j]>res[j+1])
                yo=1;
        ok&=yo;
    }

    if(ok)
    {
        db("YES")
        for(int i=0;i<n;i++)
            cout << res[i] << ' ';
        cout << '\n';
    }
    else
        db("NO")

    return 0;
}