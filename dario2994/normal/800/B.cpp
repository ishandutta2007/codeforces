#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;

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

#if DEBUG && !ONLINE_JUDGE
    ifstream input_from_file("input.txt");
    #define cin input_from_file

    #define dbg_var(x) clog << #x  << ": " << x << endl;
    #define dbg_vec(x) clog << #x << ": " << print_iterable(x.begin(), x.end(), -1) << endl;
    #define dbg_array(x, len) clog << #x << ": " << print_iterable(x, x+len, -1) << endl;
#else
    #define dbg_var(x) 
    #define dbg_vec(x)
    #define dbg_array(x, len)
#endif

///////////////////////////////////////////////////////////////////////////
//////////////////// DO NOT TOUCH BEFORE THIS LINE ////////////////////////
///////////////////////////////////////////////////////////////////////////

template <typename coord>
struct Point{
	coord x,y;

    Point() : x(0), y(0) {}
    Point(coord x, coord y) : x(x), y(y) {}

	bool operator <(const Point<coord>& other) const {
        if (x == other.x) return y < other.y;
		return x < other.x;
	}
    Point<coord> operator -(const Point<coord>& other) const {
        return Point<coord>(x-other.x, y-other.y);
    }
    coord SquaredNorm() const {
        return x*x+y*y;
    }
};


template <typename coord>
ostream& operator <<(ostream& out, const Point<coord>& P) {
    out << "(" << P.x << ", " << P.y << ")";
    return out;
}

// This should not compile if used.
const int MAXN = 1010; 

double DistanceFromLine(Point<double> p1, Point<double> p2, Point<double> p0) {
    p2 = p2-p1;
    p0 = p0-p1;
    return abs(p2.y*p0.x-p2.x*p0.y) / sqrt(p2.x*p2.x + p2.y*p2.y);
}

Point<double> coord[MAXN];

int main() {
    ios::sync_with_stdio(false);

    int N;
    cin >> N;
    for (int i = 0; i < N; i++) {
        int a, b;
        cin >> a >> b;
        coord[i] = Point<double>(a, b);
    }

    double ans = 1e10;
    for (int i = 0; i < N; i++) {
        auto A = coord[i];
        auto B = coord[(i+1)%N];
        auto C = coord[(i+2)%N];
        MinPlace(ans, DistanceFromLine(A, B, C));
        MinPlace(ans, DistanceFromLine(B, C, A));
        MinPlace(ans, DistanceFromLine(C, A, B));
    }
    cout.precision(15);
    cout << ans/2.0 << "\n";
}