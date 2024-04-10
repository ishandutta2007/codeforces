#include <bits/stdc++.h>

using namespace std;

const int max_n = 100111, inf = 1000111222;

int t, n, x, y, a[max_n], b[max_n];
vector<int> all[max_n];

bool cmp(int c1, int c2) {
    return all[c1].size() < all[c2].size();
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &t);
    while (t--) {
        scanf("%d%d%d", &n, &x, &y);
        y -= x;
        for (int i = 0; i < n; ++i) {
            scanf("%d", &a[i]);
            b[i] = -1;
            --a[i];
            all[a[i]].push_back(i);
        }
        int other = -1;
        set<pair<int, int>> q;
        for (int i = 0; i <= n; ++i) {
            if (all[i].empty()) {
                other = i;
            } else {
                q.insert({all[i].size(), i});
            }
        }
        assert(other != -1);
        while (!q.empty() && x--) {
            pair<int, int> p = *q.rbegin();
            q.erase(p);
            const int col = p.second;
            --p.first;
            if (p.first) {
                q.insert(p);
            }
            b[all[col].back()] = col;
            all[col].pop_back();
        }
        //cout << "$" << x << endl;
        assert(x <= 0);
        vector<int> cols;
        for (int i = 0; i <= n; ++i) {
            cols.push_back(i);
        }
        sort(cols.begin(), cols.end(), cmp);
        vector<pair<int, int>> v, rv;
        int mx = 0;
        for (int col : cols) {
            mx = max(mx, (int) all[col].size());
            for (int pos : all[col]) {
                v.push_back({pos, col});
            }
            all[col].clear();
        }
        rv = v;
        rotate(rv.begin(), rv.begin() + mx, rv.end());
        for (int i = 0; i < v.size(); ++i) {
            //cout << v[i].second << " " << rv[i].second << " " << y << endl;
            if (y) {
                b[v[i].first] = rv[i].second;
                --y;
                if (b[v[i].first] == a[v[i].first]) {
                    b[v[i].first] = other;
                    ++y;
                }
            } else {
                b[v[i].first] = other;
            }
        }
        if (!y) {
            puts("YES");
            for (int i = 0; i < n; ++i) {
                printf("%d ", 1 + b[i]);
            }
            puts("");
        } else {
            puts("NO");
        }
    }
    return 0;
}