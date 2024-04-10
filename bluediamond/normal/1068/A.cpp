#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll n,m,k,l;
    cin>>n>>m>>k>>l;
    ll a=(k+l+m-1)/m;
    if(a<=n/m) cout<<a<<"\n";
    else cout<<"-1\n";
    return 0;
}
/**

**/