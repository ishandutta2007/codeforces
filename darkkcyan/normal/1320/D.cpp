#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
const ld eps = 1e-8;
// for matching the kactl notes
#define sz(x) ((int)x.size())
#define rep(i,a,b) for (int i = (int)(a); i < (int)(b); ++i) 
#define all(a) (a).begin(), (a).end()
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

#define def_op(type, op) \
    friend inline type operator op(type u, const type& v) { return u op ##= v; } \
    type& operator op ##= (const type& o)
template<int mod_>
struct modint {
    static constexpr int mod = mod_;
    int x;
    modint(int xx = 0): x(xx) {}
    modint(ll xx): x((int)(xx % mod)) {}
    def_op(modint, +) {
        if ((x += o.x) >= mod) x -= mod;
        return *this;
    }
    def_op(modint, -) {
        if ((x -= o.x) < 0) x += mod;
        return *this;
    }
    def_op(modint, *) {
        return *this = modint(1ll * x * o.x);
    }
    friend bool operator==(const modint& u, const modint& v) {
        return u.x == v.x;
    }
};

using mint = modint<(int)1e9+8181>;
// using mint2 = modint<(int)998'244'353>; 

struct Hash {
    mint u;
    // int v; 
    Hash(int x = 0): u(x)/*,  v(x) */ {}
    def_op(Hash, +) {
        u += o.u;
        // v += o.v; 
        return *this;
    }
    def_op(Hash, -) {
        u -= o.u;
        // v -= o.v; 
        return *this;
    }
    def_op(Hash, *) {
        u *= o.u;
        // v *= o.v; 
        return *this;
    }
    friend bool operator==(const Hash& u, const Hash& v) {
        return u.u == v.u /* and u.v == v.v*/;
    }
    
    friend ostream& operator<<(ostream& out, const Hash& u) {
        // return out << pair{u.u.x, u.v}; 
        return out << u.u.x;
    }
};

const int maxn = 201010;
const int bs = 250;

mt19937 rng;
int base;
Hash pwbase[maxn];
void precal() {
    base = (int)(rng() % 10000 * 2 + 3);
    pwbase[0] = 1;
    rep(i, 1, maxn) pwbase[i] = pwbase[i - 1] * base;
}

struct Query {
    int id;
    int l, r;
};

int n, q;
string s;

void get_small(string& ans, int l, int r) {
    ans.clear();
    rep(i, l, r) {
        if (ans.empty()) ans += s[i];
        else if (s[i] == '0' or ans.back() == '0') ans += s[i];
        else ans.pop_back();
    }
}

Hash hash_ans[maxn];

// mt19937 rng; 
#define rand()  ((int)(rng() >> 1))
int main() {
    rng.seed((ll)main ^ time(0));
    precal();
#ifdef LOCAL
    freopen("main.inp", "r", stdin); 
    freopen("main.out", "w", stdout);  
    freopen(".log", "w", stderr);
#endif
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;  
    cin >> s;  
    cin >> q;  
    // n = q = 200'000;  
    // s = string(n, '1');  
    vector<int> sum_1(n + 1);
    rep(i, 0, n) {
        sum_1[i + 1] = sum_1[i] + (s[i] == '1');
    }
    vector<vector<Query>> queries(maxn / bs + 10);
    
    rep(i, 0, q) {
        int l1, l2, len;
        cin >> l1 >> l2 >> len;  
        // len = rand() % n + 1;  
        // l1 = rand() % (n - len + 1) + 1;  
        // l2 = rand() % (n - len + 1) + 1;  
            
        --l1; --l2;
        if (sum_1[l1 + len] - sum_1[l1] != sum_1[l2 + len] - sum_1[l2]) {
            hash_ans[i] = 1;
            continue;
        }
        if (len <= bs) {
            static string u, v;
            get_small(u, l1, l1 + len);
            get_small(v, l2, l2 + len);
            hash_ans[i] = u != v;
            clog << db(i) << db(l1) << db(l2) << db(len) << db(u) << db(v) << endl;
            continue;
        }
        queries[l1 / bs].push_back({2 * i, l1, l1 + len});
        queries[l2 / bs].push_back({2 * i + 1, l2, l2 + len});
    }
    
    rep(blk, 0, sz(queries)) {
        auto& cur_qr = queries[blk];
        if (cur_qr.empty()) continue;
        sort(all(cur_qr), [&](const auto& u, const auto& v) {
                return u.r < v.r;
                });
        
        static deque<pair<int, Hash>> qu;
        qu.clear();
        
        int r = (blk + 1) * bs;
        for (auto [qid, ql, qr]: cur_qr) {
            while (r < qr) {
                int ch = s[r++] - '0' + 1;
                if (qu.empty()) {
                    qu.emplace_back(ch, ch);
                } else if (ch == 1 or qu.back().first == 1) {
                    qu.emplace_back(ch, qu.back().second * base + ch);
                } else {
                    qu.pop_back();
                }
            }
            
            static vector<pair<int, Hash>> history;
            auto cur_hs = qu.size() ? qu.back().second : 0;
            int l = (blk + 1) * bs;
            while (l > ql) {
                int ch = s[--l] - '0' + 1;
                if (qu.size() == 0 or qu[0].first == 1 or ch == 1) {
                    history.emplace_back(-1, 0);
                    cur_hs += pwbase[sz(qu)];
                    if (ch == 2) cur_hs += pwbase[sz(qu)];
                    qu.emplace_front(ch, 0);
                } else {
                    history.emplace_back(qu[0]);
                    qu.pop_front();
                    cur_hs -= pwbase[sz(qu)] + pwbase[sz(qu)];
                }
            }
            clog << db(qid) << db(qu) << db(cur_hs) << endl;
            if (qid & 1) {
                hash_ans[qid >> 1] += cur_hs;
            } else {
                hash_ans[qid >> 1] -= cur_hs;
            }
            while (sz(history)) {
                if (history.back().first == -1) {
                    qu.pop_front();
                } else {
                    qu.push_front(history.back());
                }
                history.pop_back();
            }
        }
    }
    
    Hash zero(0);
    rep(i, 0, q) {
        cout << (hash_ans[i] == zero ? "Yes\n": "No\n");
    }
    
    return 0;
}

// vim: foldmethod=marker