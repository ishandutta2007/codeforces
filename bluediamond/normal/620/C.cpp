#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    set<int> cur;
    vector<pair<int, int>> seg;
    cin >> n;
    int last = 0;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        if (cur.count(x))
        {
            seg.push_back({last, i});
            last = i + 1;
            cur.clear();
        }
        else
        {
            cur.insert(x);
        }
    }
    if (seg.empty())
    {
        cout << "-1\n";
    }
    else
    {
        if (last != n)
        {
            seg.back().second = n - 1;
        }
        cout << (int) seg.size() << "\n";
        for (auto &it : seg)
        {
            cout << it.first + 1 << " " << it.second + 1 << "\n";
        }
    }

}