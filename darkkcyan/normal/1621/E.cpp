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
    int n;
    vector<ll> val, lz;
    Segtree(int n_): n(n_), val(4 * n), lz(4 * n) {}
    void push(int i, int l, int r ) {
        if (lz[i] == 0) return ;
        val[i] += lz[i];
        if (r - l > 1) {
            lz[2 * i] += lz[i];
            lz[2 * i + 1] += lz[i];
        }
        lz[i] = 0;
    }
    void upd(int from, int to, ll delta, int i, int l, int r) {
        DB();
        clog << db(from) << db(to) << db(delta) << db(i) << db(l) << db(r) << endl;
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
        val[i] = min(val[2 * i], val[2 * i + 1]);
    }
    ll get(int from, int to, int i, int l, int r) {
        push(i, l, r);
        if (from >= r or l >= to) return LLONG_MAX;
        if (from <= l and r <= to) return val[i];
        int mid = (l + r) / 2;
        return min(
                get(from, to, 2 * i, l, mid),
                get(from, to, 2 * i + 1, mid, r)
        );
    }
    
    void upd(int from, int to, ll delta) {
        upd(from, to, delta, 1, 0, n);
    }
    ll get(int from, int to) {
        return get(from, to, 1, 0, n);
    }
    list<ll> get(int i, int l, int r) {
        push(i, l, r);
        if (r - l == 1) return {val[i]};
        int mid = (l + r) / 2;
        auto ans = get(2 * i, l, mid);
        ans.splice(ans.end(), get(2 * i + 1, mid, r));
        return ans;
    }
    
    list<ll> get() {
        return get(1, 0, n);
    }
};

const int maxn = 101010;
int m, n;
ll a[maxn];
vector<ll> b[maxn];
ll b_sum[maxn];

int main() {
#ifdef LOCAL
    freopen("main.inp", "r", stdin); 
    freopen("main.out", "w", stdout);  
    freopen(".log", "w", stderr);
#endif
    cin.tie(0)->sync_with_stdio(0);
    
    int ntest;
    cin >> ntest;
    
    while (ntest--) {
        DB();
        cin >> n >> m;
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        for (int i = 0; i < m; ++i) {
            int k; cin >> k;
            b[i].resize(k);
            for (auto& x: b[i]) cin >> x;
            b_sum[i] = accumulate(all(b[i]), 0ll);
        }
        
        sort(a, a + n, greater<ll>());
        reverse(a, a + m);
        
        Segtree st(m);
        for (int i = 0; i < m; ++i) {
            st.upd(i, i + 1, - i - 1);
        }
        auto find_pos = [&](ll b_val, int k) {
            int l = 0, r = m;
            while (l < r) {
                int mid = (l + r) / 2;
                if (a[mid] * k >= b_val) r = mid;
                else l = mid + 1;
            }
            return l;
        };
        clog << db(st.get()) << endl;
        for (int i = 0; i < m; ++i) {
            int pos = find_pos(b_sum[i], sz(b[i]));
            clog << db(i) << db(pos) << endl;
            st.upd(pos, m, 1);
        }
        clog << db(st.get()) << endl;
        
        string ans;
        for (int i = 0; i < m; ++i) {
            DB();
            int old_pos = find_pos(b_sum[i], sz(b[i]));
            st.upd(old_pos, m, -1);
            clog << db(i) << db(old_pos) << db(b_sum[i]) << db(st.val[1]) << db(st.get()) << endl;
            
            for (auto x: b[i]) {
                ll new_sum = b_sum[i] - x;
                auto pos = find_pos(new_sum, sz(b[i]) - 1);
                st.upd(pos, m, 1);
                clog << db(x) << db(new_sum) << db(pos) << db(st.val[1]) << db(st.get()) << endl;
                auto ok = st.val[1] >= 0;
                ans += char(ok + '0');
                st.upd(pos, m, -1);
            }
            
            st.upd(old_pos, m, 1);
        }
        cout << ans << '\n';
    }
    
    return 0;
}

// vim: foldmethod=marker