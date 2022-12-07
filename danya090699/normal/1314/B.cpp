#include <bits/stdc++.h>
using namespace std;
const int inf=1e9;
main()
{
	//freopen("input.txt", "r", stdin);
	int n, k;
	cin>>n>>k;
    int dp[1<<(n+1)][2][2];
    for(int a=0; a<(1<<(n+1)); a++)
    {
        for(int t=0; t<2; t++)
        {
            for(int b=0; b<2; b++) dp[a][t][b]=-inf;
        }
        dp[a][0][0]=0;
    }
    for(int a=0; a<k; a++)
    {
        int i;
        scanf("%d", &i);
        dp[(1<<n)+i-1][1][0]=0;
    }
    for(int a=(1<<n)-1; a; a--)
    {
        for(int lt=0; lt<2; lt++)
        {
            for(int rt=0; rt<2; rt++)
            {
                for(int lb=0; lb<2; lb++)
                {
                    for(int rb=0; rb<2; rb++)
                    {
                        int va=dp[a*2][lt][lb]+dp[a*2+1][rt][rb]+(lt|rt)+(lb|rb);
                        int add=(a*2<(1<<n));

                        if(lt+rt==0) dp[a][0][lb|rb]=max(dp[a][0][lb|rb], va+(lb|rb)*add);

                        if(lt+rt==1)
                        {
                            dp[a][0][1]=max(dp[a][0][1], va+1*add);
                            dp[a][1][lb|rb]=max(dp[a][1][lb|rb], va+(lb|rb)*add);
                        }

                        if(lt+rt==2) dp[a][1][1]=max(dp[a][1][1], va+1*add);
                    }
                }
            }
        }
    }
    int an=0;
    for(int t=0; t<2; t++) for(int b=0; b<2; b++) an=max(an, dp[1][t][b]+(t|b));
    cout<<an;
}