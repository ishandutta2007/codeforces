#include <bits/stdc++.h>

using namespace std;

const int max_n = 100111, inf = 1000111222;

int n, x[max_n], y[max_n], ans[max_n];

struct state {
    int x, y;
    vector<int> ids;

    void fast_swap(state &s) {
        swap(x, s.x);
        swap(y, s.y);
        ids.swap(s.ids);
    }

    void inv() {
        x *= -1;
        y *= -1;
        for (int id : ids) {
            ans[id] *= -1;
        }
    }

    void add(const state &s) {
        x += s.x;
        y += s.y;
        for (int id : s.ids) {
            ids.push_back(id);
        }
    }
};

long long dist(int x, int y) {
    return 1LL * x * x + 1LL * y * y;
}

bool ok(int x, int y) {
    return dist(x, y) <= 1000000LL * 1000000LL;
}

state a[max_n];

void find_ok(int i) {
    int min_inv = 1e9;
    for (int q = i; q <= i + 2; ++q) {
        for (int w = q + 1; w <= i + 2; ++w) {
            for (int z1 = -1; z1 <= 1; z1 += 2) {
                for (int z2 = -1; z2 <= 1; z2 += 2) {
                    if (ok(z1 * a[q].x + z2 * a[w].x, z1 * a[q].y + z2 * a[w].y)) {
                        int cnt = 0;
                        if (z1 == -1) {
                            cnt += a[q].ids.size();
                        }
                        if (z2 == -1) {
                            cnt += a[w].ids.size();
                        }
                        min_inv = min(min_inv, cnt);
                    }
                }
            }
        }
    }
    for (int q = i; q <= i + 2; ++q) {
        for (int w = q + 1; w <= i + 2; ++w) {
            for (int z1 = -1; z1 <= 1; z1 += 2) {
                for (int z2 = -1; z2 <= 1; z2 += 2) {
                    if (ok(z1 * a[q].x + z2 * a[w].x, z1 * a[q].y + z2 * a[w].y)) {
                        int cnt = 0;
                        if (z1 == -1) {
                            cnt += a[q].ids.size();
                        }
                        if (z2 == -1) {
                            cnt += a[w].ids.size();
                        }
                        if (cnt == min_inv) {
                            if (z1 == -1) {
                                a[q].inv();
                            }
                            if (z2 == -1) {
                                a[w].inv();
                            }
                            if (w < i + 2) {
                                a[w].fast_swap(a[i + 2]);
                            }
                            if (q < i + 1) {
                                a[q].fast_swap(a[i + 1]);
                            }
                            return;
                        }
                    }
                }
            }
        }
    }
    exit(228);
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d%d", &a[i].x, &a[i].y);
        a[i].ids.push_back(i);
        ans[i] = 1;
    }
    for (int i = n - 3; i >= 0; --i) {
        find_ok(i);
        if (a[i + 1].ids.size() < a[i + 2].ids.size()) {
            a[i + 1].fast_swap(a[i + 2]);
        }
        a[i + 1].add(a[i + 2]);
    }
    if (n >= 2) {
        if (!ok(a[0].x + a[1].x, a[0].y + a[1].y)) {
            a[0].inv();
        }
    }
    for (int i = 0; i < n; ++i) {
        printf("%d ", ans[i]);
    }
    return 0;
}