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
        int n; cin >> n;
        vector<int> a(n);
        rep(i, n) cin >> a[i];
        
        map<int, int> val;
        set<int> one_pos;
        int prv = a[n - 1];
        rep(i, n) {
            val[i] = a[i];
            if (__gcd(a[i], prv) == 1) one_pos.insert(i);
            prv = a[i];
        }
        int cur_pos = 1;
        
        using mit = map<int, int>::iterator;
        auto cycle_next = [&](mit it, map<int, int>& mp) ->mit {
            auto ans = next(it);
            if (ans == mp.end()) return mp.begin();
            return ans;
        };
        
        auto cycle_prev = [&](mit it, map<int, int>& mp) -> mit {
            if (it == mp.begin()) return --mp.end();
            return prev(it);
        };
        
        vector<int> ans;
        while (len(one_pos) and len(val) > 1) {
            auto it = one_pos.lower_bound(cur_pos);
            if (it == one_pos.end()) {
                cur_pos = 0;
                continue;
            }
            DB();
            clog << db(cur_pos) << endl;
            clog << db(*it) << endl;
            clog << db(val) << endl;
            clog << db(one_pos) << endl;
            
            ans.push_back(*it);
            cur_pos = *it;
            auto val_it = val.find(cur_pos);
            assert(val_it != val.end());
            auto prv_it = cycle_prev(val_it, val), nxt_it = cycle_next(val_it, val);
            
            if (__gcd(val_it->second, prv_it->second) == 1) {
                one_pos.erase(val_it->first);
            }
            if (__gcd(val_it->second, nxt_it->second) == 1) {
                one_pos.erase(nxt_it->first);
            }
            
            val.erase(val_it);
            if (__gcd(prv_it->second, nxt_it->second) == 1) {
                one_pos.insert(nxt_it->first);
            }
            cur_pos = cycle_next(nxt_it, val)->first;
        }
        if (len(val) == 1 and val.begin()->second == 1) ans.push_back(val.begin()->first);
        cout << len(ans);
        for (auto i: ans) cout << ' ' << i + 1;
        cout << '\n';
    }
    
    return 0;
}

// vim: foldmethod=marker