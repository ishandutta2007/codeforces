#include <bits/stdc++.h>

using namespace std;



int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--)
    {
        string s;
        int n;
        cin >> n >> s;
        vector<pair<char, int>> t;
        for (auto &x : s)
        {
            if (t.empty() || x != t.back().first)
            {
                t.push_back({x, 0});
            }
            t.back().second++;
        }
        int ans = 0;
        for (int i = 1; i < (int) t.size(); i++)
        {
            if (t[i].first == 'P')
            {
                ans = max(ans, t[i].second);
            }
        }
        cout << ans << "\n";
    }
}