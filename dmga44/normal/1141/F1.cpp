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
#define MAXN 1505

ll a[MAXN],ac[MAXN];
vector<pii> in[MAXN*MAXN];
set<ll> s;
map<ll,int> m;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    for(int i=0;i<n;i++)
    {
        cin >> a[i];
        ac[i+1]=ac[i]+a[i];
    }

    for(int i=0;i<n;i++)
        for(int j=i;j<n;j++)
            s.insert(ac[j+1]-ac[i]);

    int cont=0;
    for(auto y : s)
    {
        m[y]=cont;
        cont++;
    }

    for(int i=0;i<n;i++)
        for(int j=i;j<n;j++)
            in[m[ac[j+1]-ac[i]]].push_back(pii(j,i));

    for(int i=0;i<cont;i++)
        sort(in[i].begin(),in[i].end());

    vector<pii> res;
    for(int i=0;i<cont;i++)
    {
        vector<pii> x;
        for(auto y : in[i])
            if(!x.size() || x.back().first<y.second)
                x.push_back(y);
        if(x.size()>res.size())
        {
            res.clear();
            for(auto y : x)
                res.push_back(y);
        }
    }

    db(res.size())
    for(auto y : res)
        cout << y.second+1 << ' ' << y.first+1 << '\n';

    return 0;
}