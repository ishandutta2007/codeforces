#include <bits/stdc++.h>
using namespace std;

#define llong long long 
#define len(x) ((int)x.size())
#define rep(i,n) for (int i = -1; ++ i < n; )
#define rep1(i,n) for (int i = 0; i ++ < n; )
#define CONCAT_(x, y) x##y/*{{{*/
#define CONCAT(x, y) CONCAT_(x, y)
#define SPEC(name) CONCAT(name, __LINE__)
#ifdef LOCAL_DEBUG   
int __db_level = 0;
#define clog cerr << string(__db_level * 2, ' ')
struct debug_block {
    string msg;
    debug_block(const string& s): msg(s) { clog << "{ " << msg << endl; ++__db_level; }
    ~debug_block() { --__db_level; clog << "} " << msg << endl; }
};
#define DB(args...) stringstream SPEC(ss); SPEC(ss)<< args; debug_block SPEC(dbbl)(SPEC(ss).str())
#else
#define clog if (0) cerr
#define DB(...)
#endif
#define db(val) "[" #val " = " << val << "]; "
template<class U, class V> ostream& operator<<(ostream& out, const pair<U, V>& p) {
    return out << "(" << p.first << ", " << p.second << ")";
}
template<size_t i, class T> ostream& print_tuple_utils(ostream& out, const T& tup) {
    if constexpr(i == tuple_size<T>::value) return out << ")";
    else return print_tuple_utils<i + 1, T>(out << (i ? ", " : "(") << get<i>(tup), tup);
}
template<class ...U>
ostream& operator<<(ostream& out, const tuple<U...>& tup) { return print_tuple_utils<0, tuple<U...>>(out, tup); }
template<class, typename = void> struct has_const_iterator : false_type {};
template<class T> struct has_const_iterator<T, void_t<typename T::const_iterator>> : true_type {};
template<class T>
typename enable_if<has_const_iterator<T>::value && !is_same<T, string>::value, ostream&>::type
operator<<(ostream& out, const T& container) { 
    auto beg = container.begin(), end = container.end();
    out << "(" << container.size() << ") {";
    if (beg != end) out << *(beg++);
    while (beg != end) out << ", " << *(beg++);
    return out << "}";
}
#define ptrtype(x) typename iterator_traits<x>::value_type
template<class u> vector<ptrtype(u)> $v(u a, u b) { return vector<ptrtype(u)>(a, b); }/*}}}*/
// ACTUAL SOLUTION BELOW ////////////////////////////////////////////////////////////

// Change these
using ans_type = llong;
constexpr bool testing = 0;
constexpr bool print_brute = 0;
constexpr bool multitest = 0;

mt19937 rng(testing ? 177013 : chrono::system_clock::now().time_since_epoch().count());  // or mt19937_64

const int maxn = 2020;
const int max_val = (int)(3e6 + 10);
using point = pair<int, int>;
#define x first
#define y second
int n, m;
point robber[maxn], light[maxn];

void read() {
    if constexpr(!testing) {
        cin >> n >> m;
        rep(i, n) cin >> robber[i].x >> robber[i].y;
        rep(i, m) cin >> light[i].x >> light[i].y;
    } else {
        ofstream inp("main.inp");
        // generate test
    }
}

void print_ans(ostream& cout, const ans_type& ans) {
    cout << ans << '\n';
}

ans_type solve() {
    sort(light, light + m);
    clog << db(vector(light, light + m)) << endl;
    {
        int new_m = 0;
        rep(i, m) {
            while (new_m and light[new_m - 1].y <= light[i].y) --new_m;
            light[new_m++] = light[i];
        }
        m = new_m;
    }
    clog << db(vector(light, light + m)) << endl;
    clog << db(vector(robber, robber + n)) << endl;
    
    vector<vector<pair<int, int>>> moments(max_val);
    rep(i, n) rep(f, m) {
        int dist = light[f].x + 1 - robber[i].x;
        if (dist <= 0) continue;
        moments[dist].emplace_back(i, f + 1);
    }
    
    multiset<int, greater<int>> up_set;
    vector<int> cur_up(n, 0);
    rep(i, n) {
        rep(f, m) {
            if (light[f].x < robber[i].x) continue;
            cur_up[i] = max(0, light[f].y - robber[i].y + 1);
            break;
        }
        up_set.insert(cur_up[i]);
    }
    
    clog << db(up_set) << endl;
    int ans = *up_set.begin();
    
    rep(t, max_val) {
        if (!len(moments[t])) continue;
        clog << db(t) << ' ' << db(moments[t]) << endl;
        for (auto [i, f]: moments[t]) {
            up_set.erase(up_set.find(cur_up[i]));
            int ly = f == m ? -100 : light[f].y;
            cur_up[i] = max(0, ly - robber[i].y + 1);
            up_set.insert(cur_up[i]);
        }
        clog << db(up_set) << endl;
        clog << db(cur_up) << endl;
        ans = min(ans, t + *up_set.begin());
    }
    return ans;
}

ans_type brute() {
    return ans_type();
}

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int ntest = testing ? 1000 : 1; 
    if (multitest and !testing) cin >> ntest;
    
    rep1(testcase, ntest) {
        DB(testcase);
        read();
        if constexpr (!testing) {
            print_ans(cout, solve());
            if (print_brute) print_ans(cout << endl << "====" << endl, brute());
        } else {
            auto u = solve();
            auto v = brute();
            assert(u == v);
        }
    }
    

    return 0;
}

// Remember:
// - Multitest? REFRESHING the data!!!
// - Constrains for each set of data may differs. Should NOT USE the same max constant (maxn)
//   for all of them.
// vim: foldmethod=marker