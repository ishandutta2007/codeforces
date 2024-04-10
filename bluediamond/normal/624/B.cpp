#include <iostream>
#include <algorithm>
using namespace std;
long long v[30];
int main()
{
    long long n,i,poz,s;
    cin>>n;
    for(i=1;i<=n;i++)
        cin>>v[i];
    sort(v+1,v+n+1);
    poz=v[n];
    s=v[n];
    for(i=n-1;i>0;i--)
    {
        int x=min(poz-1,v[i]);
        if(x<0)
           break;
        poz=x;
        s+=x;
    }
    cout<<s;
    return 0;
}