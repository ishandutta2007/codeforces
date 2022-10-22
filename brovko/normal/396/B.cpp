#include <bits/stdc++.h>
#define int long long
#define ld long double
#define x first
#define y second
#define pb push_back
#define pii pair <int, int>

using namespace std;

bool prime(int x)
{
    for(int i = 2; i * i <= x; i++)
        if(x % i == 0)
            return 0;

    return 1;
}

int v(int x)
{
    while(!prime(x))
        x--;

    return x;
}

int u(int x)
{
    x++;

    while(!prime(x))
        x++;

    return x;
}

pii sum(pii x, pii y)
{
    int g = __gcd(x.y, y.y);
    int b = x.y * y.y / g;

    int a = x.x * (y.y / g) + (x.y / g) * y.x;

    int g2 = __gcd(a, b);

    a /= g2;
    b /= g2;

    return {a, b};
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;

    while(t--)
    {
        int x;
        cin >> x;

        int l = v(x);
        int r = u(x);

        pii ans = {l - 2, 2};

        ans = sum(ans, make_pair(x - l + 1, r));

        ans.y *= l;

        int g = __gcd(ans.x, ans.y);

        ans.x /= g;
        ans.y /= g;

        cout << ans.x << '/' << ans.y << "\n";
    }
}