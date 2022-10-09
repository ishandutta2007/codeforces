#include <bits/stdc++.h>
using namespace std;

#define llong long long 
#define len(x) ((int)x.size())
#define rep(i,n) for (int i = -1; ++ i < n; )
#define rep1(i,n) for (int i = 0; i ++ < n; )
#ifdef testing
mt19937 rng(177013);
#else
mt19937 rng(chrono::system_clock::now().time_since_epoch().count());
#endif
#define rand() (int)(rng() >> 1)
#define CONCAT_(x, y) x##y/*{{{*/
#define CONCAT(x, y) CONCAT_(x, y)
#define SPEC(name) CONCAT(name, __LINE__)
#ifdef LOCAL_DEBUG   
int __db_level = 0;
#define clog cerr << string(__db_level * 2, ' ')
struct debug_block {
    string msg;
    debug_block(const string& s): msg(s) { clog << "{ " << msg << endl; ++__db_level; }
    ~debug_block() { --__db_level; clog << "} " << msg << endl; }
};
#define DB(args...) stringstream SPEC(ss); SPEC(ss)<< args; debug_block SPEC(dbbl)(SPEC(ss).str())
#else
#define clog if (0) cerr
#define DB(...)
#endif
#define db(val) "[" #val " = " << val << "]; "
template<class U, class V> ostream& operator<<(ostream& out, const pair<U, V>& p) {
    return out << "(" << p.first << ", " << p.second << ")";
}
template<size_t i, class T> ostream& print_tuple_utils(ostream& out, const T& tup) {
    if constexpr(i == tuple_size<T>::value) return out << ")";
    else return print_tuple_utils<i + 1, T>(out << (i ? ", " : "(") << get<i>(tup), tup);
}
template<class ...U>
ostream& operator<<(ostream& out, const tuple<U...>& tup) { return print_tuple_utils<0, tuple<U...>>(out, tup); }
template<class, typename = void> struct has_const_iterator : false_type {};
template<class T> struct has_const_iterator<T, void_t<typename T::const_iterator>> : true_type {};
template<class T>
typename enable_if<has_const_iterator<T>::value && !is_same<T, string>::value, ostream&>::type
operator<<(ostream& out, const T& container) { 
    auto beg = container.begin(), end = container.end();
    out << "(" << container.size() << ") {";
    if (beg != end) out << *(beg++);
    while (beg != end) out << ", " << *(beg++);
    return out << "}";
}
#define ptrtype(x) typename iterator_traits<x>::value_type
template<class u> vector<ptrtype(u)> $v(u a, u b) { return vector<ptrtype(u)>(a, b); }/*}}}*/
// ACTUAL SOLUTION START HERE ////////////////////////////////////////////////////////////////

int n, m;
vector<vector<int>> board;
void read() {
    cin >> n >> m;
    board.assign(n, vector<int>(m));
    
    rep(i, n) {
        string s; cin >> s;
        rep(f, m)
            board[i][f] = s[f] - '0';
    }
}

vector<tuple<int, int, int, int, int, int>> ans;
void change(int x1, int y1, int x2, int y2, int x3, int y3) {
    board[x1][y1] ^= 1;
    board[x2][y2] ^= 1;
    board[x3][y3] ^= 1;
    ans.emplace_back(x1, y1, x2, y2, x3, y3);
}

void change(const vector<pair<int, int>>& c) {
    assert(c.size() == 3);
    change(c[0].first, c[0].second, c[1].first, c[1].second, c[2].first, c[2].second);
}

void solve() {
    ans.clear();
    int cur_n = n, cur_m = m;
    
    while (cur_n > cur_m) {
        int row = cur_n - 1;
        rep(i, cur_m - 1) {
            if (board[row][i]) 
                change(row, i, row - 1, i, row - 1, i + 1);
        }
        if (board[row][cur_m - 1])
            change(row, cur_m - 1, row - 1, cur_m - 1, row - 1, cur_m - 2);
        --cur_n;
    }
    while (cur_m > cur_n) {
        int col = cur_m - 1;
        rep(i, cur_n - 1) if (board[i][col])
            change(i, col, i, col - 1, i + 1, col - 1);
        if (board[cur_n - 1][col])
            change(cur_n - 1, col, cur_n - 1, col - 1, cur_n - 2, col - 1);
        --cur_m;
    }
    
    assert(cur_n == cur_m);
    while (cur_n > 2) {
        DB(cur_n);
        int row = cur_n - 1, col = cur_m - 1;
        rep(i, cur_m - 2) {
            if (board[row][i]) change(row, i, row - 1, i, row - 1, i + 1);
            if (board[i][col]) change(i, col, i, col - 1, i + 1, col - 1);
        }
        vector<pair<int, int>> rest = {{row, col}, {row - 1, col}, {row, col - 1}};
        int cnt = board[row][col] + board[row - 1][col] + board[row][col - 1];
        if (cnt == 1) {
            vector<pair<int, int>> cur = {{row - 1, col - 1}};
            for (auto [r, c]: rest) if (!board[r][c]) cur.emplace_back(r, c);
            change(cur);
            cnt = 3;
        }
        if (cnt == 2) {
            vector<pair<int, int>> cur = {{row - 1, col - 1}};
            for (auto [r, c]: rest) if (board[r][c]) cur.emplace_back(r, c);
            change(cur);
            cnt = 0;
        }
        if (cnt == 3) change(rest);
        rep(i, n) {
            clog << board[i] << endl;
        }
        --cur_n; --cur_m;
    }
    assert(cur_n == 2);
    vector<pair<int, int>> one, zero;
    rep(i, 2) rep(f, 2) {
        if (board[i][f]) one.emplace_back(i, f);
        else zero.emplace_back(i, f);
    }
    
    if (len(one) == 4) {
        swap(zero, one);
        one.push_back(zero.back());
        zero.pop_back();
        change(zero);
    }
    if (len(one) == 3) change(one);
    if (len(one) == 1) {
        one.push_back(zero.back()); zero.pop_back();
        one.push_back(zero.back()); zero.pop_back();
        change(one);
        zero.push_back(one[0]);
        one.erase(one.begin());
    }
    if (len(one) == 2) {
        zero.push_back(one[0]);
        change(zero);
        zero.back() = one[1];
        change(zero);
    }
}

int main(void) {
#ifdef LOCAL
    freopen("main.inp", "r", stdin);
    freopen("main.out", "w", stdout);
    freopen(".log", "w", stderr);
#endif
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int ntest; cin >> ntest;
    while (ntest--) {
        read();
        solve();
        cout << len(ans) << '\n';
        for (auto [x1, y1, x2, y2, x3, y3]: ans) {
            cout << x1 + 1 << ' ' << y1 + 1 << ' ' << x2 + 1 << ' ' << y2 + 1 << ' ' << x3 + 1 << ' ' << y3 + 1 << '\n';
        }
        assert(len(ans) <= n * m);
        rep(i, n) rep(f, m) assert(!board[i][f]);
    }
    
    
    return 0;
}

// vim: foldmethod=marker