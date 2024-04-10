#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,m,i,j;
    cin>>n>>m;
    char a[n+2][m+2];
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            cin>>a[i][j];
            if(a[i][j]=='.')
            {
                if((i+j)%2==0)
                a[i][j]='B';
                else a[i][j]='W';
            }
        }
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        cout<<a[i][j];
        cout<<"\n";
    }
    return 0;
}