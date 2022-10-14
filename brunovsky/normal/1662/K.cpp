#include <bits/stdc++.h>
#ifdef LOCAL
#include "code/formatting.hpp"
#else
#define debug(...) (void)0
#endif

using namespace std;

struct Pd2 {
    using T = double;
    using L = double;
    using H = double;
    static constexpr bool FLOAT = true;
    static constexpr double inf = numeric_limits<double>::infinity();

    T x, y;
    Pd2() : x(0), y(0) {}
    Pd2(T x, T y) : x(x), y(y) {}
    template <typename A>
    Pd2(A point) : x(point[0]), y(point[1]) {}

    auto paired() const { return make_pair(x, y); }
    friend bool operator==(Pd2 a, Pd2 b) { return a.paired() == b.paired(); }
    friend bool operator!=(Pd2 a, Pd2 b) { return a.paired() != b.paired(); }
    friend bool operator<(Pd2 a, Pd2 b) { return a.paired() < b.paired(); }
    friend bool operator>(Pd2 a, Pd2 b) { return a.paired() > b.paired(); }

    explicit operator bool() const noexcept { return x || y; }

    bool boxed(Pd2 lo, Pd2 hi) const {
        return lo.x <= x && x <= hi.x && lo.y <= y && y <= hi.y;
    }
    friend auto min(Pd2 a, Pd2 b) { return Pd2(min(a.x, b.x), min(a.y, b.y)); }
    friend auto max(Pd2 a, Pd2 b) { return Pd2(max(a.x, b.x), max(a.y, b.y)); }

    T& operator[](int i) { return *(&x + i); }
    T operator[](int i) const { return *(&x + i); }
    Pd2 operator-() const { return Pd2(-x, -y); }
    Pd2 operator+() const { return Pd2(x, y); }
    friend Pd2 operator+(Pd2 u, Pd2 v) { return Pd2(u.x + v.x, u.y + v.y); }
    friend Pd2 operator-(Pd2 u, Pd2 v) { return Pd2(u.x - v.x, u.y - v.y); }
    friend Pd2 operator*(T k, Pd2 u) { return Pd2(u.x * k, u.y * k); }
    friend Pd2 operator*(Pd2 u, T k) { return Pd2(u.x * k, u.y * k); }
    friend Pd2 operator/(Pd2 u, T k) { return Pd2(u.x / k, u.y / k); }
    friend Pd2& operator+=(Pd2& u, Pd2 v) { return u = u + v; }
    friend Pd2& operator-=(Pd2& u, Pd2 v) { return u = u - v; }
    friend Pd2& operator*=(Pd2& u, T k) { return u = u * k; }
    friend Pd2& operator/=(Pd2& u, T k) { return u = u / k; }

    friend auto refl(Pd2 u) { return Pd2(u.y, u.x); }  // reflection across xOy bisector
    friend auto conj(Pd2 u) { return Pd2(u.x, -u.y); } // complex conjugate
    friend auto perp_ccw(Pd2 u) { return Pd2(-u.y, u.x); } // rh rotation
    friend auto perp_cw(Pd2 u) { return Pd2(u.y, -u.x); }  // lh rotation

    friend auto manh(Pd2 u) { return abs(u.x) + abs(u.y); }
    friend auto manh(Pd2 a, Pd2 b) { return manh(a - b); }
    friend auto abs(Pd2 u) { return Pd2(abs(u.x), abs(u.y)); }

    friend auto dot(Pd2 u, Pd2 v) { return u.x * v.x + u.y * v.y; }
    friend auto norm2(Pd2 u) { return dot(u, u); }
    friend auto norm(Pd2 u) { return std::sqrt(norm2(u)); }

    friend auto cross(Pd2 u, Pd2 v) { return u.x * v.y - u.y * v.x; }
    friend auto cross(Pd2 a, Pd2 b, Pd2 c) { return cross(b - a, c - a); }

    friend auto dist2(Pd2 a, Pd2 b) { return norm2(a - b); }
    friend auto dist(Pd2 a, Pd2 b) { return norm(a - b); }
    friend auto dot_cross(Pd2 a, Pd2 b) { return Pd2(cross(a, b), dot(a, b)); }

    friend auto unit(Pd2 u) { return u / norm(u); }

    friend auto rotate(Pd2 u, double rad) {
        return dot_cross(u, Pd2(std::sin(rad), std::cos(rad)));
    }

    friend string to_string(Pd2 p) {
        return '(' + to_string(p.x) + ',' + to_string(p.y) + ')';
    }
    friend ostream& operator<<(ostream& out, Pd2 p) { return out << to_string(p); }
    friend istream& operator>>(istream& in, Pd2& p) { return in >> p.x >> p.y; }

    friend int orientation(Pd2 a, Pd2 b, Pd2 c) {
        // To return 1 the crosses must all agree on sign and magnitude.
        auto va = cross(a, b, c), vb = cross(b, c, a), vc = cross(c, a, b);
        int sa = (va > 0) - (va < 0), sb = (vb > 0) - (vb < 0), sc = (vc > 0) - (vc < 0);
        auto sum = abs(va + vb + vc), dif = max({va, vb, vc}) - min({va, vb, vc});
        return sa == sb && sb == sc && dif <= 1e-5 * sum ? sa : 0;
    }

    friend bool collinear(Pd2 a, Pd2 b, Pd2 c) { return orientation(a, b, c) == 0; }
    friend bool samedir(Pd2 u, Pd2 v) { return orientation(Pd2(), u, v) == 0; }
    friend bool onsegment(Pd2 a, Pd2 b, Pd2 c) {
        return orientation(a, b, c) == 0 && dot(a - b, c - b) <= 0;
    }

    friend auto signed_linedist(Pd2 a, Pd2 u, Pd2 v) {
        return double(cross(a, u, v)) / dist(u, v);
    }
    friend auto linedist(Pd2 a, Pd2 u, Pd2 v) { return abs(signed_linedist(a, u, v)); }
    friend auto raydist(Pd2 a, Pd2 u, Pd2 v) {
        if (dot(a - u, v - u) <= 0) {
            return dist(a, u);
        } else {
            return linedist(a, u, v);
        }
    }
    friend auto segdist(Pd2 a, Pd2 u, Pd2 v) {
        if (dot(a - u, v - u) <= 0) {
            return dist(a, u);
        } else if (dot(a - v, u - v) <= 0) {
            return dist(a, v);
        } else {
            return linedist(a, u, v);
        }
    }

    friend auto cos(Pd2 u) { return clamp<double>(u.x / norm(u), -1.0, 1.0); }
    friend auto sin(Pd2 u) { return clamp<double>(u.y / norm(u), -1.0, 1.0); }
    friend auto angle(Pd2 u) {
        static const double TAU = 4 * acos(0);
        auto ang = std::atan2(u.y, u.x);
        return ang < 0 ? ang + TAU : ang;
    }

    friend auto cos(Pd2 u, Pd2 v) {
        return clamp<double>(dot(u, v) / (norm(u) * norm(v)), -1.0, 1.0);
    }
    friend auto sin(Pd2 u, Pd2 v) {
        return clamp<double>(cross(u, v) / (norm(u) * norm(v)), -1.0, 1.0);
    }
    friend auto ccw_angle(Pd2 u, Pd2 v) {
        static const double TAU = 4 * acos(0);
        auto ang = std::atan2(cross(u, v), dot(u, v));
        return ang < 0 ? ang + TAU : ang;
    }
};

const double eps = 5 * numeric_limits<double>::epsilon();

auto three(Pd2 a, Pd2 b, Pd2 c, Pd2 m) { return dist(a, m) + dist(b, m) + dist(c, m); }

auto meeting(Pd2 a, Pd2 b, Pd2 c) {
    Pd2 m = (a + b + c) / 3;
    double w = 0.94;
    while (w > eps) {
        for (Pd2 p : {a, b, c}) {
            Pd2 n = m + w * (p - m);
            if (three(a, b, c, n) < three(a, b, c, m)) {
                m = (m + n) / 2;
            }
        }
        w *= 0.95;
    }
    return three(a, b, c, m);
}

auto four(Pd2 a, Pd2 b, Pd2 c, Pd2 m) {
    return max({meeting(a, b, m), meeting(b, c, m), meeting(c, a, m)});
}

auto locate(Pd2 a, Pd2 b, Pd2 c) {
    Pd2 m = (a + b + c) / 3;
    double w = 0.94;
    while (w > eps) {
        for (Pd2 p : {a, b, c}) {
            Pd2 n = m + w * (p - m);
            if (four(a, b, c, n) < four(a, b, c, m)) {
                m = (m + n) / 2;
            }
        }
        w *= 0.95;
    }
    return m;
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    Pd2 a, b, c;
    cin >> a >> b >> c;
    cout << setprecision(9) << showpoint << fixed;
    Pd2 m = locate(a, b, c);
    debug(m);
    cout << four(a, b, c, m) << '\n';
    return 0;
}