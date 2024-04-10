#ifdef LOCAL
// #define gentest
#endif

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


mt19937 rng;
#define rand() ((int)(rng() >> 1))

int n;
int ai, aj, ak;
vector<int> arr;
void init() {
#ifdef gentest
    n = rand() % 10 + 4;
    cout << db(n) << endl;
    arr.resize(n);
    rep(i, 0, n) arr[i] = i + 1;
    shuffle(all(arr), rng);
    sort(arr.begin(), arr.begin() + 3);
    ai = arr[0];
    aj = arr[1];
    ak = arr[2];
    cout << db(ai) << db(aj) << db(ak) << endl;
        
    rep(i, 0, n) arr[i] = i + 1;
    reverse(arr.begin() + ai - 1, arr.begin() + aj - 1);
    reverse(arr.begin() + aj - 1, arr.begin() + ak);
    cout << db(arr) << endl;
#else 
    cin >> n;
#endif
}

ll ask(ll l, ll r) {
    cout << "? " << l << ' ' << r << endl;
    assert(l <= r);
    ll ans = 0;
#ifndef gentest
    cin >> ans;
    return ans;
#else
    rep(i, l, r + 1)
        rep(f, i + 1, r + 1) {
            ans += arr[f - 1] < arr[i - 1];
        }
    cout << db(ans) << endl;
#endif
    return ans;
}

void answer(ll i, ll j, ll k) {
    cout << "! " << i << ' ' << j << ' ' << k << endl;
#ifdef gentest
    assert(i == ai);
    assert(j == aj);
    assert(k == ak);
#endif
}

ll c2(ll num) { return num * (num - 1) / 2; }

ll solve_c2(ll k) {
    if (k == 0) return 1;
    ll l = 0, r = 1;
    while (r * (r - 1) / 2 < k) r <<= 1;
    l = r / 2;
    while (l < r) {
        ll mid = l + (r - l) / 2;
        if (mid * (mid - 1) / 2 >= k) r = mid;
        else l =mid + 1;
    }
    assert(l * (l - 1) / 2 == k);
    return r;
}

void solve() {
    init();
    ll total = ask(1, n);
    
    int l = 1, r = n;
    int mid;
    ll last_ans = -1;
    while (r - l > 1) {
        mid = l + (r - l) / 2;
        last_ans = ask(1, mid);
        clog << db(l) << db(r) << db(mid) << db(last_ans) << endl;
        if (last_ans == 0) {
            l = mid;
        } else if (last_ans == total) {
            r = mid;
        } else break;
    }
    
    ll cur_ans = ask(1, mid - 1);
    ll d = last_ans - cur_ans;
    clog << db(cur_ans) << db(last_ans) << db(d) << endl;
    
    ll nxt = mid - d;
    clog << db(nxt) << endl;
    
    last_ans = nxt == 1 ? 0 : ask(1, nxt - 1);
    if (last_ans != 0) {
        ll u = last_ans;
        ll v = total - u;
        ll j = nxt;
        ll i = nxt - solve_c2(u);
        ll k = nxt + solve_c2(v) - 1;
        answer(i, j, k);
        return ;
    }
    
    ll i = nxt;
    
    // r = min(r + 1, n);
    l = (int)max((ll)l, i);
    while (l < r) {
        mid = l + (r - l + 1) / 2;
        last_ans = ask(i, mid);
        if (c2(mid - i + 1) == last_ans) {
            l = mid;
        } else {
            r = mid - 1;
        }
    }
    
    ll j = l + 1;
    ll k = j + (j > n ? 0 : solve_c2(ask(j, n)) - 1);
    clog << db(i) << db(j) << db(k) << endl;
    if (k == j) {
        k = j - 1;
        j = i;
        i --;
    }
    answer(i, j, k);
}

int main() {
#ifdef LOCAL
    // freopen("main.inp", "r", stdin); 
    // freopen("main.out", "w", stdout);  
    // freopen(".log", "w", stderr);
#endif
    cin.tie(0)->sync_with_stdio(0);
    
#ifdef gentest
    while (true) {
        cout << string(10, '-') << endl;
        solve();
    }
#else
    int ntest;
    cin >> ntest;
    while (ntest--) {
        solve();
    }
#endif
    
    return 0;
}

// vim: foldmethod=marker