#include <bits/stdc++.h>
#ifdef LOCAL
#include "code/formatting.hpp"
#else
#define debug(...) (void)0
#endif

using namespace std;

__int128_t abs(__int128_t n) { return n > 0 ? n : -n; }

template <typename T>
struct quot {
    using unit_type = T;
    T n, d; // n/d

    quot() : n(0), d(1) {}
    quot(T num) : n(num), d(1) {}
    quot(T num, T den) : n(den >= 0 ? num : -num), d(den >= 0 ? den : -den) {}

    explicit operator bool() const noexcept { return n != 0 && d != 0; }
    explicit operator T() const noexcept { return assert(d), n / d; }
    explicit operator double() const noexcept { return assert(d), double(n) / d; }

    static int sign(T x) { return x > 0 ? +1 : x < 0 ? -1 : 0; }
    static bool undefined(quot f) { return f.n == 0 && f.d == 0; }
    static int infsign(quot f) { return f.d == 0 ? sign(f.n) : 0; }

    friend quot abs(quot f) { return quot(abs(f.n), f.d); }
    friend quot inv(quot f) { return quot(f.d, f.n); }
    friend T floor(quot f) { return f.n >= 0 ? f.n / f.d : (f.n - f.d + 1) / f.d; }
    friend T ceil(quot f) { return f.n >= 0 ? (f.n + f.d - 1) / f.d : f.n / f.d; }

    friend bool operator==(quot a, quot b) { return compare(a, b) == 0; }
    friend bool operator!=(quot a, quot b) { return compare(a, b) != 0; }
    friend bool operator<(quot a, quot b) { return compare(a, b) < 0; }
    friend bool operator>(quot a, quot b) { return compare(a, b) > 0; }
    friend bool operator<=(quot a, quot b) { return compare(a, b) <= 0; }
    friend bool operator>=(quot a, quot b) { return compare(a, b) >= 0; }

    static int compare(quot a, quot b) {
        if (a.d == 0 || b.d == 0) {
            return infsign(a) - infsign(b);
        }
        T x = floor(a), y = floor(b);
        while (x == y) {
            a.n -= x * a.d;
            b.n -= y * b.d;
            if (a.n == 0 || b.n == 0) {
                return sign(a.n - b.n);
            }
            swap(a.n, b.d), swap(a.d, b.n);
            x = a.n / a.d, y = b.n / b.d;
        }
        return sign(x - y);
    }

    friend quot operator+(quot a, quot b) {
        if (a.d == b.d) {
            return quot(a.n + b.n, a.d);
        } else if (a.d == 0 || b.d == 0) {
            return a.d == 0 ? a : b;
        } else if (a.d < b.d && b.d % a.d == 0) {
            return quot(a.n * (b.d / a.d) + b.n, b.d);
        } else if (a.d > b.d && a.d % b.d == 0) {
            return quot(a.n + b.n * (a.d / b.d), a.d);
        } else {
            return quot(a.n * b.d + b.n * a.d, a.d * b.d);
        }
    }
    friend quot operator-(quot a, quot b) { return a + (-b); }
    friend quot operator*(quot a, quot b) {
        if (a.n == b.d) {
            return quot(b.n, a.d);
        } else if (a.d == b.n) {
            return quot(a.n, b.d);
        } else {
            return quot(a.n * b.n, a.d * b.d);
        }
    }
    friend quot operator/(quot a, quot b) { return a * inv(b); }
    friend quot operator%(quot a, quot b) { return a - T(a / b) * b; }
    friend quot& operator+=(quot& a, quot b) { return a = a + b; }
    friend quot& operator-=(quot& a, quot b) { return a = a - b; }
    friend quot& operator*=(quot& a, quot b) { return a = a * b; }
    friend quot& operator/=(quot& a, quot b) { return a = a / b; }
    friend quot& operator%=(quot& a, quot b) { return a = a % b; }

    friend quot operator-(quot f) { return quot(-f.n, f.d); }
    friend bool operator!(quot f) { return f.n == 0; }

    friend string to_string(quot f) {
        if (f.d == 0) {
            return f.n ? f.n > 0 ? "inf" : "-inf" : "undef";
        } else if (f.d == 1) {
            return to_string(f.n);
        } else {
            return to_string(f.n) + '/' + to_string(f.d);
        }
    }

    friend ostream& operator<<(ostream& out, quot f) { return out << to_string(f); }
};

using Q = quot<__int128_t>;

struct Pt2 {
    using T = Q; // points, vectors, coefs, manh -- integer/frac/quot
    using L = Q; // crosses, dotes, dist2, norm2 -- integer/frac/quot
    using H = Q; // huge (circle predicates) -- int128/double
    static constexpr bool FLOAT = false;

    T x, y;
    Pt2() : x(0), y(0) {}
    Pt2(T x, T y) : x(x), y(y) {}

    auto paired() const { return make_pair(x, y); }
    friend bool operator==(Pt2 a, Pt2 b) { return a.paired() == b.paired(); }
    friend bool operator!=(Pt2 a, Pt2 b) { return a.paired() != b.paired(); }
    friend bool operator<(Pt2 a, Pt2 b) { return a.paired() < b.paired(); }
    friend bool operator>(Pt2 a, Pt2 b) { return a.paired() > b.paired(); }
    friend bool operator<=(Pt2 a, Pt2 b) { return a.paired() <= b.paired(); }
    friend bool operator>=(Pt2 a, Pt2 b) { return a.paired() >= b.paired(); }

    explicit operator bool() const noexcept { return x || y; }

    bool boxed(Pt2 lo, Pt2 hi) const {
        return lo.x <= x && x <= hi.x && lo.y <= y && y <= hi.y;
    }
    friend auto min(Pt2 a, Pt2 b) { return Pt2(min(a.x, b.x), min(a.y, b.y)); }
    friend auto max(Pt2 a, Pt2 b) { return Pt2(max(a.x, b.x), max(a.y, b.y)); }

    T& operator[](int i) { return *(&x + i); }
    T operator[](int i) const { return *(&x + i); }
    Pt2 operator-() const { return Pt2(-x, -y); }
    Pt2 operator+() const { return Pt2(x, y); }
    friend Pt2 operator+(Pt2 u, Pt2 v) { return Pt2(u.x + v.x, u.y + v.y); }
    friend Pt2 operator-(Pt2 u, Pt2 v) { return Pt2(u.x - v.x, u.y - v.y); }
    friend Pt2 operator*(T k, Pt2 u) { return Pt2(u.x * k, u.y * k); }
    friend Pt2 operator*(Pt2 u, T k) { return Pt2(u.x * k, u.y * k); }
    friend Pt2 operator/(Pt2 u, T k) { return Pt2(u.x / k, u.y / k); }
    friend Pt2& operator+=(Pt2& u, Pt2 v) { return u = u + v; }
    friend Pt2& operator-=(Pt2& u, Pt2 v) { return u = u - v; }
    friend Pt2& operator*=(Pt2& u, T k) { return u = u * k; }
    friend Pt2& operator/=(Pt2& u, T k) { return u = u / k; }

    friend auto refl(Pt2 u) { return Pt2(u.y, u.x); }  // reflection across xOy bisector
    friend auto conj(Pt2 u) { return Pt2(u.x, -u.y); } // complex conjugate
    friend auto perp_ccw(Pt2 u) { return Pt2(-u.y, u.x); } // rh rotation
    friend auto perp_cw(Pt2 u) { return Pt2(u.y, -u.x); }  // lh rotation

    friend auto manh(Pt2 u) { return abs(u.x) + abs(u.y); }
    friend auto manh(Pt2 a, Pt2 b) { return manh(a - b); }
    friend auto abs(Pt2 u) { return Pt2(abs(u.x), abs(u.y)); }

    friend auto dot(Pt2 u, Pt2 v) { return L(u.x) * v.x + L(u.y) * v.y; }
    friend auto norm2(Pt2 u) { return dot(u, u); }
    friend auto norm(Pt2 u) { return std::sqrt(double(norm2(u))); }

    friend auto cross(Pt2 u, Pt2 v) { return L(u.x) * v.y - L(u.y) * v.x; }
    friend auto cross(Pt2 a, Pt2 b, Pt2 c) { return cross(b - a, c - a); }

    friend auto dist2(Pt2 a, Pt2 b) { return norm2(a - b); }
    friend auto dist(Pt2 a, Pt2 b) { return norm(a - b); }

    friend int orientation(Pt2 a, Pt2 b, Pt2 c) {
        auto sign = cross(a, b, c);
        return (sign > 0) - (sign < 0);
    }

    friend bool collinear(Pt2 a, Pt2 b, Pt2 c) { return orientation(a, b, c) == 0; }
    friend bool samedir(Pt2 u, Pt2 v) { return cross(u, v) == 0; }
    friend bool onsegment(Pt2 a, Pt2 b, Pt2 c) {
        return orientation(a, b, c) == 0 && dot(a - b, c - b) <= 0;
    }

    friend auto signed_linedist(Pt2 a, Pt2 u, Pt2 v) {
        return double(cross(a, u, v)) / dist(u, v);
    }
    friend auto linedist(Pt2 a, Pt2 u, Pt2 v) { return abs(signed_linedist(a, u, v)); }
    friend auto raydist(Pt2 a, Pt2 u, Pt2 v) {
        if (dot(a - u, v - u) <= 0) {
            return dist(a, u);
        } else {
            return linedist(a, u, v);
        }
    }
    friend auto segdist(Pt2 a, Pt2 u, Pt2 v) {
        if (dot(a - u, v - u) <= 0) {
            return dist(a, u);
        } else if (dot(a - v, u - v) <= 0) {
            return dist(a, v);
        } else {
            return linedist(a, u, v);
        }
    }
};

auto sort_uniq(vector<Pt2> pts) {
    sort(begin(pts), end(pts));
    pts.erase(unique(begin(pts), end(pts)), end(pts));
    return pts;
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    const int M = 25000;
    int N;
    cin >> N;
    vector<Pt2> people(N);
    for (int i = 0; i < N; i++) {
        int x, y;
        cin >> x >> y;
        people[i] = Pt2(Q(1, x), Q(1, y));
    }
    people.push_back(Pt2(0, M));
    people.push_back(Pt2(M, 0));

    auto pts = sort_uniq(people);
    int P = pts.size();

    vector<Pt2> hull;
    int i = 0, S = 0;
    while (i < P) {
        while (S > 1 && orientation(hull[S - 2], hull[S - 1], pts[i]) < 0) {
            hull.pop_back(), S--;
        }
        hull.push_back(pts[i++]), S++;
    }

    vector<int> ok;
    for (int i = 0; i < N; i++) {
        if (binary_search(begin(hull), end(hull), people[i])) {
            ok.push_back(i);
        }
    }
    for (int i = 0, O = ok.size(); i < O; i++) {
        cout << ok[i] + 1 << " \n"[i + 1 == O];
    }
    return 0;
}