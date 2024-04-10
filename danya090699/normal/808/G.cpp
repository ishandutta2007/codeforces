#include <bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("input.txt", "r", stdin);
    string s, t;
    cin>>s>>t;
    int n=s.size(), m=t.size();
    int f[m];
    f[0]=0;
    for(int a=1; a<m; a++)
    {
        int pr=f[a-1];
        while(pr>0)
        {
            if(t[a]==t[pr]) break;
            else pr=f[pr-1];
        }
        if(t[a]==t[pr]) f[a]=pr+1;
        else f[a]=0;
    }
    int go[m+1][26];
    for(int a=0; a<26; a++)
    {
        if('a'+a==t[0]) go[0][a]=1;
        else go[0][a]=0;
    }
    for(int a=1; a<=m; a++)
    {
        for(int b=0; b<26; b++)
        {
            if(a==m or t[a]!='a'+b)
            {
                go[a][b]=go[f[a-1]][b];
            }
            else go[a][b]=a+1;
        }
    }
    int dp[n+1][m+1];
    for(int a=0; a<=n; a++) for(int b=0; b<=m; b++) dp[a][b]=-1;
    dp[0][0]=0;
    for(int a=0; a<n; a++)
    {
        for(int b=0; b<=m; b++)
        {
            if(dp[a][b]!=-1)
            {
                int st=0, en=25;
                if(s[a]!='?')
                {
                    st=s[a]-'a', en=s[a]-'a';
                }
                for(st; st<=en; st++)
                {
                    int ne=go[b][st];
                    if(ne==m) dp[a+1][ne]=max(dp[a+1][ne], dp[a][b]+1);
                    else dp[a+1][ne]=max(dp[a+1][ne], dp[a][b]);
                }
            }
        }
    }
    int an=0;
    for(int a=0; a<=m; a++) an=max(an, dp[n][a]);
    cout<<an;
}