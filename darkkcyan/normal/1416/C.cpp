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
using ans_type = pair<llong, llong>;
constexpr bool testing = 0;
constexpr bool print_brute = 0;
constexpr bool multitest = 0;

mt19937 rng(testing ? 177013 : chrono::system_clock::now().time_since_epoch().count());  // or mt19937_64

const int maxn = 301010;
int n;
int a[maxn];

void read() {
    if constexpr(!testing) {
        cin >> n;
        rep(i, n) cin >> a[i];
    } else {
        ofstream inp("main.inp");
        n = 10;
        const int maxa = 20;
        rep(i, n) a[i] = (int)(rng() % maxa) + 1;
        inp << n << endl;
        rep(i, n) inp << a[i] << ' ';
    }
}

void print_ans(ostream& cout, const ans_type& ans) {
    cout << ans.first << ' ' << ans.second << '\n';
}
const int max_bit = 31;

ans_type solve() {
    pair<llong, llong> ans;
    
    llong min_ans = 0;
    array<pair<llong, llong>, max_bit> lv_ans;
    vector<vector<int>> buckets(1);
    rep(i, n) buckets[0].push_back(a[i]);
    
    for (int cur_bit = max_bit; cur_bit--; ) {
        llong ans0 = 0, ans1 = 0;
        
        vector<vector<int>> new_buckets;
        for (auto& cur_buck: buckets) {
            vector<int> left_buck, right_buck;
            int cnt0 = 0, cnt1 = 0;
            for (auto i: cur_buck) {
                int bit = (i  >> cur_bit) & 1;
                if (bit) {
                    ans1 += cnt0;
                    cnt1++;
                    right_buck.push_back(i);
                } else {
                    ans0 += cnt1;
                    cnt0 ++;
                    left_buck.push_back(i);
                }
            }
            if (len(left_buck)) new_buckets.push_back(left_buck);
            if (len(right_buck)) new_buckets.push_back(right_buck);
        }
        lv_ans[cur_bit] = {ans0, ans1};
        min_ans += min(ans0, ans1);
        buckets = new_buckets;
    }
    
    llong min_mask = 0;
    llong cur_ans = 0;
    for (int i = max_bit; i --; ) {
        llong new_ans = cur_ans + lv_ans[i].first;
        clog << db(i) << db(cur_ans) << db(new_ans) << endl;
        clog << db(lv_ans[i]) << endl;
        for (int f = i; f--; ) {
            new_ans += min(lv_ans[f].first, lv_ans[f].second);
        }
        if (new_ans > min_ans) {
            min_mask |= 1 << i;
            cur_ans += lv_ans[i].second;
            clog << db(cur_ans) << endl;
            clog << "pick " << endl;
        } else {
            cur_ans += lv_ans[i].first;
        }
        clog << db(i) << db(cur_ans)  << endl;
    }
    return {min_ans, min_mask};
}

ans_type brute() {
    pair<llong, llong> ans(LLONG_MAX, LLONG_MAX);
    rep(cur_mask, 100) {
        llong cur_inv = 0;
        rep(i, n) for (int f = i + 1; f < n; ++f) {
            if ((a[i] ^ cur_mask) > (a[f] ^ cur_mask)) ++cur_inv;
        }
        ans = min(ans, {cur_inv, cur_mask});
    }
    return ans;
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