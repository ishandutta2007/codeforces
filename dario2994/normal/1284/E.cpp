#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define SZ(x) ((int)((x).size()))

template <typename T1, typename T2>
string print_iterable(T1 begin_iter, T2 end_iter, int counter) {
    bool done_something = false;
    stringstream res;
    res << "[";
    for (; begin_iter != end_iter and counter; ++begin_iter) {
        done_something = true;
        counter--;
        res << *begin_iter << ", ";
    }
    string str = res.str();
    if (done_something) {
        str.pop_back();
        str.pop_back();
    }
    str += "]";
    return str;
}

vector<int> SortIndex(int size, std::function<bool(int, int)> compare) {
    vector<int> ord(size);
    for (int i = 0; i < size; i++) ord[i] = i;
    sort(ord.begin(), ord.end(), compare);
    return ord;
}

template <typename T>
bool MinPlace(T& a, const T& b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}

template <typename T>
bool MaxPlace(T& a, const T& b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}

template <typename S, typename T>
ostream& operator <<(ostream& out, const pair<S, T>& p) {
    out << "{" << p.first << ", " << p.second << "}";
    return out;
}

template <typename T>
ostream& operator <<(ostream& out, const vector<T>& v) {
    out << "[";
    for (int i = 0; i < (int)v.size(); i++) {
        out << v[i];
        if (i != (int)v.size()-1) out << ", ";
    }
    out << "]";
    return out;
}

template<class TH>
void _dbg(const char* name, TH val){
    clog << name << ": " << val << endl;
}
template<class TH, class... TA>
void _dbg(const char* names, TH curr_val, TA... vals) {
    while(*names != ',') clog << *names++;
    clog << ": " << curr_val << ", ";
    _dbg(names+1, vals...);
}

#if DEBUG && !ONLINE_JUDGE
    ifstream input_from_file("input.txt");
    #define cin input_from_file

    #define dbg(...) _dbg(#__VA_ARGS__, __VA_ARGS__)
    #define dbg_arr(x, len) clog << #x << ": " << print_iterable(x, x+len, -1) << endl;
#else
    #define dbg(...)
    #define dbg_arr(x, len)
#endif

// This choices for absolute and relative precision have been selected as
// they seem to give the best result with coordinates in the range [-1e6, 1e6].
static const long double absolute_precision = 1e-6;
static const long double relative_precision = 1e-9;

// Equality tester functions.
// It is specialized for double to account for precision issues.
template <typename T>
bool Equal(T x, T y, T precision = 0) {
    return x == y;
}

template <typename T = double>
bool Equal(double x, double y, double precision = absolute_precision) {
    return abs(x-y) < precision;
}

template <typename T = long double>
bool Equal(long double x, long double y,
           long double precision = absolute_precision) {
    return abs(x-y) < precision;
}

// Relative equality is defined only for floating point types.
bool RelativeEqual(double x, double y, double precision = relative_precision) {
    return abs(x-y) < precision * abs(y);
}

bool RelativeEqual(long double x, long double y,
                   long double precision = relative_precision) {
    return abs(x-y) < precision * abs(y);
}

// The the 2d-point is the main character of this library.
// It holds a pair of coordinates and offers a big amount of operations related
// to geometry.
template <typename coord>
struct Point {
    coord x,y;

    Point() : x(0), y(0) {}
    Point(coord x, coord y) : x(x), y(y) {}
    template <typename coord2>
    Point(const Point<coord2>& other) : x(other.x), y(other.y) {}

    bool operator ==(const Point<coord>& other) const {
        return Equal(other.x, x) && Equal(other.y, y);
    }
    bool operator <(const Point<coord>& other) const {
        if (Equal(x, other.x)) return y < other.y;
        return x < other.x;
    }
    bool operator >(const Point<coord>& other) const {
        return other < *this;
    }
    Point<coord> operator -(const Point<coord>& other) const {
        return Point<coord>(x-other.x, y-other.y);
    }
    Point<coord> operator -() const {
        return Point<coord>(-x, -y);
    }
    void operator -=(const Point<coord>& other) {
        x -= other.x;
        y -= other.y;
    }
    Point<coord> operator +(const Point<coord>& other) const {
        return Point<coord>(x + other.x, y + other.y);
    }
    void operator +=(const Point<coord>& other) {
        x += other.x;
        y += other.y;
    }
    Point<coord> operator *(coord lambda) const {
        return Point<coord>(lambda*x, lambda*y);
    }
    void operator *=(coord lambda) {
        x *= lambda;
        y *= lambda;
    }
    Point<coord> operator /(coord lambda) const {
        return Point<coord>(x/lambda, y/lambda);
    }
    void operator /=(coord lambda) {
        x /= lambda;
        y /= lambda;
    }
    // Scalar product.
    coord operator *(const Point<coord>& other) const {
        return x * other.x + y * other.y;
    }
    // Cross product.
    coord operator ^(const Point<coord>& other) const {
        return x * other.y - y * other.x;
    }
    coord SquaredNorm() const {
        return x*x+y*y;
    }
    coord Norm() const {
        return sqrt(SquaredNorm());
    }
    bool IsOrigin() const {
        return Equal<coord>(x, 0) and Equal<coord>(y, 0);
    }
};

template <typename coord>
ostream& operator <<(ostream& out, const Point<coord>& P) {
    out << "(" << P.x << ", " << P.y << ")";
    return out;
}

template <typename coord>
istream& operator >>(istream& in, Point<coord>& P) {
    in >> P.x >> P.y;
    return in;
}

// Returns 1 if val > 0, -1 if val < 0, 0 if val == 0.
template <typename T>
short int GetSign(T val) {
    if (Equal<T>(val, 0)) return 0;
    return (val > T{0}) - (val < T{0});
}

// Returns the distance between A and B.
template <typename coord>
coord Distance(const Point<coord>& A, const Point<coord>& B) {
    return (A-B).Norm();
}

// Whether A, B are one multiple of the other (i.e. are aligned w.r.t. the
// origin).
// Even though this is equivalent to A^B == 0, we are not going
// to do that for floating point types as that would give a huge
// loss of precision.
template <typename coord>
bool AreDependent(const Point<coord>& A, const Point<coord>& B) {
    return Equal<coord>(A^B, 0);
}

template <typename coord = double>
bool AreDependent(const Point<double>& A, const Point<double>& B) {
    double p = A.x * B.y;
    double q = A.y * B.x;
    return Equal<double>(p, q) or RelativeEqual(p, q);
}

template <typename coord = long double>
bool AreDependent(const Point<long double>& A, const Point<long double>& B) {
    long double p = A.x * B.y;
    long double q = A.y * B.x;
    return Equal<long double>(p, q) or RelativeEqual(p, q);
}


// Returns -1 if B lays on the right side of the line OA, returns 1 if B lays on
// the left side and 0 if O, A, B are collinear.
template <typename coord>
short int RelativePosition(const Point<coord>& O,
                           const Point<coord>& A,
                           const Point<coord>& B){
    return GetSign((A-O)^(B-O));
}

// Computes the distance from V to the line AB.
// A, B must be distinct.
template <typename coord>
coord DistanceFromLine(const Point<coord>& V,
                       Point<coord> A,
                       Point<coord> B) {
    return DoubleTriangleArea(V, A, B) / (A-B).Norm();
}

// Returns whether the lines AB and CD are parallel.
template <typename coord>
bool AreParallel(const Point<coord>& A, const Point<coord>& B,
                 const Point<coord>& C, const Point<coord>& D) {
    return AreDependent(B-A, D-C);
}

// Returns the intersection point between the line AB and CD.
// The two lines must be nonparallel.
// This function is assuming that nonintegers coordinates are used (as the
// intersection point may not have integer coordinates).
template <typename coord>
Point<coord> Intersection(const Point<coord>& A, const Point<coord>& B,
                          const Point<coord>& C, const Point<coord>& D) {
    coord lambda = ((C-A)^(D-A)) / ((C-D)^(B-A));
    return A + ((B-A) * lambda);
}

// Returns whether A, B, C are collinear.
template <typename coord>
bool AreAligned(const Point<coord>& A, const Point<coord>& B,
                const Point<coord>& C) {
    return AreDependent(A-C, B-C);
}

// Assuming that A, B, C are collinear, returns whether they are in the exact
// order A - B - C on such line.
// The points must be collinear and distinct.
template <typename coord>
bool AreSorted(const Point<coord>& A,
               const Point<coord>& B,
               const Point<coord>& C) {
    return (A < B && B < C) or (A > B && B > C);
}

// Returns the double of the signed area of the triangle having vertices
// A, B, C.
// The double is returned instead of the area as this assures that the result
// is integer if A, B, C had integer coordinates.
template <typename coord>
coord DoubleSignedTriangleArea(const Point<coord>& A,
                               const Point<coord>& B,
                               const Point<coord>& C) {
    return (B-A)^(C-A);
}

template <typename coord>
coord DoubleTriangleArea(const Point<coord>& A, const Point<coord>& B,
                               const Point<coord>& C) {
    return abs(DoubleSignedTriangleArea(A, B, C));
}

// Returns true iff angle(B) > angle(A). Angles are computed anti-clockwise
// and the point (1, 0) has angle = 0.
// Points A, B should not be the origin.
// TODO: Improve the comment:
// This is a *perfectly* working less operator as even in floating points we
// have that + and * are commutative and therefore we always have A^B = -B^A.
template <typename coord>
bool CompareAngle(const Point<coord>& A, const Point<coord>& B) {
    bool upA = A.y > 0 || (A.y == 0 && A.x > 0);
    bool upB = B.y > 0 || (B.y == 0 && B.x > 0);
    if (upA != upB) return upA;
    return RelativePosition({}, A, B) == 1;
}

// Rotates P anticlockwise by 90 degree.
template <typename coord>
Point<coord> Rotate90(const Point<coord> P) {
    return {-P.y, P.x};
}

///////////////////////////////////////////////////////////////////////////
//////////////////// DO NOT TOUCH BEFORE THIS LINE ////////////////////////
///////////////////////////////////////////////////////////////////////////

typedef Point<LL> pt;
const int MAXN = 2600;
pt P[MAXN];
int N;

LL binom4(LL N) {
    return (N*(N-1)*(N-2)*(N-3))/24ll;
}
LL binom3(LL N) {
    return (N*(N-1)*(N-2))/6ll;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); // Remove in problems with online queries!

    cin >> N;
    for (int i = 0; i < N; i++) cin >> P[i].x >> P[i].y;
    LL res = 0;
    for (int k = 0; k < N; k++) {
        pt O = P[k];
        vector<pt> Q;
        for (int i = 0; i < N; i++) {
            if (i == k) continue;
            Q.push_back(P[i]-O);
        }
        sort(Q.begin(), Q.end(), CompareAngle<LL>);
        // dbg(Q);
        LL ris = binom4(N-1);
        int it = 0;
        O = {0, 0};
        for (int i = 0; i < N-1; i++) {
            pt A = Q[i];
            // cout << "BEFORE" << it << " " << i << endl;
            if (it == i) it = (it+1)%(N-1);
            // cout << "AFTER" << it << endl;
            while (it != i and (A^Q[it]) > 0) {
                it = (it+1)%(N-1);
                // dbg(it);
            }
            // dbg(i, it);
            LL sz = it-i;
            if (sz <= 0) sz += N-1;
            ris -= binom3(sz-1);
        }
        res += ris;
        // dbg(ris);
    }
    cout << res << "\n";
}