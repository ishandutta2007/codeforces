#include <bits/stdc++.h>
#define int long long
#define ld long double
#define x first
#define y second
#define pb push_back

using namespace std;

int n, m, a[400005], b[400005], c[400005], p[400005];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> m >> n;

    for(int i = 0; i < m; i++)
        cin >> b[i];

    for(int i = 0; i < n; i++)
        cin >> a[i];

    for(int i = 0; i < n - 1; i++)
        c[i] = a[i + 1] - a[i];

    c[n - 1] = 1e18;

    for(int i = n; i < n + m - 1; i++)
        c[i] = b[i - n + 1] - b[i - n];

    int k = 0;

    for(int i = 1; i < n + m - 1; i++)
    {
        while(k > 0 && c[k] != c[i])
            k = p[k - 1];

        if(c[k] == c[i])
            k++;

        p[i] = k;
    }

    int ans = 0;

    for(int i = n - 1; i < n + m - 1; i++)
        if(p[i] == n - 1)
            ans++;

    cout << ans;
}