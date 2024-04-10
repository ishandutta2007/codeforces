#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pii;
typedef pair<double,ll> pdi;
typedef pair<string,ll> psi;
typedef pair<ll,string> pls;
typedef pair<ll,pii> pip;
typedef pair<pii,pii> ppp;
#define MAXN 500005

vector<int> g[MAXN];
map<vector<int>,ll> ma;
ll c[MAXN];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while(t--)
    {
        ll n,m;
        cin >> n >> m;
        ma.clear();
        for(int i=0;i<n;i++)
        {
            cin >> c[i];
            g[i].clear();
        }
        for(int i=0;i<m;i++)
        {
            int u,v;
            cin >> u >> v;
            u--,v--;
            g[v].push_back(u);
        }

        for(int i=0;i<n;i++)
        {
            sort(g[i].begin(),g[i].end());
            if(g[i].size())
                ma[g[i]]+=c[i];
        }

        ll res=0;
        for(auto y : ma)
            res=__gcd(res,y.second);
        db(res)
    }

    return 0;
}