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

const int MAXN = 1<<20;
const int MAXC = 70;
LL x[MAXN];
int color[MAXN];

vector<short int> min_color[MAXN];
vector<short int> max_color[MAXN];
int same_color[MAXN];

int pref_min_color[MAXC];
int pref_max_color[MAXC];

LL solve(int l, int r) {
    if (l == r) return 1;
    int m = (l+r)/2;
    LL res = solve(l, m) + solve(m+1, r);
    // dbg(res);
    LL a = 1e18, b = -1e18;
    int color_a = -1, color_b = -1;
    int j1 = m+1, j2 = m+1;
    for (int i = m; i >= l; i--) {
        if (x[i] < a) a = x[i], color_a = color[i];
        if (x[i] > b) b = x[i], color_b = color[i];
        while (j1 <= r and x[j1] >= a) j1++;
        while (j2 <= r and x[j2] <= b) j2++;
        if (j1 < j2) {
            if (color_a == color_b) res += j1-m-1;
            min_color[j1].push_back(color_b);
            min_color[j2].push_back(-color_b);
            same_color[j2]++;
        } else {
            if (color_a == color_b) res += j2-m-1;
            max_color[j2].push_back(color_a);
            max_color[j1].push_back(-color_a);
            same_color[j1]++;
        }
    }

    a = 1e18, b = -1e18;
    color_a = -1, color_b = -1;
    
    int pref_same_color = 0;
    for (int i = m+1; i <= r; i++) {
        if (x[i] < a) a = x[i], color_a = color[i];
        if (x[i] > b) b = x[i], color_b = color[i];
        for (int c: min_color[i]) {
            if (c > 0) pref_min_color[c]++;
            else pref_min_color[-c]--;
        }
        for (int c: max_color[i]) {
            if (c > 0) pref_max_color[c]++;
            else pref_max_color[-c]--;
        }
        pref_same_color += same_color[i];
        if (color_a == color_b) res += pref_same_color;
        res += pref_min_color[color_a];
        res += pref_max_color[color_b];
    }

    for (int i = m+1; i <= r+1; i++) {
        min_color[i].clear(), max_color[i].clear(), same_color[i] = 0;
    }
    for (int c = 0; c < MAXC; c++) pref_min_color[c] = pref_max_color[c] = 0;

    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); // Remove in problems with online queries!
    
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> x[i], color[i] = 1 + __builtin_popcountll(x[i]);

    LL res = solve(0, n-1);
    cout << res << "\n";
}