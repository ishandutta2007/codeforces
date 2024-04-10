#include <bits/stdc++.h>
//#define int long long
#define ld long double
#define x first
#define y second
#define pb push_back

using namespace std;

int n, a, b, c, d;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    int ans = -1, x = 0, y = 0;

    for(int i = 0; i < 4; i++)
    {
        cin >> a >> b >> c >> d;

        if(n >= min(a, b) + min(c, d))
            ans = i + 1, x = min(a, b), y = n - x;
    }

    cout << ans;

    if(ans > -1)
        cout << ' ' << x << ' ' << y;
}