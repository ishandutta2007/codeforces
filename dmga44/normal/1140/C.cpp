#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pii;
typedef pair<ll,pii> pip;
typedef pair<pii,pii> ppp;
typedef long double ld;
typedef pair<pii,string> pps;
typedef pair<char,int> pci;
#define pi (acos(-1))
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<ll, null_type, less<ll>,rb_tree_tag, tree_order_statistics_node_update> ordered_set;
#define MAXN 300005

ll t[MAXN],b[MAXN],it[MAXN],ib[MAXN],ac[MAXN];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n,k;
    cin >> n >> k;
    vector<pii> ts,bs;
    for(int i=0;i<n;i++)
    {
        cin >> t[i] >> b[i];
        ts.push_back(pii(t[i],i));
        bs.push_back(pii(b[i],i));
    }

    sort(ts.rbegin(),ts.rend());
    sort(bs.rbegin(),bs.rend());

    priority_queue<ll,vector<ll>,greater<ll> > pq;
    ll p=0,sum=0,res=0;
    for(ll i=0;i<n;i++)
    {
        while(p<=i)
        {
//            cout << bs[p].first << ' ' << bs[p].second << '\n';
            ll x=t[bs[p].second];
            sum+=x;
            pq.push(x);
            p++;
        }
        if(pq.size()>k)
        {
            sum-=pq.top();
            pq.pop();
        }
        res=max(res,sum*bs[i].first);
    }
    db(res)

    return 0;
}