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

int main() {
#ifdef LOCAL
    freopen("main.inp", "r", stdin); 
    freopen("main.out", "w", stdout);  
    freopen(".log", "w", stderr);
#endif
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int ntest; cin >> ntest;
    while (ntest--) {
        DB();
        int n, m; cin >> n >> m;
        vector<vector<int>> free_day(n + 1);
        vector<vector<int>> free_id(m);
        rep(i, m) {
            int k; cin >> k;
            free_id[i].resize(k);
            rep(f, k) {
                cin >> free_id[i][f];
                free_day[free_id[i][f]].push_back(i);
            }
        }
        
        vector<int> big;
        rep1(i, n) {
            if (len(free_day[i]) > (m + 1) / 2)
                big.push_back(i);
        }
        clog << db(big) << endl;
        if (len(big) == 0) {
            cout << "YES\n";
            rep(i, m) cout << free_id[i][0] << ' ';
            cout << '\n';
            continue;
        }
        
        bool has_ans = false;
        for (auto bid: big) {
            vector<int> single;
            for (auto day: free_day[bid]) 
                if (len(free_id[day]) == 1) single.push_back(day);
            if (len(single) > (m + 1) / 2) continue;
            has_ans = true;
            vector<int> ans(m);
            single.resize(min(len(single), (m + 1) / 2));
            clog << db(bid) << db(single) << endl;
            for (auto i: single) ans[i] = bid;
            int needed = (m + 1) / 2 - len(single);
            for (auto i: free_day[bid]) {
                if (needed == 0) break;
                if (ans[i] != 0) continue;
                --needed;
                ans[i] = bid;
            }
            rep(i, m) if (ans[i] == 0) {
                if (free_id[i][0] == bid) {
                    assert(len(free_id[i]) > 1);
                    ans[i] = free_id[i][1];
                } else ans[i] = free_id[i][0];
            }
            cout << "YES\n";
            for (auto i: ans) cout << i << ' ';
            cout << '\n';
            break;
        }
        if (!has_ans) cout << "NO\n";
    }
    
    return 0;
}

// vim: foldmethod=marker