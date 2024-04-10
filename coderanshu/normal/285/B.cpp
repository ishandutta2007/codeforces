#include<bits/stdc++.h>
using namespace std;
#define ll long int
ll mod(ll x)
{
    return (x>0)?x:-x;
}
int main()
{
    ios_base::sync_with_stdio(0);
    ll n,s,t,i,count=0;
    cin>>n>>s>>t;
    ll a[n];
    for(i=0;i<n;i++)
    cin>>a[i];
    if(s==t){
        cout<<0;return 0;
    }
    ll k=s;
    while(a[k-1]!=s)
    {
        count++;
        if(a[k-1]==t)
        {
        cout<<count;
        return 0;
        }
        k=a[k-1];
    }
    cout<<-1;
    return 0;
}