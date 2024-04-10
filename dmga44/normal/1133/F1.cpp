#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define MAXN 200005

int c[MAXN];
vector<int> g[MAXN];
bool mk[MAXN];

int main()
{
    ios_base::sync_with_stdio(0);
    cout.tie();

    int n,m,u,v;
    cin >> n >> m;
    pii r=pii(-1,0);
    for(int i=0;i<m;i++)
    {
        cin >> u >> v;
        c[u]++,c[v]++;
        g[u].push_back(v);
        g[v].push_back(u);
        r=max(r,max(pii(c[u],u),pii(c[v],v)));
    }
    int s=r.second;
    mk[s]=1;
    queue<int> q;
    for(auto y : g[s])
    {
        cout << y << ' ' << s << '\n';
        q.push(y);
        mk[y]=1;
    }

    while(!q.empty())
    {
        u=q.front();
        q.pop();
        for(auto y : g[u])
            if(!mk[y])
            {
                cout << u << ' ' << y << '\n';
                mk[y]=1;
                q.push(y);
            }
    }

    return 0;
}