#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pii;
typedef pair<ll,pii> pip;
typedef pair<pii,ll> ppi;
typedef pair<pii,pii> ppp;
typedef pair<ld,ll> pli;
typedef pair<pii,string> pps;
typedef pair<char,ll> pci;
typedef complex<double> point;
typedef vector<point> polygon;
#define pi (acos(-1))
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<ll, null_type, less<ll>,rb_tree_tag, tree_order_statistics_node_update> ordered_set;

int f(int x)
{
    int v=((x+3)%4);
    if(v==1)
        return 2;
    if(v==2)
        return 1;
    return v;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int x;
    cin >> x;
    pii v=pii(f(x),0);
    x++;
    pii v1=pii(f(x),1);
    x++;
    pii v2=pii(f(x),2);
    vector<pii> vs;
    vs.push_back(v);
    vs.push_back(v1);
    vs.push_back(v2);

    sort(vs.begin(),vs.end());

    cout << vs[0].second << ' ' << (char)('A'+vs[0].first) << '\n';

    return 0;
}