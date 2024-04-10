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

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n,x;
    cin >> n;
    vector<int> v,v1,v2;
    for(int i=0;i<n;i++)
    {
        cin >> x;
        v.push_back(x);
    }

    sort(v.begin(),v.end());

    for(int i=0;i<n;i++)
    {
        if(i&1)
            v2.push_back(v[i]);
        else
            v1.push_back(v[i]);
    }

    bool ok=1;
    for(int i=0;i+1<v1.size();i++)
        ok&=(v1[i]!=v1[i+1]);
    for(int i=0;i+1<v2.size();i++)
        ok&=(v2[i]!=v2[i+1]);

    if(ok)
    {
        db("YES")
        db(v1.size())
        for(auto y : v1)
            cout << y << ' ';
        cout << '\n';
        reverse(v2.begin(),v2.end());
        db(v2.size())
        for(auto y : v2)
            cout << y << ' ';
        cout << '\n';

    }
    else
        db("NO")

    return 0;
}