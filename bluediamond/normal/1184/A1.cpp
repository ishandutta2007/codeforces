#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
        ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

        ll r;
        cin >> r;
        if (r % 2 == 0)
        {
                /// r = x * x + x + 1 + 2 * x * y
                /// r = x * (x + 1) + 1 + 2 * x * y
                /// r = even + odd + even
                /// r = odd
                cout << "NO\n";
                return 0;
        }

        /// if (x == 1) => r = 2 * y + 3, y >= 1 => r >= 5

        if (r >= 5)
                cout << "1 " << (r - 3) / 2 << "\n";
        else
                cout << "NO\n";


        return 0;
}