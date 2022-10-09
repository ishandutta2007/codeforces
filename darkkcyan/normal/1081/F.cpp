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

struct solver {
    int n, t;
    virtual void init() = 0;
    virtual int ask(int l, int r) = 0;  // 1-indexed, [l, r]
    virtual void answer(const vector<bool>& ans) = 0;
    
    void solve() {
        init();
        if (t == 0 or t == n) {
            answer(vector<bool>(n, !!t));
            return ;
        }
        
        vector<bool> cur_xor(n);
        vector<bool> ans(n);
        
        auto upd_cur_xor = [&](int l, int r) {  // 0-indexed, [l, r)
            rep(i, l, r) cur_xor[i] = 1 - cur_xor[i];
        };
        
        function<int(int, int, int)> ask_til_diff_parity = [&](int l, int r, int par) {  // 1-indexed, [l, r]
            assert((r - l + n) % 2 == 0);
            int new_t = ask(l, r);
            int diff = (new_t - t) & 1;
            clog << db(l) << db(r) << db(par) << db(diff) << db(new_t) << endl;
            if (diff == (r & 1)) {
                upd_cur_xor(0, r);
            } else {
                upd_cur_xor(l - 1, n);
            }
            if (diff == par) {
                return new_t;
            }
            t = new_t;
            return ask_til_diff_parity(l, r, par);
        };
        
        auto ask_til_left_flip = [&](int l, int r) { return ask_til_diff_parity(l, r, r & 1); };
        auto ask_til_right_flip = [&](int l, int r) { return ask_til_diff_parity(l,r, !(r & 1)); };
        
        {
            int new_t = ask_til_right_flip(2, n);
            ans[0] = cur_xor[0] ^ ((new_t + t - (n - 1)) / 2);
            t = new_t;
            clog << db(ans[0]) << endl;
        }
        
        rep(i, 1, n) {
            int new_t = ask_til_left_flip(i + (~n & 1), i + 1);
            
            int sx = (new_t + t - (i + 1)) / 2;
            int px = (new_t ^ sx) & 1;
            clog << db(i) << db(sx) << db(px) << endl;
            ans[i] = cur_xor[i] ^ px;
            rep(f, 0, i) ans[i] = ans[i] ^ cur_xor[f] ^ ans[f];
            
            t = new_t;
        }
        
        answer(ans);
    }
};

struct IOSolver: solver {
    void init() override {
        cin >> n >> t;
    }
    
    int ask(int l, int r) override {
        cout << "? " << l << ' ' << r << endl;
        int ans; cin >> ans;
        return ans;
    }
    
    void answer(const vector<bool>& ans) override {
        cout << "! ";
        for (auto i: ans) cout << i;
        cout << endl;
    }
};

struct AutoSolver: solver {
    string s, org;
    mt19937 rng;
    AutoSolver(bool from_file) {
        if (from_file) {
            ifstream inp("main.inp");
            inp >> rng;
            inp >> s;
        } else {
            ll seed = (ll)this ^ time(0);
            s = "";
            rng.seed(seed);
            n = (int)(rng() % 10 + 1);
            rep(i, 0, n) s += char((rng() & 1) + '0');
            
            rng.seed(seed + 1);
            dump_state();
        }
    }
    
    AutoSolver(const string& s_, ll seed): s(s_) {
        rng.seed(seed);
        dump_state();
    }
    
    void dump_state() {
        ofstream inp("main.inp");
        inp << rng << endl;
        inp << s << endl;
    }
    
    int cnt_query;
    void init() override {
        n = sz(s);
        t = (int)count(all(s), '1');
        cout << s << ' ' << db(n) << db(t) << endl;
        org = s;
        cnt_query = 40;
    }
    
    int ask(int l, int r) override {
        --cnt_query;
        if (cnt_query < 0) {
            cout << "Query exceed " << endl;
            exit(0);
        }
        cout << "? " << l << ' ' << r << endl;
        if (rng() & 1) {
            r = n;
        } else {
            l = 1;
        }
        rep(i, l - 1, r) {
            s[i] ^= 1;
        }
        int new_t = (int)count(all(s), '1');
        cout << s << ' ' << db(n) << db(new_t) << endl;
        return new_t;
    }
    
    void answer(const vector<bool>& ans) override {
        cout << "! ";
        for (auto i: ans) {
            cout << i;
        }
        cout << endl;
        cout << db(org) << endl;
        assert(sz(ans) == n);
        rep(i, 0, n) {
            assert((org[i] & 1) == ans[i]);
        }
    }
};

int main() {
#ifdef LOCAL
    // freopen("main.inp", "r", stdin);  
    // freopen("main.out", "w", stdout);   
    // freopen(".log", "w", stderr); 
#endif
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
#ifndef LOCAL
    IOSolver().solve();  
#else
    // IOSolver().solve();   
    // AutoSolver("1100", (ll)main).solve();  
    while (1) {
        AutoSolver(true).solve();
        cout << "OK " << endl;
    }
#endif
    
    
    return 0;
}

// vim: foldmethod=marker