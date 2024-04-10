#pragma GCC optimize ("Ofast")
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
int get_num() {
    int a, c;
    while (isspace(a = getchar()));
    a -= '0';
    while (!isspace(c = getchar()))
        a = a * 10 + c - '0';
    return a;
}


const int maxn = 200010;
int n;
int a[maxn], b[maxn];

int main() {
#ifdef LOCAL
    freopen("main.inp", "r", stdin); 
    freopen("main.out", "w", stdout);   
    freopen(".log", "w", stderr); 
#endif
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    // cin >> n;  
    // rep(i, 0, n) cin >> a[i];  
    // rep(i, 0, n) cin >> b[i];  
    n = get_num(); 
    rep(i, 0, n) a[i] = get_num(); 
    rep(i, 0, n) b[i] = get_num(); 
    // n = 200'000;  
    // mt19937 rng;  
// #define rand() ((int)(rng() >> 1))  
    // rep(i, 0, n) a[i] = rand() % 100 + 1; 
    // rep(i, 0, n) b[i] = 100; 
    
    ll based_ans = 0;
    rep(i, 0, n) based_ans += abs(a[i] - b[i]);
    
    struct Event {
        int t1, t2, pos, open_pos;
    };
    enum T1 {open, close};
    enum T2 {le, gr};
    vector<Event> evt;
    evt.reserve(n);
    rep(i, 0, n) {
        if (a[i] == b[i]) continue;
        if (a[i] > b[i]) {
            evt.push_back({open, gr, b[i], b[i]});
            evt.push_back({close, gr, a[i], b[i]});
        } else {
            evt.push_back({open, le, a[i], a[i]});
            evt.push_back({close, le, b[i], a[i]});
        }
    }
    sort(all(evt), [&](const Event& u, const Event& v) {
            return u.pos < v.pos;
            });
    
    multiset<int> open_le, open_gr;
    int max_dec = 0;
    for (auto& [t1, t2, pos, open_pos]: evt) {
        if (t1 == close) {
            if (t2 == le) {
                open_le.erase(open_le.find(open_pos));
                if (sz(open_gr)) {
                    if (*open_gr.begin() <= open_pos) {
                        max_dec = max(max_dec, pos - open_pos);
                    }
                    auto it = open_gr.lower_bound(open_pos);
                    if (it != open_gr.end()) max_dec = max(max_dec, pos - *it);
                }
            } else {
                open_gr.erase(open_gr.find(open_pos));
                if (sz(open_le)) {
                    if (*open_le.begin() <= open_pos)
                        max_dec = max(max_dec, pos - open_pos);
                    auto it = open_le.lower_bound(open_pos);
                    if (it != open_le.end()) max_dec = max(max_dec, pos - *it);
                }
            }
        } else {
            if (t2 == le) open_le.insert(pos);
            else open_gr.insert(pos);
        }
    }
    auto ans = based_ans - 2ll * max_dec;
    cout << ans << '\n';
    
    return 0;
}

// vim: foldmethod=marker