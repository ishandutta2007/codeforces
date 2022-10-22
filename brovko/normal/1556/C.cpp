#include <bits/stdc++.h>
#define int long long
#define ld long double
#define pb push_back
#define x first
#define y second

using namespace std;

int n, a[1005];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    for(int i = 0; i < n; i++)
        cin >> a[i];

    int ans = 0;

    for(int i = 0; i < n; i += 2)
    {
        int Min = 0, x = 0;

        for(int j = i + 1; j < n; j += 2)
        {
            if(j - 1 > i)
                x += a[j - 1];

            if(Min + min(a[i], a[j] - x) >= 0)
                ans += max(0ll, min(a[i], a[j] - x) - max({-Min, 1ll, 1 - x}) + 1);

            //cout << i << ' ' << j << ' ' << max(0ll, min(a[i], a[j] - x) - max({Min, 1ll, 1 - x}) + 1) << endl;}

            x -= a[j];
            Min = min(Min, x);
        }
    }

    cout << ans;
}