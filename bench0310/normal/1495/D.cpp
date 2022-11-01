#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m;
    cin >> n >> m;
    vector<int> v[n+1];
    for(int i=1;i<=m;i++)
    {
        int a,b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    const ll mod=998244353;
    vector res(n+1,vector(n+1,ll(0)));
    for(int x=1;x<=n;x++)
    {
        for(int y=x;y<=n;y++)
        {
            vector<int> dx(n+1,-1);
            vector<int> dy(n+1,-1);
            vector<int> py(n+1,-1);
            auto go=[&](int src,vector<int> &d,vector<int> &p)
            {
                vector<int> q={src};
                d[src]=0;
                int idx=0;
                while(idx<(int)q.size())
                {
                    int a=q[idx++];
                    for(int to:v[a])
                    {
                        if(d[to]==-1)
                        {
                            d[to]=d[a]+1;
                            p[to]=a;
                            q.push_back(to);
                        }
                    }
                }
            };
            go(x,dx,py);
            go(y,dy,py);
            vector<bool> on_path(n+1,0);
            int z=x;
            while(z!=y)
            {
                on_path[z]=1;
                z=py[z];
            }
            on_path[y]=1;
            ll r=1;
            for(int i=1;i<=n;i++)
            {
                if(on_path[i]) continue;
                int c=0;
                for(int from:v[i]) c+=(dx[from]+1==dx[i]&&dy[from]+1==dy[i]);
                r=(r*c)%mod;
            }
            res[x][y]=res[y][x]=r;
        }
    }
    for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) cout << res[i][j] << " \n"[j==n];
    return 0;
}