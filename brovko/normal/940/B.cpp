#include <bits/stdc++.h>
#define int long long
#define ld long double
#define y1 sdopgh

using namespace std;

int n, k, a, b;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k >> a >> b;
    int ans = 0;

    while(n > 1)
    {
        int c = min(n - 1, n % k);
        ans += a * c;
        n -= c;

        if(n > 1)
        {
            if(n / k * (k - 1) * a > b)
            {
                n /= k;
                ans += b;
            }
            else
            {
                ans += a * (n - 1);
                n = 1;
            }
        }
    }

    cout << ans;
}