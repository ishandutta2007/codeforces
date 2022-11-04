#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    pair<int, int> a[n];
    int b[n];
    fill(b, b + n, 0);
    b[0] = 1;
    for (int i = 0; i < n; i++)
        cin >> a[i].first;
    for (int i = 0; i < n; i++)
        a[i].second = i + 1;
    sort(a + 1, a + n);
    reverse(a + 1, a + n);
    vector<pair<int, int> > ans;
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (a[j].first && b[j])
            {
                a[j].first--;
                b[i] = 1;
                ans.push_back({a[j].second, a[i].second});
                break;
            }
        }
    }
    if (ans.size() < n - 1)
        cout << -1 << endl;
    else
    {
        cout << ans.size() << endl;
        for (auto p: ans)
            cout << p.first << " " << p.second << endl;
    }
    return 0;
}