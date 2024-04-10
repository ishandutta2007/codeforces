#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define SZ(x) ((int)((x).size()))

// Returns the time elapsed in nanoseconds from 1 January 1970, at 00:00:00.
LL get_time() {
    return chrono::duration_cast<chrono::nanoseconds>(
        chrono::steady_clock::now().time_since_epoch())
        .count();
}

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

const int MAXN = 1010;
int mat[MAXN][MAXN];
int a[MAXN][MAXN];
int b[MAXN][MAXN];
LL sum = 0;

void update(int x, int y) {
    sum -= a[x][y] + b[x][y];
    a[x][y] = 0, b[x][y] = 0;
    if (mat[x][y] == 1) return;
    
    if (mat[x][y+1] == 0) a[x][y] = 1 + b[x][y+1];
    if (mat[x+1][y] == 0) b[x][y] = 1 + a[x+1][y];

    sum += a[x][y] + b[x][y];
}

void update_diagonal(int x, int y) {
    if (x <= 0 or y <= 0) return;
    update(x, y);
    update(x-1, y);
    update(x, y-1);
    update_diagonal(x-1, y-1);
}



int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); // Remove in problems with online queries!

    int n, m, q;
    cin >> n >> m >> q;
    for (int i = 0; i <= n+1; i++) mat[i][0] = 1, mat[i][m+1] = 1;
    for (int j = 0; j <= m+1; j++) mat[0][j] = 1, mat[n+1][j] = 1;

    int cnt = n*m;
    for (int i = n+1; i >= 0; i--) for (int j = m+1; j >= 0; j--) {
        update(i, j);
    }
    for (int _ = 0; _ < q; _++) {
        int x, y;
        cin >> x >> y;
        if (mat[x][y] == 1) cnt++;
        else cnt--;
        mat[x][y] = 1-mat[x][y];
        update_diagonal(x, y);
        cout << cnt + sum << "\n";
    }
}