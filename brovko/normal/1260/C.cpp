#include <bits/stdc++.h>
#define int long long
#define ld long double

using namespace std;

int t, r, b, k;

int gcd(int x, int y)
{
    if(x==0 || y==0)
        return x+y;
    return gcd(y%x, x);
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> t;
    while(t--)
    {
        cin >> r >> b >> k;
        int g=gcd(r, b);
        if(r>b)
            swap(r, b);
        r/=g;
        b/=g;
        int x=2-r;
        if(b%r==0)
            x=1;
        if((b-x)/r>=k)
            cout << "REBEL\n";
        else cout << "OBEY\n";
    }
}