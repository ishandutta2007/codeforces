#include <bits/stdc++.h>

using namespace std;

pair<int, int> can[20010];
pair<int, int> a[10010];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cerr.tie(0);
    int n, l, r;
    cin >> n >> l >> r;
    int mx = 0;
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i].second;
        mx = max(mx, a[i].second);
        a[i].second *= -1;
    }
    for (int i = 0; i < n; i++)
    {
        cin >> a[i].first;
        cnt += a[i].first;
    }
    sort(a, a + n);
    pair<int, int> pp = {-n - 10, cnt};
    fill(can, can + r + mx + 1, pp);
    can[0] = {0, cnt};
    for (int i = 0; i < n; i++)
    {
        int x = -a[i].second;
        for (int j = r + mx; j >= x; j--)
        {
            auto p = can[j - x];
            if (l <= j - x && j - x <= r && a[i].first)
                p.first++;
            if (a[i].first)
                p.second--;
            can[j] = max(can[j], p);
        }
    }
    int ans = 0;
    for (int i = 0; i <= r + mx; i++)
    {
        ans = max(ans, can[i].first + (int)(l <= i && i <= r && can[i].second > 0));
    }
    cout << ans << endl;
    return 0;
}