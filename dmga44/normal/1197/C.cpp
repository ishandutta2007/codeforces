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

    ll n,k,x;
    cin >> n >> k;
    set<int> s;
    ll mi=1e9+1,ma=0;
    for(int i=0;i<n;i++)
    {
        cin >> x;
        s.insert(x);
        mi=min(mi,x);
        ma=max(ma,x);
    }

    vector<int> v;

    int ant=0;
    for(auto y : s)
    {
        if(ant)
            v.push_back(y-ant);
        ant=y;
    }

    sort(v.rbegin(),v.rend());

    ll res=ma-mi;
    for(int i=0;i<min((ll)v.size(),k-1);i++)
        res-=v[i];
    db(res)

    return 0;
}