#include <bits/stdc++.h>
#define int long long
#define ld long double
#define y1 eohfweoifhew
#define y0 wepfjwewpjfef

using namespace std;

int n, k, a[505][505];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k;
    k--;

    int x = 1;

    for(int i = 0; i < n; i++)
        for(int j = 0; j < k; j++)
    {
        a[i][j] = x;
        x++;
    }

    int ans = 0;

    for(int i = 0; i < n; i++)
        for(int j = k; j < n; j++)
    {
        a[i][j] = x;

        if(j == k)
            ans += x;

        x++;
    }

    cout << ans << "\n";

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
            cout << a[i][j] << ' ';

        cout << "\n";
    }
}