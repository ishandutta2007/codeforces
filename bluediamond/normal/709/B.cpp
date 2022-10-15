#include <iostream>
#include <algorithm>
using namespace std;
int v[100005];
int main()
{
    int n,a,i,x1,x2,d1,d2;
    cin>>n>>a;
    for(i=1;i<=n;i++)
        cin>>v[i];
    if(n==1)
    {
        cout<<0;
        return 0;
    }
    sort(v+1,v+n+1);
    if(v[2]<=a and a<=v[n])
    {
        x1=a-v[2];
        x2=v[n]-a;
        if(x1<x2)
            d1=2*x1+x2;
        else
            d1=2*x2+x1;
    }
    if(a<=v[2])
        d1=v[n]-a;
    if(v[n]<=a)
        d1=a-v[2];
    if(v[1]<=a and a<=v[n-1])
    {
        x1=a-v[1];
        x2=v[n-1]-a;
        if(x1<x2)
            d2=2*x1+x2;
        else
            d2=2*x2+x1;
    }
    if(a<=v[1])
        d2=v[n-1]-a;
    if(v[n-1]<=a)
        d2=a-v[1];
    if(d1<d2)
        cout<<d1;
    else
        cout<<d2;
    return 0;
}