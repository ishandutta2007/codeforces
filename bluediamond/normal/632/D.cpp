#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = (int) 1e6 + 7;
int n;
int m;
int a[N];
int f[N];
int cnt[N];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        if (a[i] > m)
        {
            continue;
        }
        cnt[a[i]]++;
    }
    for (int i = 1; i <= m; i++)
    {
        for (int j = i; j <= m; j += i)
        {
            f[j] += cnt[i];
        }
    }
    int mx = 0;
    for (int i = 1; i <= m; i++)
    {
        mx = max(mx, f[i]);
    }
    for (int i = 1; i <= m; i++)
    {
        if (mx == f[i])
        {
            cout << i << " " << mx << "\n";
            for (int j = 1; j <= n; j++)
            {
                if (i % a[j] == 0)
                {
                    cout << j << " ";
                }
            }
            cout << "\n";
            return 0;
        }
    }
}