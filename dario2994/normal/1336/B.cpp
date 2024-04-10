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

void solve() {
    vector<int> sz(3, 0);
    cin >> sz[0] >> sz[1] >> sz[2];
    vector<vector<LL>> vec = {vector<LL>(sz[0], 0), vector<LL>(sz[1], 0), vector<LL>(sz[2], 0)};
    for (int it = 0; it < 3; it++) {
        for (int i = 0; i < sz[it]; i++) cin >> vec[it][i];
        sort(vec[it].begin(), vec[it].end());
    }
    // dbg(sz, vec);
    
    LL res = 3e18;
    vector<int> perm = {0, 1, 2};
    do {
        // dbg(perm);
        LL ris = 3e18;
        int bef = -1;
        int aft = 0;
        for (int i = 0; i < sz[perm[2]]; i++) {
            while (bef + 1 < sz[perm[0]] and vec[perm[0]][bef+1] <= vec[perm[2]][i]) bef++;
            while (aft < sz[perm[1]] and vec[perm[1]][aft] < vec[perm[2]][i]) aft++;
            if (bef < 0 or aft >= sz[perm[1]]) continue;
            // dbg(sz[perm[1]], sz, bef, aft);
            LL x = vec[perm[0]][bef], y = vec[perm[1]][aft], z = vec[perm[2]][i];
            ris = min(ris, (x-y)*(x-y) + (y-z)*(y-z) + (z-x)*(z-x));
        }
        res = min(res, ris);
    } while (next_permutation(perm.begin(), perm.end())) ;
    cout << res << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); // Remove in problems with online queries!

    int T;
    cin >> T;
    for (int i = 0; i < T; i++) solve();
}