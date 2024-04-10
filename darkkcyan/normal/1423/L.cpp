// #define multitest 
#ifdef LOCAL
// #define testing 
// #define print_brute 
#endif

#include <bits/stdc++.h>
using namespace std;

#define llong long long 
#define len(x) ((int)x.size())
#define rep(i,n) for (int i = -1; ++ i < n; )
#define rep1(i,n) for (int i = 0; i ++ < n; )
#ifdef testing
mt19937 rng(177013);
#else
mt19937 rng(chrono::system_clock::now().time_since_epoch().count());
#endif
#define rand() (int)(rng() >> 1)
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
// ACTUAL SOLUTION START HERE ////////////////////////////////////////////////////////////////

using ans_type = vector<int>;

const int maxn = 1030;
const int maxs = 33;
const int maxd = 1010;
int n, s, d;
bitset<maxn> swi[maxs];
bitset<maxn> qr[maxd];

void read() {
    cin >> n >> s >> d;
    rep(i, s) {
        swi[i].reset();
        int c; cin >> c;
        while (c--) {
            int u; cin >> u;
            --u;
            swi[i][u] = 1;
        }
    }
    rep(i, d) {
        qr[i].reset();
        int t; cin >> t;
        while (t--) {
            int u; cin >> u; --u;
            qr[i][u] = 1;
        }
    }
}

void print_ans(ostream& cout, const ans_type& ans) {
    for (auto i: ans) cout << i << '\n';
}

ans_type solve() {
    
    vector<bitset<maxn>> basis(n);
    vector<int> control_bits;
    rep(i, s) {
        auto cur = swi[i];
        rep(f, n) {
            if (!cur[f]) continue;
            if (basis[f].any()) cur ^= basis[f];
            else {
                basis[f] = cur;
                control_bits.push_back(f);
                break;
            }
        }
    }
    
    auto has_ans = [&](bitset<maxn> big_mask) {
        rep(i, n) {
            if (!big_mask[i]) continue;
            if (!basis[i].any()) return false;
            big_mask ^= basis[i];
        }
        return true;
    };
    
    sort(control_bits.begin(), control_bits.end());
    assert(len(control_bits) <= s);
    vector<int> small_swi(s);
    auto get_small_mask = [&](const bitset<maxn>& big_mask) {
        int ans = 0;
        for (auto i: control_bits) ans = ans << 1 | big_mask[i];
        return ans;
    };
    rep(i, s) {
        small_swi[i] = get_small_mask(swi[i]);
    }
    
    unordered_map<int, int> head, tail;
    function<void(unordered_map<int, int>&, int, int, int, int)> add_val = 
        [&](unordered_map<int, int>& mp, int cur, int last, int mask, int pressed) {
        if (cur == last) {
            auto it = mp.find(mask);
            if (it == mp.end()) mp[mask] = pressed;
            else it->second = min(it->second, pressed);
            return ;
        }
        add_val(mp, cur + 1, last, mask, pressed);
        add_val(mp, cur + 1, last, mask ^ small_swi[cur], pressed + 1);
    };
    
    add_val(head, 0, len(small_swi) / 2, 0, 0);
    add_val(tail, len(small_swi) / 2, len(small_swi), 0, 0);
    
    vector<int> ans(d);
    rep(i, d) {
        if (!has_ans(qr[i])) {
            ans[i] = -1;
            continue;
        }
        int cur_mask = get_small_mask(qr[i]);
        ans[i] = INT_MAX;
        for (auto& [h, ch]: head) {
            int t = cur_mask ^ h;
            if (tail.count(t)) ans[i] = min(ans[i], tail[t] + ch);
        }
    }
    
    return ans;
}

// ACUTAL SOLUTION END HERE //////////////////////////////////////////////////////////////////
// FOR HACKER/READER - you don't need to care about the part below
ans_type brute();
#ifndef testing
int main(void) {
#ifdef LOCAL
    freopen("main.inp", "r", stdin);
    freopen("main.out", "w", stdout);
    freopen(".log", "w", stderr);
#endif
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int ntest = 1;
#ifdef multitest
    cin >> ntest;
#endif
    rep1(testcase, ntest) {
        DB(testcase);
        read();
        auto ans = solve();
        print_ans(cout, ans);
#ifdef print_brute
        auto br = brute();
        print_ans(cout << endl << "====" << endl, br);
        cout << endl << "==============" << endl;
#endif
    }
    return 0;
}
#else
void gen_test(int cur_test) {
    ofstream inp("main.inp");
    
}
int main(void) {
    rep1(testcase, 10000) {
        gen_test(testcase);
        auto ans = solve();
        auto br = brute();
        assert(ans == br);
        cout << "OK " << testcase << endl;
    }
    return 0;
}
#endif

ans_type brute() {
    return ans_type();
}

// vim: foldmethod=marker