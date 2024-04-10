#include<bits/stdc++.h>
using namespace std;
char a[102][102];
int func(int i,int j,int n)
{
    int d;
    if(i==0 && j==0)
            {
                d=a[0][1]^a[1][0];
            }
    else if(i==0 && j==n-1)
            {
                d=a[0][n-2]^a[1][n-1];
            }
    else if(i==n-1 && j==0)
            {
                d=a[n-2][0]^a[n-1][1];
            }
    else if(i==n-1 && j==n-1)
            {
                d=a[n-1][n-2]^a[n-2][n-1];
            }
    else if(i==0)
            {
                d=(a[i][j-1]^a[i][j+1])^(a[i+1][j]^'x');
            }
    else if(i==n-1)
            {
                d=(a[i][j-1]^a[i][j+1])^(a[i-1][j]^'x');
            }
    else if(j==0)
            {
                d=(a[j][i-1]^a[j][i+1])^(a[j+1][i]^'x');
            }
    else if (j==n-1)
            {
                d=(a[j][i-1]^a[j][i+1])^(a[j-1][i]^'x');
            }
    else {
                d=(a[i][j-1]^a[i][j+1])^(a[i-1][j]^a[i+1][j]);
            }
            return d;
}
int main()
{
    int n,f=0,i,j,d;
    cin>>n;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            cin>>a[i][j];
        }
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            d=func(i,j,n);
            if(d!=0){f=1; break;}
        }
        if(f==1)break;
    }
    if(f==0)cout<<"YES";
    else cout<<"NO";
    return 0; 
}