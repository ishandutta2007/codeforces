#include <bits/stdc++.h>
using namespace std;
const int sz=3e5+10;
vector <int> sv[sz];
string s;
int us[sz], fo=0, dp[sz][26];
void dfs(int v)
{
    if(us[v]==1) fo=1;
    else
    {
        us[v]=1;
        for(int a=0; a<sv[v].size(); a++)
        {
            int ne=sv[v][a];
            if(us[ne]!=2) dfs(ne);
        }
        us[v]=2;
    }
}
void lazy(int v)
{
    if(us[v]==2)
    {
        for(int a=0; a<sv[v].size(); a++)
        {
            int ne=sv[v][a];
            lazy(ne);
            for(int b=0; b<26; b++) dp[v][b]=max(dp[v][b], dp[ne][b]);
        }
        dp[v][s[v]-'a']++;
        us[v]=0;
    }
}
int main()
{
    //freopen("input.txt", "r", stdin);
    int n, m;
    cin>>n>>m>>s;
    for(int a=0; a<m; a++)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        u--, v--;
        sv[u].push_back(v);
    }
    for(int a=0; a<n; a++) if(us[a]==0) dfs(a);
    if(fo) cout<<-1;
    else
    {
        int an=0;
        for(int a=0; a<n; a++)
        {
            lazy(a);
            for(int b=0; b<26; b++) an=max(an, dp[a][b]);
        }
        cout<<an;
    }
}