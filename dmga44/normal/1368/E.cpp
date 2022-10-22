#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
#define all(v) (v).begin(),(v).end()
#define allr(v) (v).rbegin(),(v).rend()
#define f first
#define s second
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<ll,ll> pii;
typedef pair<double,ll> pdi;
typedef pair<ld,ld> pdd;
typedef pair<double,ll> pdi;
typedef pair<double,pii> pdp;
typedef pair<string,ll> psi;
typedef pair<ll,string> pls;
typedef pair<string,string> pss;
typedef pair<ll,pii> pip;
typedef pair<pii,pii> ppp;
typedef complex<ld> point;
#define mod (ll)(1e9+7)
#define eps (1e-9)
#define oo (ll)(0x3f3f3f3f)
#define pi acos(-1)
#define MAXN (ll)(2e5+5)

vector<int> g[MAXN];
bool b[MAXN];
bool mm[MAXN];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--)
    {
        int n,m,u,v;
        cin >> n >> m;
        for(int i=0;i<n;i++)
        {
            g[i].clear();
            b[i]=0;
            mm[i]=0;
        }

        vector<pii> edges;
        for(int i=0;i<m;i++)
        {
            cin >> u >> v;
            u--,v--;
            g[u].push_back(v);
            edges.push_back(pii(v,u));
        }

        sort(all(edges));

        for(int i=0;i<m;i++)
        {
            u=edges[i].s;
            v=edges[i].f;
            if(!mm[u] && !b[u] && !mm[v])
            {
                b[v]=1;
                for(auto y : g[v])
                    mm[y]=1;
            }
        }

        vector<int> res;
        for(int i=0;i<n;i++)
            if(mm[i])
                res.push_back(i+1);
        db(res.size())
        for(auto y : res)
            cout << y << ' ';
        cout << '\n';
    }

    return 0;
}
/**
2
4 6
1 2
1 3
2 3
2 4
3 4
3 4
7 6
1 2
1 3
2 4
2 5
3 6
3 7
**/