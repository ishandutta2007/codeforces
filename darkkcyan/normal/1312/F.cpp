// vim: foldmethod=marker
#include <bits/stdc++.h>
using namespace std;

#define llong long long 
#define len(x) ((int)x.size())
#define rep(i,n) for (int i = -1; ++ i < n; )
#define rep1(i,n) for (int i = 0; i ++ < n; )
#define rand __rand
mt19937 rng(chrono::system_clock::now().time_since_epoch().count());  // or mt19937_64
template<class T = int> T rand(T range = numeric_limits<T>::max()) { return (T)(rng() % range); }

#define CONCAT_(x, y) x##y/*{{{*/
#define CONCAT(x, y) CONCAT_(x, y)
#ifdef LOCAL_DEBUG   
int __db_level = 0;
bool __db_same_line = false;
#define clog cerr << string(!__db_same_line ? __db_level * 2 : 0, ' ')
struct debug_block {
    function<void()> fn;
    void print_name() { __db_same_line = true; fn(); clog << endl; __db_same_line = false;  }
    debug_block(function<void()> fn_): fn(fn_) { clog << "{ "; print_name(); ++__db_level; }
    ~debug_block() { --__db_level; clog << "} "; print_name(); }
};
#define DB(args...) debug_block CONCAT(dbbl, __LINE__)([=]{ clog << args; })
#define deb(...)  if (1) { (clog << "[" #__VA_ARGS__ "] = [" << __VA_ARGS__) << "]"; if (!__db_same_line) clog << endl; }
#else
#define clog if (0) cerr
#define DB(...)
#define deb(...)
#endif
template<class T>
ostream& operator,(ostream& out, const T& thing) { return out << ", " << thing; }
template<class U, class V>
ostream& operator<<(ostream& out, const pair<U, V>& p) { return (out << "(" << p.first, p.second) << ")"; }
template<class A, class B>
ostream& operator<<(ostream& out, const tuple<A, B>& t) { return (out << "(" << get<0>(t), get<1>(t)) << ")"; }
template<class A, class B, class C>
ostream& operator<<(ostream& out, const tuple<A, B, C>& t) { return (out << "(" << get<0>(t), get<1>(t), get<2>(t)) << ")"; }
template<class T> ostream& operator<<(ostream& out, const vector<T>& container) { 
    out << "{";
    if (len(container)) out << container[0];
    rep1(i, len(container) - 1) out, container[i];
    return out << "}";
}
template<class x> vector<typename x::value_type> $v(const x& a) { return vector<typename x::value_type>(a.begin(), a.end()); }
#define ptrtype(x) typename iterator_traits<x>::value_type
template<class u> vector<ptrtype(u)> $v(u a, u b) { return vector<ptrtype(u)>(a, b); }/*}}}*/
// ACTUAL SOLUTION BELOW ////////////////////////////////////////////////////////////

int mex(const set<int>& u) {
    int ans = 0;
    while (u.count(ans)) ++ans;
    return ans;
}

vector<vector<int>> gen_nim(int n, int x, int y, int z) {
    vector<int> nim[3];
    rep(i, 3) nim[i].resize(n);
    auto get_nim = [&](int i, int s) {
        if (i < 0) return 0;
        return nim[s][i];
    };

    for (int i = 1; i < n; ++i) {
        nim[0][i] = mex({get_nim(i - x, 0), get_nim(i - y, 1), get_nim(i - z, 2)});
        nim[1][i] = mex({get_nim(i - x, 0), get_nim(i - z, 2)});
        nim[2][i] = mex({get_nim(i - x, 0), get_nim(i - y, 1)});
    }
    return {nim[0], nim[1], nim[2]};
}

int find_suff_period(const vector<int>& u) {
    for (int p = 1; p < len(u) / 2; ++p) {
        int correct_time = 0;
        for (int i = len(u) - 1; i - p >= 0; --i) {
            if (u[i] != u[i - p]) break;
            ++correct_time;
        }
        if (correct_time > 50) return p;
    }
    assert(false);
    return -1;
}

vector<int> nims[3][6][6][6];
int period[3][6][6][6];
int get_nim(llong num, int s, int x, int y, int z) {
    if (num < 0) return 0;
    // DB("get_nim"; deb(num, s, x, y, z)); 
    if (nims[s][x][y][z].empty()) {
        auto cur_nims = gen_nim(100, x, y, z);
        rep(i, 3) {
            nims[i][x][y][z] = cur_nims[i];
            period[i][x][y][z] = find_suff_period(nims[i][x][y][z]);
        }
    }
    int nim_len = len(nims[s][x][y][z]);
    int per = period[s][x][y][z];
    if (num < nim_len) return nims[s][x][y][z][num];
    num -= len(nims[s][x][y][z]);
    num %= per;
    return nims[s][x][y][z][nim_len - per + num];
}

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int ntest; cin >> ntest;
    rep1(testcase, ntest) { 
        int n, x, y, z; cin >> n >> x >> y >> z;
        vector<llong> num(n);
        vector<int> cur_nims(n);

        rep(i, n) {
            cin >> num[i];
            cur_nims[i] = get_nim(num[i], 0, x, y, z);
        }

        int nim_sum = 0;
        int ans = 0;
        for (auto i: cur_nims) nim_sum ^= i;
        rep(i, n) { 
            int cur_nim_sum = nim_sum ^ cur_nims[i];

            ans += cur_nim_sum == get_nim(num[i] - x, 0, x, y, z);
            ans += cur_nim_sum == get_nim(num[i] - y, 1, x, y, z);
            ans += cur_nim_sum == get_nim(num[i] - z, 2, x, y, z);
        }

        cout << ans << '\n';
    }

    return 0;
}