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
#define MAXN 200005

vector<int> g[MAXN],ig[MAXN];
int level[MAXN];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n,m,u,v;
    cin >> n >> m;
    for(int i=0;i<m;i++)
    {
        cin >>u >> v;
        u--,v--;
        g[u].push_back(v);
        ig[v].push_back(u);
    }

    int k;
    cin >> k;
    vector<int> path(k);
    for(int i=0;i<k;i++)
    {
        cin >> path[i];
        path[i]--;
    }

    int s=path[0];
    int t=path[k-1];
    level[t]=1;
    queue<int> q;
    for(q.push(t);!q.empty();q.pop())
    {
        int u=q.front();

        for(auto y : ig[u])
            if(!level[y])
            {
                level[y]=level[u]+1;
                q.push(y);
            }
    }

    ll r1=0,r2=0;
    for(int i=0;i<k-1;i++)
    {
//        cout << r1 << ' ' << r2 << '\n';
        int avs=0;
        for(auto y : g[path[i]])
            if(level[y]==level[path[i]]-1)
                avs++;

        bool ok=(level[path[i+1]]==(level[path[i]]-1));
        if(!ok || avs>1)
            r2++;
        if(!ok)
            r1++;
    }
    cout << r1 << ' ' << r2 << '\n';

    return 0;
}