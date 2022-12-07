#include <bits/stdc++.h>
using namespace std;
const int sz=2e3+10, mod=1e9+7;
int dp[sz][sz], q[sz][sz];
int main()
{
    //freopen("input.txt", "r", stdin);
    int n;
    cin>>n;
    dp[n*2][0]=0, q[n*2][0]=1;
    for(int a=n*2-1; a>=0; a--)
    {
        for(int b=0; b<=a; b++)
        {
            if((a-b)%2==0 and n*2-a>=b)
            {
                int cq=0;
                if(n*2-(a+1)>=b+1)
                {
                    dp[a][b]+=dp[a+1][b+1];
                    cq+=q[a+1][b+1];
                }
                if(b)
                {
                    dp[a][b]+=dp[a+1][b-1];
                    cq+=q[a+1][b-1];
                }
                if(cq>0) dp[a][b]++;
                else q[a][b]=1;
                if(dp[a][b]>=mod) dp[a][b]-=mod;

            }
        }
    }
    cout<<dp[0][0];
}