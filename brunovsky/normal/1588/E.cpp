#include <bits/stdc++.h>
#ifdef LOCAL
#include "code/formatting.hpp"
#else
#define debug(...) (void)0
#endif

using namespace std;

struct P {
    using T = int32_t;    // points, vectors, coefs, manh -- integer or frac
    using L = int64_t;    // cross, dot, dist2, norm2 -- integer or frac
    using H = __int128_t; // huge: delaunay. if L=int128, just use (long) double here
    using D = double;     // dist, norm, angles -- float

    T x, y;
    int id = -1;

    P() : x(0), y(0) {}
    P(T x, T y) : x(x), y(y) {}
    // P(T x, T y, int id) : x(x), y(y), id(id) {}

    auto paired() const { return make_pair(x, y); }
    friend bool operator==(P a, P b) { return a.x == b.x && a.y == b.y; }
    friend bool operator!=(P a, P b) { return !(a == b); }
    friend bool operator<(P a, P b) { return a.paired() < b.paired(); }

    explicit operator bool() const noexcept { return x || y; }

    bool boxed(P min, P max) const {
        return min.x <= x && x <= max.x && min.y <= y && y <= max.y;
    }
    friend P clamp(P p, P min, P max) {
        return P(clamp(p.x, min.x, max.x), clamp(p.y, min.y, max.y));
    }

    T& operator[](int i) { return *(&x + i); }
    T operator[](int i) const { return *(&x + i); }
    P operator-() const { return P(-x, -y); }
    P operator+() const { return P(x, y); }
    friend P operator+(P u, P v) { return P(u.x + v.x, u.y + v.y); }
    friend P operator-(P u, P v) { return P(u.x - v.x, u.y - v.y); }
    friend P operator*(T k, P u) { return P(u.x * k, u.y * k); }
    friend P operator*(P u, T k) { return P(u.x * k, u.y * k); }
    friend P operator/(P u, T k) { return P(u.x / k, u.y / k); }
    friend P& operator+=(P& u, P v) { return u = u + v; }
    friend P& operator-=(P& u, P v) { return u = u - v; }
    friend P& operator*=(P& u, T k) { return u = u * k; }
    friend P& operator/=(P& u, T k) { return u = u / k; }

    friend auto refl(P u) { return P(u.y, u.x); }
    friend auto conj(P u) { return P(u.x, -u.y); } // complex conjugate
    friend auto perp_ccw(P u) { return P(-u.y, u.x); }
    friend auto perp_cw(P u) { return P(u.y, -u.x); }

    friend auto int_norm(P u) { return gcd(u.x, u.y); }
    friend auto int_unit(P u) { return u ? u / int_norm(u) : u; }

    friend auto norm2(P u) { return L(u.x) * u.x + L(u.y) * u.y; }
    friend auto norm(P u) { return std::sqrt(D(norm2(u))); }

    friend auto manh(P u) { return abs(u.x) + abs(u.y); }
    friend auto manh(P a, P b) { return manh(a - b); }
    friend auto abs(P u) { return P(abs(u.x), abs(u.y)); }

    friend auto dot(P u, P v) { return L(u.x) * v.x + L(u.y) * v.y; }
    auto dot(P a, P b) const { return L(a.x - x) * (b.x - x) + L(a.y - y) * (b.y - y); }

    friend auto cross(P u, P v) { return L(u.x) * v.y - L(u.y) * v.x; }
    auto cross(P a, P b) const { return L(a.x - x) * (b.y - y) - L(a.y - y) * (b.x - x); }

    friend auto dist2(P a, P b) { return norm2(a - b); }
    friend auto dist(P a, P b) { return norm(a - b); }

    friend P interpolate(P a, P b, T k) { return a + (b - a) * k; }

    friend string to_string(P p) {
        return '(' + to_string(p.x) + ',' + to_string(p.y) + ')';
        // return to_string(p.x) + ' ' + to_string(p.y);
    }
    friend ostream& operator<<(ostream& out, P p) { return out << to_string(p); }
    friend istream& operator>>(istream& in, P& p) { return in >> p.x >> p.y; }
};

// ***** LINES, RAYS AND SEGMENTS

bool parallel(P u, P v) { return cross(u, v) == 0; }
bool samedir(P u, P v) { return cross(u, v) == 0 && dot(u, v) >= 0; }
bool collinear(P a, P b, P c) { return a.cross(b, c) == 0; }

// points are collinear in this order (b lies in [ac])
bool onsegment(P a, P b, P c) { return a.cross(b, c) == 0 && b.dot(a, c) <= 0; }

// is p to the left (1), right (-1) or on the line u->v (as seen from u to v)?
int lineside(P p, P u, P v) {
    auto c = u.cross(v, p);
    return (c > 0) - (c < 0);
}

// distance of a to line uv
auto signed_linedist(P a, P u, P v) { return P::D(a.cross(u, v)) / dist(u, v); }
auto linedist(P a, P u, P v) { return abs(signed_linedist(a, u, v)); }

// distance of a to ray uv->
auto signed_raydist(P a, P u, P v) {
    if (u.dot(a, v) <= 0) {
        return lineside(a, u, v) * dist(a, u);
    } else {
        return signed_linedist(a, u, v);
    }
}
auto raydist(P a, P u, P v) {
    if (u.dot(a, v) <= 0) {
        return dist(a, u);
    } else {
        return linedist(a, u, v);
    }
}

// shortest distance from a to segment [uv]
auto signed_segmentdist(P a, P u, P v) {
    if (u.dot(a, v) <= 0) {
        return lineside(a, u, v) * dist(a, u);
    } else if (v.dot(a, u) <= 0) {
        return lineside(a, u, v) * dist(a, v);
    } else {
        return signed_linedist(a, u, v);
    }
}
auto segmentdist(P a, P u, P v) {
    if (u.dot(a, v) <= 0) {
        return dist(a, u);
    } else if (v.dot(a, u) <= 0) {
        return dist(a, v);
    } else {
        return linedist(a, u, v);
    }
}

struct Line {
    P p, d; // p + dt

    static Line ray(P point, P dt) { return Line{point, dt}; }
    static Line slope(P dt) { return Line{P(), dt}; }
    static Line through(P u, P v) { return Line::ray(u, v - u); }

    explicit operator bool() const { return d != P(); }
    array<P::T, 3> coef() const { return {d.y, -d.x, d.y * p.x - d.x * p.y}; }

    friend bool parallel(const Line& u, const Line& v) { return parallel(u.d, v.d); }
    friend bool samedir(const Line& u, const Line& v) { return samedir(u.d, v.d); }

    friend bool online(P u, const Line& l) { return parallel(u - l.p, l.d); }
    friend bool onray(P u, const Line& l) { return samedir(u - l.p, l.d); }
    friend bool onsegment(P u, const Line& l) { return onsegment(l.p, u, l.p + l.d); }

    friend auto signed_linedist(P u, const Line& l) {
        return signed_linedist(u, l.p, l.p + l.d);
    }
    friend auto linedist(P u, const Line& l) { return linedist(u, l.p, l.p + l.d); }
    friend auto signed_raydist(P u, const Line& l) {
        return signed_raydist(u, l.p, l.p + l.d);
    }
    friend auto raydist(P u, const Line& l) { return raydist(u, l.p, l.p + l.d); }
    friend auto signed_segmentdist(P u, const Line& l) {
        return signed_segmentdist(u, l.p, l.p + l.d);
    }
    friend auto segmentdist(P u, const Line& l) { return segmentdist(u, l.p, l.p + l.d); }
};

// ***** AREAS

template <typename O = P::D>
O oriented_area(P a, P b, P c) {
    return O(a.cross(b, c)) / O(2);
}
template <typename O = P::D>
O area(P a, P b, P c) {
    return abs(oriented_area(a, b, c));
}

auto two_oriented_area(const vector<P>& ps) {
    P::L ans = 0;
    for (int i = 0, N = ps.size(); i < N; i++) {
        const auto& u = i ? ps[i - 1] : ps[N - 1];
        const auto& v = ps[i];
        ans += P::L(u.x + v.x) * P::L(v.y - u.y);
    }
    return ans;
}
auto two_area(const vector<P>& ps) { return abs(two_oriented_area(ps)); }

// ***** SWEEPERS

// 4 3 2  loc[2][0,1,2]
// 5 0 1  loc[1][0,1,2]
// 6 7 8  loc[0][0,1,2]
// robust radial sort ccw, around the origin and starting at Ox, prefer smaller norms
// also a comparator for slopes
// modify the constants to change the ordering of the lines/quadrants
bool radial_sweep_sort(P u, P v) {
    static constexpr int loc[3][3] = {{6, 7, 8}, {5, 0, 1}, {4, 3, 2}};
    int scu = (u.y > 0) - (u.y < 0), scv = (v.y > 0) - (v.y < 0);
    int sdu = (u.x > 0) - (u.x < 0), sdv = (v.x > 0) - (v.x < 0);
    int lu = loc[1 + scu][1 + sdu];
    int lv = loc[1 + scv][1 + sdv];
    if (lu != lv) {
        return lu < lv;
    } else if (auto cuv = cross(u, v); cuv != 0) {
        return cuv > 0; // >0 ==> ccw in a quadrant; <0 ==> cw in a quadrant
    } else {
        return norm2(u) < norm2(v); // < => smaller norms first
    }
}

// 4 3 2  loc[2][0,1,2]
// 5 0 1  loc[1][0,1,2]  imagine direction ---> ccw=false will swap top and bottom rows
// 6 7 8  loc[0][0,1,2]
// a comparator for a pivoted cw/ccw radial sweep with a starting direction
auto radial_sweep_sorter(P pivot, P direction = P(1, 0), bool ccw = true) {
    static constexpr int loc[3][3] = {{6, 7, 8}, {5, 0, 1}, {4, 3, 2}};
    assert(direction != P());
    return [=](const P& u, const P& v) -> bool {
        auto cu = cross(direction, u - pivot), du = dot(direction, u - pivot);
        auto cv = cross(direction, v - pivot), dv = dot(direction, v - pivot);
        int scu = (cu > 0) - (cu < 0), scv = (cv > 0) - (cv < 0);
        int sdu = (du > 0) - (du < 0), sdv = (dv > 0) - (dv < 0);
        int lu = loc[ccw ? 1 + scu : 1 - scu][1 + sdu];
        int lv = loc[ccw ? 1 + scv : 1 - scv][1 + sdv];
        if (lu != lv) {
            return lu < lv;
        } else if (auto cuv = cross(u - pivot, v - pivot); cuv != 0) {
            return ccw ? cuv > 0 : cuv < 0;
        } else {
            return dist2(u, pivot) < dist2(v, pivot); // < => smaller norms first
        }
    };
}

// a comparator for a line sweep, break ties along ccw(normal) or cw(normal)
auto line_sweep_sorter(P along = P(1, 0), bool break_ties_ccw = true) {
    assert(along != P());
    return [=](const P& u, const P& v) -> bool {
        if (auto duv = dot(along, v - u); duv != 0) {
            return duv > 0;
        } else {
            auto cuv = cross(along, v - u);
            return break_ties_ccw ? cuv > 0 : cuv < 0;
        }
    };
}

// ***** ANGLES

auto cos(P u) { return clamp(P::D(u.x) / norm(u), P::D(-1), P::D(+1)); }
auto sin(P u) { return clamp(P::D(u.y) / norm(u), P::D(-1), P::D(+1)); }
auto angle(P u) { return std::atan2(P::D(u.y), P::D(u.x)); }

auto cos(P u, P v) { return P::D(dot(u, v)) / (norm(u) * norm(v)); }
auto sin(P u, P v) { return P::D(cross(u, v)) / (norm(u) * norm(v)); }
auto angle(P u, P v) { return std::acos(cos(u, v)); }

// is p inside angle <(u,v) ccw? 1=in, -1=out, 0=on u or v; needs radial_sweep_sorter
int angleside(P p, P u, P v) {
    if (samedir(p, u) || samedir(p, v)) {
        return 0;
    } else {
        return radial_sweep_sorter(P(), u)(p, v) ? +1 : -1;
    }
}

const double TAU = 2 * atan2(0, -1);

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int N;
    P::L radius;
    cin >> N >> radius;

    vector<P> pts(N);
    for (int i = 0; i < N; i++) {
        cin >> pts[i];
    }

    vector<vector<int8_t>> ok(N, vector<int8_t>(N));

    for (int i = 0; i < N; i++) {
        double low = 0, high = TAU;
        bool first_point = true, all_bad = false;

        for (int j = 0; j < N; j++) {
            auto center_dist = dist2(pts[i], pts[j]);
            auto point_power = center_dist - radius * radius;
            if (point_power <= 0) {
                continue;
            }

            double A = angle(pts[j] - pts[i]);
            double B = abs(acos(std::sqrt(1.0 * point_power / center_dist)));
            debug(A, B);
            assert(B < TAU / 2);

            if (A < 0) {
                A += TAU;
            }
            auto L = A - B;
            auto R = A + B;

            if (L < 0) {
                L += TAU;
                R += TAU;
            }
            if (first_point) {
                low = L, high = R;
                first_point = false;
                continue;
            }

            if (R < low) {
                L += TAU;
                R += TAU;
            }
            low = max(low, L);
            high = min(high, R);
            if (L > R) {
                all_bad = true;
                break;
            }
        }

        if (all_bad) {
            continue;
        }

        bool any_outside = !first_point;

        for (int j = 0; j < N; j++) {
            if (pts[i] == pts[j]) {
                ok[i][j] = !any_outside;
                continue;
            }
            double A = angle(pts[j] - pts[i]);

            if (A < low) {
                A += TAU;
            } else if (A > high) {
                A -= TAU;
            }
            if (low <= A && A <= high) {
                ok[i][j] = true;
            }
        }
    }

    int ans = 0;
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            ans += ok[i][j] && ok[j][i];
        }
    }
    cout << ans << '\n';
    return 0;
}

// Fix a pivot, solve it in O(N log N) in parallel while sorting other points radially
// We get a window of relevant points along RH(pts[u],pts[v])
// Need to count points within a rotated oriented bounding box
// And points within a distance of the centers
// Then do IE?