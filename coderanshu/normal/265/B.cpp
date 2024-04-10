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
    ll n,h1,h2,i,sum=0;
    cin>>n;
    cin>>h2;
    sum+=h2+1;
    h1=h2;
    for(i=1;i<n;i++)
    {
        cin>>h2;
        sum+=mod(h2-h1)+2;
        h1=h2;
    }
    cout<<sum;
    return 0;
}