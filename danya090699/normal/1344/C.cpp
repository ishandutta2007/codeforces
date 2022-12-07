#include <bits/stdc++.h>
using namespace std;
const int sz=2e5+10;
vector <int> sv[2][sz];
char an[sz];
int us[sz];
void cyc(int v)
{
    us[v]=1;
    for(int a=0; a<sv[0][v].size(); a++)
    {
        int ne=sv[0][v][a];
        if(us[ne]==0) cyc(ne);
        else if(us[ne]==1)
        {
            cout<<-1;
            exit(0);
        }
    }
    us[v]=2;
}
int dp[2][sz];
void dfs(int v, int i)
{
    dp[i][v]=v;
    for(int a=0; a<sv[i][v].size(); a++)
    {
        int ne=sv[i][v][a];
        if(dp[i][ne]==-1) dfs(ne, i);
        dp[i][v]=min(dp[i][v], dp[i][ne]);
    }
}
main()
{
    //freopen("input.txt", "r", stdin);
    int n, m, q=0;
    cin>>n>>m;
    for(int a=0; a<m; a++)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        u--, v--;
        sv[0][u].push_back(v);
        sv[1][v].push_back(u);
    }
    for(int a=0; a<n; a++) if(!us[a]) cyc(a);
    for(int a=0; a<n; a++) dp[0][a]=-1, dp[1][a]=-1;
    for(int a=0; a<n; a++)
    {
        if(dp[0][a]==-1) dfs(a, 0);
        if(dp[1][a]==-1) dfs(a, 1);

        if(dp[0][a]==a and dp[1][a]==a) an[a]='A', q++;
        else an[a]='E';
    }
    cout<<q<<"\n";
    printf("%s", an);
}