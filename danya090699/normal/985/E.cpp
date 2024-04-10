#include <bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("input.txt", "r", stdin);
    int n, k, d;
    cin>>n>>k>>d;
    int ar[n];
    for(int a=0; a<n; a++) scanf("%d", &ar[a]);
    sort(ar, ar+n);
    int dp[n+1], sdp[n+1];
    dp[0]=1, sdp[0]=1;
    for(int a=0; a<n; a++)
    {
        int l=lower_bound(ar, ar+n, ar[a]-d)-ar;
        int r=a-k+1;
        if(l<=r)
        {
            int su=sdp[r];
            if(l!=0) su-=sdp[l-1];
            if(su) dp[a+1]=1;
            else dp[a+1]=0;
        }
        else dp[a+1]=0;
        sdp[a+1]=sdp[a]+dp[a+1];
    }
    if(dp[n]) cout<<"YES";
    else cout<<"NO";
}