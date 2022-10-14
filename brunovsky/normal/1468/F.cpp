#include <bits/stdc++.h>

using namespace std;

#define long int64_t

// *****

inline namespace {

struct Hasher {
    template <typename U, typename V>
    size_t operator()(const pair<U, V>& p) const noexcept {
        using std::hash;
        size_t a = hash<U>{}(p.first), b = hash<V>{}(p.second);
        return (a + b) * (a + b + 1) / 2 + b;
    }
};

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

} // namespace

namespace std {

template <>
struct hash<frac> {
    size_t operator()(frac f) const noexcept {
        size_t a = hash<long>{}(f.n), b = hash<long>{}(f.d);
        return (a + b) * (a + b + 1) / 2 + b;
    }
};

} // namespace std

auto solve() {
    int N;
    cin >> N;
    unordered_map<pair<frac, bool>, int, Hasher> slopes;
    for (int i = 0; i < N; i++) {
        long a, b, c, d;
        cin >> a >> b >> c >> d;
        frac slope = a == c ? frac(1, 0) : frac(d - b, c - a);
        bool right = a != c ? c > a : d > b;
        slopes[{slope, right}]++;
    }
    long ans = 0;
    for (const auto& [id, cnt] : slopes) {
        auto [slope, right] = id;
        int other = slopes.count({slope, !right}) ? slopes.at({slope, !right}) : 0;
        ans += 1LL * cnt * other;
    }
    return ans / 2;
}

// *****

int main() {
    ios::sync_with_stdio(false);
    unsigned T;
    cin >> T >> ws;
    for (unsigned t = 1; t <= T; ++t) {
        cout << solve() << endl;
    }
    return 0;
}