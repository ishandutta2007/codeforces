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

const int maxn = 555;
int n, m;
string board[maxn];

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
        cin >> n >> m;
        rep(i, n) cin >> board[i];
        if (n == 1) {
            cout << string(m, 'X') << '\n';
            continue;
        }
        
        clog << db(n) << db(m) << endl;
        for (int i = 0; i < n; i += 4) {
            rep(f, m) board[i][f] = 'X';
            clog << db(i) << db(board[i]) << endl;
        }
        
        if (n % 4 == 0 and n > 1) {   
            rep(f, m) board[n - 1][f] = 'X';
        }   
        
        for (int i = 2; i < n; i += 4) {
            int first = 0;
            for (; first < m and board[i][first] != 'X'; ++first);
            if (first < m) {
                board[i - 1][first] = 'X';
                if (i + 1 < n) board[i + 1][first] = 'X';
                
                for (int f = first + 1; f < m; ++f) 
                    if (board[i][f] == 'X') {
                        if (n % 4 == 0 and i == n - 2) continue;
                        board[i - 1][f] = 'X';
                    }
                continue;
            }
            
            first = 0;
            for (; first < m and board[i - 1][first] != 'X'; ++first);
            if (first == m) {
                first = 0;
                board[i - 1][first] = 'X';
            }
            
            board[i][first] = 'X';
            if (i + 1 >= n) continue;
            if (board[i + 1][first] == 'X') continue;
            if (first and board[i + 1][first - 1] == 'X') {
                board[i][first - 1] = 'X';
                continue;
            }
            if (first + 1 < m and board[i + 1][first + 1] == 'X') {
                board[i][first + 1] = 'X';
                continue;
            }
            board[i + 1][first] = 'X';
        }
        
        rep(i, n) cout << board[i] << '\n';
#ifdef LOCAL
        cout << '\n';
#endif
    }
    
    return 0;
}

// vim: foldmethod=marker