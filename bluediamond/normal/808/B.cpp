#include <iostream>
#include <iomanip>
using namespace std;
long long v[200005];
int main()
{
    int n,i,a,k;
    long double s=0;
    cin>>n>>k;
    for(i=1;i<=n;i++)
    {
        cin>>a;
        v[i]=v[i-1]+a;
    }
    for(i=1;i+k-1<=n;i++)
        s+=v[i+k-1]-v[i-1];
    cout<<fixed<<setprecision(10)<<s/(n-k+1)*1ll;
    return 0;
}