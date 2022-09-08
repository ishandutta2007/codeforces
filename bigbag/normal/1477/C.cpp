/**
 *  created: 28/01/2021, 17:28:14
**/

#include <bits/stdc++.h>

using namespace std;

const int max_n = 5055, inf = 1000111222;

struct point {
    int x, y;

    point(): x(0), y(0) {
    }

    point(int x, int y): x(x), y(y) {
    }

    point operator - (const point &p) const {
        return {x - p.x, y - p.y};
    }
};

long long cross_pr(const point &a, const point &b) {
    return 1LL * a.x * b.x + 1LL * a.y * b.y;
}

bool ok(const point &a, const point &b, const point &c) {
    return cross_pr(a - b, c - b) > 0;
}

int n, ans[max_n];
point p[max_n];

bool ok(int a, int b, int c) {
    return ok(p[a], p[b], p[c]);
}

const int seed = chrono::steady_clock::now().time_since_epoch().count();
mt19937 generator(seed);

int rnd() {
    return generator() >> 1;
}

int rnd(int r) {
    return rnd() % r;
}

int rnd(int l, int r) {
    return l + rnd(r - l + 1);
}

const bool debug = 0;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    for (int t = 0; t < 1; ++t) {
        if (debug) {
            n = rnd(3, 20);
            set<pair<int, int>> q;
            for (int i = 0; i < n; ++i) {
                int x, y;
                do {
                    const int mx = 2000000000;
                    x = rnd(mx) - mx / 2;
                    y = rnd(mx) - mx / 2;
                } while (q.count({x, y}));
                p[i] = {x, y};
                q.insert({x, y});
            }
        } else {
            scanf("%d", &n);
            for (int i = 0; i < n; ++i) {
                scanf("%d%d", &p[i].x, &p[i].y);
            }
        }
        for (int i = 0; i < n; ++i) {
            ans[i] = i;
        }
        for (int i = 2; i < n; ++i) {
            int pos = i;
            while (pos >= 2 && !ok(ans[pos - 2], ans[pos - 1], ans[pos])) {
                swap(ans[pos - 1], ans[pos]);
                if (pos < i) {
                    assert(ok(ans[pos - 1], ans[pos], ans[pos + 1]));
                }
                --pos;
            }
        }
        for (int i = 0; i + 2 < n; ++i) {
            assert(ok(ans[i], ans[i + 1], ans[i + 2]));
        }
        for (int i = 0; i < n; ++i) {
            printf("%d ", ans[i] + 1);
        }
        puts("");
    }
    return 0;
}