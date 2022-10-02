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

const int MAXN = -1;

struct pt {
    int id;
    int x[3];
};

bool operator <(pt A, pt B) {
    if (A.x[0] == B.x[0]) {
        if (A.x[1] == B.x[1]) return A.x[2] < B.x[2];
        return A.x[1] < B.x[1];
    }
    return A.x[0] < B.x[0];
}

int Solve(const vector<pt>& points, int c) {
    if (c == 3) return points[0].id;
    int N = points.size();
    vector<int> rest;
    for (int i = 0; i < N; i++) {
        vector<pt> subproblem;
        subproblem.push_back(points[i]);
        while (i+1 < N and points[i+1].x[c] == points[i].x[c]) {
            i++;
            subproblem.push_back(points[i]);
        }
        int k = Solve(subproblem, c+1);
        if (k != -1) rest.push_back(k);
    }
    for (int i = 1; i < (int)rest.size(); i += 2) {
        cout << rest[i-1] << " " << rest[i] << "\n";
    }
    if (rest.size()%2 == 1) return rest.back();
    return -1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); // Remove in problems with online queries!
    int N;
    cin >> N;
    vector<pt> points(N);
    for (int i = 0; i < N; i++) {
        cin >> points[i].x[0] >> points[i].x[1] >> points[i].x[2];
        points[i].id = i+1;
    }
    sort(points.begin(), points.end());
    assert(Solve(points, 0) == -1);
}