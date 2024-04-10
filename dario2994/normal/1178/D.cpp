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

const int MAXN = 1100;

// void solve(int n) {
    // if (n <= 5) {
        
    // }
    // edges.push_back()
// }

bool din[MAXN][2*MAXN];
bool iscomp[2*MAXN];

typedef pair<int,int> pii;
vector<pii> moves = {{3,3}, {4,4}, {4,5}, {5,5}, {6,7}};
vector<vector<pii>> graphs = {{{1,2}, {2,3}, {3,1}},
    {{1,2}, {2,3}, {3,4}, {4,1}},
    {{1,2}, {2,3}, {3,4}, {4,1}, {1,3}},
    {{1,2}, {2,3}, {3,4}, {4,5}, {5,1}},
    {{1,2}, {2,3}, {3,4}, {4,5}, {5,6}, {6,1}, {1,3}}};

vector<pii> edges;
void solve(int x, int y) {
    if (x == 0 and y == 0) return;
    for (int i = 0; i < SZ(moves); i++) {
        auto pp = moves[i];
        if (x >= pp.first and y >= pp.second and din[x-pp.first][y-pp.second]) {
            int z = x-pp.first;
            for (auto ee : graphs[i]) edges.push_back({ee.first + z, ee.second+z});
            solve(x-pp.first, y-pp.second);
            return;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); // Remove in problems with online queries!

    for (int p = 2; p < 2*MAXN; p++) {
        if (iscomp[p]) continue;
        for (int i = 2*p; i < 2*MAXN; i += p) iscomp[i] = true;
    }
    
    for (auto pp : moves) din[pp.first][pp.second] = true;

    for (int i = 1; i < MAXN; i++) {
        for (int j = 1; j < 2*MAXN; j++) {
            for (auto pp : moves) if (i-pp.first >= 0 and j-pp.second >= 0) din[i][j] |= din[i-pp.first][j-pp.second];
        }
    }
    din[0][0] = true;

    int N;
    cin >> N;
    if (N == 8) {
        cout << 11 << "\n";
        for (int i = 1; i <= 7; i++) cout << i << " " << i+1 << "\n";
        cout << "8 1\n";
        cout << "1 3\n";
        cout << "2 4\n";
        cout << "5 7\n";
        return 0;
    }
    if (N == 9) {
        cout << 11 << "\n";
        for (int i = 1; i <= 8; i++) cout << i << " " << i+1 << "\n";
        cout << "9 1\n";
        cout << "1 3\n";
        cout << "2 4\n";
        return 0;
    }
    for (int j = N; j < 2*MAXN; j++) if (!iscomp[j] and din[N][j]) {
        solve(N, j);
        cout << edges.size() << "\n";
        for (auto pp : edges) cout << pp.first << " " << pp.second << "\n";
        return 0;
    }
    // for (int i = 3; i <= 1000; i++) {
        // bool works = false;
        // for (int j = i; j < 2*MAXN; j++) if (!iscomp[j] and din[i][j]) {
            // works = true;
            // break;
        // }
        // if (!works) cout << i << " " << "NO" << endl;
    // }
}