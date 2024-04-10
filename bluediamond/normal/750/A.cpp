#include <iostream>
using namespace std;
#define ll long long
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    ll n,k,s=0,nr=0;
    cin>>n>>k;
    while(nr<n)
    {
        s+=(nr+1)*5;
        if(s+k>4*60)
            break;
        nr++;
    }
    cout<<nr;
    return 0;
}
/**

**/