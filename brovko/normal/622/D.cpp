#include <bits/stdc++.h>
#define int long long
#define ld long double
#define y1 eohfweoifhew
#define y0 wepfjwewpjfef

using namespace std;

int n;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    for(int i = n - (int)(n % 2 == 0); i >= 1; i -= 2)
        cout << n + 1 - i << ' ';

    for(int i = 3; i <= n; i += 2)
        cout << n + 1 - i << ' ';

    cout << n << ' ';

    for(int i = n / 2 * 2; i >= 2; i -= 2)
        cout << n + 1 - i << ' ';

    for(int i = 2; i <= n; i += 2)
        cout << n + 1 - i << ' ';
}