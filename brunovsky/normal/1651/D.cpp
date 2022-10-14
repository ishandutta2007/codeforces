#include <bits/stdc++.h>
#ifdef LOCAL
#include "code/formatting.hpp"
#else
#define debug(...) (void)0
#endif

using namespace std;

struct Pt2 {
    using T = int32_t;    // points, vectors, coefs, manh -- integer/frac/quot
    using L = int64_t;    // crosses, dotes, dist2, norm2 -- integer/frac/quot
    using H = __int128_t; // huge (circle predicates) -- int128/double
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

    friend auto int_norm(Pt2 u) { return abs(gcd(u.x, u.y)); }
    friend auto int_unit(Pt2 u) { return u / int_norm(u); }

    friend string to_string(Pt2 p) { return to_string(p.x) + ' ' + to_string(p.y); }
    friend ostream& operator<<(ostream& out, Pt2 p) { return out << to_string(p); }
    friend istream& operator>>(istream& in, Pt2& p) { return in >> p.x >> p.y; }

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

    friend auto cos(Pt2 u) { return clamp<double>(double(u.x) / norm(u), -1.0, 1.0); }
    friend auto sin(Pt2 u) { return clamp<double>(double(u.y) / norm(u), -1.0, 1.0); }
    friend auto angle(Pt2 u) {
        static const double TAU = 4 * acos(0);
        auto ang = std::atan2(u.y, u.x);
        return ang < 0 ? ang + TAU : ang;
    }

    friend auto cos(Pt2 u, Pt2 v) {
        return clamp<double>(double(dot(u, v)) / (norm(u) * norm(v)), -1.0, 1.0);
    }
    friend auto sin(Pt2 u, Pt2 v) {
        return clamp<double>(double(cross(u, v)) / (norm(u) * norm(v)), -1.0, 1.0);
    }
    friend auto ccw_angle(Pt2 u, Pt2 v) {
        static const double TAU = 4 * acos(0);
        auto ang = std::atan2(cross(u, v), dot(u, v));
        return ang < 0 ? ang + TAU : ang;
    }
};

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int N;
    cin >> N;

    vector<Pt2> pts(N);
    for (int i = 0; i < N; i++) {
        cin >> pts[i];
    }

    auto uni = pts;
    sort(begin(uni), end(uni));
    uni.erase(unique(begin(uni), end(uni)), end(uni));

    int S = uni.size();
    vector<int> index(N);
    for (int i = 0; i < N; i++) {
        index[i] = lower_bound(begin(uni), end(uni), pts[i]) - begin(uni);
    }

    const array<Pt2, 4> dds = {Pt2(1, 0), Pt2(0, 1), Pt2(-1, 0), Pt2(0, -1)};

    map<Pt2, int> ptset;
    for (int i = 0; i < S; i++) {
        ptset.emplace(uni[i], i);
    }

    vector<vector<int>> graph(5 * S);
    for (int i = 0; i < S; i++) {
        for (auto dp : dds) {
            int j = ptset.emplace(uni[i] + dp, ptset.size()).first->second;
            graph[j].push_back(i);
        }
    }

    int M = ptset.size();

    const Pt2 inf = Pt2(INT_MAX, INT_MAX);
    vector<Pt2> orig(M, inf);
    vector<int> bfs(M - S);

    iota(begin(bfs), end(bfs), S);
    for (auto [p, i] : ptset) {
        if (i >= S) {
            orig[i] = p;
        }
    }

    for (int i = 0; i < M; i++) {
        int u = bfs[i];
        for (int v : graph[u]) {
            if (orig[v] == inf) {
                orig[v] = orig[u];
                bfs.push_back(v);
            }
        }
    }

    for (int i = 0; i < N; i++) {
        cout << orig[index[i]] << '\n';
    }

    return 0;
}