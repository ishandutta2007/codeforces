#include <bits/stdc++.h>
#define int long long
using namespace std;
main()
{
    //freopen("input.txt", "r", stdin);
    int T;
    cin>>T;
    while(T--)
    {
        int m, d, w;
        cin>>m>>d>>w;
        int x=w/__gcd(w, d-1);
        m=min(m, d);
        int q=(m-1)/x, l=m-x*q, r=m-x;
        cout<<1ll*(l+r)*q/2<<"\n";
    }
}