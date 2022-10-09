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

#define defop(type, op) \
    inline friend type operator op(type u, const type& v) { return u op ##= v; } \
    type& operator op ##= (const type& o) 
template<int mod>
struct modint {
    int x;
    modint(int xx = 0): x(xx) {}
    modint(ll xx): x((int)(xx % mod)) {}
    defop(modint, +) {
        if ((x += o.x) >= mod) x -= mod;
        return *this;
    }
    defop(modint, -) {
        if ((x -= o.x) < 0) x += mod;
        return *this;
    }
    defop(modint, *) {
        return *this = modint(1ll * x * o.x);
    }
    
    friend print_op(modint) {
        return out << u.x;
    }
    friend bool operator==(modint u, modint v) {
        return u.x == v.x;
    }
};

// using mint = modint<998244353>; 
using mint = modint<(int)1e9 + 7>; 

#ifdef LOCAL
// const char min_char = '0'; 
// const char max_char = '2'; 
const char min_char = 'a';
const char max_char = 'z';
#else
const char min_char = 'a';
const char max_char = 'z';
#endif

int n, k;
string s;

mint brute() {
    function<int(const string&, const string&)> cal_bigger = [&](const string& u, const string& v) {
        int cnt_bigger = 0;
        rep(l, 0, n) {
            rep(r, l + 1, n + 1) {
                bool is_bigger = u.substr(l, r - l) < v.substr(l, r - l);
                // clog << db(l) << db(r) << db(is_bigger) << endl; 
                if (is_bigger) {
                // if (lexicographical_compare(u.begin() + l, u.begin() + r, v.begin() + l, v.begin() + r)) {  
                    ++cnt_bigger;
                }
            }
        }
        return cnt_bigger;
    };
    string t(n, ' ');
    
    DB();
    mint ans = 0;
    function<void(int)> backtrack = [&](int pos) {
        if (pos == n) {
            auto bigger = cal_bigger(s, t);
            clog << db(t) << db(bigger) << endl;
            if (bigger == k) {
                clog << "here" << endl;
                ans += 1;
            }
            return ;
        }
        for (char i = min_char; i <= max_char; ++i) {
            t[pos] = i;
            backtrack(pos + 1);
        }
    };
    backtrack(0);
    return ans;
}

mint solve() {
    vector<vector<mint>> dple(n + 1, vector<mint>(k + 1)), dpeq = dple, dpgr = dple;
    vector<mint> suff_sum_le(k + 1), suff_sum_gr(k + 1);
    
    dpeq[n][0] = 1;
    
    for (int i = n; i--; ) {
        mint cnt_bigger = (int)(max_char - s[i]);
        mint cnt_smaller = (int)(s[i] - min_char);
        int l = n - i;
        rep(cur_k, l, k + 1) {
            dpgr[i][cur_k] += cnt_bigger * (dpgr[i + 1][cur_k - l] + dple[i + 1][cur_k - l] + dpeq[i + 1][cur_k - l]);
        }
        rep(cur_k, 0, k + 1) {
            dple[i][cur_k] += cnt_smaller * (dpgr[i + 1][cur_k] + dple[i + 1][cur_k] + dpeq[i + 1][cur_k]);
        }
        
        rep(cur_k, 0, k + 1) {
            dpeq[i][cur_k] += suff_sum_le[cur_k];
            int u = i + 1, v = n - 1;
            while (u <= v and cur_k - (n - u) * (u - i) >= 0) {
                dpeq[i][cur_k] += dpgr[u][cur_k - (n - u) * (u - i)];
                ++u;
            }
            while (u < v and cur_k - (n - v) * (v - i) >= 0) {
                dpeq[i][cur_k] += dpgr[v][cur_k - (n - v) * (v - i)];
                --v;
            }
        }
        dpeq[i][0] += 1;
        
        rep(cur_k, 0, k + 1) {
            suff_sum_le[cur_k] += dple[i][cur_k];
        }
        // rep(cur_k, l, k + 1) { 
            // suff_sum_gr[cur_k] += dpgr[i][cur_k - l]; 
        // } 
        DB();
        clog << db(i) << endl;
        clog << db(l) << endl;
        clog << db(cnt_bigger) << db(cnt_smaller) << db(s[i] - min_char) << endl;
        clog << db(dple[i]) << endl;
        clog << db(dpeq[i]) << endl;
        clog << db(dpgr[i]) << endl;
        clog << db(suff_sum_le) << endl;
        clog << db(suff_sum_gr) << endl;
    }
    auto ans = dple[0][k] + dpgr[0][k] + dpeq[0][k];
    return ans;
}

mt19937 rng;
#define rand() ((int)(rng() >> 1))
void gentest() {
    ofstream inp("main.inp");
    n = rand() % 5 + 1;
    s = "";
    rep(i, 0, n) s += char(min_char + rand() % (max_char - min_char + 1));
    k = rand() % 20;
    inp << n << ' ' << k << endl;
    inp << s;
}
void check() {
    gentest();
    auto ans = solve();
    auto exp = brute();
    cout << db(ans) << db(exp) << endl;
    if (ans == exp) {
        cout << "OK" << endl;
        return ;
    }
    cout << "NO" << endl;
    exit(0);
}

int main() {
#ifdef LOCAL
    // while (1) check();    
    freopen("main.inp", "r", stdin); 
    freopen("main.out", "w", stdout);  
    freopen(".log", "w", stderr);
#endif
    cin.tie(0)->sync_with_stdio(0);
    
    cin >> n >> k >> s;
    cout << solve();
#ifdef LOCAL
    cout << endl << brute() << endl;
#endif
    
    return 0;
}

// vim: foldmethod=marker