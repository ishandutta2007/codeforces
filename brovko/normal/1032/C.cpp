#include <iostream>

using namespace std;
int n, a[200000], dp[200000][5], ans[200000], x;
int main()
{
    cin >> n;
    for(int i=0;i<n;i++)
        cin >> a[i];
    for(int i=0;i<5;i++)
        dp[0][i]=-1;
    for(int i=1;i<n;i++)
        for(int j=0;j<5;j++)
        if(dp[i-1][j]!=0)
    {
        if(a[i]>a[i-1])
            for(int k=j+1;k<5;k++)
            dp[i][k]=j+1;
        if(a[i]<a[i-1])
            for(int k=0;k<j;k++)
            dp[i][k]=j+1;
        if(a[i]==a[i-1])
            for(int k=0;k<5;k++)
            if(k!=j)
            dp[i][k]=j+1;
    }
    x=-1;
    for(int i=0;i<5;i++)
        if(dp[n-1][i]!=0)
        x=i;
    if(x==-1)
    {
        cout << -1;
        return 0;
    }
    x++;
    ans[n-1]=x;
    for(int i=n-2;i>=0;i--)
    {
        ans[i]=dp[i+1][ans[i+1]-1];
    }
    for(int i=0;i<n;i++)
        cout << ans[i] << ' ';
    return 0;
}