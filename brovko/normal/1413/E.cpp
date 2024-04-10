#include <bits/stdc++.h>
#define int long long
#define ld long double

using namespace std;

int t, a, b, c, d;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> t;

    while(t--)
    {
        cin >> a >> b >> c >> d;

        if(a > b * c)
            cout << -1 << "\n";
        else
        {
            b *= d;

            int n = a / b;
            cout << (n + 1) * a - n * (n + 1) / 2 * b << "\n";
        }
    }
}