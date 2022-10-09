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

int n;
string l, r;

string solve() {
    if (l == r) return l;
    bool padded = false;
    if (n == 1) {
        n = 2;
        l = "0" + l;
        r = "0" + r;
        padded = true;
    }
    auto dec = [&](string& x) -> bool {
        int i = n;
        while (i--) {
            if (x[i] == '1') break;
            x[i] = '1';
        }
        if (i == -1) return false;
        x[i] = '0';
        return true;
    };
    auto inc = [&](string& x) -> bool {
        int i = n;
        while (i--) {
            if (x[i] == '0') break;
            x[i] = '0';
        }
        if (i == -1) return false;
        x[i] = '1';
        return true;
    };
    
    const string zero = string(n, '0');
    const string one = string(n - 1, '0') + '1';
    
    auto pref_xor = [&](string x) {
        string last = x.substr(n - 2);
        if (last == "00") return x;
        if (last == "10") {
            x.back() = '1';
            return x;
        }
        if (last == "01") return one;
        return zero;
    };
    
    auto xxx = [&](string u, const string& v) {
        rep(i, len(u)) u[i] = char((u[i] != v[i]) + '0');
        return u;
    };
    
    string ans(n, '0');
    auto upd_ans = [&](const string& other) {
        DB();
        clog << db(other)<< endl;
        ans = max(ans, other);
    };
    
    string lower = l;
    if (!dec(lower)) lower = l;
    int cu = 0;
    clog << db(r) << ' ' << db(lower) << endl;
    for (string up = r; up >= l and cu < 4; ++cu) {
        int cd = 0;
        for (string down = lower; down < up and cd < 4; ++cd) {
            string x = xxx(pref_xor(down), pref_xor(up));
            clog << db(up) << db(down) << db(x) << endl;
            upd_ans(x);
            if (!inc(down)) break;
        }
        if (!dec(up)) break;
    }
    clog << db(ans) << endl;
    
    string cor_tail[] = {"00", "10"};
    string tail[] = {"00", "11"};
    rep(tail_up, 2) 
    rep(tail_down, 2) {
        DB();
        clog << db(tail_up) << endl;
        clog << db(tail_down) << endl;
        string u = r;
        bool has = true;
        while (u.substr(n - 2) != cor_tail[tail_up]) {
            if (!dec(u)) {
                has = false;
                break;
            }
        }
        if (!has) continue;
        string v = lower;
        while (v.substr(n - 2) != cor_tail[tail_down]) {
            if (!inc(v)) {
                has = false;
                break;
            }
        }
        if (!has) continue;
        if (v > u) continue;
        clog << db(u) << db(v) << endl;
        string cur_ans = "";
        int i = 0;
        while (i < n - 2 and u[i] == v[i]) {
            cur_ans += '0';
            ++i;
        }
        if (i < n - 2) {
            cur_ans += '1';
            ++i;
        }
        while (i < n - 2) {
            ++i;
            cur_ans += '1';
        }
        cur_ans += xxx(tail[tail_up], tail[tail_down]);
        upd_ans(cur_ans);
    }
    if (padded) ans.erase(ans.begin());
    return ans;
}

mt19937 rng;
#define rand() ((int)(rng() >> 1))
void gen() {
    n = rand() % 100 + 1;
    l = r = "";
    rep(i, n) {
        l += char('0' + rand() % 2);
        r += char('0' + rand() % 2);
    }
    if (l > r) swap(l, r);
    ofstream inp("main.inp");
    inp << n << endl;
    inp << l << endl;
    inp << r << endl;
    solve();
}

int main(void) {
    // while (true) { gen(); }  
#ifdef LOCAL
    freopen("main.inp", "r", stdin);
    freopen("main.out", "w", stdout);
    freopen(".log", "w", stderr);
#endif
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> l >> r;
    cout << solve() ;
    
    return 0;
}

// vim: foldmethod=marker