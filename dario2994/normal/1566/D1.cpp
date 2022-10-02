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

void solve() {
    int n, m;
    cin >> n >> m;
    unordered_map<int,vector<int>> vals;
    unordered_map<int, int> from;
    unordered_map<int, int> to;
    vector<int> a(n*m);
    for (int i = 0; i < n*m; i++) {
        cin >> a[i];
        vals[a[i]].push_back(i);
    }
    sort(a.begin(), a.end());
    from[a[0]] = 0;
    to[a.back()] = n*m-1;
    for (int i = 1; i < n*m; i++) {
        if (a[i] != a[i-1]) {
            to[a[i-1]] = i-1;
            from[a[i]] = i;
        }
    }
    vector<int> row(n*m);
    vector<int> col(n*m);
    for (auto pp: from) {
        int z = pp.first;
        int low = from[z], high = to[z];
        vector<int> vec = vals[z];
        int k = 0;
        for (int r = 0; r < n; r++) {
            int a = low - r*m, b = high-r*m;
            a = max(0, a);
            b = min(m-1, b);
            if (b < a) continue;
            for (int i = b; i >= a; i--) {
                int u = vec[k];
                k++;
                row[u] = r;
                col[u] = i;
            }
        }
    }
    int res = 0;
    vector<bool> occ(n*m, false);
    for (int i = 0; i < n*m; i++) {
        int r = row[i], c = col[i];
        for (int j = r*m; j < r*m+c; j++) res += occ[j];
        occ[r*m+c] = true;
    }
    cout << res << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); // Remove in problems with online queries!

    int t;
    cin >> t;
    for (int i = 0; i < t; i++) solve();
}