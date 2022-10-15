#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

ll n,k;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>k;
    ll val=2*k-1;
    if(val<=n)
        cout<<val<<"\n";
    else
    {
        k-=(n+1)/2;
        cout<<2*k<<"\n";
    }
    return 0;
}
/**

**/