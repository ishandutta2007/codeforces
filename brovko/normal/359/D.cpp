#include <bits/stdc++.h>
//#define int long long
#define ld long double
#define x first
#define y second
#define pb push_back

using namespace std;

int n, a[300005], Min[300005][20], gcd[300005][20], dp[300005];

int getmin(int L, int R)
{
    return min(Min[L][dp[R - L]], Min[R - (1 << dp[R - L])][dp[R - L]]);
}

int getgcd(int L, int R)
{
    return __gcd(gcd[L][dp[R - L]], gcd[R - (1 << dp[R - L])][dp[R - L]]);
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    for(int i = 2; i < 300005; i++)
        dp[i] = dp[i / 2] + 1;

    cin >> n;

    for(int i = 0; i < n; i++)
        cin >> a[i];

    for(int i = 0; i < n; i++)
    {
        Min[i][0] = a[i];
        gcd[i][0] = a[i];
    }

    for(int j = 1; j < 20; j++)
        for(int i = 0; i <= n - (1 << j); i++)
        {
            Min[i][j] = min(Min[i][j - 1], Min[i + (1 << j - 1)][j - 1]);
            gcd[i][j] = __gcd(gcd[i][j - 1], gcd[i + (1 << j - 1)][j - 1]);
        }

    int ans = 0;
    vector <int> v;

    for(int i = 0; i < n; i++)
    {
        int L = -1, R = i;

        while(R - L > 1)
        {
            int M = (L + R) / 2;

            if(getmin(M, i + 1) == a[i] && getgcd(M, i + 1) == a[i])
                R = M;
            else L = M;
        }

        int l = R;

        L = i, R = n;

        while(R - L > 1)
        {
            int M = (L + R) / 2;

            if(getmin(i, M + 1) == a[i] && getgcd(i, M + 1) == a[i])
                L = M;
            else R = M;
        }

        int r = L;

        if(r - l > ans)
        {
            ans = r - l;
            v.clear();
        }

        if(r - l == ans)
            v.pb(l);
    }

    sort(v.begin(), v.end());
    vector <int> u;

    for(int i = 0; i < v.size(); i++)
        if(u.size() == 0 || v[i] != u.back())
            u.pb(v[i]);

    cout << u.size() << ' ' << ans << "\n";

    for(auto x:u)
        cout << x + 1 << ' ';
}