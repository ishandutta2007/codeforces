#include <bits/stdc++.h>
#define int long long
#define ld long double
#define y1 eohfweoifhew
#define y0 wepfjwewpjfef

using namespace std;

int n, k, f[100005], w[100005], Sum[100005][40], Min[100005][40], up[100005][40];

int getsum(int x, int d)
{
    int ans = 0;

    for(int j = 39; j >= 0; j--)
        if((1ll << j) <= d)
    {
        d -= (1ll << j);
        ans += Sum[x][j];
        x = up[x][j];
    }

    return ans;
}

int getmin(int x, int d)
{
    int ans = 1e18;

    for(int j = 39; j >= 0; j--)
        if((1ll << j) <= d)
    {
        d -= (1ll << j);
        ans = min(ans, Min[x][j]);
        x = up[x][j];
    }

    return ans;
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k;

    for(int i = 0; i < n; i++)
        cin >> f[i];

    for(int i = 0; i < n; i++)
        cin >> w[i];

    for(int i = 0; i < n; i++)
        up[i][0] = f[i];

    for(int j = 1; j < 40; j++)
        for(int i = 0; i < n; i++)
            up[i][j] = up[up[i][j - 1]][j - 1];

    for(int i = 0; i < n; i++)
    {
        Sum[i][0] = w[i];
        Min[i][0] = w[i];
    }

    for(int j = 1; j < 40; j++)
        for(int i = 0; i < n; i++)
    {
        Sum[i][j] = Sum[i][j - 1] + Sum[up[i][j - 1]][j - 1];
        Min[i][j] = min(Min[i][j - 1], Min[up[i][j - 1]][j - 1]);
    }

    for(int i = 0; i < n; i++)
        cout << getsum(i, k) << ' ' << getmin(i, k) << "\n";
}