#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
const ld eps = 1e-8;
#define len(x) ((int)x.size())
#define rep(i,n) for (int i = -1; ++ i < n; )
#define rep1(i,n) for (int i = 0; i ++ < n; )
#define be(a) (a).begin(), (a).end()
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

struct BIT {
    vector<int> vals;
    BIT(int sz): vals(sz + 10) {}
    void upd(int i, int v) {
        for (++i; i < len(vals); i += i & -i) vals[i] += v;
    }
    
    int get(int i) {
        int ans = 0;
        for (++i; i > 0; i -= i & -i) ans += vals[i];
        return ans;
    }
};


int main(void) {
#ifdef LOCAL
    freopen("main.inp", "r", stdin);
    freopen("main.out", "w", stdout);
    freopen(".log", "w", stderr);
#endif
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i, n) cin >> a[i];
    
    BIT bit(n);
    vector<int> pos(n + 1);
    rep(i, n) pos[a[i]] = i;
    
    ll cur_ans = 0;
    set<int> lower, upper;
    auto adjust = [&]() {
        int sz = len(lower) + len(upper);
        while (len(lower) > sz / 2) {
            upper.insert(*lower.rbegin());
            lower.erase(--lower.end());
        }
        while (len(lower) < sz / 2) {
            lower.insert(*upper.begin());
            upper.erase(upper.begin());
        }
    };
    
    auto add_val = [&](int v) {
        if (!len(upper)) {
            upper.insert(v);
            return ;
        }
        if (v < *upper.begin()) {
            lower.insert(v);
        } else upper.insert(v);
        adjust();
    };
    
    rep1(i, n) {
        DB();
        clog << db(i) << db(pos[i]) << endl;
        int cnt_left = bit.get(pos[i]);
        int cnt_right = i - 1 - cnt_left;
        cur_ans -= min(cnt_left, cnt_right);
        cur_ans += cnt_right;
        bit.upd(pos[i], 1);
        add_val(pos[i]);
        clog << db(cur_ans) << endl;
        int med;
        clog << db(lower) << db(upper) << endl;
        if ((len(lower) + len(upper)) & 1) {
            med = *upper.begin();
        } else {
            int u = *lower.rbegin(), v = *upper.begin();
            if (abs(u - pos[i]) > abs(v - pos[i])) med = u;
            else med = v;
        }
        clog << db(med) << endl;
        
        int u = med, v = pos[i];
        if (u > v) swap(u, v);
        int cnt_added = abs(bit.get(v) - bit.get(u - 1));
        int cnt_rest = v - u + 1 - cnt_added;
        clog << db(cnt_added) << db(cnt_rest) << endl;
        cur_ans += cnt_rest;
        clog << db(cur_ans) << endl;
        
        cout << cur_ans << ' ';
    }
    
    return 0;
}

// vim: foldmethod=marker