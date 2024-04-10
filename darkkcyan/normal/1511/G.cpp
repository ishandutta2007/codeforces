#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
const ld eps = 1e-8;
// for matching the kactl notes
#define sz(x) ((int)x.size())
#define rep(i,a,b) for (int i = (int)(a); i < (int)(b); ++i) 
#define all(a) (a).begin(), (a).end()
// #define constexpr(...) (__VA_ARGS__)  
// DEBUGING TEMPLETE ////////////////////////////////////////////////////////////////////////{{{
#define db(val) "["#val" = "<<(val)<<"] "
#define CONCAT_(x, y) x##y
#define CONCAT(x, y) CONCAT_(x, y)
#ifdef LOCAL_DEBUG   
#   define clog cerr << flush << string(__db_level * 2, ' ')
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

template<class U, class V> ostream& operator<<(ostream& out, const pair<U, V>& p) {
    return out << "(" << p.first << ", " << p.second << ")";
}

template<size_t i, class T> ostream& print_tuple_utils(ostream& out, const T& tup) {
    if constexpr(i == tuple_size<T>::value) return out << ")"; 
    else return print_tuple_utils<i + 1, T>(out << (i ? ", " : "(") << get<i>(tup), tup); 
}

template<class ...U> ostream& operator<<(ostream& out, const tuple<U...>& tup) {
    return print_tuple_utils<0, tuple<U...>>(out, tup);
}

template<class Con, class = decltype(begin(declval<Con>()))>
typename enable_if<!is_same<Con, string>::value, ostream&>::type
operator<<(ostream& out, const Con& container) { 
    out << "{";
    for (auto it = container.begin(); it != container.end(); ++it)
        out << (it == container.begin() ? "" : ", ") << *it;
    return out << "}";
}
// ACTUAL SOLUTION START HERE ////////////////////////////////////////////////////////////////}}}

struct DS {
    vector<int> cnt;
    int sum_upper;
    int shift;
    DS() {}
    DS(int mx_bit): cnt(1 << mx_bit), sum_upper(0), shift(0) {}
    
    int& get(int num) {
        num += shift;
        num &= sz(cnt) - 1;
        return cnt[num];
    }
    
    void change(int num, int delta) {
        num &= sz(cnt) - 1;
        if (num >= sz(cnt) / 2) sum_upper += delta;
        get(num) += delta;
    }
    
    void shift_up() {
        sum_upper -= get(sz(cnt) / 2);
        ++shift;
        if (shift == sz(cnt)) shift = 0;
        sum_upper += get(sz(cnt) - 1);
    }
    void shift_down() {
        sum_upper -= get(sz(cnt) - 1);
        --shift;
        if (shift == -1) shift += sz(cnt);
        sum_upper += get(sz(cnt) / 2);
    }
};


struct Query {
    int l, r, id;
};
const int mx_bit = 18;
const int maxn = 201010;
const int buck_size = 448;

int n, m, q;
bool has[maxn];
Query queries[maxn];
string ans;

int main() {
#ifdef LOCAL
    freopen("main.inp", "r", stdin); 
    freopen("main.out", "w", stdout);  
    freopen(".log", "w", stderr);
#endif
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    rep(i, 0, n) {
        int x; cin >> x;
        --x;
        has[x] ^= 1;
    }
    
    cin >> q;
    rep(i, 0, q) {
        cin >> queries[i].l >> queries[i].r;
        --queries[i].l;
        queries[i].id = i;
    }
    sort(queries, queries+ q, [&](const Query& u, const Query& v) {
            int bu = u.l / buck_size;
            int bv = v.l / buck_size;
            if (bu != bv) return bu < bv;
            return bu & 1 ? u.r > v.r : u.r < v.r;
            });
    
    vector<DS> ds;
    rep(i, 0, mx_bit) {
        ds.emplace_back(i + 1);
    }
    
    int l = 0, r = 0;
    
    auto add = [&](int num) {
        if (!has[num]) return ;
        clog << "add " << db(num) << endl;
        rep(i, 0, mx_bit) ds[i].change(num - l, 1);
    };
    
    auto rem = [&](int num) {
        if (!has[num]) return ;
        clog << "rem " << db(num) << endl;
        rep(i, 0, mx_bit) ds[i].change(num - l, -1);
    };
    
    ans.resize(q);
    rep(i, 0, q) {
        DB();
        auto [ql, qr, qid] = queries[i];
        while (l > ql) {
            for (auto& d: ds) d.shift_down();
            --l;
            add(l);
        }
        while (r < qr) {
            add(r++);
        }
        
        while (l < ql) {
            rem(l);
            ++l;
            for (auto& d: ds) d.shift_up();
        }
        while (r > qr) {
            rem(--r);
        }
        bool is_zero = 1;
        for (auto& d: ds) if (d.sum_upper & 1) {
            clog << db(sz(d.cnt)) << db(d.sum_upper) << endl;
            clog << db(d.cnt) << db(d.shift) << endl;
            is_zero = 0;
            break;
        }
        
        ans[qid] = is_zero ? 'B' : 'A';
    }
    cout << ans;
    
    return 0;
}

// vim: foldmethod=marker