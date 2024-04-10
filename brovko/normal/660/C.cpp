#include <bits/stdc++.h>
#define int long long
#define ld long double
#define y1 eohfweoifhew
#define y0 wepfjwewpjfef

using namespace std;

int n, k, a[300005];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k;

    for(int i = 0; i < n; i++)
        cin >> a[i];

    int k0 = 0;
    int r = 0;

    int ans = 0, x = 0, y = 0;

    for(int i = 0; i < n; i++)
    {
        while(r < n && k0 <= k)
        {
            if(a[r] == 0)
                k0++;

            r++;
        }

        if(k0 > k)
        {
            k0--;
            r--;
        }

        if(r - i > ans)
        {
            ans = r - i;
            x = i;
            y = r;
        }

        if(a[i] == 0)
            k0--;
    }

    cout << ans << "\n";

    for(int i = 0; i < n; i++)
    {
        if(i >= x && i < y)
            cout << 1 << ' ';
        else cout << a[i] << ' ';
    }
}