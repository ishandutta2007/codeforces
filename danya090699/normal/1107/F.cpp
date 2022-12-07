#include <bits/stdc++.h>
#define int long long
using namespace std;
struct el
{
    int a, b, k;
};
bool comp(el a, el b){return a.b>b.b;}
main()
{
    //freopen("input.txt", "r", stdin);
    int n;
    cin>>n;
    el ar[n];
    for(int a=0; a<n; a++) cin>>ar[a].a>>ar[a].b>>ar[a].k;
    sort(ar, ar+n, comp);
    int dp[n+1][n+1];
    for(int a=0; a<=n; a++) for(int b=0; b<=n; b++) dp[a][b]=0;
    for(int a=0; a<n; a++)
    {
        for(int b=0; b<=a; b++)
        {
            dp[a+1][b+1]=max(dp[a+1][b+1], dp[a][b]+ar[a].a-ar[a].b*b);
            dp[a+1][b]=max(dp[a+1][b], dp[a][b]+ar[a].a-ar[a].b*ar[a].k);
            dp[a+1][b]=max(dp[a+1][b], dp[a][b]);
        }
    }
    int an=0;
    for(int a=0; a<=n; a++) an=max(an, dp[n][a]);
    cout<<an;
}