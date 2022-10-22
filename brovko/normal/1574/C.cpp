#include <bits/stdc++.h>
#define int long long
#define ld long double
#define x first
#define y second
#define pb push_back

using namespace std;

int n, a[200005];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    for(int i = 0; i < n; i++)
        cin >> a[i];

    sort(a, a + n);
    int s = 0;

    for(int i = 0; i < n; i++)
        s += a[i];

    int m;
    cin >> m;

    while(m--)
    {
        int x, y;
        cin >> x >> y;

        int L = -1, R = n;

        while(R - L > 1)
        {
            int M = (L + R) / 2;

            if(a[M] >= x)
                R = M;
            else L = M;
        }

        int ans = 4e18;

        if(L >= 0)
            ans = min(ans, max(x + y - s, x - a[L]));

        if(R < n)
            ans = min(ans, a[R] + y - s);

        cout << max(0ll, ans) << "\n";
    }
}