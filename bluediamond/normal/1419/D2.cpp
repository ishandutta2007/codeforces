#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int N = (int) 1e5 + 7;
int n;
int a[N];
int b[N];
bool is[N];

bool ok(int x)
{
    for (int i = 1; i <= n; i++)
    {
        b[i] = -1;
        is[i] = 0;
    }
    for (int i = 1; i <= x; i++)
    {
        int pos = 2 * i;
        if (pos >= n)
        {
            return 0;
        }
        b[pos] = a[i];
        is[pos] = 1;
    }
    int y = x;
    int value = b[2 * x];
    for (int i = 1; i <= n; i++)
    {
        if (b[i + 1] == value || b[i - 1] == value)
        {
            continue;
        }
        if (b[i] == -1)
        {
            b[i] = a[++y];
        }
    }
    for (int i = 1; i <= n; i++)
    {
        if (b[i] == -1)
        {
            b[i] = a[++y];
        }
    }
    int cnt = 0;
    for (int i = 2; i < n; i++)
    {
        cnt += (b[i] < b[i - 1] && b[i] < b[i + 1]);
    }
    return (cnt >= x);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    sort(a + 1, a + n + 1);
    int l = 0, r = n, sol = 0;
    while (l <= r)
    {
        int m = (l + r) / 2;
        if (ok(m))
        {
            sol = m;
            l = m + 1;
        }
        else
        {
            r = m - 1;
        }
    }
    ok(sol);
    cout << sol << "\n";
    for (int i = 1; i <= n; i++)
    {
        cout << b[i] << " ";
    }
    cout << "\n";
}