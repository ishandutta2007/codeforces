#include <bits/stdc++.h>
using namespace std;

#define llong long long 
#define len(x) ((int)x.size())
#define rep(i,n) for (int i = -1; ++ i < n; )
#define rep1(i,n) for (int i = 0; i ++ < n; )
#define rand __rand
mt19937 rng(chrono::system_clock::now().time_since_epoch().count());  // or mt19937_64
template<class T = int> T rand(T range = numeric_limits<T>::max()) { return (T)(rng() % range); }

#define CONCAT_(x, y) x##y/*{{{*/
#define CONCAT(x, y) CONCAT_(x, y)
#ifdef LOCAL_DEBUG   
int __db_level = 0;
bool __db_same_line = false;
#define clog cerr << string(!__db_same_line ? __db_level * 2 : 0, ' ')
struct debug_block {
    function<void()> fn;
    void print_name() { __db_same_line = true; fn(); clog << endl; __db_same_line = false;  }
    debug_block(function<void()> fn_): fn(fn_) { clog << "{ "; print_name(); ++__db_level; }
    ~debug_block() { --__db_level; clog << "} "; print_name(); }
};
#define DB(args...) debug_block CONCAT(dbbl, __LINE__)([=]{ clog << args; })
#define deb(...)  if (1) { (clog << "[" #__VA_ARGS__ "] = [" << __VA_ARGS__) << "]"; if (!__db_same_line) clog << endl; }
#else
#define clog if (0) cerr
#define DB(...)
#define deb(...)
#endif
template<class T>
ostream& operator,(ostream& out, const T& thing) { return out << ", " << thing; }
template<class U, class V>
ostream& operator<<(ostream& out, const pair<U, V>& p) { return (out << "(" << p.first, p.second) << ")"; }
template<class A, class B>
ostream& operator<<(ostream& out, const tuple<A, B>& t) { return (out << "(" << get<0>(t), get<1>(t)) << ")"; }
template<class A, class B, class C>
ostream& operator<<(ostream& out, const tuple<A, B, C>& t) { return (out << "(" << get<0>(t), get<1>(t), get<2>(t)) << ")"; }
template<class T> ostream& operator<<(ostream& out, const vector<T>& container) { 
    out << "{";
    if (len(container)) out << container[0];
    rep1(i, len(container) - 1) out, container[i];
    return out << "}";
}
template<class x> vector<typename x::value_type> $v(const x& a) { return vector<typename x::value_type>(a.begin(), a.end()); }
#define ptrtype(x) typename iterator_traits<x>::value_type
template<class u> vector<ptrtype(u)> $v(u a, u b) { return vector<ptrtype(u)>(a, b); }/*}}}*/
// ACTUAL SOLUTION BELOW ////////////////////////////////////////////////////////////

template<class T>
inline T get_num() {
    int ch;
    while (!isdigit(ch = getchar()));
    T num = (T)(ch - '0');
    while (isdigit(ch = getchar())) {
        num = num * 10 + (T)(ch - '0');
    }
    return num;
}

const int maxn = 1010;
int n, m, q;
char board[maxn][maxn];
int first_change[maxn][maxn];
int qu[maxn * maxn];

int dr[] = {-1, 0, 1, 0};
int dc[] = {0, -1, 0, 1};

int main(void) {
    n = get_num<int>(); m = get_num<int>(); q = get_num<int>();
    rep(i, n) {
        int ch; 
        rep(f, m) {
            while (!isdigit(ch = getchar()));
            board[i][f] = (char)ch;
        }
    }
    bool has_same = false;
    int qu_len = 0;

    rep(r, n) rep(c, m) {
        first_change[r][c] = INT_MAX;
        bool change = false;
        rep(dir, 4) {
            int nr = r + dr[dir];
            int nc = c + dc[dir];
            if (nr < 0 or nc < 0 or nr >= n or nc >= m) continue;
            if (board[r][c] != board[nr][nc]) continue;
            change = true;
            break;
        }
        if (change) {
            qu[qu_len++] = r * m + c;
            first_change[r][c] = 1;
            has_same = true;
        }
    }

    for (int i = 0; i < qu_len; ++i) {
        int r = qu[i] / m;
        int c = qu[i] % m;
        rep(dir, 4) {
            int nr = r + dr[dir];
            int nc = c + dc[dir];
            if (nr < 0 or nc < 0 or nr >= n or nc >= m) continue;
            if (first_change[nr][nc] != INT_MAX) continue;
            first_change[nr][nc] = first_change[r][c] + 1;
            qu[qu_len++] = nr * m + nc;
        }
    }

    while (q--) {
        int r = get_num<int>() - 1, c = get_num<int>() - 1;
        llong p = get_num<llong>();
        llong fc = has_same ? (llong)first_change[r][c] : LLONG_MAX;
        int init = board[r][c] - '0';
        if ((fc > p) or ((p - fc) & 1)) cout << init << '\n';
        else cout << (!init) << '\n';
    }

    return 0;
}

// vim: foldmethod=marker