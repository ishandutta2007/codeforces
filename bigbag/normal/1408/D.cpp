#include <bits/stdc++.h>

using namespace std;

const int max_n = 2022, inf = 1000111;
const int max_x = 1000111;

int n, m, mx[max_x];
pair<int, int> a[max_n], b[max_n];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        cin >> a[i].first >> a[i].second;
    }
    for (int i = 0; i < m; ++i) {
        cin >> b[i].first >> b[i].second;
    }
    sort(b, b + m);
    vector<pair<int, int>> v;
    for (int i = 0; i < n; ++i) {
        vector<pair<int, int>> all;
        for (int j = 0; j < m; ++j) {
            if (a[i].first <= b[j].first && a[i].second <= b[j].second) {
                pair<int, int> p(b[j].first - a[i].first, b[j].second - a[i].second + 1);
                while (!all.empty() && all.back().second <= p.second) {
                    all.pop_back();
                }
                all.push_back(p);
            }
        }
        for (auto p : all) {
            //cout << "$" << i << ": " << p.first << " " << p.second << endl;
            mx[p.first] = max(mx[p.first], p.second);
        }
    }
    int ans = inf;
    for (int i = max_x - 2; i >= 0; --i) {
        mx[i] = max(mx[i], mx[i + 1]);
    }
    for (int i = 0; i < max_x; ++i) {
        ans = min(ans, i + mx[i]);
    }
    printf("%d\n", ans);
    return 0;
}