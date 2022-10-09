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

const int maxn = 52;
const int max_num = 5 * maxn;
const int max_carry = 5 * maxn / 9 + 2;
const int carry0 = max_carry;
const int carry_range = max_carry * 2 + 10;
const int inf = 5e7;

int dp[2][carry_range][max_num][max_num];

int& get(int i, int carry, int cp, int cm) {
    return dp[i & 1][carry + carry0][cp][cm];
}

void init_layer(int layer) {
    layer &= 1;
    rep(carry, carry_range) rep(cp, max_num) rep(cm, max_num)
        dp[layer][carry][cp][cm] = inf;
}

int& chkmin(int& x, int y) {
    if (y < x) x = y;
    return x;
}

int main(void) {
#ifdef LOCAL
    freopen("main.inp", "r", stdin);
    freopen("main.out", "w", stdout);
    freopen(".log", "w", stderr);
#endif
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    string s; cin >> s;
    reverse(s.begin(), s.end());
    
    init_layer(0); 
    get(0, 0, max_num - 1, max_num - 1) = 0; 
    
    s += "0";
    
    rep(i, len(s)) {
        init_layer(i + 1);
        int dig = s[i] - '0';
        for (int carry = -max_carry ; carry <= max_carry; ++carry)
        for (int cp = max_num; cp--; )
        for (int cm = max_num; cm--; ) {
            int cur = get(i, carry, cp, cm);
            if (cur == inf) continue;
            if (cp) chkmin(get(i, carry, cp - 1, cm), cur);
            if (cm) chkmin(get(i, carry, cp, cm - 1), cur);
            if ((cp - cm + carry - dig) % 10 == 0) {
                int new_carry = cp - cm + carry;
                if (new_carry >= 0) new_carry /= 10;
                else new_carry = -((-new_carry + 9) / 10);
                if (new_carry >= -max_carry and new_carry <= max_carry) {
                    chkmin(get(i + 1, new_carry, cp, cm), cur + cp + cm);
                    // if (cp == 1 and cm == 3) { 
                        // clog << db(i) << db(cp) << db(cm) << db(carry) << db(new_carry) << db(cur) << endl; 
                    // } 
                }
            }
        }
    }
    
    int ans = inf;
    rep(cp, max_num) rep(cm, max_num) ans = min(ans, get(len(s), 0, cp, cm));
    cout << ans;
    
    
    return 0;
}

// vim: foldmethod=marker