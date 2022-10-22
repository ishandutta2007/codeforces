#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<int,pii> pip;
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
#define MAXN 5005

vector<int> v[MAXN];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n,m,a,b;
    cin >> n >> m;
    for(int i=0;i<m;i++)
    {
        cin >> a >> b;
        a--,b--;
        v[a].push_back((b-a+n)%n);
    }

    for(int i=0;i<n;i++)
        sort(v[i].rbegin(),v[i].rend());

    for(int i=0;i<n;i++)
    {
        int res=0;
        for(int j=0;j<n;j++)
            if(v[(i+j)%n].size())
                res=max(j+(int)(v[(i+j)%n].size()*n)-n+v[(i+j)%n][v[(i+j)%n].size()-1],res);

        cout << res << ' ';
    }
    cout << '\n';

    return 0;
}