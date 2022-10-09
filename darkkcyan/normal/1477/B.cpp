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

const int maxn = 201010;

int it[maxn * 4], lz[maxn * 4];
void build(const string& s, int i, int l, int r) {
    if (l >= r) return ;
    lz[i] = -1;
    if (l == r - 1) {
        it[i] = s[l] - '0';
        return ;
    }
    
    int mid = (l + r) / 2;
    build(s, 2 * i, l, mid);
    build(s, 2 * i + 1, mid, r);
    it[i] = it[2 * i] + it[2 * i + 1];
}

void propagate(int i, int l, int r) {
    if (l >= r) return ;
    if (lz[i] == -1) return ;
    it[i] = lz[i] * (r - l);
    if (l < r - 1) {
        lz[2 * i] = lz[2 * i + 1] = lz[i];
    }
    lz[i] = -1;
}

void upd(int from, int to, int val, int i, int l, int r) {
    propagate(i, l, r);
    if (l >= r or from >= r or l >= to) return ;
    if (from <= l and r <= to) {
        lz[i] = val;
        propagate(i, l, r);
        return ;
    }
    int mid = (l + r) / 2;
    upd(from, to, val, 2 * i, l, mid);
    upd(from, to, val, 2 * i + 1, mid, r);
    it[i] = it[2 * i] + it[2 * i + 1];
}

int get(int from, int to, int i, int l, int r) {
    propagate(i, l, r);
    if (l >= r or from >= r or l >= to) return 0;
    if (from <= l and r <= to) return it[i];
    int mid = (l + r )  / 2;
    return get(from, to, 2 * i, l, mid) + get(from, to, 2 * i + 1, mid, r);
}

bool cmp(const string& s, int i, int l, int r) {
    propagate(i, l, r);
    if (l >= r) return true;
    if (l == r - 1) {
        return s[l] - '0' == it[i];
    }
    int mid = (l + r) / 2;
    return cmp(s, 2 * i, l, mid) and cmp(s, 2 * i + 1, mid, r);
}

int n, q;
string s, f;
int ql[maxn], qr[maxn];
int main(void) {
#ifdef LOCAL
    freopen("main.inp", "r", stdin);
    freopen("main.out", "w", stdout);
    freopen(".log", "w", stderr);
#endif
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int ntest; cin >> ntest;
    while (ntest--) {
        cin >> n >> q;
        cin >> s >> f;
        build(f, 1, 0, len(f));
        rep(i, q) {
            cin >> ql[i] >> qr[i];
            --ql[i];
        }
        bool ok = true;
        for (int i = q; i--; ) {
            int t = get(ql[i], qr[i], 1, 0, len(f));
            if (t * 2 == qr[i] - ql[i]) {
                ok = false;
                break;
            }
            if (t * 2 < qr[i] - ql[i]) {
                upd(ql[i], qr[i], 0, 1, 0, len(f));
            } else {
                upd(ql[i], qr[i], 1, 1, 0, len(f));
            }
        }
        if (ok) ok = cmp(s, 1, 0, len(f));
        if (ok) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
    
    return 0;
}

// vim: foldmethod=marker