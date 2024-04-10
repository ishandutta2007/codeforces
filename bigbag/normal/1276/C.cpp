#include <bits/stdc++.h>

using namespace std;

const int max_n = 400444, inf = 1000111222;

int n, a[max_n];
map<int, int> cnt;
vector<pair<int, int>> v;

void write(int n, int m) {
    printf("%d\n", n * m);
    printf("%d %d\n", n, m);
    vector<int> all;
    reverse(v.begin(), v.end());
    for (int i = 0; i < v.size(); ++i) {
        for (int j = 0; j < min(n, v[i].first); ++j) {
            all.push_back(v[i].second);
        }
    }
    vector<vector<int>> ans(n, vector<int> (m, 0));
    int x = 0, y = 0;
    for (int i = 0; i < n * m; ++i) {
        if (x == 0) {
            y = i / n;
        }
        ans[x][y] = all[i];
        ++x;
        ++y;
        x %= n;
        y %= m;
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            printf("%d ", ans[i][j]);
        }
        puts("");
    }
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
        ++cnt[a[i]];
    }
    for (auto p : cnt) {
        v.push_back({p.second, p.first});
    }
    sort(v.begin(), v.end());
    int sum = n, pos = v.size() - 1;
    int mx = 0, best_h, best_w;
    for (int h = n; h > 0; --h) {
        while (pos >= 0 && v[pos].first > h) {
            sum -= v[pos].first;
            --pos;
        }
        int w = sum + (v.size() - pos - 1) * h;
        w /= h;
        //cout << h << " " << sum << " + " << v.size() - pos - 1 << "*" << h << endl;
        //cout << h << " " << w << endl;
        if (h > w) {
            continue;
        }
        if (h * w > mx) {
            mx = h * w;
            best_h = h;
            best_w = w;
        }
    }
    write(best_h, best_w);
    return 0;
}