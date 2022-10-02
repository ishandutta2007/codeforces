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

const int MAXN = 110;
bool mat[MAXN][MAXN];
vector<vector<int>> ops;
void make_op(int x1, int y1, int x2, int y2, int x3, int y3) {
    ops.push_back({x1, y1, x2, y2, x3, y3});
    mat[x1][y1] ^= 1;
    mat[x2][y2] ^= 1;
    mat[x3][y3] ^= 1;
}

void solve() {
    ops.clear();
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        string S;
        cin >> S;
        for (int j = 0; j < m; j++) mat[i][j] = S[j] == '1';
    }

    for (int i = n-1; i >= 2; i--) for (int j = 0; j < m; j++) {
        if (mat[i][j]) {
            if (j != 0) make_op(i, j, i-1, j, i-1, j-1);
            else make_op(i, j, i-1, j, i-1, j+1);
        }
    }
    for (int j = m-1; j >= 2; j--) {
        for (int i = 0; i <= 1; i++) {
            if (mat[i][j]) {
                make_op(i, j, 0, j-1, 1, j-1);
            }
        }
    }

    while (1) {
        // cout << "YO" << endl;
        vector<pair<int,int>> ones;
        vector<pair<int,int>> zers;
        for (int i = 0; i < 2; i++) for (int j = 0; j < 2; j++) {
            if (mat[i][j]) ones.push_back({i, j});
            else zers.push_back({i, j});
        }
        if (ones.size() == 0) break;
        else if (ones.size() == 3) {
            make_op(ones[0].first, ones[0].second,
                    ones[1].first, ones[1].second,
                    ones[2].first, ones[2].second);
        } else if (ones.size() == 2) {
            make_op(ones[0].first, ones[0].second,
                    zers[0].first, zers[0].second,
                    zers[1].first, zers[1].second);
        } else if (ones.size() == 1) {
            make_op(ones[0].first, ones[0].second,
                    zers[0].first, zers[0].second,
                    zers[1].first, zers[1].second);
        } else {
            make_op(0, 0, 0, 1, 1, 0);
        }
    }

    // assert(SZ(ops) <= n*m);
    // for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) assert(mat[i][j] == 0);
    
    cout << ops.size() << "\n";
    for (auto vec: ops) {
        for (int z: vec) cout << z+1 << " ";
        cout << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); // Remove in problems with online queries!

    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) solve();
}