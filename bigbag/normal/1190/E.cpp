#include <bits/stdc++.h>

using namespace std;

const int max_n = 100111, inf = 1000111;
const int max_lev = 16;
const double pi = 2 * acos(0.0);

int n, m, x[max_n], y[max_n], nxt[max_lev][max_n], dp[max_n];

double get_ang(double x, double y) {
    double ang = atan2(y, x);
    if (ang < 0) {
        ang += 2 * pi;
    }
    return ang;
}

vector<pair<double, double>> upd(const vector<pair<double, double>> &v) {
    vector<pair<double, double>> res;
    for (const auto &p : v) {
        while (!res.empty() && res.back().second >= p.second) {
            res.pop_back();
        }
        res.push_back(p);
    }
    while (!res.empty() && res[0].second <= res.back().second - 2 * pi) {
        res.pop_back();
    }
    return res;
}

bool get_bit(int mask, int pos) {
    return (bool) (mask & (1 << pos));
}

int get_nxt(int pos, int len) {
    if (len < 0) {
        return -1;
    }
    for (int i = 0; i < max_lev; ++i) {
        if (get_bit(len, i)) {
            pos = nxt[i][pos];
        }
    }
    return pos;
}

double grad(double rad) {
    return rad / pi * 180;
}

int get_minimum_barriers(double r) {
    vector<pair<double, double>> v;
    for (int i = 0; i < n; ++i) {
        double d = hypot(x[i], y[i]);
        double l = sqrt(d * d - r * r);
        double ang = get_ang(x[i], y[i]);
        double alpha = atan(l / r);
        if (ang - alpha < 0) {
            ang += 2 * pi;
        }
        v.push_back({ang - alpha, ang + alpha});
        //cout << grad(v.back().first) << " " << grad(v.back().second) << endl;
    }
    sort(v.begin(), v.end());
    v = upd(v);
    int last = v.size();
    for (int i = 0; i < v.size(); ++i) {
        if (v[i].second >= 2 * pi) {
            last = i;
            break;
        }
    }
    int pos = last - 1;
    nxt[0][last] = last;
    dp[last] = 0;
    for (int i = last - 1; i >= 0; --i) {
        while (v[i].second < v[pos].first) {
            --pos;
        }
        nxt[0][i] = pos + 1;
        dp[i] = 1 + dp[pos + 1];
    }
    if (last == v.size()) {
        return dp[0];
    }
    for (int lev = 1; lev < max_lev; ++lev) {
        for (int i = 0; i <= last; ++i) {
            nxt[lev][i] = nxt[lev - 1][nxt[lev - 1][i]];
        }
    }
    int start = 0, to = 0; // [start; to)
    while (start < last && v[start].first <= v[last].second - 2 * pi) {
        ++start;
    }
    if (get_nxt(start, dp[0] - 1) >= last) {
        return dp[0];
    }
    for (int i = last; i < v.size(); ++i) {
        while (to < last && v[to].second < v[i].first) {
            ++to;
        }
        if (i + 1 == v.size()) {
            start = 0;
        } else {
            while (start < last && v[start].first <= v[i + 1].second - 2 * pi) {
                ++start;
            }
        }
        if (i + 1 == v.size()) {
            if (get_nxt(start, dp[0] - 1) >= to) {
                return dp[0];
            }
            return dp[0] + 1;
        }
        if (get_nxt(start, dp[0] - 2) >= to) {
            return dp[0];
        }
    }
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d%d", &n, &m);
    double l = 0, r = inf;
    for (int i = 0; i < n; ++i) {
        scanf("%d%d", &x[i], &y[i]);
        if (x[i] == 0 && y[i] == 0) {
            puts("0.0");
            return 0;
        }
        r = min(r, hypot(x[i], y[i]));
    }
    //cout << get_minimum_barriers(sqrt(2)) << endl;
    //return 0;
    for (int it = 0; it < 55; ++it) {
        double mid = (l + r) / 2;
        // cout << fixed << setprecision(20) << mid << ": " << get_minimum_barriers(mid) << endl;
        if (get_minimum_barriers(mid) <= m) {
            l = mid;
        } else {
            r = mid;
        }
    }
    printf("%.10f\n", l);
    return 0;
}