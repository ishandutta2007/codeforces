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
    vector<int> v[2];
    ll sum=0;
    for(int i=0;i<n;i++)
    {
        cin >> x;
        v[x&1].push_back(x);
        sum+=x;
    }

    sort(v[0].rbegin(),v[0].rend());
    sort(v[1].rbegin(),v[1].rend());

    if(v[0].size()==v[1].size())
        db(0)
    else
    {
        if(v[0].size()<v[1].size())
            swap(v[0],v[1]);
        ll s1=0;
        for(int i=0;i<=v[1].size();i++)
            s1+=v[0][i];
        for(int i=0;i<v[1].size();i++)
            s1+=v[1][i];
        db(sum-s1)
    }

    return 0;
}