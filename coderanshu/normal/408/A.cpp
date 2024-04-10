#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,i,j,sum,m,x;
    cin>>n;
    int a[n];
    for(i=0;i<n;i++)
    cin>>a[i];
    for(i=0;i<n;i++)
    {
        sum=0;
        for(j=0;j<a[i];j++)
        {
        cin>>x;
        sum+=x;
        }
        if(i==0)m=sum*5+a[i]*15;
        else m=min(m,sum*5+a[i]*15);
    }
    cout<<m;
    return 0;
}