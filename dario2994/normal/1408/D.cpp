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

struct pt {
    int x, y;
};

ostream& operator<<(ostream& out, pt P) {
    out << "(" << P.x << ", " << P.y << ")";
    return out;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); // Remove in problems with online queries!

    int N, M;
    cin >> N >> M;
    vector<pt> A(N);
    vector<pt> B(M);
    for (int i = 0; i < N; i++) cin >> A[i].x >> A[i].y;
    for (int i = 0; i < M; i++) cin >> B[i].x >> B[i].y;

    vector<pair<int,int>> vec;
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (B[j].x < A[i].x or B[j].y < A[i].y) continue;
            vec.push_back({B[j].x-A[i].x + 1, B[j].y - A[i].y + 1});
        }
    }

    sort(vec.begin(), vec.end());
    
    vector<pt> C(1);
    C[0].x = 0, C[0].y = 1e7;
    for (auto pp: vec) {
        int x = pp.first, y = pp.second;
        while (y >= C.back().y) C.pop_back();
        if (C.back().x < x) C.push_back({x, y});
    }

    C.push_back({10000000, 0});

    int res = 1e7;
    for (int i = 0; i < SZ(C)-1; i++) {
        int x = C[i].x, y = C[i+1].y;
        res = min(res, x + y);
    }
    cout << res << "\n";
}