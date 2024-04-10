#include <bits/stdc++.h>
#define int long long
#define ld long double
#define y1 eohfweoifhew
#define y0 wepfjwewpjfef

using namespace std;

int n, t;
ld a[15][15];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> t;

    a[0][0] = t;
    int ans = 0;

    for(int i = 0; i < n; i++)
        for(int j = 0; j <= i; j++)
            if(a[i][j] >= 1)
    {
        a[i + 1][j] += (a[i][j] - 1) / 2;
        a[i + 1][j + 1] += (a[i][j] - 1) / 2;
        ans++;
    }

    cout << ans;
}