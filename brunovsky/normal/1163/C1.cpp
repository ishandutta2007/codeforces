#include <bits/stdc++.h>

using namespace std;

#define long int64_t

// *****

struct frac {
    long n, d;

    constexpr frac() : n(0), d(1) {}
    constexpr frac(long num) : n(num), d(1) {}
    constexpr frac(long num, long den) : n(num), d(den) {
        auto g = gcd(n, d);
        g = ((g < 0) == (d < 0)) ? g : -g;
        n /= g, d /= g;
    }

    explicit operator bool() const noexcept { return n != 0 && d != 0; }
    explicit operator long() const noexcept { return assert(d != 0), n / d; }
    explicit operator double() const noexcept { return assert(d != 0), 1.0 * n / d; }

    friend frac abs(frac f) { return frac(abs(f.n), f.d); }
    friend long floor(frac f) { return f.n >= 0 ? f.n / f.d : (f.n - f.d + 1) / f.d; }
    friend long ceil(frac f) { return f.n >= 0 ? (f.n + f.d - 1) / f.d : f.n / f.d; }
    friend frac gcd(frac a, frac b) {
        while (a != 0) {
            b = b % a;
            swap(a, b);
        }
        return abs(b);
    }

    friend bool operator==(frac a, frac b) { return a.n == b.n && a.d == b.d; }
    friend bool operator!=(frac a, frac b) { return a.n != b.n || a.d != b.d; }
    friend bool operator<(frac a, frac b) { return a.n * b.d < b.n * a.d; }
    friend bool operator>(frac a, frac b) { return a.n * b.d > b.n * a.d; }
    friend bool operator<=(frac a, frac b) { return a.n * b.d <= b.n * a.d; }
    friend bool operator>=(frac a, frac b) { return a.n * b.d >= b.n * a.d; }

    friend frac operator+(frac a, frac b) {
        return frac(a.n * b.d + b.n * a.d, a.d * b.d);
    }
    friend frac operator-(frac a, frac b) {
        return frac(a.n * b.d - b.n * a.d, a.d * b.d);
    }
    friend frac operator*(frac a, frac b) { return frac(a.n * b.n, a.d * b.d); }
    friend frac operator/(frac a, frac b) { return frac(a.n * b.d, a.d * b.n); }
    friend frac operator%(frac a, frac b) { return a - long(a / b) * b; }
    friend frac& operator+=(frac& a, frac b) { return a = a + b; }
    friend frac& operator-=(frac& a, frac b) { return a = a - b; }
    friend frac& operator*=(frac& a, frac b) { return a = a * b; }
    friend frac& operator/=(frac& a, frac b) { return a = a / b; }
    friend frac& operator%=(frac& a, frac b) { return a = a % b; }

    friend frac operator-(frac f) { return frac(-f.n, f.d); }
    friend bool operator!(frac f) { return f.n == 0; }

    friend string to_string(frac f) {
        if (f.d == 0) {
            return f.n ? f.n > 0 ? "inf" : "-inf" : "undef";
        } else if (f.d == 1) {
            return to_string(f.n);
        } else {
            return to_string(f.n) + '/' + to_string(f.d);
        }
    }

    friend ostream& operator<<(ostream& out, frac f) { return out << to_string(f); }
};

namespace std {

template <>
struct hash<frac> {
    size_t operator()(frac f) const noexcept {
        size_t a = hash<long>{}(f.n), b = hash<long>{}(f.d);
        return (a + b) * (a + b + 1) / 2 + b;
    }
};

} // namespace std

pair<frac, frac> get_line(int x0, int y0, int x1, int y1) {
    assert(x0 != x1 || y0 != y1);
    if (x0 == x1) {
        return {frac(1, 0), x0};
    } else {
        return {frac(y1 - y0, x1 - x0), frac(x0 * y1 - x1 * y0, x1 - x0)};
    }
}

auto solve() {
    int N;
    cin >> N;
    vector<array<int, 2>> points(N);
    for (auto& [x, y] : points) {
        cin >> x >> y;
    }

    unordered_map<frac, unordered_set<frac>> slope_map;
    int num_slopes = 0;

    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            auto [x0, y0] = points[i];
            auto [x1, y1] = points[j];
            auto [slope, b] = get_line(x0, y0, x1, y1);
            num_slopes += slope_map[slope].insert(b).second;
        }
    }

    long ans = 0;
    for (const auto& [slope, bs] : slope_map) {
        long c = bs.size();
        ans += c * (num_slopes - c);
    }
    return ans / 2;
}

// *****

int main() {
    ios::sync_with_stdio(false);
    cout << solve() << endl;
    return 0;
}