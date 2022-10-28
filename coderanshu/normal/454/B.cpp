#include<bits/stdc++.h>
using namespace std;
#define ll long int

int main()
{
    ios_base::sync_with_stdio(0);
    ll n,i,j;
    cin>>n;
    ll a[n];
    for(i=0;i<n;i++)
    cin>>a[i];
    i=0;
    while(a[i]<=a[i+1] && i<n-1)
    {
        i++;
    }
    if(i==n-1){ cout<<0; return 0; }
    j=i+1;
    i++;
    while(a[i]<=a[i+1] && i<n-1){i++;}
    if(i!=n-1)
    cout<<-1;
    else if(a[n-1]>a[0])
    cout<<-1;
    else cout<<n-j;
    return 0;
}