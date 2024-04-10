#include <iostream>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    long long n,k,t;
    cin>>n>>k>>t;
    if(t<=k)
    {
        cout<<t;
        return 0;
    }
    if(t<=n)
    {
        cout<<k;
        return 0;
    }
    cout<<n+k-t;
    return 0;
}