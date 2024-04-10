#include <bits/stdc++.h>

using namespace std;

const int max_n = 100111, inf = 1000111222;

struct point {
    int x, y;
    point() {
        x = y = 0;
    }
    point(int x, int y) : x(x), y(y) {
    }
    void read() {
        scanf("%d%d", &x, &y);
    }
    void write(string s = "") {
        printf("%d %d%s", x, y, s.c_str());
    }
    void write_point(string s = "") {
        printf("(%d %d)%s", x, y, s.c_str());
    }
    bool operator < (const point &a) const {
        return x < a.x || x == a.x && y < a.y;
    }
    point operator - (const point &a) const {
        return point(x - a.x, y - a.y);
    }
};

long long vect_pr(point a, point b) {
    return 1LL * a.x * b.y - 1LL * a.y * b.x;
}

bool cv(point a, point b, point c) {
    return vect_pr(b - a, c - b) < 0;
}

bool ccv(point a, point b, point c) {
    return vect_pr(b - a, c - b) > 0;
}

vector<point> convex_hull(int n, point p[]) {
    sort(p, p + n);
    vector<point> res, up, down;
    if (n == 1) {
        res.push_back(p[0]);
        res.push_back(p[0]);
        return res;
    }
    for (int i = 0; i < n; ++i) {
        if (cv(p[0], p[i], p[n - 1]) || i == 0 || i + 1 == n) {
            //cout << "U" << i << endl;
            while (up.size() > 1 && !cv(up[up.size() - 2], up[up.size() - 1], p[i])) {
                up.pop_back();
            }
            up.push_back(p[i]);
        }
    }
    for (int i = 0; i < n; ++i) {
        if (ccv(p[0], p[i], p[n - 1]) || i == 0 || i + 1 == n) {
            //cout << "D" << i << endl;
            while (down.size() > 1 && !ccv(down[down.size() - 2], down[down.size() - 1], p[i])) {
                down.pop_back();
            }
            down.push_back(p[i]);
        }
    }
    down.pop_back();
    reverse(down.begin(), down.end());
    down.pop_back();
    res = up;
    for (int i = 0; i < down.size(); ++i) {
        res.push_back(down[i]);
    }
    /*for (int i = 0; i < res.size(); ++i) {
        cout << "(" << res[i].x << " " << res[i].y << ") ";
    }
    cout << endl;*/
    return res;
}

int n[2];
point p[max_n];
vector<point> v[2];
vector<pair<long long, long long>> a, b;

long long dist(const point &p) {
    return 1LL * p.x * p.x + 1LL * p.y * p.y;
}

vector<pair<long long, long long>> get(const vector<point> &v) {
    vector<pair<long long, long long>> res;
    for (int i = 0; i < v.size(); ++i) {
        res.push_back({dist(v[i] - v[(i + 1) % v.size()]), vect_pr(v[(i + 2) % v.size()] - v[(i + 1) % v.size()], v[(i + 1) % v.size()] - v[i])});
        //cout << "(" << res.back().first << " " << res.back().second << ") ";
    }
    //cout << endl;
    return res;
}

int pr[3 * max_n];

void get_prefix_function(const vector<pair<long long, long long>> &s, int p[]) {
    p[0] = 0;
    for (int i = 1; i < s.size(); ++i) {
        p[i] = p[i - 1];
        while (p[i] > 0 && s[i] != s[p[i]]) {
            p[i] = p[p[i] - 1];
        }
        if (s[i] == s[p[i]]) {
            ++p[i];
        }
    }
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d%d", &n[0], &n[1]);
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < n[i]; ++j) {
            scanf("%d%d", &p[j].x, &p[j].y);
        }
        v[i] = convex_hull(n[i], p);
    }
    if (v[0].size() != v[1].size()) {
        puts("NO");
        return 0;
    }
    a = get(v[0]);
    b = get(v[1]);
    a.push_back({-1, -1});
    for (int i = 0; i < 2 * b.size(); ++i) {
        a.push_back(b[i % b.size()]);
    }
    get_prefix_function(a, pr);
    for (int i = b.size() + 1; i < a.size(); ++i) {
        if (pr[i] == b.size()) {
            puts("YES");
            return 0;
        }
    }
    puts("NO");
    return 0;
}