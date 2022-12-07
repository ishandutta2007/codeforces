#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i].first;
        a[i].second = i;
    }
    sort(a.begin() + 1, a.end());
    reverse(a.begin() + 1, a.end());
    if (a[0].first == 0) {
        cout << -1;
        return 0;
    }
    int last = 1;
    vector<pair<int, int>> ans;
    for (int i = 0; i < n; i++) {
        if (i >= last) {
            break;
        }
        for (int j = last; a[i].first > 0 && j < n; j++) {
            ans.push_back({a[i].second, a[j].second});
            a[i].first--;
            last++;
        }
        if (last == n) {
            break;
        }
    }
    if (last != n) {
        cout << -1;
        return 0;
    }
    cout << ans.size() << '\n';
    for (pair<int, int> pa : ans) {
        cout << pa.first + 1 << ' ' << pa.second + 1 << '\n';
    }
}