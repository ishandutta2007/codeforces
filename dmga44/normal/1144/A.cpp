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

    int n;
    cin >> n;
    while(n--)
    {
        string s;
        cin >> s;
        sort(s.begin(),s.end());

        bool ok=1;
        for(int i=0;i<s.size();i++)
            if(s[i]!=(s[0]+i))
                ok=0;
        if(ok)
            db("Yes")
        else
            db("No")
    }

    return 0;
}