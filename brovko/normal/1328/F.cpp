#include <bits/stdc++.h>
#define int long long
#define ld long double
#define x first
#define y second
#define pb push_back

using namespace std;

int n, k, a[200005];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k;

    for(int i = 0; i < n; i++)
        cin >> a[i];

    sort(a, a + n);

    int ans = 1e18;

    map <int, int> m;

    for(int i = 0; i < n; i++)
    {
        m[a[i]]++;

        if(m[a[i]] == k)
            ans = 0;
    }

    int x;

    int S = 0;

    for(int i = 0; i < n; i++)
        S += a[i];

    int s = 0;

    for(int i = 0; i < n; i++)
    {
        s += a[i];
        x = a[i] * (i + 1) - s + S - s - a[i] * (n - i - 1) - n + k;
        ans = min(ans, x);

        if((i == 0 || a[i] != a[i - 1]) && i + m[a[i]] >= k)
            ans = min(ans, i * (a[i] - 1) - (s - a[i]) + k - m[a[i]]);

        if((i == n - 1 || a[i] != a[i + 1]) && n - i - 1 + m[a[i]] >= k)
            ans = min(ans, S - s - (n - i - 1) * (a[i] + 1) + k - m[a[i]]);
    }

    cout << max(0ll, ans);
}