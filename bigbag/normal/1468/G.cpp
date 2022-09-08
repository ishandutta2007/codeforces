/**
 *  created: 25/12/2020, 16:23:33
**/

#include <bits/stdc++.h>

using namespace std;

typedef __int128 Int;
typedef long double Real;
const Real EPS = 0l, PI = acosl(-1); // [0; 1e-4]
constexpr bool NORMALIZE_FRACTION = true;

istream& operator >> (istream &is, __float128 &x) {
    long double y;
    is >> y;
    x = y;
    return is;
}

istream& operator >> (istream &is, __int128 &x) {
    long long y;
    is >> y;
    x = y;
    return is;
}

ostream& operator << (ostream &os, __float128 x) {
    long double y = x;
    os << y;
    return os;
}

ostream& operator << (ostream &os, __int128 x) {
    if (x < 0) {
        os << '-';
        x = -x;
    }
    if (x == 0) {
        os << '0';
    }
    string s;
    while (x) {
        s += '0' + x % 10;
        x /= 10;
    }
    reverse(s.begin(), s.end());
    os << s;
    return os;
}

__float128 abs(__float128 x) {
    return (x < 0 ? -x : x);
}

__int128 abs(__int128 x) {
    return (x < 0 ? -x : x);
}

Real max(Real x, Int y) {
    return (x < y ? y : x);
}

Real max(Int x, Real y) {
    return (x < y ? y : x);
}

Real min(Real x, Int y) {
    return (x < y ? x : y);
}

Real min(Int x, Real y) {
    return (x < y ? x : y);
}

bool is_less(Int x, Int y) {
    return x < y;
}

bool is_less(Int x, Real y) {
    return x + EPS < y;
    //return x + EPS * max(Real(1), max(Real(abs(x)), abs(y))) < y;
}

bool is_less(Real x, Int y) {
    return x + EPS < y;
    //return x + EPS * max(Real(1), max(abs(x), Real(abs(y)))) < y;
}

bool is_less(Real x, Real y) {
    return x + EPS < y;
    //return x + EPS * max(Real(1), max(abs(x), abs(y))) < y;
}

template<typename T1, typename T2>
bool is_equal(T1 x, T2 y) {
    return !is_less(x, y) && !is_less(y, x);
}

template<typename T1, typename T2>
bool is_less_equal(T1 x, T2 y) {
    return !is_less(y, x);
}

template<typename T>
struct Fraction {
    static const Int mod1 = 10000224369648808037LLU,
                     mod2 = 10000181636822014217LLU,
                     mod3 = 10000732729655599871LLU,
                     mod4 = 10000155984745642811LLU;

    T a, b;

    template<typename T2>
    Fraction(T2 x): a(x), b(1) {
    }

    template<typename T2, typename T3>
    Fraction(T2 x, T3 y): a(x), b(y) {
        assert(!is_equal(b, Int(0)));
        if (is_less(b, Int(0))) {
            a *= -1;
            b *= -1;
        }
        if (NORMALIZE_FRACTION) {
            Int g = __gcd(abs(a), abs(b));
            a /= g;
            b /= g;
        }
    }

    Fraction operator + (const Fraction &f) const {
        T g = __gcd(b, f.b);
        return {a * (f.b / g) + f.a * (b / g), b * (f.b / g)};
    }

    Fraction operator - (const Fraction &f) const {
        T g = __gcd(b, f.b);
        return {a * (f.b / g) - f.a * (b / g), b * (f.b / g)};
    }

    Fraction operator * (const Fraction &f) const {
        return {a * f.a, b * f.b};
    }

    template<typename T2>
    bool operator == (const Fraction<T2> &f) const {
        return mul(a, f.b, mod1) == mul(f.a, b, mod1) &&
               mul(a, f.b, mod2) == mul(f.a, b, mod2) &&
               mul(a, f.b, mod3) == mul(f.a, b, mod3) &&
               mul(a, f.b, mod4) == mul(f.a, b, mod4);
    }

    template<typename T2>
    bool operator != (const Fraction<T2> &f) const {
        return !(*this == f);
    }

    friend ostream& operator << (ostream &os, const Fraction &f) {
        os << f.a << "/" << f.b;
        return os;
    }

private:
    static Int mul(Int x, Int y, Int mod) {
        x %= mod;
        if (x < 0) {
            x += mod;
        }
        y %= mod;
        if (y < 0) {
            y += mod;
        }
        return x * y % mod;
    }
};

template<typename T>
struct Point {
    T x, y;

    Point(): x(0), y(0) {
    }

    Point(T x, T y): x(x), y(y) {
    }

    template<typename T2>
    Point(const Point<T2> &p): x(p.x), y(p.y) {
    }

    Point operator - () const {
        return {-x, -y};
    }

    Point operator - (const Point &p) const {
        return {x - p.x, y - p.y};
    }

    Point operator + (const Point &p) const {
        return {x + p.x, y + p.y};
    }

    Point operator * (T k) const {
        return {x * k, y * k};
    }

    template<typename T2>
    bool operator < (const Point<T2> &p) const {
        return is_less(x, p.x) || is_equal(x, p.x) && is_less(y, p.y);
    }

    template<typename T2>
    bool operator == (const Point<T2> &p) const {
        return is_equal(x, p.x) && is_equal(y, p.y);
    }

    template<typename T2>
    bool operator != (const Point<T2> &p) const {
        return !is_equal(x, p.x) || !is_equal(y, p.y);
    }

    T length_sqr() const {
        return x * x + y * y;
    }

    Real length() const {
        return sqrtl(length_sqr());
    }

    Real angle() const {
        Real res = atan2l(y, x);
        if (res < 0) {
            res += 2 * PI;
        }
        return res;
    }

    bool half() const {
        return (is_less(x, Int(0)) && is_less_equal(y, Int(0))) ||
               (is_less_equal(Int(0), x) && is_less(y, Int(0)));
    }

    Point<Real> normalized() const {
        auto len2 = length_sqr();
        assert(is_less(Int(0), len2));
        auto len = sqrtl(len2);
        return {x / len, y / len};
    }

    Point rotate90_ccw() const {
        return {-y, x};
    }

    Point rotate90_cw() const {
        return {y, -x};
    }

    friend istream& operator >> (istream &is, Point &p) {
        is >> p.x >> p.y;
        return is;
    }

    friend ostream& operator << (ostream &os, const Point &p) {
        os << "(" << p.x << " " << p.y << ")";
        return os;
    }
};

Point<Real> operator - (const Point<Int> &a, const Point<Real> &b) {
    return {a.x - b.x, a.y - b.y};
}

Point<Real> operator - (const Point<Real> &a, const Point<Int> &b) {
    return {a.x - b.x, a.y - b.y};
}

Point<Real> operator + (const Point<Int> &a, const Point<Real> &b) {
    return {a.x + b.x, a.y + b.y};
}

Point<Real> operator + (const Point<Real> &a, const Point<Int> &b) {
    return {a.x + b.x, a.y + b.y};
}

template<typename T>
Point<Fraction<T>> operator - (const Point<Int> &a, const Point<Fraction<T>> &b) {
    return {Fraction<T> (a.x) - b.x, Fraction<T> (a.y) - b.y};
}

template<typename T>
Point<Fraction<T>> operator - (const Point<Fraction<T>> &a, const Point<Int> &b) {
    return {a.x - Fraction<T> (b.x), a.y - Fraction<T> (b.y)};
}

template<typename T>
Point<Fraction<T>> operator + (const Point<Int> &a, const Point<Fraction<T>> &b) {
    return {Fraction<T> (a.x) + b.x, Fraction<T> (a.y) + b.y};
}

template<typename T1, typename T2>
Point<Real> operator / (const Point<T1> &a, T2 k) {
    return {a.x / Real(k), a.y / Real(k)};
}

template<typename T1, typename T2>
auto get_dist_sqr(const Point<T1> &a, const Point<T2> &b) {
    return (a - b).length_sqr();
}

template<typename T1, typename T2>
Real get_dist(const Point<T1> &a, const Point<T2> &b) {
    return (a - b).length();
}

template<typename T1, typename T2>
auto vector_product(const Point<T1> &a, const Point<T2> &b) {
    return a.x * b.y - a.y * b.x;
}

template<typename T1, typename T2>
auto dot_product(const Point<T1> &a, const Point<T2> &b) {
    return a.x * b.x + a.y * b.y;
}

template<typename T1, typename T2>
bool cw(const Point<T1> &a, const Point<T2> &b) {
    return is_less(vector_product(a, b), Int(0));
}

template<typename T1, typename T2>
bool ccw(const Point<T1> &a, const Point<T2> &b) {
    return is_less(Int(0), vector_product(a, b));
}

template<typename T1, typename T2, typename T3>
bool cw(const Point<T1> &a, const Point<T2> &b, const Point<T3> &c) {
    return cw(b - a, c - b);
}

template<typename T1, typename T2, typename T3>
bool ccw(const Point<T1> &a, const Point<T2> &b, const Point<T3> &c) {
    return ccw(b - a, c - b);
}

template<typename T1, typename T2>
Real get_angle(const Point<T1> &a, const Point<T2> &b) {
    Real c = dot_product(a, b) / a.length() / b.length();
    if (c < -1) {
        c = -1;
    }
    if (c > 1) {
        c = 1;
    }
    return acosl(c);
}

template<typename T1, typename T2>
bool cmp_by_angle(const Point<T1> &a, const Point<T2> &b) {
    const bool h1 = a.half(), h2 = b.half();
    if (h1 != h2) {
        return h1 < h2;
    }
    return ccw(a, b);
}

template<typename T>
struct Circle {
    Point<T> c;
    T r;

    Circle(): c(0, 0), r(0) {
    }

    Circle(T x, T y, T r): c(x, y), r(r) {
    }

    Circle(const Point<T> &c, T r): c(c), r(r) {
    }

    template<typename T2>
    bool contains_inside(const Point<T2> &p, bool strictly) const {
        auto d = get_dist_sqr(c, p);
        return (strictly && is_less(d, r * r)) ||
               (!strictly && is_less_equal(d, r * r));
    }

    template<typename T2>
    bool contains_on_border(const Point<T2> &p) const {
        return is_equal(get_dist(c, p), r);

        auto d = get_dist_sqr(c, p);
        return is_equal(d, r * r);
    }

    friend istream& operator >> (istream &is, Circle &c) {
        is >> c.c >> c.r;
        return is;
    }

    friend ostream& operator << (ostream &os, const Circle &c) {
        os << "(c = " << c.c << ", r = " << c.r << ")";
        return os;
    }
};

template<typename T>
struct Line {
    T A, B, C;

    Line(): A(0), B(0), C(0) {
    }

    Line(T A, T B, T C): A(A), B(B), C(C) {
    }

    Line(const Point<T> &a, const Point<T> &b) {
        A = a.y - b.y;
        B = b.x - a.x;
        C = -A * a.x - B * a.y;
    }

    template<typename T1>
    auto eval(const Point<T1> &p) const {
        return A * p.x + B * p.y + C;
    }

    template<typename T1>
    bool contains(const Point<T1> &p) const {
        auto val = eval(p);
        auto zero = val * 0;
        return is_equal(val, zero);
    }

    Point<T> normal_vector() const {
        return {A, B};
    }

    friend istream& operator >> (istream &is, Line &s) {
        is >> s.A >> s.B >> s.C;
        return is;
    }

    friend ostream& operator << (ostream &os, const Line &l) {
        os << "(" << l.A << " " << l.B << " " << l.C << ")";
        return os;
    }
};

template<typename T>
struct Segment {
    Point<T> a, b;

    Segment(): a(0, 0), b(0, 0) {
    }

    Segment(const Point<T> &a, const Point<T> &b): a(a), b(b) {
    }

    Line<T> get_line() const {
        return {a, b};
    }

    template<typename T1>
    bool contains_point_on_line(const Point<T1> &p, bool strictly) const { // p should be on the line this->get_line()
        return is_less_equal(min(a.x, b.x), p.x) && is_less_equal(p.x, max(a.x, b.x)) &&
               is_less_equal(min(a.y, b.y), p.y) && is_less_equal(p.y, max(a.y, b.y)) &&
               (!strictly ||
                (is_less(min(a.x, b.x), p.x) && is_less(p.x, max(a.x, b.x))) ||
                (is_less(min(a.y, b.y), p.y) && is_less(p.y, max(a.y, b.y))));
    }

    template<typename T1>
    bool contains(const Point<T1> &p, bool strictly) const {
        return get_line().contains(p) && contains_point_on_line(p, strictly);
    }

    auto length_sqr() const {
        return get_dist_sqr(a - b);
    }

    auto length() const {
        return get_dist(a, b);
    }

    friend istream& operator >> (istream &is, Segment &s) {
        is >> s.a >> s.b;
        return is;
    }

    friend ostream& operator << (ostream &os, const Segment &s) {
        os << "(" << s.a << " " << s.b << ")";
        return os;
    }
};

Line<Int> shift(const Line<Int> &l, const Point<Int> &p) {
    return {l.A, l.B, l.C - l.A * p.x - l.B * p.y};
}

Line<Real> shift(const Line<Int> &l, const Point<Real> &p) {
    return {l.A, l.B, l.C - l.A * p.x - l.B * p.y};
}

Line<Real> shift(const Line<Real> &l, const Point<Int> &p) {
    return {l.A, l.B, l.C - l.A * p.x - l.B * p.y};
}

Line<Real> shift(const Line<Real> &l, const Point<Real> &p) {
    return {l.A, l.B, l.C - l.A * p.x - l.B * p.y};
}

template<typename T1, typename T2>
Line<Real> get_angle_bisector(const Point<T1> &a, const Point<T2> &b) {
    return {Point<Real>(0, 0), a.normalized() + b.normalized()};
}

template<typename T1, typename T2>
Line<Real> get_segment_bisector(const Point<T1> &a, const Point<T2> &b) {
    auto mid = (a + b) / 2;
    auto dir = (b - a).rotate90_cw();
    return {mid, mid + dir};
}

template<typename T1, typename T2>
Line<Int> get_segment_bisector_precise(const Point<T1> &a, const Point<T2> &b) {
    assert((a.x + b.x) % 2 == 0);
    assert((a.y + b.y) % 2 == 0);
    Point<Int> mid((a.x + b.x) / 2, (a.y + b.y) / 2);
    Point<Int> dir(b.x - a.x, b.y - a.y);
    dir = dir.rotate90_cw();
    return {mid, mid + dir};
}

enum ObjectCount {
    ZERO, CONSTANT, INF
};

template<typename T1, typename T2>
Point<Real> get_intersection_with_tangent_private(T1 r, const Line<T2> &l) {
    auto len = l.A * l.A + l.B * l.B;
    Real x0 = -l.A * l.C / Real(len), y0 = -l.B * l.C / Real(len);
    return {x0, y0};
}

template<typename T1, typename T2>
vector<Point<Real>> get_intersection_private(T1 r, const Line<T2> &l) {
    auto len = l.A * l.A + l.B * l.B;
    if (is_less(r * r * len, l.C * l.C)) {
        return {};
    }
    Real x0 = -l.A * l.C / Real(len), y0 = -l.B * l.C / Real(len);
    if (is_equal(r * r * len, l.C * l.C)) {
        return {{x0, y0}};
    }
    Real d = r * r - l.C * l.C / Real(len);
    Real mult = sqrtl(d / Real(len));
    return {{x0 + l.B * mult, y0 - l.A * mult},
            {x0 - l.B * mult, y0 + l.A * mult}};
}

template<typename T1, typename T2>
vector<Point<Real>> get_intersection(const Circle<T1> &c, const Line<T2> &l) {
    auto res = get_intersection_private(c.r, shift(l, -c.c));
    for (auto &p : res) {
        p.x += c.c.x;
        p.y += c.c.y;
    }
    return res;
}

template<typename T1, typename T2>
bool intersect(const Circle<T1> &c, const Segment<T2> &s, bool strictly) {
    auto v = get_intersection(c, s.get_line());
    if (strictly && v.size() == 1) {
        return false;
    }
    for (const auto &p : v) {
        if (s.contains(p, strictly)) {
            return true;
        }
    }
    return false;
}

template<typename T1, typename T2>
pair<vector<Point<Real>>, ObjectCount> get_intersection(Circle<T1> c1, Circle<T2> c2) {
    if (c1.c == c2.c) {
        if (is_equal(c1.r, c2.r)) {
            return {{}, INF};
        }
        return {{}, ZERO};
    }
    auto x2 = c2.c.x - c1.c.x;
    auto y2 = c2.c.y - c1.c.y;
    auto A = -2 * x2;
    auto B = -2 * y2;
    auto C = x2 * x2 + y2 * y2 + c1.r * c1.r - c2.r * c2.r;
    auto res = get_intersection_private(c1.r, Line<Real> (A, B, C));
    for (auto &p : res) {
        p.x += c1.c.x;
        p.y += c1.c.y;
    }
    return {res, CONSTANT};
}

template<typename T1, typename T2, typename T3>
void get_common_tangents_private(const Point<T1> &c, T2 r1, T3 r2, vector<Line<Real>> &ans) {
    auto r = r2 - r1;
    auto z = c.length_sqr();
    auto d = z - r * r;
    if (is_less(d, Int(0))) {
        return;
    }
    if (d < 0) {
        d = 0;
    }
    Real sd = sqrtl(d);
    Line<Real> l;
    l.A = (c.x * r + c.y * sd) / z;
    l.B = (c.y * r - c.x * sd) / z;
    l.C = r1;
    ans.push_back(l);
}

template<typename T1, typename T2>
vector<Line<Real>> get_common_tangents(const Circle<T1> &a, const Circle<T2> &b) {
    vector<Line<Real>> res;
    for (int i = -1; i <= 1; i += 2) {
        for (int j = -1; j <= 1; j += 2) {
            get_common_tangents_private(b.c - a.c, a.r * i, b.r * j, res);
        }
    }
    for (auto &l : res) {
        l = shift(l, a.c);
    }
    return res;
}

template<typename T1, typename T2>
vector<Line<Real>> get_tangents(const Circle<T1> &a, const Point<T2> &p) {
    if (is_less(get_dist_sqr(p, a.c), a.r * a.r)) {
        return {};
    }
    int start = -1;
    if (is_equal(get_dist_sqr(p, a.c), a.r * a.r)) {
        start = 1;
    }
    vector<Line<Real>> res;
    for (int i = start; i <= 1; i += 2) {
        get_common_tangents_private(p - a.c, a.r * i, 0, res);
    }
    for (auto &l : res) {
        l = shift(l, a.c);
    }
    return res;
}

template<typename T1, typename T2>
vector<Point<Real>> get_tangent_points(const Circle<T1> &a, const Point<T2> &p) {
    if (is_less(get_dist_sqr(p, a.c), a.r * a.r)) {
        return {};
    }
    auto tangents = get_tangents(a, p);
    vector<Point<Real>> res;
    for (const auto &l : tangents) {
        res.push_back(get_intersection_with_tangent_private(a.r, shift(l, -a.c)) + a.c);
    }
    return res;
}

template<typename T>
T get_doubled_oriented_area(const vector<Point<T>> &a) {
    T res = 0;
    for (int i = 0; i < a.size(); ++i) {
        res += (a[(i + 1) % a.size()].x - a[i].x) * (a[i].y + a[(i + 1) % a.size()].y);
    }
    return res;
}

template<typename T>
T get_doubled_area(const vector<Point<T>> &a) {
    return abs(get_doubled_oriented_area(a));
}

template<typename T>
Real get_area(const vector<Point<T>> &a) {
    return get_doubled_area(a) / Real(2);
}

template<typename T>
Real get_perimeter(const vector<Point<T>> &a) {
    Real res = 0;
    for (int i = 0; i < a.size(); ++i) {
        res += get_dist(a[i], a[(i + 1) % a.size()]);
    }
    return res;
}

template<typename T1, typename T2>
Real get_oriented_dist(const Point<T1> &a, const Line<T2> &l) {
    return l.eval(a) / sqrtl(l.A * l.A + l.B * l.B);
}

template<typename T1, typename T2>
Real get_dist(const Point<T1> &a, const Line<T2> &l) {
    return abs(get_oriented_dist(a, l));
}

template<typename T1, typename T2>
Real get_dist(const Point<T1> &a, const Segment<T2> &s) {
    auto l = s.get_line();
    Real len = get_oriented_dist(a, l);
    auto p = a - l.normal_vector().normalized() * len;
    if (s.contains_point_on_line(p, false)) {
        return abs(len);
    }
    return min(get_dist(a, s.a), get_dist(a, s.b));
}

template<typename T1, typename T2>
bool intersect_1d(T1 l1, T1 r1, T2 l2, T2 r2, bool strictly) {
    if (r1 < l1) {
        swap(r1, l1);
    }
    if (r2 < l2) {
        swap(r2, l2);
    }
    return (strictly && is_less(max(l1, l2), min(r1, r2))) ||
           (!strictly && is_less_equal(max(l1, l2), min(r1, r2)));
}

template<typename T>
int get_sign(T x) {
    if (is_less(x, Int(0))) {
        return -1;
    }
    if (is_less(Int(0), x)) {
        return 1;
    }
    return 0;
}

template<typename T1, typename T2>
bool intersect(const Segment<T1> &a, const Segment<T2> &b, bool strictly) {
    if (!strictly) {
        return intersect_1d(a.a.x, a.b.x, b.a.x, b.b.x, strictly) &&
               intersect_1d(a.a.y, a.b.y, b.a.y, b.b.y, strictly) &&
               get_sign(vector_product(b.a - a.a, a.b - b.a)) * get_sign(vector_product(b.b - a.a, a.b - b.b)) <= 0 &&
               get_sign(vector_product(a.a - b.a, b.b - a.a)) * get_sign(vector_product(a.b - b.a, b.b - a.b)) <= 0;

    } else {
        assert(false); // not supported yet
    }
}

template<typename T1, typename T2>
Real get_dist(const Segment<T1> &a, const Segment<T2> &b) {
    if (intersect(a, b, false)) {
        return 0;
    }
    return min({get_dist(a.a, b),
               get_dist(a.b, b),
               get_dist(b.a, a),
               get_dist(b.b, a)});
}

template<typename T1, typename T2>
pair<Point<Real>, ObjectCount> get_intersection(const Line<T1> &l1, const Line<T2> &l2) {
    auto d = l1.A * l2.B - l1.B * l2.A;
    if (is_equal(d, Int(0))) {
        if (is_equal(l1.A * l2.C - l1.C * l2.A, Int(0)) &&
            is_equal(l1.B * l2.C - l1.C * l2.B, Int(0))) {
            return {{0, 0}, INF};
        }
        return {{0, 0}, ZERO};
    }
    Real x = l1.B * l2.C - l1.C * l2.B;
    Real y = -(l1.A * l2.C - l1.C * l2.A);
    return {{x / d, y / d}, CONSTANT};
}

template<typename T1, typename T2>
pair<Point<Fraction<Int>>, ObjectCount> get_intersection_precise(const Line<T1> &l1, const Line<T2> &l2) {
    Int d = l1.A * l2.B - l1.B * l2.A;
    if (is_equal(d, Int(0))) {
        if (is_equal(l1.A * l2.C - l1.C * l2.A, Int(0)) &&
            is_equal(l1.B * l2.C - l1.C * l2.B, Int(0))) {
            return {{0, 0}, INF};
        }
        return {{0, 0}, ZERO};
    }
    Int x = l1.B * l2.C - l1.C * l2.B;
    Int y = -(l1.A * l2.C - l1.C * l2.A);
    return {{{x, d}, {y, d}}, CONSTANT};
}

template<typename T1, typename T2, typename T3>
pair<Circle<Real>, bool> build_circle(const Point<T1> &a, const Point<T2> &b, const Point<T3> &c) {
    if (a == b || a == c || b == c) {
        return {{0, 0, 0}, false};
    }
    auto l1 = get_segment_bisector(a, b);
    auto l2 = get_segment_bisector(a, c);
    auto center = get_intersection(l1, l2);
    if (center.second != CONSTANT) {
        return {{0, 0, 0}, false};
    }
    return {{center.first, get_dist(center.first, a)}, true};
}

template<typename T1, typename T2, typename T3>
pair<Point<Fraction<Int>>, bool> build_circle_precise(const Point<T1> &a, const Point<T2> &b, const Point<T3> &c) {
    if (a == b || a == c || b == c) {
        return {{0, 0}, false};
    }
    auto l1 = get_segment_bisector_precise(a, b);
    auto l2 = get_segment_bisector_precise(a, c);
    auto center = get_intersection_precise(l1, l2);
    if (center.second != CONSTANT) {
        return {{0, 0}, false};
    }
    return {center.first, true};

}

template<typename T>
vector<Point<T>> convex_hull(vector<Point<T>> v) {
    if (v.size() <= 2) {
        return v;
    }
    sort(v.begin(), v.end());
    vector<Point<T>> up, down;
    for (const auto &p : v) {
        if (!ccw(v[0], p, v.back())) {
            while (up.size() >= 2 && !cw(up[up.size() - 2], up.back(), p)) {
                up.pop_back();
            }
            up.push_back(p);
        }
    }
    for (const auto &p : v) {
        if (!cw(v[0], p, v.back())) {
            while (down.size() >= 2 && !ccw(down[down.size() - 2], down.back(), p)) {
                down.pop_back();
            }
            down.push_back(p);
        }
    }
    down.pop_back();
    reverse(down.begin(), down.end());
    down.pop_back();
    for (const auto &p : down) {
        up.push_back(p);
    }
    return up;
}

template<typename T>
struct NonVerticalLine {
    T k, b;

    NonVerticalLine(): k(0), b(0) {
    }

    template<typename T2>
    NonVerticalLine(const Line<T2> &l) {
        assert(!is_equal(l.B, Int(0)));
        k = T(-l.A) / T(l.B);
        b = T(-l.C) / T(l.B);
    }

    template<typename T2, typename T3>
    NonVerticalLine(const Point<T2> &a, const Point<T2> &b) {
        assert(!is_equal(a.x, b.x));
        k = T(b.y - a.y) / T(b.x - a.x);
        b = a.y - k * a.x;
    }

    template<typename T2>
    auto eval(T2 x) const {
        return k * x + b;
    }

    friend ostream& operator << (ostream &os, const NonVerticalLine &l) {
        os << "(" << l.k << " " << l.b << ")";
        return os;
    }
};

template<typename T>
pair<Point<Real>, bool> get_half_plane_intersection(const vector<Line<T>> &v, Real l = -1e9, Real r = 1e9, size_t its = 100) {
    vector<NonVerticalLine<Real>> up, down;
    for (const auto &ln : v) {
        if (is_equal(ln.B, Int(0))) {
            if (is_equal(ln.A, Int(0))) {
                if (is_less(ln.C, Int(0))) {
                    return {{0, 0}, false};
                }
                continue;
            }
            if (is_less(Int(0), ln.A)) {
                l = max(l, Real(-ln.C) / ln.A);
            } else {
                r = min(r, Real(-ln.C) / ln.A);
            }
        } else if (is_less(Int(0), ln.B)) {
            down.push_back(ln);
        } else {
            up.push_back(ln);
        }
    }
    if (is_less(r, l)) {
        return {{0, 0}, false};
    }
    auto get_max = [](const vector<NonVerticalLine<Real>> &v, Real x) {
        Real res = v[0].eval(x);
        for (const auto &ln : v) {
            res = max(res, ln.eval(x));
        }
        return res;
    };
    auto get_min = [](const vector<NonVerticalLine<Real>> &v, Real x) {
        Real res = v[0].eval(x);
        for (const auto &ln : v) {
            res = min(res, ln.eval(x));
        }
        return res;
    };
    if (down.empty() || up.empty()) {
        Real x = (l + r) / 2;
        Real y = 0;
        if (!down.empty()) {
            y = get_max(down, x) - 10;
        } else if (!up.empty()) {
            y = get_min(up, x) + 10;
        }
        return {{x, y}, true};
    }
    const Real phi1 = (2.236067977499789696409173668731l - 1) / 2; // (sqrt(5) - 1) / 2
    const Real phi2 = 1 - phi1;
    Real mid1 = l * phi1 + r * phi2;
    Real mid2 = l * phi2 + r * phi1;
    Real ans1 = get_min(up, mid1) - get_max(down, mid1);
    Real ans2 = get_min(up, mid2) - get_max(down, mid2);
    while (its--) {
        if (ans2 < ans1) {
            r = mid2;
            mid2 = mid1;
            ans2 = ans1;

            mid1 = l * phi1 + r * phi2;
            Real l1 = get_max(down, mid1), r1 = get_min(up, mid1);
            if (is_less_equal(l1, r1)) {
                return {{mid1, (l1 + r1) / 2}, true};
            }
            ans1 = r1 - l1;
        } else {
            l = mid1;
            mid1 = mid2;
            ans1 = ans2;

            mid2 = l * phi2 + r * phi1;
            Real l2 = get_max(down, mid2), r2 = get_min(up, mid2);
            if (is_less_equal(l2, r2)) {
                return {{mid2, (l2 + r2) / 2}, true};
            }
            ans2 = r2 - l2;
        }
    }
    return {{0, 0}, false};
}

template<typename T1, typename T2>
bool contains(const vector<Point<T1>> &v, const Point<T2> &p, bool strictly) { // v is convex, not necessarily strict-convex
    assert(v.size() >= 2);
    int z1 = get_sign(vector_product(p - v[0], v[1] - p));
    T1 lx = v[0].x, rx = v[0].x, ly = v[0].y, ry = v[0].y;
    for (int i = 0; i < v.size(); ++i) {
        int z2 = get_sign(vector_product(p - v[i], v[(i + 1) % v.size()] - p));
        if (strictly && z2 == 0) {
            return false;
        }
        if (z1 * z2 < 0) {
            return false;
        }
        lx = min(lx, v[i].x);
        ly = min(ly, v[i].y);
        rx = max(rx, v[i].x);
        ry = max(ry, v[i].y);
    }
    if (strictly) {
        return is_less(lx, p.x) && is_less(p.x, rx) &&
               is_less(ly, p.y) && is_less(p.y, ry);
    }
    return is_less_equal(lx, p.x) && is_less_equal(p.x, rx) &&
           is_less_equal(ly, p.y) && is_less_equal(p.y, ry);
}

const int max_n = 200111;

int n, h;
Point<Int> p[max_n], eye;

Segment<Int> get_eye_segment(Point<Int> to) {
    return {eye, to};
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> h;
    for (int i = 0; i < n; ++i) {
        cin >> p[i];
    }
    eye = p[n - 1];
    eye.y += h;

    Real ans = get_dist(p[n - 1], p[n - 2]);
    Segment<Int> best = get_eye_segment(p[n - 2]);

    for (int i = n - 2; i; --i) {
        Segment<Int> cur(p[i], p[i - 1]);
        if (!ccw(best.a, best.b, p[i - 1])) {
            auto inter = get_intersection(best.get_line(), cur.get_line());
            Point<Real> mid = inter.first;
            if (inter.second == INF) {
                mid = p[i];
            }
            ans += get_dist(mid, p[i - 1]);
            best = get_eye_segment(p[i - 1]);
        }
    }
    cout << fixed << setprecision(20) << ans << "\n";
    return 0;
}