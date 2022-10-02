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

///////////////////////////////////////////////////////////////////////////
//////////////////// DO NOT TOUCH BEFORE THIS LINE ////////////////////////
///////////////////////////////////////////////////////////////////////////

// Computational geometry library containing all the basic operations for
// 2d geometry.
// When possible everything is done avoiding the usage of floating point
// calculations to guarantee exact results.
// This can backfire as overflow becomes a real issue.

// TODO: A nontrivial amount of this library still has to be tested.

#include <vector>
#include <iostream>
#include <cmath>
using namespace std;

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


// Returns a vector containing the points in the convex hull,
// in anticlockwise order starting from the leftmost, lowest one.
// The complexity is linear, apart from the sorting.
// If a point is collinear with two points in the convex hull, the point is not
// inserted in the convex hull.
// It works smoothly if there are multiple equal points, if all points are
// aligned points and even if all points coincide.
// ACHTUNG: The points vector must be nonempty.
template <typename coord>
vector<Point<coord>> ConvexHull(vector<Point<coord>> points) {
    int N = points.size();
    // Sorting from south to north (and from west to east) the points.
    sort(points.begin(), points.end());

    // All points are equal.
    if (points[0] == points.back()) return {points[0]};

    vector<Point<coord>> anticlockwise, clockwise;
    anticlockwise.push_back(points[0]);
    clockwise.push_back(points[0]);

    for (int i = 1; i < N; i++) {
        // Finds the convex hull of the first i+1 points.
        Point<coord> V = points[i];

        // Comparing V with the line generated by the last two points in
        // the anticlockwise array.
        while (anticlockwise.size() > 1 and
               RelativePosition(anticlockwise.rbegin()[1], V,
                                anticlockwise.back()) != -1) {
            anticlockwise.pop_back();
        }
        anticlockwise.push_back(V);

        // Comparing V with the line generated by the last two points in
        // the clockwise array.
        while (clockwise.size() > 1 and
               RelativePosition(clockwise.rbegin()[1], V,
                                clockwise.back()) != 1) {
            clockwise.pop_back();
        }
        clockwise.push_back(V);
    }

    // Joining anticlockwise and clockwise in a single vector.
    anticlockwise.pop_back();
    reverse(clockwise.begin(), clockwise.end());
    clockwise.pop_back();
    anticlockwise.insert(anticlockwise.end(), clockwise.begin(), clockwise.end());
    return anticlockwise;
}

const int MAXN = -1;

typedef Point<LL> pt;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); // Remove in problems with online queries!
    int N;
    cin >> N;
    if (N == 1) {
        cout << 0 << "\n";
        return 0;
    }
    vector<pt> vec;
    for (int i = 0; i < N; i++) {
        LL x, y;
        cin >> x >> y;
        vec.push_back({x, y-x*x});
    }
    vector<pt> conv = ConvexHull(vec);
    int M = conv.size();
    int res = 0;
    for (int i = 0; i < M; i++) {
        if (conv[i].x > conv[(i+1)%M].x) res++;
    }
    cout << res << "\n";
}