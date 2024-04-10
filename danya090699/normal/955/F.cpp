#include <bits/stdc++.h>
using namespace std;
const int sz=3e5+10, x=5;
vector <int> sv[sz];
int n, k=1, dp[sz], dp2[sz][x+1], dp3[sz][x+1];
long long an=0;
int dfs(int v, int pr)
{
    int re=0;
    dp[v]=1;
    vector <int> sp;
    for(int a=0; a<sv[v].size(); a++)
    {
        int ne=sv[v][a];
        if(ne!=pr)
        {
            re=max(re, dfs(ne, v));
            sp.push_back(dp[ne]);
        }
    }
    if(sp.size()>=k)
    {
        sort(sp.begin(), sp.end(), greater <int>());
        dp[v]=sp[k-1]+1;
    }
    re=max(re, dp[v]);
    an+=re;
    return re;
}
void dfs2(int v, int pr)
{
    dp2[v][1]=n;
    vector <int> sp[x+1];
    for(int a=0; a<sv[v].size(); a++)
    {
        int ne=sv[v][a];
        if(ne!=pr)
        {
            dfs2(ne, v);
            for(int b=1; b<=x; b++) dp3[v][b]=max(dp3[v][b], dp3[ne][b]);
            for(int b=2; b<=x; b++) sp[b].push_back(dp2[ne][b-1]);
        }
    }
    for(int a=2; a<=x; a++)
    {
        sort(sp[a].begin(), sp[a].end(), greater <int>());
        for(int b=0; b<sp[a].size(); b++) if(sp[a][b]>=b+1) dp2[v][a]=max(dp2[v][a], b+1);
    }
    for(int a=1; a<=x; a++) dp3[v][a]=max(dp3[v][a], dp2[v][a]);
    for(int a=1; a<=x; a++)
    {
        int va=max(dp3[v][a], k-1), pr=k-1;
        if(a<x) pr=max(dp3[v][a+1], k-1);
        an+=(va-pr)*a;
    }
}
int main()
{
    //freopen("input.txt", "r", stdin);
    cin>>n;
    for(int a=0; a<n-1; a++)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        u--, v--;
        sv[u].push_back(v);
        sv[v].push_back(u);
    }
    while(1)
    {
        int q=0, va=1;
        for(int a=0; a<=x; a++)
        {
            q+=va, va*=k;
        }
        if(q>n) break;
        dfs(0, -1);
        k++;
    }
    dfs2(0, -1);
    cout<<an;
}