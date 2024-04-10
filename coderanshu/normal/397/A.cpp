#include<bits/stdc++.h>
using namespace std;
// if if concept
int main()
{
    int x,y,m,n,z,j,count=0,i;
    int a[100]={};
    cin>>n;
    cin>>x>>y;
    for(i=1;i<n;i++)
    {
        cin>>m>>z;
        for(j=m;j<=z-1;j++) a[j]=1;
    }
    for(i=x;i<=y-1;i++)
    {
       if(a[i]==0)count++;
    }
    cout<<count;
    return 0;
}