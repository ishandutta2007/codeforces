//Come on, make Togliatti great again!
#include <bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("input.txt", "r", stdin);
    int n, k;
    cin>>n>>k;
    int q[n][2];
    for(int a=0; a<n; a++)
    {
        q[a][0]=0, q[a][1]=0;
        long long x;
        cin>>x;
        while(x%2==0)
        {
            x/=2, q[a][0]++;
        }
        while(x%5==0)
        {
            x/=5, q[a][1]++;
        }
    }
    int dp[k+1][2][n*60], dp2[k+1][2][n*60];
    for(int a=0; a<=k; a++) for(int b=0; b<2; b++) for(int c=0; c<n*60; c++) dp[a][b][c]=-1;
    dp[0][0][0]=0;
    for(int i=0; i<n; i++)
    {
        for(int a=0; a<=k; a++) for(int b=0; b<2; b++) for(int c=0; c<n*60; c++) dp2[a][b][c]=-1;
        for(int a=0; a<=k; a++)
        {
            for(int b=0; b<2; b++)
            {
                for(int c=0; c<n*60; c++)
                {
                    if(dp[a][b][c]!=-1)
                    {
                        dp2[a][b][c]=max(dp2[a][b][c], dp[a][b][c]);
                        if(a!=k)
                        {
                            int dv=0, py=0;
                            if(b==0) dv=c;
                            else py=c;
                            dv+=q[i][0], py+=q[i][1];
                            if(dv>=py)
                            {
                                dp2[a+1][0][dv-py]=max(dp2[a+1][0][dv-py], dp[a][b][c]+py);
                            }
                            else
                            {
                                dp2[a+1][1][py-dv]=max(dp2[a+1][1][py-dv], dp[a][b][c]+dv);
                            }
                        }
                    }
                }
            }
        }
        for(int a=0; a<=k; a++) for(int b=0; b<2; b++) for(int c=0; c<n*60; c++) dp[a][b][c]=dp2[a][b][c];
    }
    int an=0;
    for(int a=0; a<2; a++) for(int b=0; b<n*60; b++) an=max(an, dp[k][a][b]);
    cout<<an;
}