// #define multitest 
#ifdef LOCAL
#define testing       
#define print_brute 
#endif

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

using ans_type = optional<vector<int>>;

struct Book {
    int time;
    int type;
};
const int maxn = 201010;
int n, m, k;
Book books[maxn];
void read() {
    cin >> n >> m >> k;
    rep(i, n) {
        int a, b; cin >> books[i].time >> a >> b;
        books[i].type = a << 1 | b;
    }
}

void print_ans(ostream& cout, const ans_type& _ans) {
    if (!_ans) {
        cout << "-1";
        return ;
    }
    auto& ans = *_ans;
    clog << db(ans) << endl;
    assert(len(ans) == m);
    llong sum = 0;
    int cnt_like[2] = {0, 0};
    for (auto i: ans) {
        sum += books[i].time;
        
        if (books[i].type >> 1) cnt_like[1] ++;
        if (books[i].type & 1) cnt_like[0] ++;
    }
    clog << db(cnt_like[0]) << db(cnt_like[1]) << endl;
    assert(cnt_like[0] >= k);
    assert(cnt_like[1] >= k);
    cout << sum << '\n';
    for (auto i: ans )cout << i + 1 << ' ';
}

ans_type solve() {
    vector<int> compr_id(n);
    vector<pair<int, int>> vals;
    rep(i, n) {
        vals.emplace_back(books[i].time, i);
    }
    sort(vals.begin(), vals.end());
    // same value "must" have different id, but they should be adjacency
    rep(i, n) compr_id[vals[i].second] = i;
    
    struct BIT {
        vector<int> cnt;
        vector<llong> sum;
        BIT(): cnt(n + 10), sum(n + 10) {}
        void add(int pos, llong val, int delta = 1) {
            clog << db(pos) << db(val) << db(delta) << endl;
            val *= delta;
            for (++pos; pos < len(cnt); pos += pos & -pos) {
                cnt[pos] += delta;
                sum[pos] += val;
            }
        }
        
        llong get_sum(int total) {
            llong cur_sum = 0;
            int cur_cnt = 0;
            int cur_pos = 0;
            for (int i = 20; i--; ) {
                int new_pos = cur_pos + (1 << i);
                if (new_pos >= len(cnt)) continue;
                int new_cnt = cur_cnt + cnt[new_pos];
                if (new_cnt > total) continue;
                cur_sum += sum[new_pos];
                cur_cnt = new_cnt;
                cur_pos = new_pos;
            }
            return cur_sum;
        }
    };
    
    vector<int> book_group[4];
    rep(i, n) book_group[books[i].type].push_back(i);
    llong sum[4]{};
    rep(g, 4) {
        sort(book_group[g].begin(), book_group[g].end(), [&](int u, int v) {
            return books[u].time < books[v].time;
        });
        for (auto i: book_group[g]) sum[g] += books[i].time;
    }
    sum[3] = 0;
    
    BIT bit;
    for (auto i: book_group[0]) bit.add(compr_id[i], books[i].time);
    for (auto i: book_group[3]) bit.add(compr_id[i], books[i].time);
        
    int u = len(book_group[1]), v = len(book_group[2]);
    
    pair<llong, int> min_ans(LLONG_MAX, -1);
    
    rep(cnt_both, len(book_group[3]) + 1) {
        DB(cnt_both);
        while (u > 0 and u + cnt_both > k) {
            --u;
            llong tm = books[book_group[1][u]].time;
            sum[1] -= tm;
            bit.add(compr_id[book_group[1][u]], tm);
        }
        
        while (v > 0 and v + cnt_both > k) {
            --v;
            llong tm = books[book_group[2][v]].time;
            sum[2] -= tm;
            bit.add(compr_id[book_group[2][v]], tm);
        }
        if (cnt_both >= m) {
            min_ans = min(min_ans, {sum[3], cnt_both});
        }
        if (u + cnt_both >= k and v + cnt_both >= k and u + v + cnt_both <= m) {
            llong cur_ans = sum[3] + sum[1] + sum[2] + bit.get_sum(m - u - v - cnt_both);
            min_ans = min(min_ans, {cur_ans, cnt_both});
            clog << db(u) << db(v) << db(cur_ans) << db(vector(sum, sum + 4)) << endl;
        }
        
        if (cnt_both == len(book_group[3])) break;
        llong tm = books[book_group[3][cnt_both]].time; 
        sum[3] += tm;
        bit.add(compr_id[book_group[3][cnt_both]], tm, -1);
    }
    if (min_ans.second == -1) return {};
    clog << db(min_ans) << endl;
    vector<int> ans;
    rep(i, min_ans.second) ans.push_back(book_group[3][i]);
    for (int i = len(book_group[3]) - 1; i >= min_ans.second; --i)
        book_group[0].push_back(book_group[3][i]);
    
    rep(i, k - min_ans.second) {
        ans.push_back(book_group[1][i]);
        ans.push_back(book_group[2][i]);
    }
    for (auto g: {1, 2}) {
        for (int i = len(book_group[g]) - 1; i >= max(0, k - min_ans.second); --i) 
            book_group[0].push_back(book_group[g][i]);
    }
    sort(book_group[0].begin(), book_group[0].end(), [&](int x, int y) {
        return books[x].time < books[y].time;
    });
    clog << db(book_group[0]) << endl;
    
    for (int i = 0; len(ans) < m; ++i)
        ans.push_back(book_group[0][i]);
    
    return {ans};
}

// ACUTAL SOLUTION END HERE //////////////////////////////////////////////////////////////////
// FOR HACKER/READER - you don't need to care about the part below
int brute();
#ifndef testing
int main(void) {
#ifdef LOCAL
    freopen("main.inp", "r", stdin);
    freopen("main.out", "w", stdout);
    freopen(".log", "w", stderr);
#endif
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int ntest = 1;
#ifdef multitest
    cin >> ntest;
#endif
    rep1(testcase, ntest) {
        DB(testcase);
        read();
        auto ans = solve();
        print_ans(cout, ans);
#ifdef print_brute
        auto br = brute();
        cout << endl << "=====\n" << br << endl;
        cout << endl << "==============" << endl;
#endif
    }
    return 0;
}
#else
void gen_test(int cur_test) {
    ofstream inp("main.inp");
    n = rand() % 10 + 1;
    m = rand() % n + 1;
    k = rand() % m + 1;
    inp << n << ' ' << m << ' ' << k << endl;
    rep(i, n) {
        books[i].time = rand() % 100 + 1;
        int a = rand() % 2;
        int b = rand() % 2;
        inp << books[i].time << ' ' << a << ' ' << b << '\n';
        books[i].type = a << 1 | b;
    }
}
int main(void) {
    rep1(testcase, 10000) {
        gen_test(testcase);
        // solve(); 
        auto ans = solve(); 
        auto br = brute(); 
        llong sum = 0;
        if (!ans) sum = -1;
        else for (auto i: *ans) sum += books[i].time;
        assert(sum == br); 
        cout << "OK " << testcase << endl;
    }
    return 0;
}
#endif

int brute() {
    vector dp(n + 1, vector(n + 1, vector(n + 1, vector(n + 1, (llong)INT_MAX))));
    dp[0][0][0][0] = 0;
    rep1(i, n) {
        dp[i] = dp[i - 1];
        int a = books[i - 1].type >> 1;
        int b = books[i - 1].type & 1;
        int tm = (int)books[i - 1].time;
        rep(cnt, n) rep(u, n) rep(v, n) {
            dp[i][cnt + 1][u + a][v + b] = min(dp[i][cnt + 1][u + a][v + b],
                    dp[i - 1][cnt][u][v] + tm);
        }
    }
    llong ans = INT_MAX;
    rep(u, n + 1) rep(v, n + 1) if (u >= k and v >= k) ans = min(ans, dp[n][m][u][v]);
    if (ans >= INT_MAX) ans = -1;
    return (int)ans;
}

// vim: foldmethod=marker