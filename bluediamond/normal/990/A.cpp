#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll a,b,c1,c2;
    cin>>a>>b>>c1>>c2;
    ll mod=a%b;
    cout<<min((ll)mod*c2,(ll)(b-mod)*c1);
    return 0;
}
/**

**/