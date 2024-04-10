/**
 * This is the implementation of the second solution in the editorial.
 * The one thing that bug me in the editorial is that why we only consider only
 * balance with absolute value no more than a.
 * I might have an answer for this.
 * The thing is, we also need observations in the first solution.
 * If we can generate positive balance and negative balance, then we can just
 * generate what-ever balance we like. That might be the reasons
 * why we only need to check balance till a.
 */
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

const int maxa = 2020;
struct State {
    int carry;
    int balance;
    
    operator int () const {
        return carry * (2 * maxa) + (balance + maxa);
    }
};
struct Trace {
    State prev;
    int prev_dig;
};

Trace trace[maxa * (maxa * 2)];

int a;
int main() {
#ifdef LOCAL
    freopen("main.inp", "r", stdin); 
    freopen("main.out", "w", stdout);  
    freopen(".log", "w", stderr);
#endif
    cin.tie(0)->sync_with_stdio(0);
    cin >> a;
    
    memset(trace, -1, sizeof(trace));
    queue<State> qu;
    State root{-1, -1};
    rep(dig, 1, 10) {
        State cur {dig * a / 10, dig * a % 10 * a - dig};
        trace[cur] = {root, dig};
        qu.push(cur);
    }
    
    for (; qu.size(); qu.pop()) {
        DB();
        auto u = qu.front();
        clog << db(u.carry) << db(u.balance) << endl;
        clog << db(trace[u].prev.carry) << db(trace[u].prev.balance) << db(trace[u].prev_dig) << endl;
        if (u.carry == 0 and u.balance == 0) break;
        rep(dig, 0, 10) {
            int x = u.carry + dig * a;
            int mul_dig = x % 10;
            State v {x / 10, u.balance + mul_dig * a - dig};
            clog << db(dig) << db(x) << db(mul_dig) << db(v.carry) << db(v.balance) << endl;
            if (abs(v.balance) > a) continue;
            if (trace[v].prev_dig != -1) continue;
            trace[v] = {u, dig};
            qu.push(v);
        }
    }
    
    State u {0, 0};
    if (trace[u].prev_dig == -1) {
        cout << "-1\n";
        return 0;
    }
    string s;
    for (; u != root; u = trace[u].prev) {
        if (trace[u].prev_dig or s.size()) s += char('0' + trace[u].prev_dig);
    }
    
    // reverse(all(s)); 
    cout << s;
    
    return 0;
}

// vim: foldmethod=marker