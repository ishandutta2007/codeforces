#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int l = a[n - 1], r = (int) 2e6, ans = 0;
    while (l <= r)
    {
        int x = (l + r) / 2, used = n;
        int pos = n - 1;
        for (int i = 0; i < n; i++)
        {
            while (pos > i && a[pos] + a[i] > x)
            {
                pos--;
            }
            if (pos > i && a[pos] + a[i] <= x)
            {
                used--;
                pos--;
            }
            else
            {
                break;
            }
        }
        if (used <= k)
        {
            ans = x;
            r = x - 1;
        }
        else
        {
            l = x + 1;
        }
    }
    cout << ans << "\n";
}