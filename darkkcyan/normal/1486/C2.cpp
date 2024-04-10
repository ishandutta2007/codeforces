#ifdef LOCAL
// #define inter 
#endif
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
const ld eps = 1e-8;
#define len(x) ((int)x.size())
#define rep(i,n) for (int i = -1; ++ i < n; )
#define rep1(i,n) for (int i = 0; i ++ < n; )
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

mt19937 rng(177013);
#define rand() ((int)(rng() >> 1))
int n;
#ifdef inter
int __cnt_qr;
vector<int> a;
#endif
void init() {
#ifdef inter
    __cnt_qr = 20;
    n = rand() % 10 + 1;
    a.resize(n);
    rep(i, n) a[i] = i;
    shuffle(a.begin(), a.end(), rng);
    cout << n << endl;
    cout << a << endl;
#else
    cin >> n;
#endif
}

int ask(int l, int r) {
    assert(l < r);
    cout << "? " << l << ' ' << r << endl;
#ifdef inter
    assert(__cnt_qr > 0);
    --__cnt_qr;
    set<pair<int, int>> prio;
    for (int i = l - 1; i < r; ++i) {
        prio.emplace(a[i], i);
        if (prio.size() > 2) prio.erase(prio.begin());
    }
    return prio.begin()->second + 1;
#else
    int ans; cin >> ans;
    return ans;
#endif
}

void answer(int ans) {
    cout << "! " << ans << endl;
#ifdef inter
    assert(ans - 1 == (int)(max_element(a.begin(), a.end()) - a.begin()));
#endif
}

void solve() {
    init();
    if (n == 1) {
        answer(1);
        return ;
    }
    int sec = ask(1, n);
    if (sec != n and ask(sec, n) == sec) {
        int l = sec + 1, r = n;
        while (l < r) {
            int mid = (l + r) / 2;
            if (ask(sec, mid) == sec) r = mid;
            else l = mid + 1;
        }
        answer(l);
    } else {
        int l = 1, r = sec - 1;
        while (l < r) {
            int mid = (l + r + 1) / 2;
            if (ask(mid, sec) == sec) l = mid;
            else r = mid - 1;
        }
        answer(l);
    }
}

int main(void) {
#ifdef LOCAL
    // freopen("main.inp", "r", stdin); 
    // freopen("main.out", "w", stdout); 
    // freopen(".log", "w", stderr); 
#endif
    // ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); 
#ifdef inter
    while (true) {
        solve();
        cout << "OK" << endl;
    }
#else
    solve();
#endif
    
    return 0;
}

// vim: foldmethod=marker