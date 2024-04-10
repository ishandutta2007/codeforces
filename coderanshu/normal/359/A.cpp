#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,m,i,j;
    cin>>n>>m;
    int a[n][m];
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            cin>>a[i][j];
        }
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            if((i==0 || j==0 || i==n-1 || j==m-1) && a[i][j]==1)
            {
                cout<<2;
                return 0;
            }
        }
    }
    cout<<4;
    return 0;
}