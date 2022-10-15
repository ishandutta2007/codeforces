#include <iostream>
using namespace std;
int main()
{
    long long cn,n,k,x;
    cin>>n>>k;
    cn=n;
    n/=2;
    x=n/(k+1);
    cout<<x<<" "<<x*k<<" "<<cn-x*(1+k);
    return 0;
}