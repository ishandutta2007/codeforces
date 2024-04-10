#include <bits/stdc++.h>

using namespace std;

vector<pair<int, int> > ans;
int cur[(int)1e5 + 10], mx[(int)1e5 + 10];

int main()
{
    int n;
    cin >> n;
    int m = (int)1e5;
    for (int i = 0; i <= m; i++)
    {
        cur[i] = 0;
        mx[i] = 0;
    }
    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        mx[x] = max(mx[x], y);
    }
    for (int i = 0; i < n; i++)
    {
        int w;
        cin >> w;
        int l = -1;
        int r = n + 1;
        while (r - l > 1)
        {
            int q = (l + r) / 2;
            if (cur[q] - q < w)
            {
                r = q;
            }
            else
            {
                l = q;
            }
        }
        if (l >= 0)
        {
            int q = l;
            if (cur[q] - q > w)
            {
                cout << "NO" << endl;
                return 0;
            }
            else if ((q == 0 || cur[q] < cur[q - 1]) && cur[q] <= mx[q])
            {
                ans.push_back({q, cur[q]});
                cur[q]++;
            }
            else
            {
                cout << "NO" << endl;
                return 0;
            }
        }
        else
        {
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << ans[i].first << " " << ans[i].second << endl;
    }
    return 0;
}