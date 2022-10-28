#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    long int n,m,sum=0,i,l,r,p;
    cin>>n>>m;
    int a[n];
    for(i=0;i<n;i++)
    {
    cin>>a[i];
    sum+=a[i];
    }
    if(sum>0)
    p=n-sum;
    else p=n+sum;
    for(i=0;i<m;i++)
    {
        cin>>l>>r;
        if((r-l+1)%2==0 && (r-l+1)<=p)
        cout<<1<<"\n";
        else cout<<0<<"\n";
    }
    return 0;
}