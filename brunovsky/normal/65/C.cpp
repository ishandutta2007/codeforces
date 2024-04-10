#include <bits/stdc++.h>
#ifdef LOCAL
#include "code/formatting.hpp"
#else
#define debug(...) (void)0
#endif

using namespace std;
#define long int64_t
static_assert(sizeof(int) == 4 && sizeof(long) == 8);

struct Point3d {
    double x, y, z;
    constexpr Point3d() : x(0), y(0), z(0) {}
    constexpr Point3d(double x, double y, double z) : x(x), y(y), z(z) {}
    constexpr Point3d(const array<double, 3>& a) : x(a[0]), y(a[1]), z(a[2]) {}

    using P = Point3d;
    static constexpr double inf = numeric_limits<double>::infinity();
    static constexpr double deps = 30 * numeric_limits<double>::epsilon();

    static constexpr P zero() { return P(0, 0, 0); }
    static constexpr P one() { return P(1, 1, 1); }
    static constexpr P pinf() { return P(inf, inf, inf); }

    friend bool same(const P& a, const P& b, double eps = deps) {
        return dist(a, b) <= max(a.manhattan(), b.manhattan()) * eps;
    }
    bool operator==(const P& b) const { return same(*this, b); }
    bool operator!=(const P& b) const { return !same(*this, b); }
    explicit operator bool() const noexcept { return *this != zero(); }

    P operator-() const { return P(-x, -y, -z); }
    P operator+(const P& u) const { return P(x + u.x, y + u.y, z + u.z); }
    P operator-(const P& u) const { return P(x - u.x, y - u.y, z - u.z); }
    friend P operator*(double k, const P& u) { return P(k * u.x, k * u.y, k * u.z); }
    P operator*(double k) const { return P(k * x, k * y, k * z); }
    P operator/(double k) const { return P(x / k, y / k, z / k); }
    friend P& operator+=(P& u, const P& v) { return u = u + v; }
    friend P& operator-=(P& u, const P& v) { return u = u - v; }
    friend P& operator*=(P& u, double k) { return u = u * k; }
    friend P& operator/=(P& u, double k) { return u = u / k; }

    P& normalize() { return *this /= norm(); }
    P unit() const { return *this / norm(); }
    double norm() const { return dist(*this); }
    double norm2() const { return dist2(*this); }
    friend auto dot(const P& u, const P& v) { return u.x * v.x + u.y * v.y + u.z * v.z; }
    friend auto dot2(const P& u, const P& v) { return dot(u, v) * dot(u, v); }
    friend double dist(const P& u) { return std::sqrt(dist2(u)); }
    friend double dist(const P& a, const P& b) { return std::sqrt(dist2(a, b)); }
    friend double dist2(const P& u) { return dot(u, u); }
    friend double dist2(const P& a, const P& b) { return dist2(a - b); }
    double manhattan() const { return abs(x) + abs(y) + abs(z); }
    friend double manhattan(const P& a, const P& b) { return (a - b).manhattan(); }
    friend P abs(const P& u) { return P(abs(u.x), abs(u.y), abs(u.z)); }

    P cross(const P& a, const P& b) const { return crossed(a - *this, b - *this); }
    friend P crossed(const P& u, const P& v) {
        return P(u.y * v.z - u.z * v.y, u.z * v.x - u.x * v.z, u.x * v.y - u.y * v.x);
    }
    P normal(const P& a, const P& b) const { return cross(a, b).unit(); }
    friend P normal(const P& u, const P& v) { return crossed(u, v).unit(); }

    friend P interpolate(const P& a, const P& b, double k) { return a + (b - a) * k; }

    friend string to_string(const P& a) {
        return '(' + to_string(a.x) + ',' + to_string(a.y) + ',' + to_string(a.z) + ')';
    }
    friend ostream& operator<<(ostream& out, const P& a) {
        return out << a.x << ' ' << a.y << ' ' << a.z;
    }
    friend istream& operator>>(istream& in, P& a) { return in >> a.x >> a.y >> a.z; }
};

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    cout << setprecision(10) << fixed << showpoint;
    int N;
    cin >> N;
    vector<Point3d> points(N + 1);
    for (Point3d& p : points) {
        cin >> p;
    }
    double vp, vs; // velocity potter, snitch
    cin >> vp >> vs;
    Point3d start;
    cin >> start;
    if (start == points[0]) {
        cout << "YES\n0\n" << start << endl;
        return 0;
    }
    double time = 0;
    for (int i = 0; i < N; i++) {
        double relay_distance = dist(points[i], points[i + 1]);
        double relay_duration = relay_distance / vs;
        double relay_end_time = time + relay_duration;
        double travel_end_time = dist(start, points[i + 1]) / vp;
        if (travel_end_time <= relay_end_time + 1000 * Point3d::deps) {
            // binary search the answer
            double L = 0, R = 1;
            while (abs(R - L) >= Point3d::deps) {
                double M = (L + R) / 2;
                Point3d middle = interpolate(points[i], points[i + 1], M);
                double relay_middle_time = time + relay_distance * M / vs;
                double travel_middle_time = dist(start, middle) / vp;
                if (travel_middle_time <= relay_middle_time) {
                    R = M;
                } else {
                    L = M;
                }
            }
            double M = (L + R) / 2;
            Point3d middle = interpolate(points[i], points[i + 1], M);
            double relay_middle_time = time + relay_distance * M / vs;
            cout << "YES\n";
            cout << relay_middle_time << '\n';
            cout << middle << '\n';
            return 0;
        }
        time = relay_end_time;
    }
    cout << "NO\n";
    return 0;
}