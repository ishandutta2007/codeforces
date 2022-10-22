#include <bits/stdc++.h>
#define int long long
#define ld long double
#define y1 eohfweoifhew
#define y0 wepfjwewpjfef

using namespace std;

int n, h, k, a[100005];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> h >> k;

    for(int i = 0; i < n; i++)
        cin >> a[i];

    int H = 0;
    int ans = 0;

    for(int i = 0; i < n; i++)
    {
        int x = (a[i] + H - h + k - 1) / k;

        if(x > 0)
        {
            ans += x;
            H = max(0ll, H - x * k);
        }

        H += a[i];
    }

    ans += (H + k - 1) / k;

    cout << ans;
}