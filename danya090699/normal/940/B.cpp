#include <bits/stdc++.h>
#define int long long
using namespace std;
main()
{
    int n, k, a, b, an=0;
    cin>>n>>k>>a>>b;
    while(1)
    {
        an+=(n%k)*a, n-=n%k;
        if(b>=(n-n/k)*a)
        {
            an+=n*a;
            break;
        }
        else
        {
            n/=k, an+=b;
        }
    }
    cout<<an-a;
}