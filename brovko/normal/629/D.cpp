#include <bits/stdc++.h>
#define int long long
#define ld long double
#define y1 eohfweoifhew
#define y0 wepfjwewpjfef

using namespace std;

int n, r[100005], h[100005], a[100005], y, dp[100005], t[100005];
vector <int> v;
map <int, int> m;

int Max(int r)
{
    int ans = 0;

    for(; r >= 0; r = (r & r + 1) - 1)
        ans = max(ans, t[r]);

    return ans;
}

void upd(int i, int d)
{
    for(; i < y; i = (i | i + 1))
        t[i] = max(t[i], d);
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    for(int i = 0; i < n; i++)
    {
        cin >> r[i] >> h[i];
        a[i] = r[i] * r[i] * h[i];
        v.push_back(a[i]);
    }

    sort(v.begin(), v.end());

    y = 1;

    for(auto to:v)
    {
        if(m[to] == 0)
        {
            m[to] = y;
            y++;
        }
    }

    for(int i = 0; i < n; i++)
    {
        int x = m[a[i]];
        dp[x] = max(dp[x], Max(x - 1) + a[i]);
        upd(x, dp[x]);
    }

    cout << setprecision(20) << (ld)Max(y - 1) * 3.14159265358979;
}