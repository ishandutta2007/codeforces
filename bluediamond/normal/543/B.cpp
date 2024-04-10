#include <bits/stdc++.h>

using namespace std;


const int N=3000+7;
int n, m, s1, t1, l1, s2, t2, l2, d[N][N];
vector<int> g[N];

int main()
{
        ios::sync_with_stdio(0); cin.tie(0);

      ///  freopen ("input", "r", stdin);

        cin>>n>>m;
        for (int i=1; i<=m; i++)
        {
                int a, b;
                cin>>a>>b;
                g[a].push_back(b);
                g[b].push_back(a);
        }


        cin>>s1>>t1>>l1>>s2>>t2>>l2;

        for (int root=1; root<=n; root++)
        {
                for (int i=1; i<=n; i++)
                        d[root][i]=-1;
                d[root][root]=0;
                queue<int> q;
                q.push(root);
                while (!q.empty())
                {
                        int a=q.front();
                        q.pop();
                        for (auto &b : g[a])
                        {
                                if (d[root][b]==-1)
                                {
                                        d[root][b]=1+d[root][a];
                                        q.push(b);
                                }
                        }
                }
        }

        int sol=(int) 1e9;

        for (int it=1; it<=2; it++)
        {
                for (int x=1; x<=n; x++)
                {
                        for (int y=1; y<=n; y++)
                        {
                                int d1=d[s1][x]+d[x][y]+d[y][t1];
                                int d2=d[s2][x]+d[x][y]+d[y][t2];
                                if (d1<=l1 && d2<=l2)
                                {
                                        sol=min(sol, d1+d2-d[x][y]);
                                }
                        }
                }
                swap(s2, t2);
        }
        /// or 0 com
        if (d[s1][t1]<=l1 && d[s2][t2]<=l2)
                sol=min(sol, d[s1][t1]+d[s2][t2]);
        if (sol==(int) 1e9)
                sol=-1;
        else
                sol=m-sol;
        cout<<sol<<"\n";

        return 0;
}