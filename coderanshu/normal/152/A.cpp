#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,m,i,j,count=0;
    cin>>n>>m;
    char a[n+2][m+2];
    char maxima[m+2];
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            cin>>a[i][j];
            if(i==0)
            maxima[j]=a[i][j];
            else maxima[j]=max(maxima[j],a[i][j]);
        }
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            if(a[i][j]==maxima[j])
            {
                count++;
                break;
            }
        }
    }
    cout<<count;
    return 0;
}