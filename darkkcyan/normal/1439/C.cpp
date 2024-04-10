#ifdef LOCAL 
// #define testing 
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

const int maxn = 201010;
int n, q;
llong a[maxn];

llong sum[maxn * 4], mx[maxn * 4], mi[maxn * 4], lz[maxn * 4];

inline void reset(int i, int l, int r) {
    if (r - l <= 0) return ;
    sum[i] = sum[2 * i] + sum[2 * i + 1];
    mx[i] = max(mx[2 * i], mx[2 * i + 1]);
    mi[i] = min(mi[2 * i], mi[2 * i + 1]);
}

void build(int i, int l, int r) {  // [l; r)
    lz[i] = -1;
    if (r - l == 1) {
        sum[i] = mx[i] = mi[i] = a[l];
    }
    if (r - l <= 1) return ;
    int mid = (l + r + 1) / 2;
    build(2 * i, l, mid);
    build(2 * i + 1, mid, r);
    reset(i, l, r);
}

inline void propagate(int i, int l, int r) {
    if (lz[i] == -1) return ;
    sum[i] = 1ll * lz[i] * (r - l);
    mx[i] = mi[i] = lz[i];
    if (r - l > 1) {
        lz[2 * i] = lz[2 * i + 1] = lz[i];
    }
    lz[i] = -1;
}

void assign(int x, llong y, int i, int l, int r) {  // set [0; x)
    propagate(i, l, r);
    if (l >= r or l >= x) return ;
    if (r <= x) {
        if (mi[i] > y) return ;
        if (mx[i] <= y) {
            clog << db(i) << db(l) << db(r) << db(sum[i]) << db(mx[i]) << endl;
            lz[i] = y;
            propagate(i, l, r);
            return ;
        }
    }
    if (r - l <= 1) {
        return ;
    }
    int mid = (l + r + 1) / 2;
    assign(x, y, 2 * i, l, mid);
    assign(x, y, 2 * i + 1, mid, r);
    reset(i, l, r);
}

llong get_sum(int from, int to, int i, int l, int r) { // [from; to)
    propagate(i, l, r);
    if (l >= r or l >= to or from >= r) return 0;
    if (from <= l and r <= to) return sum[i];
    int mid = (l + r + 1) / 2;
    return get_sum(from, to, 2 * i, l, mid) + get_sum(from, to, 2 * i + 1, mid, r);
}

int find_pos_by_sum(llong the_sum, int i, int l, int r) { // find first pos that has sum from [l; pos) > sum
    propagate(i, l, r);
    if (the_sum < 0) return l;
    if (sum[i] < the_sum) return r;
    if (r - l == 1) return r;
    int mid = (l + r + 1) / 2;
    int ans = find_pos_by_sum(the_sum, 2 * i, l, mid);  // this also propagate sum of the left child
    if (ans == mid) ans = find_pos_by_sum(the_sum - sum[2 * i], 2 * i + 1, mid, r);
    return ans;
}

int find_pos_by_val(llong val, int i, int l, int r) {  // first pos from l to r that is bigger or eq to val
    propagate(i, l, r);
    if (mx[i] <= val) return l;
    if (mi[i] > val) return r;
    if (r - l == 1) return l;
    int mid = (l + r + 1) / 2;
    int ans = find_pos_by_val(val, 2 * i, l, mid);
    if (ans == mid) ans = find_pos_by_val(val, 2 * i + 1, mid, r);
    return ans;
}

void print_it(ostream& out, int i, int l, int r) {
    propagate(i, l, r);
    if (r - l == 1) {
        out << mx[i] << ' ';
        return ;
    }
    int mid = (l + r + 1) / 2;
    print_it(out, 2 * i, l, mid);
    print_it(out, 2 * i + 1, mid, r);
}

int main(void) {
#ifdef LOCAL
    freopen("main.inp", "r", stdin);
    freopen("main.out", "w", stdout);
    freopen(".log", "w", stderr);
#endif
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifdef testing
    n = q = 200'000;
    rep(i, n) a[i] = rand() % 1'000'000'000+ 1;
    sort(a, a + n, greater<int>());
#else
    cin >> n >> q;
    rep(i, n) cin >> a[i];
#endif
    build(1, 0, n);
    // print_it(cout, 1, 0, n);  
    // cout << endl;  
    rep(query, q) {
        int type, x;
        llong y;
#ifdef testing
        type = rand() % 2 + 1;
        x = rand() % n + 1;
        y = rand() % 1'000'000'000+ 1;
#else
        cin >> type >> x >> y;
#endif
        if (type == 1) {
            assign(x, y, 1, 0, n);
            // print_it(cerr, 1, 0, n); 
            // cerr << endl; 
        } else {
            int ans = 0;
            DB(db(x) << db(y) << db(n));
            --x;
            while (y > 0 and x < n) {
                int start = find_pos_by_val(y, 1, 0, n);
                start = max(start, x);
                if (start >= n) break;
                llong nxt_sum = get_sum(0, start, 1, 0, n);
                int end = find_pos_by_sum(y + nxt_sum, 1, 0, n);
                llong diff = get_sum(0, end, 1, 0, n) - nxt_sum;
                if (diff > y) {
                    --end;
                    diff -= get_sum(end, end + 1, 1, 0, n);
                }
                if (diff == 0) break;
                y -= diff;
                clog << db(start) << db(end) << db(diff) << db(y) << endl;
                ans += end - start;
                x = end;
                if (x >= n) break;
                // print_it(cout, 1, 0, n); cout << endl; 
                assert(2 * diff >= y); 
            }
            cout << ans << '\n';
        }
    }
    
    return 0;
}

// vim: foldmethod=marker