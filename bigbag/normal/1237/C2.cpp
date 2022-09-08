#include <bits/stdc++.h>

using namespace std;

const int max_n = 50555, inf = 1000111222;

struct point {
    int x, y, z, id;

    bool operator < (const point &p) const {
        return x < p.x || x == p.x && y < p.y || x == p.x && y == p.y && z < p.z;
    }
};

int n, used[max_n];
point p[max_n];
vector<pair<int, int>> ans;

void add(int x, int y) {
    ans.push_back({x, y});
    used[x] = used[y] = 1;
}

void solve1d(int l, int r) {
    for (int i = l; i + 1 < r; i += 2) {
        add(i, i + 1);
    }
}

void solve2d(int l, int r) {
    for (int i = l; i < r; ) {
        int pos = i;
        while (i < r && p[i].y == p[pos].y) {
            ++i;
        }
        solve1d(pos, i);
    }
    vector<int> v;
    for (int i = l; i < r; ++i) {
        if (!used[i]) {
            v.push_back(i);
        }
    }
    for (int i = 0; i + 1 < v.size(); i += 2) {
        add(v[i], v[i + 1]);
    }
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d%d%d", &p[i].x, &p[i].y, &p[i].z);
        p[i].id = i + 1;
    }
    sort(p, p + n);
    for (int i = 0; i < n; ) {
        int pos = i;
        while (i < n && p[i].x == p[pos].x) {
            ++i;
        }
        solve2d(pos, i);
    }
    vector<int> v;
    for (int i = 0; i < n; ++i) {
        if (!used[i]) {
            v.push_back(i);
        }
    }
    assert(v.size() % 2 == 0);
    for (int i = 0; i < v.size(); i += 2) {
        add(v[i], v[i + 1]);
    }
    for (int i = 0; i < ans.size(); ++i) {
        int x = ans[i].first;
        int y = ans[i].second;
        printf("%d %d\n", p[x].id, p[y].id);
    }
    return 0;
}