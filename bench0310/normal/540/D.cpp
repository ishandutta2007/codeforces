#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

array<double,3> operator+(const array<double,3> &a,const array<double,3> &b)
{
    return {a[0]+b[0],a[1]+b[1],a[2]+b[2]};
}

array<double,3> operator*(const double &a,const array<double,3> &b)
{
    return {a*b[0],a*b[1],a*b[2]};
}

int main()
{
    int r,s,p;
    scanf("%d%d%d",&r,&s,&p);
    vector<vector<vector<array<double,3>>>> dp(r+1,vector<vector<array<double,3>>>(s+1,vector<array<double,3>>(p+1,{0,0,0})));
    for(int a=1;a<=r;a++) for(int b=0;b<=s;b++) dp[a][b][0]={1,0,0};
    for(int b=1;b<=s;b++) for(int c=0;c<=p;c++) dp[0][b][c]={0,1,0};
    for(int c=1;c<=p;c++) for(int a=0;a<=r;a++) dp[a][0][c]={0,0,1};
    for(int a=1;a<=r;a++)
    {
        for(int b=1;b<=s;b++)
        {
            for(int c=1;c<=p;c++)
            {
                double x=a*b+b*c+c*a;
                dp[a][b][c]=dp[a][b][c]+(a*b/x)*dp[a][b-1][c];
                dp[a][b][c]=dp[a][b][c]+(b*c/x)*dp[a][b][c-1];
                dp[a][b][c]=dp[a][b][c]+(c*a/x)*dp[a-1][b][c];
            }
        }
    }
    printf("%.12f %.12f %.12f\n",dp[r][s][p][0],dp[r][s][p][1],dp[r][s][p][2]);
    return 0;
}