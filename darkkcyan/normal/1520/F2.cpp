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

int n, t;

int ask(int l, int r) {
    cout << "? " << l << ' ' << r << endl;
    int ans; cin >> ans;
    return ans;
}

void answer(int x) {
    cout << "! " << x << endl;
}

void solve_ez() {
    int l = 1, r = n;
    int k;
    cin >> k;
    while (l < r) {
        int mid = (l + r) / 2;
        int cur = mid - ask(1, mid);
        if (cur >= k) {
            r = mid;
        } else l = mid + 1;
    }
    answer(l);
}

struct BIT {
    vector<int> vals;
    BIT(int len): vals(len + 10) {}
    
    void upd(int i, int u) {
        clog << db(i) << db(u) << endl;
        for (++i; i < sz(vals); i += i & -i) vals[i] += u;
    }
    
    int find_last_smaller(int value) {
        int ans = 0;
        for (int i = 20; i--; ) {
            int na = ans + (1 << i);
            if (na >= sz(vals)) continue;
            if (vals[na] >= value) continue;
            clog << db(i) << db(na) << db(vals[na]) << endl;
            value -= vals[na];
            ans = na;
        }
        return ans - 1;
    }
    
    int get(int i) {
        int ans = 0;
        for (++i; i > 0; i -= i & -i) ans += vals[i];
        return ans;
    }
};

void solve_hard() {
    int cnt_blk = (n + 31) / 32;
    BIT bit(cnt_blk);
    
    int k; cin >> k;
    
    auto my_ask = [&](int l, int r) {
        return ask(l + 1, r);
    };
    auto my_answer = [&](int x) {
        answer(x + 1);
    };
    for (int l = 0; l < n; l += 32) {
        int r = min(l + 32, n);
        bit.upd(l / 32, r - l - my_ask(l, r));
    }
                
    while (t--) {
        DB();
        int blk = bit.find_last_smaller(k) + 1;
        int l = blk * 32, r = min(l + 32, n) - 1;
        clog << db(k) << endl;
        clog << db(blk) << endl;
        while (l < r) {
            int mid = (l + r) / 2;
            if (mid + 1 - my_ask(0, mid + 1) >= k) r = mid;
            else l = mid + 1;
        }
        my_answer(l);
        bit.upd(blk, -1);
        if (t) {
            cin >> k;
        }
    }
}

int main() {
#ifdef LOCAL
    // freopen("main.inp", "r", stdin);  
    // freopen("main.out", "w", stdout);   
    // freopen(".log", "w", stderr); 
#endif
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> t;
    if (t == 1) solve_ez();
    else solve_hard();
    
    return 0;
}

// vim: foldmethod=marker