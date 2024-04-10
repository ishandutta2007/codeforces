#define _USE_MATH_DEFINES
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

template <typename Container>
int SZ(const Container& S) { return S.size(); }

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

#if DEBUG && !ONLINE_JUDGE
    ifstream input_from_file("input.txt");
    #define cin input_from_file

    #define dbg_var(x) clog << #x  << ": " << x << endl;
    #define dbg_array(x, len) clog << #x << ": " << print_iterable(x, x+len, -1) << endl;
#else
    #define dbg_var(x)
    #define dbg_array(x, len)
#endif

///////////////////////////////////////////////////////////////////////////
//////////////////// DO NOT TOUCH BEFORE THIS LINE ////////////////////////
///////////////////////////////////////////////////////////////////////////

const int MAXN = -1; 

// int GetSign(LL a) {
    // return (a > 0) - (a < 0);
// }

struct Point {
    LL x, y;
    Point() : x(0), y(0) {}
    Point(LL x, LL y) : x(x), y(y) {}
    Point operator +(const Point& other) const { return {x+other.x, y+other.y}; };
    Point operator -(const Point& other) const { return {x-other.x, y-other.y}; };
    Point operator *(LL lambda) const { return {x*lambda, y*lambda}; };
    LL operator *(const Point& other) const {
        return x * other.x + y*other.y;
    }
    bool operator <(const Point& other) const {
        return x * other.y > y*other.x;
    }
};

Point Rotate90(const Point& P) {
    return {-P.y, P.x};
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); // Remove in problems with online queries!

    int N;
    cin >> N;
    Point O;
    vector<Point> P(N);
    for (int i = 0; i < N; i++) {
        cin >> P[i].x >> P[i].y;
        O = O+P[i];
    }
    vector<bool> removed(N, false);
    for (int i = 0; i < N; i++) {
        if (removed[i]) continue;
        for (int j = 0; j < N; j++) {
            if (removed[j]) continue;
            Point Q = ((P[i]+P[j])*N) - (O*2);
            if (Q.x == 0 and Q.y == 0) {
                removed[i] = true;
                removed[j] = true;
                break;
            }
        }
    }
    vector<int> not_removed;
    for (int i = 0; i < N; i++) {
        if (!removed[i]) not_removed.push_back(i);
    }
    if (not_removed.empty()) {
        cout << "-1" << "\n";
        return 0;
    }
    set<Point> good_lines;
    int M = not_removed.size();
    for (int index : not_removed) {
        Point A = P[not_removed[0]];
        Point B = P[index];
        Point Q = ((A+B)*N) - (O*2);
        Q = Rotate90(Q);
        if (Q.y < 0 || (Q.y == 0 and Q.x < 0)) Q = Q*(-1);
        good_lines.insert(Q);
    }
    
    int res = 0;
    for (const Point& line : good_lines) {
        vector<LL> scal(M);
        for (int i = 0; i < M; i++) scal[i] = P[not_removed[i]] * line;
        sort(scal.begin(), scal.end());
        LL center = scal.back() + scal[0];
        bool works = true;
        for (int i = 0; i <= M-1-i; i++) {
            if (scal[i] + scal[M-1-i] != center) {
                works = false;
                break;
            }
        }
        if (works) res++;
    }
    cout << res << "\n";
}