#include <bits/stdc++.h>
#ifdef LOCAL
#include "code/formatting.hpp"
#else
#define debug(...) (void)0
#endif

using namespace std;

// Get x%1 in two queries
// Get y%1 in two queries
// Then get x/1 and y/1 in one query with a weirdly tilted polygon or something

const double eps = 1e-9;

auto make_vertical(int n, int m, int step, double skip, double width) {
    vector<pair<double, double>> pts;
    pts.emplace_back(skip, m + 3);
    pts.emplace_back(skip, -3);
    double i = skip;
    while (i <= n + 10) {
        pts.emplace_back(i + width, -3);
        pts.emplace_back(i + width, m + 1);
        pts.emplace_back(i + step, m + 1);
        pts.emplace_back(i + step, -3);
        i += step;
    }
    pts.emplace_back(i + step, -3);
    pts.emplace_back(i + step, m + 3);
    return pts;
}

auto make_horizontal(int n, int m, int step, double skip, double width) {
    auto pts = make_vertical(m, n, step, skip, width);
    for (auto& [x, y] : pts) {
        swap(x, y);
    }
    return pts;
}

auto make_tilted(int n, int m, double x0, double y0) {
    vector<pair<double, double>> pts;
    double w = 1.0 / (m + 5);
    pts.emplace_back(-3, y0);
    for (int i = 0; i <= m; i++) {
        pts.emplace_back(-1, i + y0);
        pts.emplace_back(n, i + y0);
        pts.emplace_back(n, i + w * (i + 2) + y0);
        pts.emplace_back(-1, i + w * (i + 1) + y0);
    }
    pts.emplace_back(-3, m + y0);
    return pts;
}

auto query(const vector<pair<double, double>>& pts) {
    int N = pts.size();
    cout << "? " << N << '\n';
    for (auto [u, v] : pts) {
        cout << setprecision(10) << showpoint << fixed;
        cout << u << ' ' << v << '\n';
    }
    cout.flush();
    double ans;
    cin >> ans;
    return max(0.0, ans);
}

bool one(double x) { return x >= 1.0 - eps / 5; }

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    double x0, y0;
    double a0 = query(make_vertical(n, m, 2, 0.0, 2.0 - eps));
    if (one(a0)) {
        x0 = 1.0 - query(make_vertical(n, m, 2, 0.0, 1.0));
    } else {
        x0 = 1.0 - query(make_vertical(n, m, 2, 1.0, 1.0));
    }
    double b0 = query(make_horizontal(n, m, 2, 0.0, 2.0 - eps));
    if (one(b0)) {
        y0 = 1.0 - query(make_horizontal(n, m, 2, 0.0, 1.0));
    } else {
        y0 = 1.0 - query(make_horizontal(n, m, 2, 1.0, 1.0));
    }
    debug(x0, y0);

    double z = query(make_tilted(n, m, x0, y0));
    double w = 1.0 / (m + 5);
    int runs = 100, i = floor(z / w) - 1;
    double L = 0, R = n - 1;
    auto get = [&](double j) {
        return ((n - j) * w * (i + 1) + (j + 1) * w * (i + 2)) / (n + 1);
    };
    while (runs--) {
        double M = (L + R) / 2;
        double a = get(M), b = get(M + 1);
        double area = (a + b) / 2;
        area >= z ? R = M : L = M;
    }
    debug(x0);
    double x = (L + R) / 2;
    double y = i + y0;
    cout << setprecision(10) << showpoint << fixed;
    cout << "! " << x << ' ' << y << endl;
    return 0;
}