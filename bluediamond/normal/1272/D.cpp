#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = (int) 2e5 + 7;
int n;
int a[N];
int l[N];
int r[N];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    l[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        if (a[i - 1] < a[i])
        {
            l[i] = 1 + l[i - 1];
        }
        else
        {
            l[i] = 1;
        }
    }
    r[n] = 1;
    for (int i = n - 1; i >= 1; i--)
    {
        if (a[i] < a[i + 1])
        {
            r[i] = 1 + r[i + 1];
        }
        else
        {
            r[i] = 1;
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        ans = max(ans, l[i]);
        ans = max(ans, r[i]);
    }
    for (int i = 2; i < n; i++)
    {
        if (a[i - 1] < a[i + 1])
        {
            ans = max(ans, l[i - 1] + r[i + 1]);
        }
    }
    cout << ans << "\n";
}