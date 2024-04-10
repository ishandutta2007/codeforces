#include <bits/stdc++.h>
#define int long long
#define ld long double
#define y1 eohfweoifhew
#define y0 wepfjwewpjfef

using namespace std;

int n, a[1005];

int gcd(int x, int y)
{
    if(x == 0)
        return y;

    return gcd(y % x, x);
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    for(int i = 0; i < n; i++)
        cin >> a[i];

    int x = 0;

    for(int i = 0; i < n - 1; i++)
        if(gcd(a[i], a[i + 1]) > 1)
            x++;

    cout << x << "\n";

    for(int i = 0; i < n; i++)
    {
        cout << a[i] << ' ';

        if(i < n - 1 && gcd(a[i], a[i + 1]) > 1)
            cout << 1 << ' ';
    }
}