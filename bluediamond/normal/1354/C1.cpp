#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const ld PI = 2.0 * acos(0.0);

ld rad(ld x)
{
    return x * PI / (ld) 180;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        ld all = (ld) 180 * (2 * n - 2) / (ld) (2 * n);
        n--;
        n /= 2;
        ld a = all - 90, ans = 0;
        for (int i = 1; i <= n; i++)
        {
            ans += cos(rad(a));
            a = 90 - a;
            a = all - a;
            a -= 90;
        }
        ans *= 2.0;
        ans++;
        cout << fixed << setprecision(6) << ans << "\n";
    }
}