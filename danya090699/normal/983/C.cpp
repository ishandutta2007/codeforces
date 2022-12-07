#include <bits/stdc++.h>
using namespace std;
const int inf=1e9;
int dp[5][10][10][10][10][10];
int main()
{
    //freopen("input.txt", "r", stdin);
    int n;
    cin>>n;
    int ar[n][2];
    for(int a=0; a<n; a++) cin>>ar[a][0]>>ar[a][1];
    for(int a=0; a<5; a++)
    {
        for(int b=9; b>=0; b--)
        {
            for(int c=b; c>=0; c--)
            {
                for(int d=c; d>=0; d--)
                {
                    for(int e=d; e>=0; e--)
                    {
                        for(int f=1; f<10; f++) dp[a][b][c][d][e][f]=inf;
                    }
                }
            }
        }
    }
    dp[0][0][0][0][0][1]=0;
    for(int a=0; a<=n; a++)
    {
        int i=a%5;
        for(int b=9; b>=0; b--)
        {
            for(int c=b; c>=0; c--)
            {
                for(int d=c; d>=0; d--)
                {
                    for(int e=d; e>=0; e--)
                    {
                        for(int f=1; f<10; f++)
                        {
                            int va=dp[i][b][c][d][e][f], go[5]={b, c, d, e, -1};
                            if(a<n) go[4]=ar[a][0];
                            for(int g=0; g<5; g++)
                            {
                                int t=go[g];
                                if(t!=-1)
                                {
                                    int ne[4]={b, c, d, e}, add=abs(f-t);
                                    for(int h=0; h<4; h++)
                                    {
                                        if(ne[h]==t)
                                        {
                                            ne[h]=0, add++;
                                        }
                                    }
                                    sort(ne, ne+4, greater <int>());
                                    int yk=a;
                                    while(yk<n and ne[3]==0)
                                    {
                                        if(ar[yk][0]==t)
                                        {
                                            ne[3]=ar[yk][1];
                                            for(int h=2; h>=0; h--) if(ne[h]<ne[h+1]) swap(ne[h], ne[h+1]);
                                            yk++, add++;
                                        }
                                        else break;
                                    }
                                    dp[yk%5][ne[0]][ne[1]][ne[2]][ne[3]][t]=min(dp[yk%5][ne[0]][ne[1]][ne[2]][ne[3]][t], va+add);
                                }
                            }
                        }
                    }
                }
            }
        }
        if(a!=n)
        {
            for(int b=9; b>=0; b--)
            {
                for(int c=b; c>=0; c--)
                {
                    for(int d=c; d>=0; d--)
                    {
                        for(int e=d; e>=0; e--)
                        {
                            for(int f=1; f<10; f++) dp[i][b][c][d][e][f]=inf;
                        }
                    }
                }
            }
        }
    }
    int an=inf;
    for(int a=1; a<10; a++) an=min(an, dp[n%5][0][0][0][0][a]);
    cout<<an;
}