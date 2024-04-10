#include <bits/stdc++.h>
#define int long long
#define ld long double
#define x first
#define y second
#define pb push_back

using namespace std;

int a[6];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    for(int i = 0; i < 6; i++)
        cin >> a[i];

    int ans = 0;

    int x = a[1] * 2 + 1;
    int y = x + min(a[0], a[2]) * 2;
    y -= 2;

    ans = (x + y) / 2 * (y - x + 2) / 2;

    ans += (y + 1) / 2 * 2 * abs(a[0] - a[2]);

    x = a[4] * 2 + 1;
    y = x + min(a[3], a[5]) * 2;
    y -= 2;

    ans += (x + y) / 2 * (y - x + 2) / 2;

    cout << ans;
}