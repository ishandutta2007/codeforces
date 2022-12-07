#include <bits/stdc++.h>
using namespace std;
const int inf=1e9;
int main()
{
    //freopen("input.txt", "r", stdin);
    int t;
    cin>>t;
    for(int i=0; i<t; i++)
    {
        int n, m, k, q[26], an=inf;
        scanf("%d%d%d", &n, &m, &k);
        char s[k+1];
        scanf("%s", s);
        for(int a=0; a<26; a++) q[a]=0;
        for(int a=0; a<k; a++) q[s[a]-'A']++;
        for(int a=0; a<26; a++)
        {
            int dp[n+1], dp2[n+1];
            for(int a=0; a<=n; a++) dp[a]=inf, dp2[a]=inf;
            dp[0]=0;
            for(int b=0; b<26; b++)
            {
                for(int c=0; c<=n; c++)
                {
                    dp2[c]=min(dp2[c], dp[c]);
                    if(b!=a) dp2[min(c+q[b], n)]=min(dp2[min(c+q[b], n)], dp[c]+q[b]);
                }
                for(int c=0; c<=n; c++) dp[c]=dp2[c], dp2[c]=inf;
            }
            for(int b=0; b<=n; b++)
            {
                int c=k-dp[b]-q[a];
                if(b+q[a]>=n and c+q[a]>=m) an=min(an, (n-b)*max(m-c, 0));
            }
        }
        printf("%d\n", an);
    }
}