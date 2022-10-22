#include <bits/stdc++.h>
#define int long long
#define ld long double
#define x first
#define y second

using namespace std;

int t, n, a[200005];

int g(int l, int r)
{
    for(int i = l; i < r; i++)
        for(int j = i + 1; j < r; j++)
            for(int k = j + 1; k < r; k++)
                if(a[i] <= a[j] && a[j] <= a[k] || a[i] >= a[j] && a[j] >= a[k])
                    return 0;

    return 1;
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> t;

    while(t--)
    {
        cin >> n;

        for(int i = 0; i < n; i++)
            cin >> a[i];

        int ans = 0;

        for(int i = 0; i < n; i++)
            for(int j = i + 1; j <= min(n, i + 5); j++)
                ans += g(i, j);

        cout << ans << "\n";
    }
}