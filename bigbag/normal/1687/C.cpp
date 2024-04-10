/**
 *  created: 03/06/2022, 18:52:30
**/

#include <bits/stdc++.h>

using namespace std;

const int max_n = 200222, inf = 1000111222;

int t, n, m, a[max_n], b[max_n], l[max_n], r[max_n], cnt[max_n];
vector<int> all[max_n], good;
set<int> q;
long long sum[max_n];

void clr() {
    for (int i = 0; i <= n; ++i) {
        all[i].clear();
    }
    q.clear();
    good.clear();
}

void del(int pos) {
    q.erase(pos);
    for (int id : all[pos]) {
        --cnt[id];
        if (!cnt[id]) {
            good.push_back(id);
        }
    }
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> t;
    while (t--) {
        cin >> n >> m;
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        for (int i = 0; i < n; ++i) {
            cin >> b[i];
            sum[i + 1] = a[i] - b[i];
        }
        for (int i = 1; i <= n; ++i) {
            sum[i] += sum[i - 1];
        }
        clr();
        for (int i = 0; i < m; ++i) {
            cin >> l[i] >> r[i];
            all[l[i] - 1].push_back(i);
            all[r[i]].push_back(i);
            cnt[i] = 2;
        }
        for (int i = 0; i <= n; ++i) {
            q.insert(i);
            if (!sum[i]) {
                del(i);
            }
        }
        while (!good.empty()) {
            int id = good.back();
            good.pop_back();
            while (true) {
                auto it = q.lower_bound(l[id]);
                if (it != q.end() && *it <= r[id]) {
                    del(*it);
                } else {
                    break;
                }
            }
        }
        if (q.empty()) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
    return 0;
}