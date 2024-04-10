#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N=100000+7;
int n, m, sol, col[N];
vector<pair<int, int>> g[N];
vector<int> nodes, c[2];
bool good;

void dfs(int a)
{
        c[col[a]].push_back(a);
        for (auto &it:g[a])
        {
                int b=it.first, colb=col[a]^it.second;
                if (col[b]==-1)
                {
                        col[b]=colb;
                        dfs(b);
                }
                else
                        good&=(col[b]==colb);
        }
}

int main()
{
        ios::sync_with_stdio(0); cin.tie(0);

        cin>>n>>m;
        for (int i=1; i<=m; i++)
        {
                int x, y;
                string s;
                cin>>x>>y>>s;
                g[x].push_back({y, (s=="B")});
                g[y].push_back({x, (s=="B")});
        }

        vector<int> sol;
        int cnt=0;
        for (int w=0;w<2;w++)
        {
                vector<int> no;
                for (int i=1;i<=n;i++)
                        col[i]=-1;

                good=1;
                for (int i=1; i<=n; i++)
                {
                        if (col[i]!=-1)
                                continue;
                        c[0].clear();
                        c[1].clear();
                        col[i]=0;
                        dfs(i);
                        if ((int) c[0].size()<(int) c[1].size())
                                for (auto &x:c[0])
                                        no.push_back(x);
                        else
                                for (auto &x:c[1])
                                        no.push_back(x);
                }
                for (int i=1;i<=n;i++)
                        for (auto &it:g[i])
                                it.second^=1;
                if (!good)
                        continue;
                if (!cnt++ || (int) no.size()<(int) sol.size())
                        sol=no;
        }
        if (!cnt)
        {
                cout<<"-1\n";
                return 0;
        }

        cout<<(int) sol.size()<<"\n";
        for (auto &x:sol)
                cout<<x<<" ";
        cout<<"\n";
}