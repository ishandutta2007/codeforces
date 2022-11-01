#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tc;
    cin >> tc;
    while(tc--)
    {
        int n,m;
        cin >> n >> m;
        vector<vector<int>> v(n+1);
        for(int i=1;i<=m;i++)
        {
            int a,b;
            cin >> a >> b;
            v[a].push_back(b);
            v[b].push_back(a);
        }
        vector<int> u(n+1,0);
        vector<int> depth(n+1,-1);
        vector<int> cnte(n+1,0);
        vector<int> cnto(n+1,0);
        int even=0;
        array<int,2> one_even={0,0};
        auto dfs=[&](auto &&self,int a)->void
        {
            depth[a]=depth[u[a]]+1;
            for(int to:v[a])
            {
                if(to==u[a]) continue;
                if(depth[to]==-1)
                {
                    u[to]=a;
                    self(self,to);
                    cnte[a]+=cnte[to];
                    cnto[a]+=cnto[to];
                }
                else
                {
                    int t=(depth[a]-depth[to])&1;
                    even+=(t==0&&(depth[a]>depth[to]));
                    if(t==0) one_even={a,to};
                    (t==0?cnte[a]:cnto[a])+=(depth[a]>depth[to]?1:-1);
                }
            }
        };
        dfs(dfs,1);
        int edge=0;
        for(int i=2;i<=n;i++) if(even>0&&cnte[i]==even&&cnto[i]==0) edge=i;
        if(even<=1||edge!=0)
        {
            array<int,2> bad={1,0};
            if(even==1) bad=one_even;
            else if(even>=2) bad={edge,u[edge]};
            vector<int> c(n+1,-1);
            auto col=[&](auto &&self,int a)->void
            {
                for(int to:v[a])
                {
                    if((a==bad[0]&&to==bad[1])||(a==bad[1]&&to==bad[0])) continue;
                    if(c[to]==-1)
                    {
                        c[to]=(c[a]^1);
                        self(self,to);
                    }
                }
            };
            c[bad[0]]=1;
            col(col,bad[0]);
            cout << "YES\n";
            for(int i=1;i<=n;i++) cout << c[i];
            cout << "\n";
        }
        else cout << "NO\n";
    }
    return 0;
}