#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
using namespace std;
typedef long long ll;
typedef double ld;
typedef pair<ll,ll> pii;
typedef pair<ll,pii> pip;
typedef pair<pii,ll> ppi;
typedef pair<pii,pii> ppp;
typedef pair<ld,ll> pli;
typedef pair<pii,string> pps;
typedef pair<string,ll> psi;
typedef pair<ll,char> pic;
typedef pair<char,ll> pci;
typedef complex<double> point;
typedef vector<point> polygon;
#define pi (acos(-1))
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<ll, null_type, less<ll>,rb_tree_tag, tree_order_statistics_node_update> ordered_set;
#define MAXN 100005

int a[MAXN],b[MAXN];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    vector<int> aa,bb;
    for(int i=0;i<n;i++)
    {
        cin >> a[i];
        if(i)
            aa.push_back(a[i]-a[i-1]);
    }

    for(int i=0;i<n;i++)
    {
        cin >> b[i];
        if(i)
            bb.push_back(b[i]-b[i-1]);
    }

    sort(aa.begin(),aa.end());
    sort(bb.begin(),bb.end());

    bool ok=1;
    for(int i=0;i<n-1;i++)
        ok&=(aa[i]==bb[i]);
    if(ok && a[0]==b[0])
        db("Yes")
    else
        db("No")

    return 0;
}