#include <bits/stdc++.h>
//#define int long long
#define ld long double
#define pb push_back
#define x first
#define y second

using li = long long;

using namespace std;


int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    vector <int> a(n);

    for(int i = 0; i < n; i++)
        cin >> a[i];

    string s;
    cin >> s;

    vector <int> sum(n + 1), dp(n + 1);

    for(int i = 0; i < n; i++)
    {
        sum[i + 1] = sum[i] + a[i];

        if(s[i] == '0')
            dp[i + 1] = dp[i];
        else dp[i + 1] = max(a[i] + dp[i], sum[i]);
    }

    cout << dp[n];
}