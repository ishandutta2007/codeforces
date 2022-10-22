#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
using namespace std;
typedef long long ll;
#define MAXN 200005

vector<int> g[MAXN],act;
vector<vector<int>> vv;
bool mk[MAXN],mk1[MAXN],a1[MAXN];

int dfs(int u)
{
    mk[u]=1;
    int r=0;
    if(a1[u])
        act.push_back(u);
    for(auto v : g[u])
    {
        if(mk1[v])
        {
            if(mk[v])
                r=1;
            else
                mk[v]=1;
        }
        else if(!mk[v])
            r=max(r,dfs(v));
    }
    return r;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cout.tie();

    int n,m,d,u,v;
    cin >> n >> m >> d;
    for(int i=0;i<m;i++)
    {
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    for(auto y : g[1])
        a1[y]=1;

    queue<int> q;

    mk1[1]=mk[1]=1;
    for(auto y : g[1])
    {
        if(mk[y])
            continue;
        mk[1]=0;
        int x=dfs(y);
        vv.push_back(act);
        act.clear();
    }

    if(vv.size()>d || g[1].size()<d)
    {
        db("NO")
        return 0;
    }
//    for(auto y : vv)
//    {
//        for(auto uu : y)
//            cout << uu << ' ';
//        cout << '\n';
//    }
    db("YES")
    d-=vv.size();
    for(int i=0;i<=n;i++)
        mk[i]=0;
    mk[1]=1;
    for(auto y : vv)
    {
        for(int i=0;i<y.size();i++)
        {
            if(!i)
            {
                cout << 1 << ' ' << y[i] << '\n';
                q.push(y[i]);
                mk[y[i]]=1;
            }
            else if(d)
            {
                d--;
                cout << 1 << ' ' << y[i] << '\n';
                q.push(y[i]);
                mk[y[i]]=1;
            }
        }
    }
//    for(int i=0;i<=n;i++)
//        cout << mk[i] << ' ';
//    cout << '\n';
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