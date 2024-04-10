#include <bits/stdc++.h>
#define int long long
#define ld long double
#define y1 sdopgh

using namespace std;

int s, f, t, n, a[100005], b[100005];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> s >> f >> t;

    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> a[i];

    if(n == 0)
    {
        cout << s;
        return 0;
    }

    b[0] = max(a[0], s);

    for(int i = 1; i < n; i++)
        b[i] = max(a[i], b[i - 1] + t);

    int ans = 1e18;
    int x = 0;

    for(int i = 0; i < n - 1; i++)
    {
        if(b[i] + 2 * t <= f && b[i] + t - a[i + 1] + 1 < ans)
        {
            ans = b[i] + t - a[i + 1] + 1;
            x = a[i + 1] - 1;
        }
    }

    if(b[n - 1] + 2 * t <= f)
    {
        ans = 0;
        x = b[n - 1] + t;
    }

    if(s - a[0] + 1 < ans)
    {
        ans = s - a[0] + 1;
        x = min(s, a[0] - 1);
    }

    cout << x;
}