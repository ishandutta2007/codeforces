#include <bits/stdc++.h>

using namespace std;

int main()
{
    const int inf=1000000000;
    int n,d;
    scanf("%d%d",&n,&d);
    char s[n+1];
    scanf("%s",s);
    vector<int> dp(n,inf);
    dp[0]=0;
    for(int o=1;o<n;o++)
    {
        if(s[o]=='0') continue;
        for(int i=max(0,o-d);i<o;i++)
        {
            if(s[i]=='1') dp[o]=min(dp[o],dp[i]+1);
        }
    }
    if(dp[n-1]!=inf) printf("%d\n",dp[n-1]);
    else printf("-1\n");
    return 0;
}