#include <bits/stdc++.h>
#define int long long
using namespace std;
const int n=1000;
main()
{
    //freopen("input.txt", "r", stdin);
    int w;
    cin>>w;
    int dp[10][n];
    for(int a=1; a<=9; a++) for(int b=0; b<n; b++) dp[a][b]=-1;
    dp[1][0]=0;
    for(int a=1; a<=8; a++)
    {
        int q;
        cin>>q;
        for(int b=0; b<n; b++)
        {
            if(dp[a][b]!=-1)
            {
                int ma=min(q, (w-dp[a][b])/a);
                for(int c=ma; c>=max(ma-n, 0ll); c--)
                {
                    int nb=(b+c*a)%n, nva=dp[a][b]+c*a;
                    dp[a+1][nb]=max(dp[a+1][nb], nva);
                }
            }
        }
    }
    int an=0;
    for(int a=0; a<n; a++) an=max(an, dp[9][a]);
    cout<<an;
}