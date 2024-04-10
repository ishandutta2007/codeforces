#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int N=100005;
vector<int> v[N];
vector<int> p(N,0);
vector<int> sz(N,0);
vector<bool> vis(N,0);

void dfs(int a)
{
    sz[a]=1;
    for(int to:v[a])
    {
        if(to==p[a]) continue;
        p[to]=a;
        dfs(to);
        sz[a]+=sz[to];
    }
}

void go(int a,int x)
{
    vis[a]=1;
    for(int to:v[a])
    {
        if(to==x) continue;
        go(to,a);
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
        int n;
        cin >> n;
        for(int i=0;i<n-1;i++)
        {
            int a,b;
            cin >> a >> b;
            v[a].push_back(b);
            v[b].push_back(a);
        }
        if(n&1)
        {
            cout << "1 " << v[1][0] << "\n";
            cout << "1 " << v[1][0] << "\n";
        }
        else
        {
            dfs(1);
            int a=0;
            for(int i=1;i<=n;i++) if(sz[i]==n/2) a=i;
            if(a==0)
            {
                cout << "1 " << v[1][0] << "\n";
                cout << "1 " << v[1][0] << "\n";
            }
            else
            {
                go(a,p[a]);
                int b=0;
                for(int i=1;i<=n;i++) if(v[i].size()==1&&vis[i]==1) b=i;
                cout << b << " " << v[b][0] << "\n";
                cout << p[a] << " " << b << "\n";
            }
        }
        for(int i=1;i<=n;i++)
        {
            v[i].clear();
            p[i]=sz[i]=vis[i]=0;
        }
    }
    return 0;
}