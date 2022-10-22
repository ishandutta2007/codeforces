#include <bits/stdc++.h>
#define int long long
#define ld long double
#define y1 sdopgh

using namespace std;

int n, a[105], k1;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
        k1 += a[i];
    }

    int k0 = 0;
    int ans = 0;

    for(int i = 0; i <= n; i++)
    {
        ans = max(ans, k0 + k1);

        if(a[i] == 0)
            k0++;
        k1 -= a[i];
    }

    cout << ans;
}