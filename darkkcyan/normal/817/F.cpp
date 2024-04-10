#include <bits/stdc++.h>
using namespace std;

// #define constexpr(...) (__VA_ARGS__)  
using ll = long long;
using ld = long double;
const ld eps = 1e-8;
// for matching the kactl notes
#define sz(x) ((int)x.size())
#define rep(i,a,b) for (int i = (int)(a); i < (int)(b); ++i) 
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

struct SegTree {
    int n;
    mutable vector<int> sum, set_lazy, inv_lazy;
    SegTree(int n_): n(n_), sum(4 * n), set_lazy(4 * n, -1), inv_lazy(4 * n, 0) {}
    void push(int i, int l, int r) const {
        if (set_lazy[i] != -1) {
            sum[i] = set_lazy[i] * (r - l);
            if (r - l > 1) {
                set_lazy[2 * i] = set_lazy[2 * i + 1] = set_lazy[i];
                inv_lazy[2 * i] = inv_lazy[2 * i + 1] = 0;
            }
            set_lazy[i] = -1;
        }
        if (inv_lazy[i]) {
            sum[i] = r - l - sum[i];
            if (r - l > 1) {
                inv_lazy[2 * i] ^= 1;
                inv_lazy[2 * i + 1] ^= 1;
            }
            inv_lazy[i] = 0;
        }
    }
    void upd_set(int from, int to, int what, int i, int l, int r) {
        // DB(); 
        // clog << db(from) << db(to) << db(i) << db(l) << db(r) << endl; 
        push(i, l, r);
        if (from >= r or l >= to) return ;
        if (from <= l and r <= to) {
            // clog << "here" << endl; 
            set_lazy[i] = what;
            inv_lazy[i] = 0;
            push(i, l, r);
            return ;
        }
        int mid = (l + r) / 2;
        upd_set(from, to, what, 2 * i, l, mid);
        upd_set(from, to, what, 2 * i + 1, mid, r);
        sum[i] = sum[2 * i] + sum[2 * i + 1];
    }
    void upd_inv(int from, int to, int i, int l, int r) {
        push(i, l, r);
        if (from >= r or l >= to) return ;
        if (from <= l and r <= to) {
            inv_lazy[i] ^= 1;
            push(i, l, r);
            return ;
        }
        int mid = (l + r) / 2;
        upd_inv(from, to, 2 * i, l, mid);
        upd_inv(from, to, 2 * i + 1, mid, r);
        sum[i] = sum[2 * i] + sum[2 * i + 1];
    }
    int find_min_zero(int i, int l, int r) {
        push(i, l, r);
        if (sum[i] == r - l) return r;
        if (r - l == 1) return l;
        int mid = (l + r) / 2;
        push(2 * i, l, mid);
        if (sum[2 * i] != mid - l) return find_min_zero(2 * i, l, mid);
        return find_min_zero(2 * i + 1, mid, r);
    }
    
    void upd_set(int from, int to, int what) {
        upd_set(from, to, what, 1, 0, n);
    }
    void upd_inv(int from, int to) {
        upd_inv(from, to, 1, 0, n);
    }
    int find_min_zero() {
        return find_min_zero(1, 0, n);
    }
    list<int> to_list(int i, int l, int r) const {
        push(i, l, r);
        if (r - l == 1) return {sum[i]};
        int mid = (l + r) / 2;
        auto ans = to_list(2 * i, l, mid);
        ans.splice(ans.end(), to_list(2 * i + 1, mid, r));
        return ans;
    }
    friend print_op(SegTree) {
        return out << u.to_list(1, 0, u.n);
    }
};

struct Query {
    int t;
    ll l, r;
};

int main() {
#ifdef LOCAL
    freopen("main.inp", "r", stdin); 
    freopen("main.out", "w", stdout);  
    freopen(".log", "w", stderr);
#endif
    cin.tie(0)->sync_with_stdio(0);
    
    vector<ll> values;
    int n; cin >> n;
    vector<Query> queries(n);
    for (auto& [t, l, r]: queries) {
        cin >> t >> l >> r;
        --l;
        values.push_back(l);
        values.push_back(r);
    }
    
    values.push_back(0);
    sort(all(values));
    values.erase(unique(all(values)), values.end());
    
    clog << db(values) << endl;
    
    SegTree st(sz(values));
    for (auto [t, l, r]: queries) {
        int il = (int)(lower_bound(all(values), l) - values.begin());
        int ir = (int)(lower_bound(all(values), r) - values.begin());
        if (t == 1) st.upd_set(il, ir, 1);
        else if (t == 2) st.upd_set(il, ir, 0);
        else st.upd_inv(il, ir);
        cout << values[st.find_min_zero()] + 1 << '\n';
        clog << db(st) << endl;
    }
    
    
    return 0;
}

// vim: foldmethod=marker