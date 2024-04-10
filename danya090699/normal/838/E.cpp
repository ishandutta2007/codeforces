//Come on, make Togliatti great again!
#include <bits/stdc++.h>
using namespace std;
const int sz=2510;
double dp[sz][2][sz];
int ar[sz][2];
double dis(int v1, int v2)
{
    return sqrt(1ll*(ar[v1][0]-ar[v2][0])*(ar[v1][0]-ar[v2][0])+1ll*(ar[v1][1]-ar[v2][1])*(ar[v1][1]-ar[v2][1]));
}
int main()
{
    //freopen("input.txt", "r", stdin);
    int n;
    cin>>n;
    for(int a=0; a<n; a++)
    {
        cin>>ar[a][0]>>ar[a][1];
        for(int b=0; b<2; b++) for(int c=0; c<n; c++) dp[a][b][c]=0;
    }
    for(int a=0; a<n-1; a++)
    {
        for(int b=0; b<2; b++)
        {
            for(int c=0; c<n; c++)
            {
                if(b==0)
                {
                    int x1=c-1, x2=(c+a+1)%n;
                    if(x1<0) x1+=n;
                    dp[a+1][0][x1]=max(dp[a+1][0][x1], dp[a][0][c]+dis(c, x1));
                    dp[a+1][1][x2]=max(dp[a+1][1][x2], dp[a][0][c]+dis(c, x2));
                }
                else
                {
                    int x1=(c+1)%n, x2=c-a-1;
                    if(x2<0) x2+=n;
                    dp[a+1][1][x1]=max(dp[a+1][1][x1], dp[a][1][c]+dis(c, x1));
                    dp[a+1][0][x2]=max(dp[a+1][0][x2], dp[a][1][c]+dis(c, x2));
                }
            }
        }
    }
    double an=0;
    for(int a=0; a<2; a++) for(int b=0; b<n; b++) an=max(an, dp[n-1][a][b]);
    cout<<fixed<<setprecision(10)<<an;
}