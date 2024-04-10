#include <bits/stdc++.h>

using namespace std;

int a[(int)1e5 + 10];
int dp[(int)1e5 + 10][2];
int mx[(int)4e5 + 10][2];

void ins(int v, int t, int l, int r, int x, int y)
{
    if (r - l == 1)
    {
        mx[v][t] = max(mx[v][t], y);
        return;
    }
    int m = (l + r) / 2;
    if (x < m)
        ins(2 * v + 1, t, l, m, x, y);
    else
        ins(2 * v + 2, t, m, r, x, y);
    mx[v][t] = max(mx[2 * v + 1][t], mx[2 * v + 2][t]);
}

int get(int v, int t, int l, int r, int q, int w)
{
    if (q >= r || w <= l)
        return 0;
    if (q <= l && r <= w)
        return mx[v][t];
    int m = (l + r) / 2;
    return max(get(2 * v + 1, t, l, m, q, w), get(2 * v + 2, t, m, r, q, w));
}

int main()
{
    srand(3228);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        a[x - 1]++;
        a[y]--;
    }
    for (int i = 1; i < m; i++)
    {
        a[i] += a[i - 1];
    }
    int ans = 0;
    for (int i = 0; i < m; i++)
    {
        //cout << a[i] << " ";
        dp[i][0] = get(0, 0, 0, n + 1, 0, a[i] + 1) + 1;
        dp[i][1] = max(dp[i][0], get(0, 1, 0, n + 1, a[i], n + 1) + 1);
        ins(0, 0, 0, n + 1, a[i], dp[i][0]);
        ins(0, 1, 0, n + 1, a[i], dp[i][1]);
        ans = max(ans, dp[i][1]);
    }
    //cout << endl;
    cout << ans << endl;
    return 0;
}