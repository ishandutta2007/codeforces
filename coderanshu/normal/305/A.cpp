#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int a[n];
    int z=0,h=0,d=0,s=0,t=0,ans=0,i;
    for(i=0;i<n;i++)
    {
        cin>>a[i];
        if(a[i]==0)
        z++;
        else if(a[i]==100)
        h++;
        else if(a[i]%10==0)
        t=i+1;
        else if(a[i]/10==0)
        s=i+1;
        else d=i+1;
    }
    ans+=z+h+(t||d)+((s&&!d)||(s&&t));
    cout<<ans<<endl;
    if(z)cout<<0<<" ";
    if(h)cout<<100<<" ";
    if(t)cout<<a[t-1]<<" ";
    if(d &&!t)cout<<a[d-1]<<" ";
    if(s&&!d || s&&t)cout<<a[s-1]<<" ";
    return 0;
}