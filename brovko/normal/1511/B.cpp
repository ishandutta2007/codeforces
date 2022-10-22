#include <bits/stdc++.h>
#define int long long
#define x first
#define y second

using namespace std;

int t, a, b, c;

int f(int x)
{
    if(x == 0)
        return 0;

    return f(x / 10) + 1;
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> t;

    while(t--)
    {
        cin >> a >> b >> c;

        int g = 1;

        while(f(g) < c)
            g *= 10;

        int x = g, y = g;

        while(f(x) < a)
            x *= 2;

        while(f(y) < b)
            y *= 3;

        cout << x << ' ' << y << "\n";
    }
}