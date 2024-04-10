#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int shit(double x)
{
    if (x > 0)
    {
        return (int) x;
    }
    else
    {
        return -shit(-x) - 1;
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    cin >> n >> k;
    map<double, int> t;
    for (int i = 0; i < n; i++)
    {
        int l, r;
        cin >> l >> r;
        t[l]++;
        t[(double) r + 0.5]--;
    }
    vector<pair<double, double>> ans;
    bool last = 0;
    int cur = 0;
    for (auto &x : t)
    {
        if (cur >= k)
        {
            ans.back().second = x.first;
        }
        cur += x.second;
        if (cur >= k && last == 0)
        {
            ans.push_back({x.first, x.first});
        }
        if (cur >= k)
        {
            last = 1;
        }
        else
        {
            last = 0;
        }
    }
    cout << (int) ans.size() << "\n";
    for (auto &x : ans)
    {
        cout << (int) x.first << " " << shit(x.second) << "\n";
    }
    cout << "\n";
}