#include <bits/stdc++.h>
#define int long long
#define ld long double
#define x first
#define y second
#define pb push_back

using namespace std;
const int N = 2002;

int n, a[2005][2005], sum[4005], dif[4005], s[2005][2005], x[2], y[2], ans[2];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> a[i][j];

    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
        {
            sum[i + j] += a[i][j];
            dif[i - j + N] += a[i][j];
        }

    ans[0] = -1;
    ans[1] = -1;

    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
        {
            s[i][j] = sum[i + j] + dif[i - j + N] - a[i][j];

            if(s[i][j] > ans[(i + j) % 2])
            {
                x[(i + j) % 2] = i;
                y[(i + j) % 2] = j;
                ans[(i + j) % 2] = s[i][j];
            }
        }

    cout << ans[0] + ans[1] << "\n" << x[0] + 1 << ' ' << y[0] + 1 << ' ' << x[1] + 1 << ' ' << y[1] + 1;
}