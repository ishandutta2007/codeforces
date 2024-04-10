#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
#define all(v) (v).begin(),(v).end()
#define allr(v) (v).rbegin(),(v).rend()
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pii;
typedef pair<double,ll> pdi;
typedef pair<string,ll> psi;
typedef pair<ll,string> pls;
typedef pair<ll,pii> pip;
typedef pair<pii,pii> ppp;
#define MAXN 10005
#define MAXG 1005

ll g,r;
bool mk[MAXN][MAXG];
vector<pii> gg[MAXN];
int d[MAXN];

void solve()
{
    queue<int> q;
    mk[0][0]=1;
    mk[0][g]=1;
    q.push(0);
    d[0]=0;

    while(!q.empty())
    {
        int u=q.front();
        q.pop();

        queue<pii> q2;
        q2.push(pii(u,0));
        while(!q2.empty())
        {
            int v=q2.front().first;
            int w=q2.front().second;
            q2.pop();

            for(auto y : gg[v])
            {
                int vv=y.first;
                int w0=w+y.second;
                if(w0<g && !mk[vv][w0])
                {
                    mk[vv][w0]=1;
                    q2.push(pii(vv,w0));
                }
                else if(w0==g && !mk[vv][g])
                {
                    mk[vv][g]=1;
                    mk[vv][0]=1;
                    q.push(vv);
                    d[vv]=d[u]+1;
                }
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n,m;
    cin >> n >> m;
    vector<int> v(m);
    for(int i=0;i<m;i++)
        cin >> v[i];
    sort(all(v));
    cin >> g >> r;
    for(int i=1;i<m;i++)
    {
        gg[i-1].push_back(pii(i,v[i]-v[i-1]));
        gg[i].push_back(pii(i-1,v[i]-v[i-1]));
    }

    solve();

    ll res=1e18;
    for(int i=0;i<m;i++)
        if(v[m-1]-v[i]<=g && mk[i][0])
            res=min(res,v[m-1]-v[i]+(g+r)*d[i]);
    if(res!=1e18)
        db(res)
    else
        db(-1)

    return 0;
}