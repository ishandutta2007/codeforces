#include <bits/stdc++.h>
using namespace std;

// #define constexpr(...) (__VA_ARGS__)  
using ll = long long;
using ld = long double;
const ld eps = 1e-8;
// for matching the kactl notes
#define sz(x) ((int)x.size())
#define rep(i,a,b) for (int i = (a); i < (b); ++i) 
#define all(a) (a).begin(), (a).end()
#define print_op(...) ostream& operator<<(ostream& out, const __VA_ARGS__& u)
// DEBUGING TEMPLETE ////////////////////////////////////////////////////////////////////////{{{
// What? You wanted to see how this template works?  Check this out:
// https://quangloc99.github.io/2021/07/30/my-CP-debugging-template.html
#define db(val) "["#val" = "<<(val)<<"] "
#define CONCAT_(x, y) x##y
#define CONCAT(x, y) CONCAT_(x, y)
#ifdef LOCAL_DEBUG   
#   define clog cerr << setw(__db_level * 2) << setfill(' ') << "" << setw(0)
#   define DB() debug_block CONCAT(dbbl, __LINE__)
    int __db_level = 0;
    struct debug_block {
        debug_block() { clog << "{" << endl; ++__db_level; }
        ~debug_block() { --__db_level; clog << "}" << endl; }
    };
#else
#   define clog if (0) cerr
#   define DB(...)
#endif

template<class U, class V> print_op(pair<U, V>) {
    return out << "(" << u.first << ", " << u.second << ")";
}
template<class Con, class = decltype(begin(declval<Con>()))>
typename enable_if<!is_same<Con, string>::value, ostream&>::type
operator<<(ostream& out, const Con& con) { 
    out << "{";
    for (auto beg = con.begin(), it = beg; it != con.end(); ++it)
        out << (it == beg ? "" : ", ") << *it;
    return out << "}";
}
template<size_t i, class T> ostream& print_tuple_utils(ostream& out, const T& tup) {
    if constexpr(i == tuple_size<T>::value) return out << ")"; 
    else return print_tuple_utils<i + 1, T>(out << (i ? ", " : "(") << get<i>(tup), tup); 
}
template<class ...U> print_op(tuple<U...>) {
    return print_tuple_utils<0, tuple<U...>>(out, u);
}
// ACTUAL SOLUTION START HERE ////////////////////////////////////////////////////////////////}}}

struct Segtree {
    int len;
    vector<int> data;
    Segtree(int n, int init_val = INT_MIN): len(n), data(2 * n, init_val) {
    }
    
    int get(int l, int r) {
        int ans = INT_MAX;
        for (l += len, r += len; l < r; l >>= 1, r >>= 1) {
            if (l & 1) ans = min(ans, data[l++]);
            if (r & 1) ans = min(ans, data[--r]);
        }
        return ans;
    };
    void upd(int i, int v) {
        i += len;
        data[i] = v;
        do {
            i >>= 1;
            data[i] = min(data[2 * i], data[2 * i + 1]);
        } while (i > 0) ;
    }
};

struct Rook {
    int r, c;
};

struct Rect {
    int r1, c1, r2, c2, id;
};

int n, m, k, q;
vector<Rook> rooks;
vector<Rect> rects;
vector<bool> ans;

void solve_horizontal() {
    Segtree st(m);
    sort(rooks.begin(), rooks.end(), [](const Rook& u, const Rook& v) {
            return u.c < v.c;
            });
    
    sort(rects.begin(), rects.end(), [](const Rect& u, const Rect& v) {
            return u.c2 < v.c2;
            });
    
    int f = 0;
    for (auto& r: rects) {
        while (f < (int)rooks.size() and rooks[f].c < r.c2) {
            st.upd(rooks[f].r, rooks[f].c);
            ++f;
        }
        if (st.get(r.r1, r.r2) >= r.c1) {
            ans[r.id] = true;
        }
    }
}

void solve() {
    ans.resize(q);
    solve_horizontal();
    for (auto& i: rooks) swap(i.r, i.c);
    for (auto& i: rects) {
        swap(i.r1, i.c1);
        swap(i.r2, i.c2);
    }
    swap(n, m);
    solve_horizontal();
}

int main() {
#ifdef LOCAL
    freopen("main.inp", "r", stdin); 
    freopen("main.out", "w", stdout);  
    freopen(".log", "w", stderr);
#endif
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> m >> k >> q;
    rooks.resize(k);
    rects.resize(q);
    for (auto& it: rooks) {
        cin >> it.c >> it.r;
        --it.c;
        --it.r;
    }
    rep(i, 0, q) {
        cin >> rects[i].c1 >> rects[i].r1 >> rects[i].c2 >> rects[i].r2;
        rects[i].id = i;
        --rects[i].c1;
        --rects[i].r1;
    }
    solve();
    
    for (auto i: ans) 
        cout << (i ? "YES" : "NO") << '\n';
    
    return 0;
}

// vim: foldmethod=marker