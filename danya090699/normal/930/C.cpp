#include <bits/stdc++.h>
using namespace std;
const int inf=1e9;
int main()
{
    //freopen("input.txt", "r", stdin);
    int n, m, an=0;
    cin>>n>>m;
    int add[m+1];
    for(int a=0; a<=m; a++) add[a]=0;
    for(int a=0; a<n; a++)
    {
        int l, r;
        cin>>l>>r;
        add[l-1]++, add[r]--;
    }
    int va[m], cu=0;
    for(int a=0; a<m; a++)
    {
        cu+=add[a];
        va[a]=cu;
    }
    int dp[m+1], le[m];
    dp[0]=0;
    for(int a=1; a<=m; a++) dp[a]=inf;
    for(int a=0; a<m; a++)
    {
        int p=upper_bound(dp, dp+m+1, va[a])-dp;
        dp[p]=va[a];
        le[a]=p;
    }
    dp[0]=0;
    for(int a=1; a<=m; a++) dp[a]=inf;
    for(int a=m-1; a>=0; a--)
    {
        int p=upper_bound(dp, dp+m+1, va[a])-dp;
        dp[p]=va[a];
        an=max(an, le[a]+p-1);
    }
    cout<<an;
}