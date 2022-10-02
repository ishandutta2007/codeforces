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

// bool solve(int a, int b, int c) {
    // static set<vector<int>> visited;
    // static map<vector<int>, bool> memo;
    // vector<int> v = {a, b, c};
    // sort(v.begin(), v.end());
    // if (v[0] == 0) return 1;
    // if (memo.count(v)) return memo[v];
    // if (visited.count(v)) return 0;
    // visited.insert(v);
    // memo[v] = solve(2*v[0], v[1]-v[0], v[2]) ||
              // solve(2*v[0], v[1], v[2]-v[0])||
              // solve(v[0], 2*v[1], v[2]-v[2]);
    // return memo[v];
// }

// set<vector<int>> visited2;
// void explore(int a, int b) {
    // vector<int> v = {a, b};
    // sort(v.begin(), v.end());
    // if (visited2.count(v)) return;
    // visited2.insert(v);
    // cout << v << " ";
    // explore(2*v[0], v[1]-v[0]);
// }

const int MAXN = 1010;
int a[MAXN];

vector<pair<int,int>> moves;
void make_move(int i, int j) {
    if (a[i] > a[j]) swap(i, j);
    assert(a[i] <= a[j]);
    assert(i != j);
    a[j] -= a[i];
    a[i] *= 2;
    moves.push_back({i, j});
}

void solve_triple(vector<int> vec) {
    auto sort_vec = [&]() { sort(vec.begin(), vec.end(), [&](int x, int y) { return a[x] < a[y]; }); };
    sort_vec();
    while (a[vec[0]] != 0) {
        int u = a[vec[0]];
        int v = a[vec[1]];
        int m = v % u; 
        if (2*m > u) m -= u;
        // m may be negative
        int t = (v-m)/u;
        for (int e = 0; (1<<e) <= t; e++) {
            if (t&(1<<e)) make_move(vec[0], vec[1]);
            else make_move(vec[0], vec[2]);
        }
        sort_vec();
        // dbg(a[1], a[2], a[3]);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); // Remove in problems with online queries!

    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    while (1) {
        vector<int> ord;
        for (int i = 1; i <= n; i++) if (a[i] != 0) ord.push_back(i);
        sort(ord.begin(), ord.end(), [&](int i, int j) { return a[i] < a[j]; });
        if (ord.size() <= 1) {
            cout << -1 << "\n";
            return 0;
        }
        if (ord.size() == 2) break;
        solve_triple({ord[0], ord[1], ord[2]});
    }
    cout << moves.size() << "\n";
    for (auto pp: moves) cout << pp.first << " " << pp.second << "\n";
}