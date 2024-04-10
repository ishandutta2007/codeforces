#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,m,i,M=0;
    cin>>n;
    int a[n];
    for(i=0;i<n;i++)
    {
    cin>>a[i];
    if(i>0)
    {
        M=max(M,a[i]-a[i-1]);    
    }
    }
    m=max(a[2]-a[0],M);
    for(i=2;i<n-1;i++)
    {
        m=min(m,max(a[i+1]-a[i-1],M));
    }
    cout<<m;
    return 0; 
}