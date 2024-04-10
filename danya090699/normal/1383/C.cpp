#include <bits/stdc++.h>
using namespace std;
bool sm[20][20], us[20];
void dfs(int v)
{
    us[v]=1;
    for(int a=0; a<20; a++)
    {
        if(sm[v][a] and !us[a]) dfs(a);
    }
}
main()
{
    //freopen("input.txt", "r", stdin);
    int T;
    cin>>T;
    while(T--)
    {
        int n, to[20];
        string s, t;
        cin>>n>>s>>t;
        for(int a=0; a<20; a++)
        {
            us[a]=0, to[a]=0;
            for(int b=0; b<20; b++) sm[a][b]=0;
        }
        for(int a=0; a<n; a++)
        {
            int u=s[a]-'a', v=t[a]-'a';
            if(u!=v)
            {
                to[u]|=(1<<v);
                sm[u][v]=1, sm[v][u]=1;
            }
        }
        int cq=0, cli=0;
        for(int a=0; a<20; a++)
        {
            if(!us[a]) dfs(a), cq++;
        }
        bool dp[1<<20];
        dp[0]=1;
        for(int mask=1; mask<(1<<20); mask++)
        {
            dp[mask]=0;
            for(int v=0; v<20; v++)
            {
                if((1<<v)&mask and dp[mask-(1<<v)] and (to[v]&mask)==0) dp[mask]=1;
            }
            if(dp[mask]) cli=max(cli, __builtin_popcount(mask));
        }
        cout<<40-cq-cli<<"\n";
    }
}