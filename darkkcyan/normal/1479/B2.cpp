#ifdef LOCAL
#define testing           
#endif
#include <bits/stdc++.h>
using namespace std;

#define llong long long 
#define len(x) ((int)x.size())
#define rep(i,n) for (int i = -1; ++ i < n; )
#define rep1(i,n) for (int i = 0; i ++ < n; )
#ifdef testing/*{{{*/
mt19937 rng(177013);
#else
mt19937 rng(chrono::system_clock::now().time_since_epoch().count());
#endif
#define rand() (int)(rng() >> 1)
#define CONCAT_(x, y) x##y
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

const int maxn = 101010;
const int inf = 1e7;
int it[maxn * 4], lz[maxn * 4];
void build(int i, int l, int r) {
    if (l >= r) return ;
    lz[i] = 0;
    it[i] = inf;
    if (l == r - 1) return ;
    int mid = (l + r) / 2;
    build(2 * i, l, mid);
    build(2 * i + 1, mid, r);
}
void push(int i, int l, int r) {
    it[i] += lz[i];
    if (r - l > 1) {
        lz[2 * i] += lz[i];
        lz[2 * i + 1] += lz[i];
    }
    lz[i] = 0;
}

int get(int from, int to, int i, int l, int r) {
    push(i, l, r);
    if (from >= r or l >= to) return inf;
    if (from <= l and r <= to) return it[i];
    int mid = (l + r) / 2;
    return min(get(from, to, 2 * i, l, mid), get(from, to, 2 * i + 1, mid, r));
}

void upd(int from, int to, int delta, int i, int l, int r) {
    push(i, l, r);
    if (from >= r or l >= to) return ;
    if (from <= l and r <= to) {
        lz[i] += delta;
        push(i, l, r);
        return ;
    }
    int mid = (l + r) / 2;
    upd(from, to, delta, 2 * i, l, mid);
    upd(from, to, delta, 2 * i + 1, mid, r);
    it[i] = min(it[2 * i], it[2 * i + 1]);
}

void assign_min(int pos, int val, int i, int l, int r) {
    push(i, l, r);
    if (pos < l or pos >= r) return ;
    if (r - l == 1) {
        it[i] = min(it[i], val);
        return ;
    }
    int mid = (l + r) / 2;
    assign_min(pos, val, 2 * i, l, mid);
    assign_min(pos, val, 2 * i + 1, mid, r);
    it[i] = min(it[2 * i], it[2 * i + 1]);
}

void print(ostream& out, int i, int l, int r) {
#ifdef LOCAL_DEBUG
    push(i, l, r);
    if (r - l == 1) {
        out << it[i] << ' ';
        return ;
    }
    int mid = (l + r) / 2;
    print(out, 2 * i, l, mid);
    print(out, 2 * i + 1, mid, r);
#endif
}

int n;
vector<int> a;
int solve() {
    auto b = a;
    b.erase(unique(b.begin(), b.end()), b.end());
    if (len(b) <= 2) return len(b);
    int sz = n + 2;
    build(1, 0, sz);
    
    int special = n + 1;
    assign_min(special, 2, 1, 0, sz);
    assign_min(b[0], 2, 1, 0, sz);
    
    for (int i = 2; i < len(b); ++i) {
        DB(i);
        int prv = b[i - 1];
        int cur = b[i];
        clog << db(cur) << endl;
        int mi_for_prev = min({
                get(0, cur, 1, 0, sz) + 1, get(cur + 1, sz, 1, 0, sz) + 1, get(cur, cur + 1, 1, 0, sz)
                });
        clog << db(get(0, cur, 1, 0, sz)) << db(get(cur + 1, sz, 1, 0, sz)) << db(get(cur, cur + 1, 1, 0, sz)) << endl;
        clog << db(mi_for_prev) << endl;
        
        upd(0, sz, 1, 1, 0, sz);
        print(cerr, 1, 0, sz);
        clog << endl;
        clog << db(prv) << db(mi_for_prev) << endl;
        assign_min(prv, mi_for_prev, 1, 0, sz);
        clog << db(i) << db(it[1]) << endl;
        print(cerr, 1, 0, sz);
        clog << endl;
    }
    
    return it[1];
}

int brute() {
    pair<int, int> ans = {INT_MAX, 0};
    rep(mask, (1 << n)) {
        int cur_ans = 0;
        int prv[2] = {-1, -1};
        rep(i, n) {
            auto& cur = prv[(mask >> i) & 1];
            if (cur == a[i]) continue;
            cur = a[i];
            ++cur_ans;
        }
        ans = min(ans, {cur_ans, mask});
    }
    clog << bitset<9>(ans.second) << endl;
    return ans.first;
}
int main(void) {
#ifdef testing
    while (true) {
        n = rand() % 10 + 1;
        a.resize(n);
        rep(i, n) a[i] = rand() % n + 1;
            ofstream inp("main.inp");
            inp << n << endl;
            for (auto i: a ) inp << i << ' ';
            inp << endl;

        auto exp = brute();
        auto ans = solve();
        inp << exp << ' ' << ans << endl;
        if (exp == ans) {
            cout << "OK" << endl;
            continue;
        }
        cout << "FAILED" << endl;
        return 0;
    }
#endif
#ifdef LOCAL
    freopen("main.inp", "r", stdin);
    freopen("main.out", "w", stdout);
    freopen(".log", "w", stderr);
#endif
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    cin >> n;
    a.resize(n);
    rep(i, n) cin >> a[i];
    cout << solve() << endl;
#ifdef LOCAL
    cout << brute() << endl;
#endif
    
    return 0;
}

// vim: foldmethod=marker