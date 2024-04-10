#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int N=500005;
vector<int> v[N];
vector<int> depth(N,0);
vector<int> p(N,0);

void dfs(int a)
{
    depth[a]=depth[p[a]]+1;
    for(int to:v[a])
    {
        if(depth[to]!=0) continue;
        p[to]=a;
        dfs(to);
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
        int n,m;
        cin >> n >> m;
        for(int i=0;i<m;i++)
        {
            int a,b;
            cin >> a >> b;
            v[a].push_back(b);
            v[b].push_back(a);
        }
        dfs(1);
        int x=1;
        for(int i=1;i<=n;i++) if(depth[i]>depth[x]) x=i;
        if(depth[x]>=(n+1)/2)
        {
            cout << "PATH\n";
            cout << depth[x] << "\n";
            cout << x;
            while(x!=1) cout << " " << (x=p[x]);
            cout << "\n";
        }
        else
        {
            vector<int> z(n+1,0);
            vector<array<int,2>> res;
            for(int i=1;i<=n;i++)
            {
                if(z[depth[i]]==0) z[depth[i]]=i;
                else
                {
                    res.push_back({z[depth[i]],i});
                    z[depth[i]]=0;
                }
            }
            cout << "PAIRING\n";
            cout << res.size() << "\n";
            for(auto [a,b]:res) cout << a << " " << b << "\n";
        }
        for(int i=1;i<=n;i++)
        {
            v[i].clear();
            depth[i]=p[i]=0;
        }
    }
    return 0;
}