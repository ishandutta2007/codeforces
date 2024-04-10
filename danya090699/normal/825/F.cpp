//Come on, make Togliatti great again!
#include <bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("input.txt", "r", stdin);
    string s;
    cin>>s;
    int n=s.size(), inf=1e9;
    int dp[n+1];
    dp[0]=0;
    for(int a=1; a<=n; a++) dp[a]=inf;
    for(int a=0; a<n; a++)
    {
        int pf[n];
        pf[a]=0;
        for(int b=a+1; b<n; b++)
        {
            int t=pf[b-1];
            while(t>0)
            {
                if(s[t+a]==s[b]) break;
                else t=pf[t-1+a];
            }
            if(s[t+a]==s[b]) pf[b]=t+1;
            else pf[b]=0;
        }
        for(int b=a+1; b<=n; b++)
        {
            if((b-a)%(b-a-pf[b-1])==0)
            {
                int le=b-a-pf[b-1];
                int q=(b-a)/le;
                if(q>999) q=4;
                else if(q>99) q=3;
                else if(q>9) q=2;
                else q=1;
                dp[b]=min(dp[b], dp[a]+q+le);
            }
            else dp[b]=min(dp[b], dp[a]+(b-a)+1);
        }
    }
    cout<<dp[n];
}