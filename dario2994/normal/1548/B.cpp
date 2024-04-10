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

LL fast_gcd(LL a, LL b) {
    if (a > b) swap(a, b);
    while (a != 0) b %= a, swap(a, b);
    return b;
}

void solve() {
    int n;
    cin >> n;
    vector<LL> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i <= n-2; i++) a[i] = llabs(a[i+1]-a[i]);
    if (n == 1) {
        cout << 1 << "\n";
        return;
    }
    int res = 1;
    vector<pair<LL,int>> vec;
    for (int i = n-2; i >= 0; i--) {
        LL q = a[i];
        for (auto& pp: vec) pp.first = fast_gcd(pp.first, q), q = pp.first;
        while (!vec.empty() and vec.back().first == 1) vec.pop_back();
        if (a[i] != 1 and (vec.empty() or vec.front().first != a[i]))
            vec.insert(vec.begin(), {a[i], i});
        vector<pair<LL,int>> new_vec;
        for (int i = 0; i < SZ(vec); i++) {
            if (i < SZ(vec) - 1 and vec[i].first == vec[i+1].first) continue;
            new_vec.push_back(vec[i]);
        }
        vec = new_vec;
        if (!vec.empty()) res = max(res, vec.back().second-i+2);
        // dbg(a[i]);
        // cout << i << ": ";
        // for (auto pp: vec) cout << pp << ", ";
        // cout << endl;
    }
    cout << res << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); // Remove in problems with online queries!

    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) solve();
}