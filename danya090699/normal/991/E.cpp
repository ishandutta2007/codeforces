#include <bits/stdc++.h>
#define int long long
using namespace std;
main()
{
    //freopen("input.txt", "r", stdin);
    int q[10];
    for(int a=0; a<10; a++) q[a]=0;
    int tr[20][20];
    for(int a=0; a<20; a++)
    {
        tr[a][0]=1, tr[a][a]=1;
        for(int b=1; b<a; b++) tr[a][b]=tr[a-1][b-1]+tr[a-1][b];
    }
    int x, an=0;
    cin>>x;
    while(x)
    {
        q[x%10]++, x/=10;
    }
    for(int a=1; a<=9; a++)
    {
        if(q[a])
        {
            //cout<<a<<" ";
            q[a]--;
            for(int n=0; n<=18; n++)
            {
                int dp[11][n+1];
                for(int b=0; b<11; b++)
                {
                    for(int c=0; c<=n; c++) dp[b][c]=0;
                }
                dp[0][n]=1;
                for(int b=0; b<10; b++)
                {
                    for(int c=0; c<=n; c++)
                    {
                        if(dp[b][c])
                        {
                            int st=0;
                            if(a!=b and q[b]) st=1;
                            for(st; st<=q[b]; st++)
                            {
                                if(c>=st) dp[b+1][c-st]+=dp[b][c]*tr[c][st];
                            }
                        }
                    }

                }
                an+=dp[10][0];
            }
            q[a]++;
        }
    }
    cout<<an;
}