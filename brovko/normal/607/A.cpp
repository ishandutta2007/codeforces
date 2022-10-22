#include <bits/stdc++.h>
#define int long long
#define ld long double
#define x first
#define y second
#define pb push_back
#define mp make_pair

using namespace std;

int n, a, b, dp[1000005];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    vector <pair <int, int> > v;

    for(int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;

        v.pb({a, b});
    }

    sort(v.begin(), v.end());
    int ans = 0;

    for(int i = 0; i < v.size(); i++)
    {
        int L = -1, R = i;

        while(R - L > 1)
        {
            int M = (L + R) / 2;

            if(v[M].x < v[i].x - v[i].y)
                L = M;
            else R = M;
        }

        if(L == -1)
            dp[i] = 1;
        else dp[i] = dp[L] + 1;

        ans = max(ans, dp[i]);
    }

    cout << n - ans;
}