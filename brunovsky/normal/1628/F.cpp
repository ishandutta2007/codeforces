#include <bits/stdc++.h>
#ifdef LOCAL
#include "code/formatting.hpp"
#else
#define debug(...) (void)0
#endif

using namespace std;

struct Pt2 {
    using T = int32_t; // points, vectors, coefs, manh -- integer/frac/quot
    using L = int32_t; // crosses, dotes, dist2, norm2 -- integer/frac/quot
    using H = int64_t; // huge (circle predicates) -- int128/double
    static constexpr bool FLOAT = false;

    T x, y;
    Pt2() : x(0), y(0) {}
    Pt2(T x, T y) : x(x), y(y) {}

    auto paired() const { return make_pair(x, y); }
    friend bool operator==(Pt2 a, Pt2 b) { return a.paired() == b.paired(); }
    friend bool operator!=(Pt2 a, Pt2 b) { return a.paired() != b.paired(); }
    friend bool operator<(Pt2 a, Pt2 b) { return a.paired() < b.paired(); }
    friend bool operator>(Pt2 a, Pt2 b) { return a.paired() > b.paired(); }

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
};

int quadrant(Pt2 u) {
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

int directed_quadrant(Pt2 u, Pt2 forward) {
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

bool angle_sort(Pt2 u, Pt2 v) {
    int qu = quadrant(u), qv = quadrant(v);
    if (qu != qv) {
        return qu < qv;
    } else if (auto cuv = cross(u, v)) {
        return cuv > 0;
    } else {
        return norm2(u) < norm2(v);
    }
}

bool biangle_sort(Pt2 u, Pt2 v) {
    return angle_sort(quadrant(u) < 3 ? u : -u, quadrant(v) < 3 ? v : -v);
}

auto angle_sorter(Pt2 pivot, Pt2 forward = Pt2(1, 0)) {
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

auto line_sorter(Pt2 along = Pt2(1, 0)) {
    assert(along);
    return [=](Pt2 u, Pt2 v) -> bool {
        if (auto duv = dot(v - u, along)) {
            return duv > 0;
        } else {
            return cross(v - u, along) > 0;
        }
    };
}

struct Ray {
    Pt2 p, d; // p + dt

    static Ray ray(Pt2 point, Pt2 dt) { return Ray{point, dt}; }
    static Ray slope(Pt2 dt) { return Ray{Pt2(), dt}; }
    static Ray through(Pt2 u, Pt2 v) { return Ray{u, v - u}; }
    static Ray halfplane(Pt2 point, Pt2 normal) { return Ray{point, perp_cw(normal)}; }

    auto operator-() const { return Ray{p + d, -d}; }
    auto q() const { return p + d; }

    friend bool operator==(Ray u, Ray v) { return u.p == v.p && u.d == v.d; }
    friend bool operator!=(Ray u, Ray v) { return u.p != v.p || u.d != v.d; }

    friend auto signed_linedist(Pt2 u, Ray l) { return signed_linedist(u, l.p, l.q()); }
    friend auto linedist(Pt2 u, Ray l) { return linedist(u, l.p, l.q()); }
    friend auto raydist(Pt2 u, Ray l) { return raydist(u, l.p, l.q()); }
    friend auto segdist(Pt2 u, Ray l) { return segdist(u, l.p, l.q()); }
    friend int orientation(Pt2 u, Ray l) { return orientation(l.p, l.q(), u); }

    // +2=> left; +1=> <=line.p on ray; 0=> on segment; -1=> >=line.q on ray; -2=> right
    friend int fiveway_orientation(Pt2 u, const Ray& line, int positive_side = +1) {
        if (int side = orientation(u, line)) {
            return positive_side > 0 ? 2 * side : -2 * side;
        } else {
            auto dup = dot(line.d, line.p - u), dqu = dot(line.d, u - line.q());
            return (dup >= 0) - (dqu >= 0);
        }
    }

    // Which line, a or b, intersects l first? Return true if a intersects first
    // If a or b is parallel to l, the answer is always false
    bool isect_compare_unsafe(Ray a, Ray b) const {
        // a hits at (an/ad)l.d, while b hits at (bn/bd)l.d
        auto an = cross(a.p - p, a.d), ad = cross(d, a.d);
        auto bn = cross(b.p - p, b.d), bd = cross(d, b.d);
        auto diff = an * bd - bn * ad;
        return (ad > 0) == (bd > 0) ? diff < 0 : diff > 0;
    }

    // Let w be the projection of u on this line, find k such that w=p+kd
    double coef(Pt2 u) const { return double(dot(u - p, d)) / norm2(d); }
};

struct live_sweep_scanner {
    using is_transparent = bool;

    Pt2 forward;

    explicit live_sweep_scanner(Pt2 forward) : forward(forward) { assert(forward); }

    bool operator()(const Ray& u, const Ray& v) const {
        if (auto duv = dot(u.p - v.p, forward); duv == 0) {
            if (auto cuv = cross(v.p - u.p, forward)) {
                return cuv > 0;
            }
        } else if (duv < 0) {
            if (auto cuv = cross(v.p - u.p, u.d)) {
                return cuv > 0;
            } // falls through if v.p lies on u
        } else if (duv > 0) {
            if (auto cuv = cross(v.d, u.p - v.p)) {
                return cuv > 0;
            } // falls through if u.p lies on v
        }
        return cross(u.d, v.d) < 0;
    }

    bool operator()(const Pt2& p, const Ray& v) const {
        if (auto cvp = cross(v.d, p - v.p)) {
            return cvp > 0;
        } else {
            return dot(v.d, v.p - p) > 0;
        }
    }

    bool operator()(const Ray& u, const Pt2& p) const {
        if (auto cud = cross(u.d, p - u.p)) {
            return cud < 0;
        } else {
            return dot(u.d, u.q() - p) < 0;
        }
    }

    bool sweep_compare(const Pt2& a, const Pt2& b) const { // rank[a] <=> rank[b]
        if (auto ab = dot(b - a, forward)) {
            return ab > 0;
        } else {
            return cross(b - a, forward) > 0;
        }
    }

    // Return true if the ray u is correctly oriented, and sweep hits u.p before u.q
    bool oriented(const Ray& u) const { return sweep_compare(u.p, u.q()); }

    // Return true if the sweep simultaneously stabs u and v at some point
    bool stabs(const Ray& u, const Ray& v) const {
        return sweep_compare(u.p, v.q()) && sweep_compare(v.p, u.q());
    }
};

struct live_angle_scanner {
    using is_transparent = bool;

    Pt2 pivot;

    explicit live_angle_scanner(Pt2 pivot = Pt2()) : pivot(pivot) {}

    bool operator()(const Ray& u, const Ray& v) const {
        // <0: u first; >0: v first; =0: same scanline
        if (auto sign = cross(pivot, v.p, u.p); sign == 0) {
            assert(samedir(u.p - pivot, v.p - pivot));
            if (auto nuv = norm2(u.p) - norm2(v.p)) {
                return nuv < 0;
            }
        } else if (sign < 0) {
            if (auto cuv = cross(v.p - u.p, u.d)) {
                return cuv > 0;
            } else {
                return cross(u.d, v.d) < 0;
            }
        } else if (sign > 0) {
            if (auto cuv = cross(v.d, u.p - v.p)) {
                return cuv > 0;
            } else {
                return cross(u.d, v.d) < 0;
            }
        }
        return cross(u.d, v.d) < 0;
    }

    bool operator()(const Pt2& p, const Ray& v) const {
        int side = fiveway_orientation(p, v);
        return side >= +1 || p == v.p;
    }

    bool operator()(const Ray& u, const Pt2& p) const {
        int side = fiveway_orientation(p, u);
        return side <= -1 || p == u.q();
    }

    // Return true if the sweep travels less from u to v than from v to u
    bool sweep_shorter(Pt2 a, Pt2 b) const {
        if (auto cuv = cross(pivot, a, b)) {
            return cuv > 0;
        } else {
            return dot(a - pivot, b - a) > 0;
        }
    }

    // Return true if the ray u is correctly oriented
    bool oriented(const Ray& ray) const { return sweep_shorter(ray.p, ray.q()); }

    // Return true if the sweep simultaneously stabs u and v at some point
    // Use this if you do not group stabs, i.e. process the endpoints one by one.
    bool stabs(const Ray& u, const Ray& v) const {
        if (sweep_shorter(u.p, v.p)) {
            return sweep_shorter(v.p, u.q());
        } else if (sweep_shorter(v.p, u.p)) {
            return sweep_shorter(u.p, v.q());
        } else {
            return u.p == v.p;
        }
    }
};

bool valid_drop_angle(Pt2 ray, Pt2 drop) {
    auto d = dot(drop, ray), c = cross(drop, ray);
    return d > 0 && d > abs(c);
}

int mateof(int i) { return i ^ 1; }
int segmentof(int i) { return i / 2; }
int head(int s) { return 2 * s; }
int tail(int s) { return 2 * s + 1; }

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int S;
    cin >> S;
    int N = 2 * S;

    vector<Pt2> pts(N);
    vector<Ray> rays(S);

    map<Ray, int, live_angle_scanner> shafts;
    const auto& scanner = shafts.key_comp();

    for (int s = 0; s < S; s++) {
        int u = head(s), v = tail(s);
        cin >> pts[u] >> pts[v];
        if (!scanner.oriented(Ray::through(pts[u], pts[v]))) {
            swap(pts[u], pts[v]);
        }
        rays[s] = Ray::through(pts[u], pts[v]);
    }

    int Q;
    cin >> Q;
    pts.resize(N + Q);
    for (int i = 0; i < Q; i++) {
        cin >> pts[i + N];
    }

    vector<int> order(N + Q);
    iota(begin(order), end(order), 0);
    sort(begin(order), end(order),
         [&](int i, int j) { return angle_sort(pts[i], pts[j]); });

    vector<int> rank(N + Q);
    for (int i = 0; i < N + Q; i++) {
        rank[order[i]] = i;
    }

    for (int s = 0; s < S; s++) {
        if (rank[head(s)] > rank[tail(s)]) {
            shafts.emplace(rays[s], s);
        }
    }

    vector<vector<int>> scans;
    for (int i : order) {
        if (scans.empty() || !samedir(pts[scans.back().back()], pts[i])) {
            scans.push_back({i});
        } else {
            scans.back().push_back(i);
        }
    }

    vector<pair<Pt2, int>> downs;
    vector<int8_t> ans(Q);

    for (const auto& scan : scans) {
        for (int i : scan) {
            if (i < N) {
                int s = segmentof(i);
                if (i == head(s)) {
                    shafts.emplace(rays[s], s);
                }
            }
        }

        for (int i : scan) {
            if (i >= N) {
                auto above = shafts.upper_bound(pts[i]);
                if (above == shafts.begin()) {
                    ans[i - N] = true;
                }
            } else {
                int s = segmentof(i), j = mateof(i);
                auto u = pts[i], v = pts[j];

                if (s == shafts.begin()->second) {
                    if (valid_drop_angle(u - v, -u)) {
                        downs.push_back({-u, s});
                    }
                }
            }
        }

        for (int i : scan) {
            if (i < N) {
                int s = segmentof(i);
                if (i == tail(s)) {
                    shafts.erase(rays[s]);
                }
            }
        }
    }

    debug(downs);
    debug(ans);

    for (auto [dir, source] : downs) {
        live_sweep_scanner sweeper(perp_ccw(dir));
        map<Ray, int, live_sweep_scanner> sweep(sweeper);

        for (int s = 0; s < S; s++) {
            if (!sweeper.oriented(rays[s])) {
                swap(pts[head(s)], pts[tail(s)]);
                rays[s] = Ray::through(pts[head(s)], pts[tail(s)]);
            }
        }

        auto sorter = line_sorter(perp_ccw(dir));
        sort(begin(order), end(order),
             [&](int i, int j) { return sorter(pts[i], pts[j]); });

        using iterator = map<Ray, int, live_sweep_scanner>::iterator;
        vector<iterator> its(S);

        vector<vector<int>> groups;
        for (int i : order) {
            if (groups.empty() || cross(dir, pts[i] - pts[groups.back().back()])) {
                groups.push_back({i});
            } else {
                groups.back().push_back(i);
            }
        }

        vector<vector<int>> prev(S);

        for (const auto& group : groups) {
            for (int i : group) {
                if (i < N) {
                    int s = segmentof(i);
                    auto u = pts[i], v = pts[mateof(i)];
                    if (sorter(u, v)) {
                        bool ok;
                        tie(its[s], ok) = sweep.emplace(rays[s], s);
                        assert(ok);
                    }
                }
            }

            for (int i : group) {
                if (i >= N) {
                    auto seg = sweep.upper_bound(pts[i]);
                    if (seg != sweep.end()) {
                        prev[seg->second].push_back(i);
                    }
                } else {
                    int s = segmentof(i);
                    auto u = pts[i], v = pts[mateof(i)];

                    if (valid_drop_angle(u - v, dir)) {
                        auto seg = next(its[s]);
                        if (seg != sweep.end()) {
                            prev[seg->second].push_back(s);
                        }
                    }
                }
            }

            for (int i : group) {
                if (i < N) {
                    int s = segmentof(i);
                    auto u = pts[i], v = pts[mateof(i)];
                    if (!sorter(u, v)) {
                        sweep.erase(its[s]);
                    }
                }
            }
        }
        assert(sweep.empty());

        vector<int> bfs = {source};

        for (int j = 0, B = 1; j < B; j++) {
            int u = bfs[j];
            for (int v : prev[u]) {
                if (v >= N) {
                    ans[v - N] = true;
                } else {
                    bfs.push_back(v), B++;
                }
            }
        }
    }

    for (int q = 0; q < Q; q++) {
        cout << (ans[q] ? "YES\n" : "NO\n");
    }
    return 0;
}