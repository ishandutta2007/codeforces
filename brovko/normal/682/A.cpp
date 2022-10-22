#include <bits/stdc++.h>
#define int long long
#define ld long double
#define y1 eohfweoifhew

using namespace std;

int n, m, ans;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;

    for(int i = 1; i <= 5; i++)
        for(int j = 1; j <= 5; j++)
            if(i + j == 5 || i + j == 10)
                ans += max(0ll, (n - i + 5) / 5) * max(0ll, (m - j + 5) / 5);

    cout << ans;
}