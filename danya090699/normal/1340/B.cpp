#include <bits/stdc++.h>
using namespace std;
string zi[10]={"1110111", "0010010", "1011101", "1011011", "0111010", "1101011", "1101111", "1010010", "1111111", "1111011"};
main()
{
    //freopen("input.txt", "r", stdin);
    int n, k;
    cin>>n>>k;
    int q[n][10];
    for(int a=0; a<n; a++)
    {
        string s;
        cin>>s;
        for(int i=0; i<10; i++)
        {
            q[a][i]=0;
            for(int j=0; j<7; j++)
            {
                if(s[j]=='1')
                {
                    if(zi[i][j]=='0')
                    {
                        q[a][i]=-1;
                        break;
                    }
                }
                else if(zi[i][j]=='1') q[a][i]++;
            }
        }
    }
    int dp[n+1][k+1];
    for(int a=0; a<=n; a++) for(int b=0; b<=k; b++) dp[a][b]=0;
    dp[0][0]=1;
    for(int a=0; a<n; a++)
    {
        for(int b=0; b<=k; b++)
        {
            if(dp[a][b])
            {
                for(int i=0; i<10; i++)
                {
                    if(q[a][i]!=-1 and b+q[a][i]<=k) dp[a+1][b+q[a][i]]=1;
                }
            }
        }
    }
    if(dp[n][k])
    {
        dp[n][k]=2;
        for(int a=n; a; a--)
        {
            for(int b=0; b<=k; b++)
            {
                if(dp[a][b]==2)
                {
                    for(int i=0; i<10; i++)
                    {
                        if(q[a-1][i]!=-1 and b-q[a-1][i]>=0 and dp[a-1][b-q[a-1][i]]==1)
                        {
                            dp[a-1][b-q[a-1][i]]=2;
                        }
                    }
                }
            }
        }
        int s=0;
        for(int a=0; a<n; a++)
        {
            for(int i=9; i>=0; i--)
            {
                if(q[a][i]!=-1 and s+q[a][i]<=k and dp[a+1][s+q[a][i]]==2)
                {
                    cout<<i;
                    s+=q[a][i];
                    break;
                }
            }
        }
    }
    else cout<<-1;
}