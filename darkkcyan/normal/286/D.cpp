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

const int inf = 1e9 + 69;
struct Seg {
    int l, r, t;
};
int n, m;
vector<Seg> segs;

int main() {
#ifdef LOCAL
    freopen("main.inp", "r", stdin); 
    freopen("main.out", "w", stdout);  
    freopen(".log", "w", stderr);
#endif
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    segs.resize(m);
    for (auto& [l, r, t]: segs) cin >> l >> r >> t;
    
    struct Event {
        vector<int> add, rem;
    };
    map<int, Event> events;
    map<int, int> changes;
    
    for (auto [l, r, t]: segs) {
        events[l].add.push_back(t);
        events[r].rem.push_back(t);
    }
    
    multiset<int> se;
    int prev_pos = -1;
    for (auto& [cur_pos, evt]: events) {
        if (se.size()) {
            int opt = *se.begin();
            changes[opt - cur_pos]++;
            changes[opt - prev_pos]--;
        }
        
        for (auto x: evt.rem) se.erase(se.find(x));
        for (auto x: evt.add) se.insert(x);
        prev_pos = cur_pos;
    }
    
    auto it = changes.begin();
    int prev_time = -inf;
    int cur_cross = 0;
    ll cur_ans = 0;
    while (n--) {
        int q; cin >> q;
        while (it != changes.end() and it->first <= q) {
            cur_ans += cur_cross * (it->first - prev_time);
            cur_cross += it->second;
            prev_time = it->first;
            ++it;
        }
        ll ans = cur_ans + cur_cross * (q - prev_time);
        cout << ans << '\n';
    }
    
    return 0;
}

// vim: foldmethod=marker