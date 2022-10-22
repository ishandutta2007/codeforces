#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pii;
typedef pair<ll,pii> pip;
typedef pair<pii,int> ppi;
typedef pair<pii,pii> ppp;
typedef long double ld;
typedef pair<ld,int> pli;
typedef pair<pii,string> pps;
typedef pair<char,int> pci;
#define pi (acos(-1))
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<ll, null_type, less<ll>,rb_tree_tag, tree_order_statistics_node_update> ordered_set;
#define MAXN 100005

int res[MAXN];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int s,b,x,y;
    cin >> s >> b;
    vector<pii> ss;
    vector<pii> bs;
    for(int i=0;i<s;i++)
    {
        cin >> x;
        ss.push_back(pii(x,i));
    }

    for(int i=0;i<b;i++)
    {
        cin >> x >> y;
        bs.push_back(pii(x,y));
    }

    sort(ss.begin(),ss.end());
    sort(bs.begin(),bs.end());

    ll re=0,l=0,r=0;
    while(l<s)
    {
        while(r<b && bs[r].first<=ss[l].first)
        {
//            cout << bs[r].first << ' ' << bs[r].second << '\n';
            re+=bs[r].second;
            r++;
        }
        res[ss[l].second]=re;

        l++;
    }

    for(int i=0;i<s;i++)
        cout << res[i] << ' ';
    cout << '\n';

    return 0;
}