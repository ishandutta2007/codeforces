#include <bits/stdc++.h>
using namespace std;
const int sz=5010;
int main()
{
    //freopen("input.txt", "r", stdin);
    int n;
    cin>>n;
    int ar[n], fi[sz], la[sz];
    for(int a=0; a<sz; a++) fi[a]=-1;
    for(int a=0; a<n; a++)
    {
        cin>>ar[a];
        if(fi[ar[a]]==-1) fi[ar[a]]=a;
        la[ar[a]]=a;
    }
    int dp[n+1];
    for(int a=0; a<=n; a++) dp[a]=0;
    for(int a=0; a<n; a++)
    {
        dp[a+1]=max(dp[a+1], dp[a]);
        int add=0, en=a;
        for(int b=a+1; b<=n; b++)
        {
            int cu=ar[b-1];
            if(fi[cu]<a) break;
            if(fi[cu]==b-1) add=(add^cu);
            en=max(en, la[cu]+1);
            if(b==en) dp[b]=max(dp[b], dp[a]+add);
        }
    }
    cout<<dp[n];
}