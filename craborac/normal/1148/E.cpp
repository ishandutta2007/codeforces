#include <bits/stdc++.h>

using namespace std;

pair<int, int> a[(int)3e5 + 10];
int b[(int)3e5 + 10];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    long long s = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i].first;
        a[i].second = i;
        s += a[i].first;
    }
    for (int i = 0; i < n; i++)
    {
        cin >> b[i];
        s -= b[i];
    }
    if (s != 0)
    {
        cout << "NO" << endl;
        return 0;
    }
    sort(a, a + n);
    sort(b, b + n);
    vector<pair<pair<int, int>, int> > ans;
    vector<pair<int, int> > cur;
    for (int i = 0; i < n; i++)
    {
        if (a[i].first < b[i])
            cur.push_back({i, b[i] - a[i].first});
        else if (a[i].first > b[i])
        {
            while (cur.size() && a[i].first > b[i])
            {
                int x = cur.size() - 1;
                int y = min(cur[x].second, a[i].first - b[i]);
                cur[x].second -= y;
                a[i].first -= y;
                pair<int, int> p = {a[cur[x].first].second, a[i].second};
                ans.push_back({p, y});
                if (cur[x].second == 0)
                    cur.pop_back();
            }
            if (a[i].first > b[i])
            {
                cout << "NO" << endl;
                return 0;
            }
        }
    }
    cout << "YES\n" << ans.size() << "\n";
    for (auto p: ans)
    {
        cout << p.first.first + 1 << " " << p.first.second + 1 << " " << p.second << "\n";
    }
    return 0;
}