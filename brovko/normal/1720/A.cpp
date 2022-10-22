#include <bits/stdc++.h>
//#define int long long
#define ld long double
#define f first
#define s second
#define pb push_back

using namespace std;
using li = long long;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--)
    {
        li a, b, c, d;
        cin >> a >> b >> c >> d;

        if(a * d == b * c)
            cout << "0\n";
        else if(a == 0 || c == 0 || a * d % (b * c) == 0 || b * c % (a * d) == 0)
            cout << "1\n";
        else cout << "2\n";
    }
}