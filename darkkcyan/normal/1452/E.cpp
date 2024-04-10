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

struct range {
    int l, r;  // [l; r)
    range(int l_ = 0, int r_ = 0): l(l_), r(r_) {}
    bool empty() const {
        return l >= r;
    }
    
    int length() const {
        if (empty()) return 0;
        return r - l;
    }
};

range intersect(const range& u, const range& v) {
    return range(max(u.l, v.l), min(u.r, v.r));
}
const int maxn = 10101;
int n, m, k;
range a[maxn];

void gen_test() {
    ofstream inp("main.inp");
    n = rand() % 10 + 1;
    m = rand() % 10 + 1;
    k = rand() % n + 1;
    inp << n << ' ' << m << ' ' << k << endl;
    rep(i, m) {
        a[i].l = rand() % n + 1;
        a[i].r = rand() % n + 1;
        if (a[i].l > a[i].r) swap(a[i].l, a[i].r);
        inp << a[i].l << ' ' << a[i].r << endl;
    }
}

int solve() {
    int ans = 0;
    rep1(l1, n - k + 1) {
        DB(db(l1));
        int base_ans = 0;
        int mid_dist = 3 * n;
        vector<int> add_ev_(2 * mid_dist), unadd_ev_(2 * mid_dist), rem_ev_(2 * mid_dist), unrem_ev_(2 * mid_dist);
        auto add_ev = add_ev_.begin() + mid_dist;
        auto unadd_ev = unadd_ev_.begin() + mid_dist;
        auto rem_ev = rem_ev_.begin() + mid_dist;
        auto unrem_ev = unrem_ev_.begin() + mid_dist;
        rep(f, m) {
            auto length = intersect(a[f], range(l1, l1 + k)).length();
            base_ans += length;
            int add_pos = a[f].l + length + 1 - k;
            if (add_pos <= a[f].l) {
                add_ev[add_pos]++;
                int unadd_pos = min(a[f].l, a[f].r - k) + 1;
                unadd_ev[unadd_pos]++;
                
                int rem_pos = max(a[f].l, a[f].r - k) + 1;
                rem_ev[rem_pos]++;
                int unrem_pos = a[f].r - (length + 1);
                unrem_ev[unrem_pos + 2]++;
            }
        }
        clog << db(base_ans) << endl;
        
        int cnt_inc = 0, cnt_dec = 0;
        int cur_ans = base_ans;
        
        for (int l2 = -mid_dist; l2 <= n; ++l2) {
            cnt_inc += add_ev[l2] - unadd_ev[l2];
            cnt_dec += rem_ev[l2] - unrem_ev[l2];
            cur_ans += cnt_inc - cnt_dec;
            clog << db(l1) << ' ' << db(l2) << db(cur_ans) << endl;
            if (l2 >= 1) {
                ans = max(ans, cur_ans);
            }
        }
    }
    return ans;
}

int brute() {
    int ans = 0;
    rep1(l1, n) {
        rep1(l2, n) {
            int cur_ans =0;
            rep(i, m) 
                cur_ans+= max(
                        intersect(a[i], range(l1, l1 + k)).length(),
                        intersect(a[i], range(l2, l2 + k)).length()
                    );
            ans = max(ans, cur_ans);
        }
    }
    return ans;
}

void stress() {
    while (true) {
        gen_test();
        auto exp = brute();
        auto ans = solve();
        if (exp == ans) {
            cout << "OK" << endl;
            continue;
        }
        cout << "Failed " << exp << ' ' << ans << endl;
        exit(0);
    }
}

int main(void) {
#ifdef testing
    stress();
#endif
#ifdef LOCAL
    freopen("main.inp", "r", stdin);
    freopen("main.out", "w", stdout);
    freopen(".log", "w", stderr);
#endif
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m >> k;
    rep(i, m) {
        cin >> a[i].l >> a[i].r;
        ++a[i].r;
    }
#ifdef print_brute
    cout << "BRUTE\n";
    cout << brute() << endl;
#else
    cout << solve();
#endif
    
    return 0;
}

// vim: foldmethod=marker