#include <bits/stdc++.h>
using namespace std;
const int sz=2e3+10;
vector <int> sv[sz];
int mi[sz], si[sz], q[sz], go[sz][sz];
bool comp(int a, int b){return mi[a]<mi[b];}
void dfs(int v)
{
    si[v]=1;
    for(int a=0; a<sv[v].size(); a++)
    {
        int ne=sv[v][a];
        dfs(ne), mi[v]=mi[ne], si[v]+=si[ne], q[v]+=q[ne];
    }
    sort(sv[v].begin(), sv[v].end(), comp);
}
void dfs2(int v, int l, int r)
{
    if(v) go[l][r]=max(go[l][r], si[v]);
    for(int a=0; a<sv[v].size(); a++)
    {
        int ne=sv[v][a];
        dfs2(ne, l, l+q[ne]), l+=q[ne];
    }
}
main()
{
    //freopen("input.txt", "r", stdin);
    int n;
    cin>>n;
    for(int i=0; i<2; i++)
    {
        int m;
        cin>>m;
        for(int a=1; a<m; a++)
        {
            int pr;
            cin>>pr;
            pr--, sv[pr].push_back(a);
        }
        for(int a=0; a<n; a++)
        {
            int v;
            cin>>v;
            v--, mi[v]=a, q[v]=1;
        }
        dfs(0);
        dfs2(0, 0, n);

        for(int a=0; a<m; a++) sv[a].clear(), q[a]=0, mi[a]=0, si[a]=0;
    }
    int dp[n+1];
    for(int a=0; a<=n; a++) dp[a]=0;
    for(int a=0; a<n; a++)
    {
        for(int b=a+1; b<=n; b++) dp[b]=max(dp[b], dp[a]+go[a][b]);
    }
    cout<<dp[n];
}