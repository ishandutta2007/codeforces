#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

inline ll co(ll n,ll k)
{
    return (n+k-1)/k;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll n,sell;
    cin>>n>>sell;
    cout<<co(2*n,sell)+co(5*n,sell)+co(8*n,sell)<<"\n";
    return 0;
}
/**

**/