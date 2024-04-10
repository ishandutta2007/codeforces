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

    int t, w, b;
    cin >> t >> w >> b;

    if((ld)w * b / __gcd(w, b) > 7e18)
    {
        int q = 0, r = t;

        int ans = q * min(w, b) + min({r, w - 1, b - 1});
        int g = __gcd(t, ans);

        cout << ans / g << '/' << t / g;

        return 0;
    }

    int x = w / __gcd(w, b) * b;

    int q = t / x, r = t % x;

    int ans = q * min(w, b) + min({r, w - 1, b - 1});
    int g = __gcd(t, ans);

    cout << ans / g << '/' << t / g;
}