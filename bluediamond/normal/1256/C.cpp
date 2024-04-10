#include <bits/stdc++.h>

using namespace std;

const int N = 1000 + 7;
int n, m, jump, c[N], suf[N], mx[N];
int ans[N];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> jump;
    for (int i = 1; i <= m; i++)
    {
        cin >> c[i];
    }

    for (int i = m; i >= 1; i--)
    {
        suf[i] = suf[i + 1] + c[i];
    }

    for (int i = 1; i <= m; i++)
    {
        mx[i] = n + 1 - suf[i];
    }

    int last = 0;
    for (int i = 1; i <= m; i++)
    {
        int now = min(last + jump, mx[i]);
        ans[now] += i;
        ans[now + c[i]] -= i;
        last = now + c[i] - 1;
    }

    if (last + jump > n)
    {
        cout << "YES\n";
        for (int i = 1; i <= n; i++)
        {
            ans[i] += ans[i - 1];
            cout << ans[i] << " ";
        }
        cout << "\n";
    }
    else
    {
        cout << "NO\n";
    }

}