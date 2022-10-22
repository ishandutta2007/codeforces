#include <bits/stdc++.h>
#define int long long
#define ld long double
#define x first
#define y second
#define pb push_back

using namespace std;

int n, a[5005], dp[5005][5005];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    for(int i = 0; i < n; i++)
        cin >> a[i];

    vector <int> v;

    for(int i = 0; i < n; i++)
        if(i == 0 || a[i] != a[i - 1])
            v.pb(a[i]);

    n = v.size();

    for(int i = n - 1; i >= 0; i--)
        for(int j = i + 1; j < n; j++)
        {
            if(v[i] == v[j])
                dp[i][j] = dp[i + 1][j - 1] + 1;
            else dp[i][j] = min(dp[i + 1][j], dp[i][j - 1]) + 1;
        }

    cout << dp[0][n - 1];
}