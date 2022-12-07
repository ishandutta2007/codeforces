#include <bits/stdc++.h>
using namespace std;
const int sz=2e5+10;
bool sm[10][10][10][10], bad[10][10];
int k, c[10], an=0;
void dfs(int l)
{
    if(l>k)
    {
        int ok=1;
        for(int a=1; a<=k; a++)
        {
            if(bad[a][c[a]])
            {
                ok=0;
                break;
            }
            for(int b=a+1; b<=k; b++)
            {
                if(sm[a][c[a]][b][c[b]])
                {
                    ok=0;
                    break;
                }
            }
            if(!ok) break;
        }
        an+=ok;
    }
    else
    {
        for(int a=1; a<=l; a++)
        {
            c[l]=a, dfs(l+1);
        }
    }
}
main()
{
    //freopen("input.txt", "r", stdin);
    int n, m;
    cin>>n>>m>>k;
    bitset <sz> in[k+1][k+1];
    vector <pair <int, int> > sv[n];
    for(int a=0; a<m; a++)
    {
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);
        u--, v--;
        sv[u].push_back({w, v});
    }
    for(int a=0; a<n; a++)
    {
        sort(sv[a].begin(), sv[a].end());
        for(int b=0; b<sv[a].size(); b++)
        {
            int to=sv[a][b].second;

            if(in[sv[a].size()][b+1][to]) bad[sv[a].size()][b+1]=1;
            else in[sv[a].size()][b+1][to]=1;
        }
    }
    for(int a=1; a<=k; a++)
    {
        for(int i=1; i<=a; i++)
        {
            for(int b=a+1; b<=k; b++)
            {
                for(int j=1; j<=b; j++)
                {
                    if((in[a][i]&in[b][j]).count()) sm[a][i][b][j]=1;
                }
            }
        }
    }
    dfs(1);
    cout<<an;
}