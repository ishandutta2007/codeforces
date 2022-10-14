#include <bits/stdc++.h>
#ifdef LOCAL
#include "code/formatting.hpp"
#else
#define debug(...) (void)0
#endif

using namespace std;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int N, A, B;
    cin >> N >> A >> B;

    mt19937 rng(random_device{}());
    uniform_real_distribution<double> dist(-1e-11, 1e-11);

    vector<double> p(N), u(N), z(N);
    for (int i = 0; i < N; i++) {
        cin >> p[i];
    }
    for (int i = 0; i < N; i++) {
        cin >> u[i];
        p[i] += dist(rng);
        u[i] += dist(rng);
        z[i] = 1.0 - (1.0 - p[i]) * (1.0 - u[i]);
    }

    auto epsilon = [&](double L, double R) {
        return (L + R + 1) * numeric_limits<double>::epsilon();
    };

    auto h = [&](double C, double D) {
        // Minimize the number of A, then the number of B
        int greats = 0, ultras = 0;
        double score = 0;

        for (int i = 0; i < N; i++) {
            double a = p[i] - C;
            double b = u[i] - D;
            double c = z[i] - C - D;
            double d = max({a, b, c, 0.0});
            score += d;
            greats += a == d && a > 0;
            ultras += b == d && b > a && b > 0;
            greats += c == d && c > a && c > b;
            ultras += c == d && c > a && c > b;
        }

        return make_tuple(score, greats, ultras);
    };

    // Given a cost of C for pokeballs, optimize for exactly B ultraballs
    auto g = [&](double C) {
        double L = 0, R = 1;
        while (R - L > epsilon(L, R)) {
            double D = (L + R) / 2;
            auto [score, greats, ultras] = h(C, D);
            ultras > B ? L = D : R = D;
        }
        double D = R;
        auto [score, greats, ultras] = h(C, D);
        score += B * D;
        return make_tuple(score, greats);
    };

    double L = 0, R = 1;
    while (R - L > epsilon(L, R)) {
        double C = (L + R) / 2;
        auto [score, greats] = g(C);
        greats > A ? L = C : R = C;
    }
    double C = R;
    auto [score, greats] = g(C);
    score += A * C;

    cout << setprecision(7) << showpoint << fixed;
    cout << score << '\n';
    return 0;
}