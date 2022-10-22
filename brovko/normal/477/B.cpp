#include <bits/stdc++.h>
#define int long long
#define ld long double
#define x first
#define y second
#define pb push_back

using namespace std;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, k;
    cin >> n >> k;

    cout << (6 * n - 1) * k << "\n";

    int x = 2 * k;

    for(int i = 0; i < n; i++)
    {
        int a = (6 * i + 1) * k, b = a + 2 * k, c = b + 2 * k;

        while(__gcd(a, x) != k || __gcd(b, x) != k || __gcd(c, x) != k)
            x += 2 * k;

        assert(x <= (6 * n - 1) * k);

        cout << a << ' ' << b << ' ' << c << ' ' << x << "\n";
        x += 2 * k;
    }
}