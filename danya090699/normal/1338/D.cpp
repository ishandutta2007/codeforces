#include <bits/stdc++.h>
using namespace std;
const int sz=1e5+10;
vector <int> sv[sz];
int dp[sz][2], an=0;
void dfs(int v, int pr)
{
    int be0=0, be1=0, q=0;
    for(int a=0; a<sv[v].size(); a++)
    {
        int ne=sv[v][a];
        if(ne!=pr)
        {
            dfs(ne, v);
            if(q)
            {
                an=max(an, max(dp[ne][0], dp[ne][1])+be0+int(sv[v].size()-2));
                an=max(an, dp[ne][0]+be1+1);
            }
            be0=max(be0, max(dp[ne][0], dp[ne][1]));
            be1=max(be1, dp[ne][0]);
            q++;
        }
    }
    dp[v][0]=be0+sv[v].size()-1;
    if(v) dp[v][0]--;
    dp[v][1]=be1+1;
}
main()
{
    //freopen("input.txt", "r", stdin);
    int n;
    cin>>n;
    for(int a=0; a<n-1; a++)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        u--, v--;
        sv[u].push_back(v);
        sv[v].push_back(u);
    }
    dfs(0, 0);
    an=max(an, max(dp[0][0], dp[0][1]));
    cout<<an;
}