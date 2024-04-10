#include <bits/stdc++.h>

using namespace std;

#define ll long long

ll n,k,a,b,cost=0;

int main()
{
    cin>>n>>k>>a>>b;
    while(n>=k)
    {
        ll nr=n%k;
        n-=n%k;
        cost+=nr*a;
        if(b>a*(n-n/k))
            break;
        cost+=b;
        n/=k;
    }
    cost+=a*(n-1);
    cout<<cost;
    return 0;
}
/**


**/