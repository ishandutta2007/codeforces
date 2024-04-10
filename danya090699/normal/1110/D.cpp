#include <bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("input.txt", "r", stdin);
    int n, m;
    cin>>n>>m;
    int q[m];
    for(int a=0; a<m; a++) q[a]=0;
    for(int a=0; a<n; a++)
    {
        int x;
        scanf("%d", &x);
        x--, q[x]++;
    }
    int dp[3][5], dp2[3][5];
    for(int a=0; a<=2; a++) for(int b=0; b<=4; b++) dp[a][b]=-1, dp2[a][b]=-1;
    dp[0][0]=0;
    for(int a=0; a<m; a++)
    {
        for(int b=0; b<=2; b++)
        {
            for(int c=0; c<=4; c++)
            {
                if(dp[b][c]!=-1)
                {
                    for(int d=0; d<=min(b, c); d++)
                    {
                        for(int le=q[a]%3; le<=q[a]; le+=3)
                        {
                            if(le>=d) dp2[min(c-d, 2)][min(le-d, 4)]=max(dp2[min(c-d, 2)][min(le-d, 4)], dp[b][c]+d+(q[a]-le)/3);
                            if(le>=6) break;
                        }
                    }
                }
            }
        }
        for(int b=0; b<=2; b++) for(int c=0; c<=4; c++) dp[b][c]=dp2[b][c], dp2[b][c]=-1;
    }
    int an=0;
    for(int a=0; a<=2; a++) for(int b=0; b<=4; b++) an=max(an, dp[a][b]);
    cout<<an;
}