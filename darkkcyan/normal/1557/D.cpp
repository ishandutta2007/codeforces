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

struct segtree {
    vector<pair<int, int>> data, lz;
    segtree(int len): data(len * 4, {0, -1}), lz(len * 4, {0, -1}) {}
    
    void push(int i, int l, int r) {
        data[i] = max(data[i], lz[i]);
        if (r - l > 1) {
            lz[2 * i] = max(lz[2 * i], lz[i]);
            lz[2 * i + 1] = max(lz[2 * i + 1], lz[i]);
        }
        lz[i] = {0, -1};
    }
    
    void upd(int from, int to, const pair<int, int>& v, int i, int l, int r) {
        push(i, l, r);
        if (from >= r or l >= to) return ;
        if (from <= l and r <= to) {
            lz[i] = max(lz[i], v);
            push(i, l, r);
            clog << db(l) << db(r) << db(i) << db(v) << db(data[i]) << endl;
            return ;
        }
        int mid  = (l + r) / 2;
        upd(from, to, v, 2 * i, l, mid);
        upd(from, to, v, 2 * i + 1, mid, r);
        data[i] = max(data[2 * i], data[2 * i + 1]);
        clog << db(i) << db(data[i]) << endl;
    }
    pair<int, int> get(int from, int to, int i, int l, int r) {
        push(i, l, r);
        if (from >= r or l >= to) return {0, -1};
        if (from <= l and r <= to) {
            return data[i];
        }
        int mid = (l + r) / 2;
        return max(
                get(from, to, 2 * i, l, mid),
                get(from, to, 2 * i + 1, mid, r)
                );
    }
    
    int size() const {
        return sz(data) >> 2;
    }
    void upd(int from, int to, const pair<int, int>& v) {
        DB();
        upd(from, to, v, 1, 0, size());
    }
    pair<int, int> get(int from, int to) {
        return get(from, to, 1, 0, size());
    }
};

int main() {
#ifdef LOCAL
    freopen("main.inp", "r", stdin); 
    freopen("main.out", "w", stdout);  
    freopen(".log", "w", stderr);
#endif
    cin.tie(0)->sync_with_stdio(0);
    
    int n, m; cin >> n >> m;
    vector<vector<pair<int, int>>> segs(n);
    vector<int> vals;
    rep(i, 0, m) {
        int id, l, r;
        cin >> id >> l >> r;
        --l;
        segs[id - 1].emplace_back(l, r);
        vals.push_back(l);
        vals.push_back(r);
    }
    
    sort(all(vals));
    vals.erase(unique(all(vals)), vals.end());
    
    vector<int> trace(n);
    segtree it(sz(vals));
    pair<int, int> ans {0, -1};
    rep(i, 0, n) {
        sort(all(segs[i]));
        pair<int, int> cur_dp = {0, -1};
        for (auto& [l, r]: segs[i]) {
            l = (int)(lower_bound(all(vals), l) - vals.begin());
            r = (int)(lower_bound(all(vals), r) - vals.begin());
            auto x = it.get(l, r);
            clog << db(l) << db(r) << db(x) << endl;
            cur_dp = max(cur_dp, x);
        }
        
        trace[i] = cur_dp.second;
        clog << db(i) << db(cur_dp) << endl;
        cur_dp = {cur_dp.first + 1, i};
        clog << db(cur_dp) << endl;
        for (auto& [l, r]: segs[i]) {
            it.upd(l, r, cur_dp);
        }
        ans = max(ans, cur_dp);
    }
    
    cout << n - ans.first << '\n';
    vector<bool> not_pick(n);
    for (int u = ans.second; u != -1; u = trace[u]) {
        not_pick[u] = true;
    }
    
    rep(i, 0, n) {
        if (!not_pick[i]) cout << i + 1 << ' ';
    }
    
    return 0;
}

// vim: foldmethod=marker