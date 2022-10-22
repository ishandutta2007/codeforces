#include <bits/stdc++.h>
#define int long long
#define ld long double
#define y1 eohfweoifhew
#define y0 wepfjwewpjfef

using namespace std;

int n, m;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;

    for(int i = 0; i < n; i++)
    {
        if(2 * i + 1 + 2 * n <= m)
            cout << 2 * i + 1 + 2 * n << ' ';

        if(2 * i + 1 <= m)
            cout << 2 * i + 1 << ' ';

        if(2 * i + 2 + 2 * n <= m)
            cout << 2 * i + 2 + 2 * n << ' ';

        if(2 * i + 2 <= m)
            cout << 2 * i + 2 << ' ';
    }
}