#include <bits/stdc++.h>
#define int long long
#define ld long double
#define y1 eohfweoifhew
#define y0 wepfjwewpjfef

using namespace std;

int n, a[105];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    for(int i = 0; i < n; i++)
        cin >> a[i];

    int l = 0;

    while(l < n && a[l] == 0)
        l++;

    int r = n - 1;

    while(r >= 0 && a[r] == 0)
        r--;

    if(r < 0)
    {
        cout << 0;
        return 0;
    }

    int ans = 1;
    int x = 1;

    for(int i = l + 1; i <= r; i++)
    {
        if(a[i] == 0)
            x++;
        else
        {
            ans *= x;
            x = 1;
        }
    }

    cout << ans;
}