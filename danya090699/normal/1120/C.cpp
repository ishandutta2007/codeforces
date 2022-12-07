#include <bits/stdc++.h>
using namespace std;
const int inf=1e9;
main()
{
    //freopen("input.txt", "r", stdin);
    int n, A, B;
    cin>>n>>A>>B;
    string s;
    cin>>s;
    int go[n], dp[n+1];
    dp[0]=0;
    for(int a=0; a<n; a++) go[a]=0, dp[a+1]=inf;
    for(int a=0; a<n; a++)
    {
        int zf[n], l=0, r=-1;
        zf[a]=0;
        for(int b=a+1; b<n; b++)
        {
            zf[b]=0;
            if(r>=b) zf[b]=min(zf[a+b-l], r-b+1);
            while(b+zf[b]<n)
            {
                if(s[a+zf[b]]==s[b+zf[b]]) zf[b]++;
                else break;
            }
            if(b+zf[b]-1>r) l=b, r=b+zf[b]-1;

            go[b]=max(go[b], min(zf[b], b-a));
        }
    }
    for(int a=0; a<n; a++)
    {
        dp[a+1]=min(dp[a+1], dp[a]+A);
        for(int b=1; b<=go[a]; b++) dp[a+b]=min(dp[a+b], dp[a]+B);
    }
    cout<<dp[n];
}