// #define multitest 
// #define testing   
// #define print_brute 

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
#define sqr(x) ((x) * (x))
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

const int maxn = 100001;
const int max_val = 2 * 100010;
const llong mod = (llong)(1e9 + 7);

vector<int> primes;
int pdiv_pos[max_val];
void sieve() {
    memset(pdiv_pos, -1, sizeof(pdiv_pos));
    for (int i = 2; i < max_val; ++i) {
        if (pdiv_pos[i] != -1) continue;
        for (int f = i; f < max_val; f += i) {
            pdiv_pos[f] = len(primes);
        }
        primes.push_back(i);
    }
}

vector<pair<int, int>> factor_pos(int num) {
    vector<pair<int, int>> ans;
    while (num > 1) {
        int p = pdiv_pos[num];
        int d = primes[p];
        ans.emplace_back(p, 0);
        while (num % d == 0) {
            ++ans.back().second;
            num /= d;
        }
    }
    return ans;
}

struct query {
    int l, r;
};

int n, q;
int a[maxn];
int last_ans;
void read() {
#ifndef testing
    cin >> n;
    rep(i, n) cin >> a[i];
    cin >> q;
    last_ans = 0;
#else 
    n = rand() % 10 + 1;
    rep(i, n) a[i] = rand() % 200000 + 1;
    q = 10;
#endif
}

#ifdef testing
llong cur_ans = 1;
int last_l, last_r;
#endif
void answer(int ans) {
#ifndef testing
    last_ans = ans;
    cout << ans << '\n';
#else
    if (cur_ans != ans) {
        cout << "FAILED" << endl;
        cout << ans << ' ' << cur_ans << endl;
        ofstream inp("main.inp");
        inp << n << '\n';
        rep(i, n) inp << a[i] << ' ';
        inp << "\n1\n" << last_l << ' ' << last_r << endl;
        exit(1);
    }
#endif
}

query get_query() {
#ifndef testing
    int x, y; cin >> x >> y;
    x = (x + last_ans) % n + 1;
    y = (y + last_ans) % n + 1;
    if (x > y) swap(x, y);
    return query{x, y};
#else 
    last_l = rand() % n + 1;
    last_r = rand() % n + 1;
    if (last_l > last_r) swap(last_l, last_r);
    cur_ans = 1;
    map<int, int> mx_pw;
    for (int i = last_l - 1; i < last_r; ++i) {
        auto ftor = factor_pos(a[i]);
        for (auto [pos, cnt]: ftor) 
            mx_pw[pos] = max(mx_pw[pos], cnt);
    }
    for (auto [pos, cnt]: mx_pw) {
        llong cur = primes[pos];
        clog << db(pos) << db(cur) << db(cnt) << endl;
        rep(i, cnt) (cur_ans *= cur) %= mod;
    }
    return query{last_l, last_r};
#endif
}

struct IT {
    int n_;
    vector<int> data;
    IT(int n__): n_(n__), data(2 * n_) {}
    
    void upd(int pos, int val) {
        for (data[pos += n_] = val; pos > 1; pos >>= 1)
            data[pos >> 1] = max(data[pos], data[pos ^ 1]);
    }
    
    int get_mx(int l, int r) {
        int ans = 0;
        for (l += n_, r += n_; l < r; l >>= 1, r >>= 1) {
            if (l & 1) ans = max(ans, data[l++]);
            if (r & 1) ans = max(ans, data[--r]);
        }
        return ans;
    }
};

struct SqrtProd {
    vector<llong> vals;
    vector<vector<llong>> buck_prod;
    int buck_size;
    vector<int> nxt, prv;
    SqrtProd(const vector<llong>& vals_) : vals(vals_) {
        buck_size = (int)sqrt(len(vals));
        int mx_blk = len(vals) / buck_size + 2;
        buck_prod.resize(mx_blk, vector<llong>(mx_blk, 1ll));
        nxt.resize(len(vals), len(vals));
        prv.resize(len(vals), -1);
        map<llong, int> pos;
        rep(i, len(vals)) {
            llong u = vals[i];
            if (pos.count(u)) {
                int id = pos[u];
                nxt[id] = i;
                prv[i] = id;
            }
            pos[u] = i;
        }
        for (int start = 0; start < len(vals); start += buck_size) {
            int l = start / buck_size;
            llong cur = 1;
            int cnt = 0;
            auto add = [&](int id) {
                ++cnt;
                if (prv[id] < start) (cur *= vals[id]) %= mod;
                if (cnt % buck_size == 0) buck_prod[l][l + cnt / buck_size] = cur;
            };
            for (int end = start; end < len(vals); ++end)
                add(end);
        }
    }
    
    llong get(int l, int r) const {
        int bl = l / buck_size, br = r / buck_size;
        llong ans = 1;
        if (bl == br) {
            for (int i = l; i < r; ++i) {
                if (prv[i] < l) (ans *= vals[i]) %= mod;
            }
        } else {
            ans = buck_prod[bl + 1][br];
            for (int i = l; i < (bl + 1) * buck_size; ++i) 
                if (nxt[i] >= br * buck_size) (ans *= vals[i]) %= mod;
            for (int i = br * buck_size; i < r; ++i) 
                if (prv[i] < l) (ans *= vals[i]) %= mod;
        }
        return ans;
    }
};

void solve() {
    int cnt_small_primes = 0;
    while (sqr(primes[cnt_small_primes]) <= max_val) ++cnt_small_primes;
    
    vector<IT> small_it(cnt_small_primes, IT(n));
    vector<llong> big_vals;
    rep(i, n) {
        auto ftor = factor_pos(a[i]);
        llong big = 1;
        for (auto [pos, cnt]: ftor) {
            if (pos < cnt_small_primes) small_it[pos].upd(i, cnt);
            else {
                assert(cnt == 1);
                assert(big == 1);
                big = primes[pos];
            }
        }
        big_vals.push_back(big);
    }
    SqrtProd sp(big_vals);
    
    rep(qr, q) {
        DB(db(qr));
        auto [l, r] = get_query();
        --l;
        llong ans = 1;
        rep(i, cnt_small_primes) {
            llong cur = primes[i];
            int mx_pw = small_it[i].get_mx(l, r);
            while (mx_pw --) (ans *= cur) %= mod;
        }
        clog << db(ans) << endl;
        (ans *= sp.get(l, r)) %= mod;
        clog << db(ans) << endl;
        answer((int)ans);
    }
}

// ACUTAL SOLUTION END HERE //////////////////////////////////////////////////////////////////
// FOR HACKER/READER - you don't need to care about the part below
int main(void) {
    sieve();
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef testing
    int ntest = 1;
#else
    int ntest = 1000000;
#endif
    rep1(testcase, ntest) {
        DB(testcase);
        read();
        solve();
        // print_ans(cout, ans); 
#ifdef print_brute
        auto br = brute();
        print_ans(cout << endl << "====" << endl, br);
#endif
    }
    return 0;
}

// vim: foldmethod=marker