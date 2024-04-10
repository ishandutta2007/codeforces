#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int N=100005;
vector<int> v[N];
vector<unordered_set<int>> s(N);
vector<int> g[N];

vector<int> go(int n,int k,bool c=0)
{
    vector<int> d(n+1,0);
    vector<bool> vis(n+1,0);
    queue<int> q;
    for(int i=1;i<=n;i++)
    {
        d[i]=v[i].size();
        if(d[i]<k) q.push(i);
    }
    while(!q.empty())
    {
        int a=q.front();
        vis[a]=1;
        q.pop();
        for(int to:v[a])
        {
            d[to]--;
            if(d[to]==k-1) q.push(to);
        }
    }
    vector<int> x;
    for(int i=1;i<=n;i++)
    {
        if(vis[i]==0)
        {
            x.push_back(i);
            if(c) for(int to:v[i]) if(vis[to]==0) g[i].push_back(to);
        }
    }
    return x;
}

void clean(int n)
{
    for(int i=1;i<=n;i++)
    {
        v[i].clear();
        s[i].clear();
        g[i].clear();
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        int n,m,k;
        cin >> n >> m >> k;
        for(int i=1;i<=m;i++)
        {
            int a,b;
            cin >> a >> b;
            v[a].push_back(b);
            v[b].push_back(a);
            s[a].insert(b);
            s[b].insert(a);
        }
        if((ll)m<((ll)k*(k-1)/2))
        {
            cout << "-1\n";
            clean(n);
            continue;
        }
        vector<int> res=go(n,k);
        if(!res.empty())
        {
            cout << "1 " << res.size() << "\n";
            for(int a:res) cout << a << " ";
            cout << "\n";
            clean(n);
            continue;
        }
        bool f=0;
        res=go(n,k-1,1);
        queue<int> q;
        vector<int> deg(n+1,0);
        for(int a:res)
        {
            deg[a]=g[a].size();
            if(deg[a]==k-1) q.push(a);
        }
        vector<bool> vis(n+1,0);
        while(!q.empty())
        {
            int a=q.front();
            q.pop();
            vis[a]=1;
            vector<int> adj;
            for(int to:g[a]) if(vis[to]==0) adj.push_back(to);
            if((int)adj.size()==k-1)
            {
                bool ok=1;
                for(int i=0;i<k-1;i++)
                {
                    for(int j=i+1;j<k-1;j++)
                    {
                        if(s[adj[i]].find(adj[j])==s[adj[i]].end())
                        {
                            ok=0;
                            break;
                        }
                    }
                    if(ok==0) break;
                }
                if(ok)
                {
                    f=1;
                    cout << "2\n";
                    cout << a << " ";
                    for(int x:adj) cout << x << " ";
                    cout << "\n";
                    break;
                }
            }
            for(int to:g[a])
            {
                deg[to]--;
                if(deg[to]==k-1) q.push(to);
            }
        }
        if(f==0) cout << "-1\n";
        clean(n);
    }
    return 0;
}