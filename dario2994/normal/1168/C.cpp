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

const int MAXN = 300010;
const int MAXL = 20;

int A[MAXN];
int fa[MAXN][MAXL];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); // Remove in problems with online queries!

    int N, Q;
    cin >> N >> Q;
    for (int i = 0; i < N; i++) cin >> A[i];
    for (int d = 0; d < MAXL; d++) fa[N][d] = N;
    vector<int> la(MAXL, N);
    for (int i = N-1; i >= 0; i--) {
        for (int d = 0; d < MAXL; d++) fa[i][d] = N;
        for (int d = 0; d < MAXL; d++) {
            if ((A[i] & (1<<d)) == 0) continue;
            fa[i][d] = i;
            for (int e = 0; e < MAXL; e++) fa[i][e] = min(fa[i][e], fa[la[d]][e]);
        }
        for (int d = 0; d < MAXL; d++) if (A[i]&(1<<d)) la[d] = i;
    }
    for (int i = 0; i < Q; i++) {
        int x, y;
        cin >> x >> y;
        x--, y--;
        int best = N;
        for (int d = 0; d < MAXL; d++) if (A[y]&(1<<d)) best = min(best, fa[x][d]);
        if (best <= y) cout << "Shi\n";
        else cout << "Fou\n";
    }
}