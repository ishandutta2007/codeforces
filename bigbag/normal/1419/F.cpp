#include <bits/stdc++.h>

using namespace std;

const int max_n = 1011, inf = 2000111222;

struct point {
    int x, y, id;

    point(int x = 0, int y = 0): x(x), y(y) {
    }
};

bool cmp_by_x(const point &a, const point &b) {
    return a.x < b.x || (a.x == b.x && a.y < b.y);
}

bool cmp_by_y(const point &a, const point &b) {
    return a.y < b.y || (a.y == b.y && a.x < b.x);
}

bool cmp_by_id(const point &a, const point &b) {
    return a.id < b.id;
}

bool BY_X;

bool cmp(const point &a, const point &b) {
    if (BY_X) {
        return cmp_by_x(a, b);
    }
    return cmp_by_y(a, b);
}

int n, used[max_n];
point p[max_n];
vector<vector<int>> ids;
vector<point> v;

int get_dist(const point &a, const point &b) {
    return abs(a.x - b.x) + abs(a.y - b.y);
}

void dfs(int v, int c, int mx) {
    used[v] = c;
    for (int i = 0; i < n; ++i) {
        if (used[i] == -1 && (p[v].x == p[i].x || p[v].y == p[i].y) && get_dist(p[i], p[v]) <= mx) {
            dfs(i, c, mx);
        }
    }
}

bool check(int mx) {
    memset(used, -1, sizeof(used));
    int c = 0;
    for (int i = 0; i < n; ++i) {
        if (used[i] == -1) {
            dfs(i, c, mx);
            ++c;
        }
    }
    //cout << "$" << c << endl;
    if (c >= 5) {
        return false;
    }
    if (c == 1) {
        return true;
    }
    if (c == 2) {
        long long D = mx;
        D *= 2;
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (used[i] != used[j]) {
                    if (p[i].x == p[j].x && llabs(p[i].y - p[j].y) <= D) {
                        return true;
                    }
                    if (p[i].y == p[j].y && llabs(p[i].x - p[j].x) <= D) {
                        return true;
                    }
                }
            }
        }
    }
    for (int i = 0; i < ids.size(); ++i) {
        int ok = 0;
        for (int id : ids[i]) {
            if (get_dist(v[i], p[id]) <= mx) {
                ok |= (1 << used[id]);
            }
        }
        if (ok + 1 == (1 << c)) {
            //cout << v[i].x << " " << v[i].y << ", c = " << c << endl;
            return true;
        }
    }
    return false;
}

void prec() {
    sort(p, p + n, cmp);
    for (int i = 0; i < v.size(); ++i) {
        int pos = lower_bound(p, p + n, v[i], cmp) - p;
        for (int j = pos - 1; j <= pos; ++j) {
            if (j >= 0 && j < n && (v[i].x == p[j].x || v[i].y == p[j].y)) {
                ids[i].push_back(p[j].id);
            }
        }
    }
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> p[i].x >> p[i].y;
        p[i].id = i;
    }
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (p[i].x != p[j].x && p[i].y != p[j].y) {
                v.push_back({p[i].x, p[j].y});
                v.push_back({p[j].x, p[i].y});
            }
        }
    }
    ids.resize(v.size());
    BY_X = true;
    prec();
    BY_X = false;
    prec();
    sort(p, p + n, cmp_by_id);
    //cout << "#" << check(1) << endl;
    //return 0;
    long long l = 0, r = inf;
    while (r - l > 1) {
        int mid = (l + r) / 2;
        if (check(mid)) {
            r = mid;
        } else {
            l = mid;
        }
    }
    if (r == inf) {
        r = -1;
    }
    cout << r << "\n";
    return 0;
}