#include <bits/stdc++.h>
#define int long long
#define ld long double
#define x first
#define y second
#define pb push_back

using namespace std;

int n, x, m, y;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> x >> m >> y;

    int ans = n + m + 1;
    int d = abs(x - y);

    for(int i = 1; i <= n; i++)
    {
        if(i + m >= d && i <= d + m)
            ans--;
    }

    for(int j = 1; j <= m; j++)
    {
        if(j + n >= d && j <= d + n)
            ans--;
    }

    if(ans != n + m + 1)
        ans++;

//    int ans2 = ans;

//    cout << ans << endl;

    for(int i = 1; i <= n; i++)
    {
        int L = max(1ll, abs(i - d));
        int R = min(m, i + d);

        if(R < L)
            continue;

//        cout << i << ' ' << L << ' ' << R  << endl;

        int L1 = max(1ll, abs(i - d) + 1);
        int R1 = min(m, i + d - 1);

        if(L1 <= R1)
            ans += R1 - L1 + 1;

        ans += R - L + 1;
    }
//
//    for(int i = 1; i <= n; i++)
//        for(int j = 1; j <= m; j++)
//        {
//            if(i + j == d || abs(i - j) == d)
//                ans2++;
//
//            if(i + j > d && abs(i - j) < d)
//                ans2 += 2;
//        }

    cout << ans;
}