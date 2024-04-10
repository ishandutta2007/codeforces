#include <bits/stdc++.h>
#define int long long
#define ld long double

using namespace std;

int n, a[100005], dp[100005], p[100005];
vector <int> v;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    for(int i = 0; i < n; i++)
        cin >> a[i];

    for(int i = 0; i < n; i++)
        if(i == 0 || a[i] != a[i - 1])
            v.push_back(a[i]);

    for(int i = 0; i <= n; i++)
        p[i] = -1;

    for(int i = 0; i < v.size(); i++)
    {
        if(i > 0)
            dp[i] = dp[i - 1];

        if(p[v[i]] > -1)
            dp[i] = max(dp[i], dp[p[v[i]] + 1] + 1);

        p[v[i]] = i;
    }

    cout << (int)v.size() - dp[(int)v.size() - 1];
}