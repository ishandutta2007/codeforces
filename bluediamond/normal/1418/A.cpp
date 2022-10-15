
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--)
    {
        ll x, y, k;
        cin >> x >> y >> k;
        x--;
        ll w = (k * y + k - 1), sol = 0;
        if (w >= 1)
        {
            sol = (w + x - 1) / x;
        }
        cout << sol + k << "\n";
    }
}