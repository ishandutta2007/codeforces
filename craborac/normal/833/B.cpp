#include <bits/stdc++.h>
#define android ios

using namespace std;

int a[(int)35e3 + 10], last[(int)35e3 + 10], pref[(int)35e3 + 10], dp[(int)35e3 + 10][51];
int mx[(int)14e4 + 10], p[(int)14e4 + 10];

void init(int v, int l, int r, int k)
{
    p[v] = 0;
    if (r - l == 1)
    {
        mx[v] = dp[l][k - 1];
    }
    else
    {
        int m = (l + r) / 2;
        init(2 * v + 1, l, m, k);
        init(2 * v + 2, m, r, k);
        mx[v] = max(mx[2 * v + 1], mx[2 * v + 2]);
    }
}

void push(int v)
{
    mx[v] += p[v];
    p[2 * v + 1] += p[v];
    p[2 * v + 2] += p[v];
    p[v] = 0;
}

void ins1(int v, int l, int r, int q, int w)
{
    if (r - l == 1)
    {
        mx[v] = w;
        p[v] = 0;
        return;
    }
    push(v);
    int m = (l + r) / 2;
    if (q < m)
        ins1(2 * v + 1, l, m, q, w);
    else
        ins1(2 * v + 2, m, r, q, w);
    mx[v] = max(mx[2 * v + 1] + p[2 * v + 1], mx[2 * v + 2] + p[2 * v + 2]);
}

void ins2(int v, int l, int r, int q, int w)
{
    //cerr << "  " << v << " " << l << " " << r << " " << q << " " << w << endl;
    if (l >= w || r <= q)
        return;
    if (q <= l && r <= w)
    {
        p[v]++;
        return;
    }
    push(v);
    int m = (l + r) / 2;
    ins2(2 * v + 1, l, m, q, w);
    ins2(2 * v + 2, m, r, q, w);
    mx[v] = max(mx[2 * v + 1] + p[2 * v + 1], mx[2 * v + 2] + p[2 * v + 2]);
}

int get(int v, int l, int r, int q, int w)
{
    //cout << v << " " << l << " " << r << " " << q << " " << w << "  " << b[v] << endl;
    if (q >= r || l >= w)
        return 0;
    if (q <= l && r <= w)
        return mx[v] + p[v];
    int m = (l + r) / 2;
    push(v);
    return max(get(2 * v + 1, l, m, q, w), get(2 * v + 2, m, r, q, w));
}

int main()
{
    android::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    fill(last, last + n + 1, -1);
    int num = 0;
    dp[0][1] = 0;
    //cout << dp[0][1] << " ";
    for (int i = 0; i < n; i++)
    {
        pref[i] = last[a[i]];
        if (pref[i] == -1)
            num++;
        dp[i + 1][1] = num;
        //cout << dp[i + 1][1] << " ";
        last[a[i]] = i;
    }
    //cout << endl;
    for (int j = 2; j <= k; j++)
    {
        init(0, 0, n + 1, j);
        dp[0][j] = (int)-1e9;
        for (int i = 0; i < n; i++)
        {
            ins2(0, 0, n + 1, pref[i] + 1, i + 1);
            //cout << pref[i] + 1 << " " << i + 1 << endl;
            dp[i + 1][j] = get(0, 0, n + 1, 0, i + 1);
            //cout << dp[i + 1][j] << endl;
        }
    }
    cout << dp[n][k] << endl;
    return 0;
}