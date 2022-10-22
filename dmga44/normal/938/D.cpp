#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pii;
#define MAXN 200005

vector<pii> g[MAXN];
ll d[MAXN];
bool mk[MAXN];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll n,m,u,v,w;
    cin >> n >> m;
    for(int i=0;i<m;i++)
    {
        cin >> u >> v >> w;
        u--,v--;
        g[u].push_back(pii(v,w));
        g[v].push_back(pii(u,w));
    }

    for(int i=0;i<n;i++)
        cin >> d[i];

    priority_queue<pii,vector<pii>,greater<pii>> pq;
    for(int i=0;i<n;i++)
        pq.push(pii(d[i],i));

    while(!pq.empty())
    {
        u=pq.top().second;
        w=pq.top().first;
        pq.pop();

        if(mk[u])
            continue;
        mk[u]=1;
        d[u]=w;
        for(auto y : g[u])
        {
            v=y.first;
            ll w0=y.second;
            pq.push(pii(2*w0+w,v));
        }
    }

    for(int i=0;i<n;i++)
        cout << d[i] << ' ';

    return 0;
}