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

    friend string to_string(Pt2 p) {
        return '(' + to_string(p.x) + ',' + to_string(p.y) + ')';
    }
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

    friend int quadrant(Pt2 u) {
        if (u.x > 0 && u.y >= 0) {
            return 1;
        } else if (u.x <= 0 && u.y > 0) {
            return 2;
        } else if (u.x < 0 && u.y <= 0) {
            return 3;
        } else if (u.x >= 0 && u.y < 0) {
            return 4;
        } else {
            return 0;
        }
    }

    friend int directed_quadrant(Pt2 u, Pt2 forward) {
        auto x = dot(forward, u), y = cross(forward, u);
        if (x > 0 && y >= 0) {
            return 1;
        } else if (x <= 0 && y > 0) {
            return 2;
        } else if (x < 0 && y <= 0) {
            return 3;
        } else if (x >= 0 && y < 0) {
            return 4;
        } else {
            return 0;
        }
    }

    friend bool angle_sort(Pt2 u, Pt2 v) {
        int qu = quadrant(u), qv = quadrant(v);
        if (qu != qv) {
            return qu < qv;
        } else if (auto cuv = cross(u, v)) {
            return cuv > 0;
        } else {
            return norm2(u) < norm2(v);
        }
    }

    friend bool biangle_sort(Pt2 u, Pt2 v) {
        return angle_sort(quadrant(u) < 3 ? u : -u, quadrant(v) < 3 ? v : -v);
    }

    friend auto angle_sorter(Pt2 pivot, Pt2 forward = Pt2(1, 0)) {
        assert(forward);
        return [=](Pt2 u, Pt2 v) -> bool {
            u -= pivot, v -= pivot;
            int qu = directed_quadrant(u, forward), qv = directed_quadrant(v, forward);
            if (qu != qv) {
                return qu < qv;
            } else if (auto cuv = cross(u, v)) {
                return cuv > 0;
            } else {
                return norm2(u) < norm2(v);
            }
        };
    }

    friend auto biangle_sorter(Pt2 pivot, Pt2 forward = Pt2(1, 0)) {
        assert(forward);
        return [=](Pt2 u, Pt2 v) -> bool {
            u -= pivot, v -= pivot;
            int qu = directed_quadrant(u, forward), qv = directed_quadrant(v, forward);
            if (qu >= 3)
                qu -= 2, u = -u;
            if (qv >= 3)
                qv -= 2, v = -v;
            if (qu != qv) {
                return qu < qv;
            } else if (auto cuv = cross(u, v)) {
                return cuv > 0;
            } else {
                return norm2(u) < norm2(v);
            }
        };
    }

    friend auto line_sorter(Pt2 along = Pt2(1, 0)) {
        assert(along);
        return [=](Pt2 u, Pt2 v) -> bool {
            if (auto duv = dot(v - u, along)) {
                return duv > 0;
            } else {
                return cross(v - u, along) < 0;
            }
        };
    }
};

template <typename Fn>
void all_point_pairs_radial_sweep(const vector<Pt2>& pts, Fn&& processor) {
    int N = pts.size();
    assert(N <= 30'000); // sanity check - we need O(N^2) memory

    vector<int> order(N);
    iota(begin(order), end(order), 0);
    sort(begin(order), end(order), [&](int u, int v) { return pts[u] < pts[v]; });

    vector<int> rank(N);
    for (int i = 0; i < N; i++) {
        rank[order[i]] = i;
    }

    int S = N * (N - 1) / 2;
    vector<array<int, 2>> slopes(S);
    for (int k = 0, i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++, k++) {
            slopes[k] = {order[i], order[j]};
        }
    }
    sort(begin(slopes), end(slopes), [&](const auto& u, const auto& v) {
        const auto &a = pts[u[0]], b = pts[u[1]], c = pts[v[0]], d = pts[v[1]];
        if (auto cuv = cross(b - a, d - c)) {
            return cuv > 0; // different slopes
        } else if (a != c) {
            return make_pair(a.x, a.y) < make_pair(c.x, c.y);
        } else {
            return make_pair(b.x, b.y) < make_pair(d.x, d.y);
        }
    });

    for (int i = 0; i < S; i++) {
        auto [u, v] = slopes[i];
        int a = rank[u], b = rank[v];
        if (a > b) {
            swap(a, b);
            swap(u, v);
        }
        assert(a + 1 == b);
        processor(order, a, u, v);
        swap(order[a], order[b]);
        swap(rank[u], rank[v]);
    }
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int N;
    int64_t S;
    cin >> N >> S;
    S *= 2;
    vector<Pt2> pts(N);
    for (int i = 0; i < N; i++) {
        cin >> pts[i];
    }
    auto area = [&](int u, int v, int w) { return abs(cross(pts[u], pts[v], pts[w])); };
    auto answer = [&](int u, int v, int w) {
        cout << "Yes\n";
        cout << pts[u].x << ' ' << pts[u].y << '\n';
        cout << pts[v].x << ' ' << pts[v].y << '\n';
        cout << pts[w].x << ' ' << pts[w].y << '\n';
        exit(0);
    };
    all_point_pairs_radial_sweep(pts, [&](auto& order, int i, int u, int v) -> void {
        {
            int L = -1, R = i;
            while (L + 1 < R) {
                int M = (L + R) / 2;
                int w = order[M];
                if (auto A = area(u, v, w); A == S) {
                    answer(u, v, w);
                } else if (A < S) {
                    R = M;
                } else {
                    L = M;
                }
            }
        }
        {
            int L = i, R = N;
            while (L + 1 < R) {
                int M = (L + R) / 2;
                int w = order[M];
                if (auto A = area(u, v, w); A == S) {
                    answer(u, v, w);
                } else if (A < S) {
                    L = M;
                } else {
                    R = M;
                }
            }
        }
    });
    cout << "No\n";
    return 0;
}