#include <bits/stdc++.h>

using namespace std;

const int max_n = 100111, inf = 1000111222;
const int n = 6;

int m, a[n + 2], b[max_n], pos[max_n];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }
    sort(a, a + n);
    reverse(a, a + n);
    scanf("%d", &m);
    for (int i = 0; i < m; ++i) {
        scanf("%d", &b[i]);
    }
    sort(b, b + m);
    vector<int> all;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            all.push_back(b[j] - a[i]);
        }
    }
    sort(all.begin(), all.end());
    set<pair<int, int>> q;
    for (int i = 0; i < m; ++i) {
        q.insert({b[i] - a[0], i});
    }
    int ans = inf;
    for (int x : all) {
        bool ok = true;
        while (true) {
            pair<int, int> p = *q.begin();
            if (p.first >= x) {
                break;
            }
            ++pos[p.second];
            if (pos[p.second] == n) {
                ok = false;
                break;
            }
            q.erase(p);
            q.insert({b[p.second] - a[pos[p.second]], p.second});
        }
        if (!ok) {
            break;
        }
        //cout << x << " " << q.rbegin()->first << " " << q.begin()->first << " " << q.size() << endl;
        ans = min(ans, q.rbegin()->first - x);
    }
    printf("%d\n", ans);
    return 0;
}