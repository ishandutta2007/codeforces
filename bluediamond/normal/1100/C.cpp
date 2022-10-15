#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ld n,r;
    cin>>n>>r;
    ld ang=180/n;
    ld x=sin(ang*3.141592653589793/180);
    ld a=x*r/(1-x);
    cout<<fixed<<setprecision(9)<<a<<"\n";
    return 0;
}