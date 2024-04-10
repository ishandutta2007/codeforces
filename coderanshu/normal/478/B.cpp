#include<bits/stdc++.h>
using namespace std;
#define ll long long int 
ll nc2(ll n)
{
    return (n*(n-1))/2;
}
int main()
{
    ll m,n;
    cin>>n>>m;
    cout<<nc2(n/m+1)*(n%m)+nc2(n/m)*(m-n%m)<<" ";
    cout<<nc2(n-m+1);
    
    return 0;
}