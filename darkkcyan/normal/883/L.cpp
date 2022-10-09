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
#define print_op(type) ostream& operator<<(ostream& out, const type& u)
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

template<class T>
using min_pq = priority_queue<T, vector<T>, greater<>>;

#define int ll
signed main() {
#ifdef LOCAL
    freopen("main.inp", "r", stdin); 
    freopen("main.out", "w", stdout);  
    freopen(".log", "w", stderr);
#endif
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, k, m;
    cin >> n >> k >> m;
    vector<min_pq<pair<ll, int>>> parking(n + 1);
    multiset<int> taxi_pos;
    
    rep(i, 0, k) {
        int x; cin >> x;
        taxi_pos.insert(x);
        parking[x].emplace(0, i);
    }
    
    min_pq<tuple<ll, int, int>> moving;
    
    auto pop_moving = [&] {
        auto [rt, pos, id] = moving.top();
        clog << db(rt) << db(pos) << db(id) << endl;
        moving.pop();
        taxi_pos.insert(pos);
        parking[pos].emplace(rt, id);
    };
    
    ll overal_t = 0;
    while (m--) {
        ll t;
        int a, b;
        cin >> t >> a >> b;
        overal_t = max(overal_t, t);
        while (moving.size() and get<0>(moving.top()) <= overal_t) pop_moving();
        
        if (sz(taxi_pos) == 0) {
            overal_t = get<0>(moving.top());
            while (moving.size() and get<0>(moving.top()) == overal_t) pop_moving();
        }
        
        auto it = taxi_pos.lower_bound(a);
        tuple<ll, pair<ll, int>, int> found_pos = {LLONG_MAX, {-1, -1}, -1};
        if (it != taxi_pos.end()) {
            found_pos = {*it - a, parking[*it].top(), *it};
        }
        if (it != taxi_pos.begin()) {
            int u = *prev(it);
            found_pos = min(found_pos, {a - u, parking[u].top(), u});
        }
        int pos = get<2>(found_pos);
        assert(pos != -1);
        taxi_pos.erase(taxi_pos.find(pos));
        auto [rt, id] = parking[pos].top();
        parking[pos].pop();
        cout << id + 1 << ' ' << overal_t + abs(a - pos) - t << '\n';
        
        moving.emplace(overal_t + abs(a - pos) + abs(a - b), b, id);
    }
    
    return 0;
}

// vim: foldmethod=marker