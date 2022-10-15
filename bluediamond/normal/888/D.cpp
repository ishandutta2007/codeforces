#include <iostream>
using namespace std;
#define ll long long
int main()
{
    ll n,k,v[15],s=0;
    cin>>n>>k;
    v[1]=1;
    v[2]=n*(n-1)/2;
    v[3]=n*(n-1)*(n-2)/3;
    v[4]=n*(n-1)*(n-2)*(n-3)/24*9;
    for(ll i=1;i<=k;i++)
        s+=v[i];
    cout<<s;
    return 0;
}
/**

**/