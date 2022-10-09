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

const int maxn = 3000;
int n;
int a[maxn];

int pos_of(int x) {
    int ans = 0;
    while (ans < n and a[ans] != x) ++ans;
    assert(ans < n);
    return ans;
}

vector<int> ans;
void do_rev(int len) {
    assert(len & 1);
    ans.push_back(len);
    reverse(a, a + len);
}

int main() {
#ifdef LOCAL
    freopen("main.inp", "r", stdin); 
    freopen("main.out", "w", stdout);  
    freopen(".log", "w", stderr);
#endif
    cin.tie(0)->sync_with_stdio(0);
    int ntest; cin >> ntest;
    while (ntest--) {
        cin >> n;
        rep(i, 0, n) cin >> a[i];
        
        ans.clear();
        bool ok = true;
        for (int len = n; len > 1; len -= 2) {
            int mx = len;
            int pmx = pos_of(mx);
            if (pmx % 2 == 1) {
                ok = false;
                break;
            }
            do_rev(pmx + 1);
            int pmx1 = pos_of(mx - 1);
            if (pmx1 % 2 == 0) {
                ok = false;
                break;
            }
            
            do_rev(pmx1);
            do_rev(pmx1 + 2);
            do_rev(3);
            do_rev(len);
        }
        
        if (!ok) {
            cout << "-1\n";
            continue;
        }
        cout << sz(ans) << '\n';
        for (auto i: ans) cout << i << ' ';
        cout << '\n';
        assert(is_sorted(a, a + n));
    }
    
    return 0;
}

// vim: foldmethod=marker