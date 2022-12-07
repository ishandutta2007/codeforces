#include <bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("input.txt", "r", stdin);
    int n;
    cin>>n;
    int ar[n+1], p[n+1];
    for(int a=0; a<n; a++)
    {
        int x;
        scanf("%d", &x);
        p[x]=a, ar[a]=x;
    }
    bool dp[n+1];
    for(int a=n; a>0; a--)
    {
        int i=p[a];
        dp[i]=0;
        for(int b=a; b<=n; b+=a)
        {
            if(i-b>=0)
            {
                if(ar[i-b]>a and dp[i-b]==0) dp[i]=1;
            }
            if(i+b<n)
            {
                if(ar[i+b]>a and dp[i+b]==0) dp[i]=1;
            }
        }
    }
    for(int a=0; a<n; a++)
    {
        if(dp[a]) cout<<"A";
        else cout<<"B";
    }
}