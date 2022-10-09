#include <bits/stdc++.h>
using namespace std;

// #define constexpr(...) (__VA_ARGS__)
using ll = long long;
using ld = long double;
const ld eps = 1e-8;
// for matching the kactl notes
#define sz(x) ((int)x.size())
#define rep(i, a, b) for (int i = (a); i < (b); ++i)
#define all(a) (a).begin(), (a).end()
#define print_op(...) ostream &operator<<(ostream &out, const __VA_ARGS__ &u)
// DEBUGING TEMPLETE
// ////////////////////////////////////////////////////////////////////////{{{
// What? You wanted to see how this template works?  Check this out:
// https://quangloc99.github.io/2021/07/30/my-CP-debugging-template.html
#define db(val) "[" #val " = " << (val) << "] "
#define CONCAT_(x, y) x##y
#define CONCAT(x, y) CONCAT_(x, y)
#ifdef LOCAL_DEBUG
#define clog cerr << setw(__db_level * 2) << setfill(' ') << "" << setw(0)
#define DB() debug_block CONCAT(dbbl, __LINE__)
int __db_level = 0;
struct debug_block {
    debug_block() {
        clog << "{" << endl;
        ++__db_level;
    }
    ~debug_block() {
        --__db_level;
        clog << "}" << endl;
    }
};
#else
#define clog                                                                   \
    if (0)                                                                     \
    cerr
#define DB(...)
#endif

template <class U, class V> print_op(pair<U, V>) {
    return out << "(" << u.first << ", " << u.second << ")";
}
template <class Con, class = decltype(begin(declval<Con>()))>
typename enable_if<!is_same<Con, string>::value, ostream &>::type
operator<<(ostream &out, const Con &con) {
    out << "{";
    for (auto beg = con.begin(), it = beg; it != con.end(); ++it)
        out << (it == beg ? "" : ", ") << *it;
    return out << "}";
}
template <size_t i, class T>
ostream &print_tuple_utils(ostream &out, const T &tup) {
    if constexpr (i == tuple_size<T>::value)
        return out << ")";
    else
        return print_tuple_utils<i + 1, T>(
            out << (i ? ", " : "(") << get<i>(tup), tup);
}
template <class... U> print_op(tuple<U...>) {
    return print_tuple_utils<0, tuple<U...>>(out, u);
}
// ACTUAL SOLUTION START HERE
// ////////////////////////////////////////////////////////////////}}}

bool is_prime(ll num) {
    if (num == 1)
        return true; // this problem only
    for (ll i = 2; i * i <= num; ++i) {
        if (num % i == 0)
            return false;
    }
    return true;
}

map<ll, int> factorize(ll num) {
    vector<pair<ll, int>> ans;
    for (ll i = 2; i * i <= num; ++i) {
        if (num % i)
            continue;
        auto &[_, cnt] = ans.emplace_back(i, 0);
        while (num % i == 0) {
            num /= i;
            ++cnt;
        }
    }
    if (num > 1)
        ans.emplace_back(num, 1);
    return {all(ans)};
}

bool solve(ll n, ll d) {
    int cnt = 0;
    while (n % d == 0) {
        n /= d;
        ++cnt;
    }
    clog << db(n) << db(cnt) << endl;
    
    if (cnt <= 1) {
        return false;
    }

    // auto is_good = [&](ll x) {
        // clog << db(x) << db(x % d) << db(x % (d * d)) << endl;
        // return (x % d == 0) and (x % (d * d) != 0);
    // };

    auto fn = factorize(n);
    auto fd = factorize(d);
    clog << db(fn) << db(fd) << endl;
    
    if (n == 1) {
        if (cnt <= 2) {
            clog << __LINE__ << "no " << db(cnt) << endl;
            return false;
        }
        if (fd.size() > 1 or fd.begin()->second > 2) {
            clog << __LINE__ << "yes " << db(fd) << endl;
            return true;
        }
        
        if (fd.begin()->second == 1) {
            clog << __LINE__ << endl;
            return false;
        }
        
        if (cnt <= 2) {
            clog << __LINE__ << "no" << db(cnt) << endl;
            return false;
        }
        clog << __LINE__ << endl;
        return true;
    }
    
    if (fn.size() > 1 or fn.begin()->second > 1) {
        clog << __LINE__ << "yes " << db(fd) << endl;
        return true;
    }
    
    if (cnt <= 2) return false;
    if (fd.size() > 1 or fd.begin()->second > 2) {
        clog << __LINE__ << "yes " << db(fd)  << endl;
        return true;
    }
    if (fd.begin()->second == 1) {
        clog << __LINE__ << "NO" << endl;
        return false;
    }
    if (fd.begin()->first == fn.begin()->first) {
        if (cnt <= 3) {
            clog << __LINE__ << "NO" << endl;
            return false;
        }
        clog << __LINE__ << endl;
        return true;
    } else {
        clog << __LINE__ << "YES" <<endl;
        return true;
    }
}

bool brute(ll n, ll d) {
    DB();
    set<multiset<ll>> way;
    multiset<ll> cur;
    
    auto is_good = [&](ll x) { return x % d == 0 and x % (d * d) != 0; };
    function<void(ll)> backtrack = [&](ll num) {
        // DB();
        if (num == 1) {
            way.insert(cur);
            return ;
        }
        for (ll i = 2; i <= num; ++i) {
            if (num % i) continue;
            if (!is_good(i)) continue;
            // clog << db(num) << db(i) << endl;
            cur.insert(i);
            backtrack(num / i);
            if (way.size() > 1) return ;
            cur.erase(cur.find(i));
        }
    };
    backtrack(n);
    clog << way << endl;
    return way.size() > 1;
}

mt19937 rng;
int rand(int l, int r) {
    return l + (int)(rng() % (r - l + 1));
}

void check() {
    while (true) {
        ll d = rand(2, 10);
        int t = rand(1, 5);
        ll n = rand(1, 5);
        while (t--) n *= d;
        cout << db(n) << db(d) << endl;
        auto ans = solve(n, d);
        auto exp = brute(n, d);
        cout << db(ans) << db(exp) << endl;
        if (ans == exp) {
            cout << "OK" << endl;
            continue;
        }
        cout << "NAH" << endl;
        exit(0);
    }
}


int main() {
#ifdef LOCAL
    while (1) check();
    freopen("main.inp", "r", stdin);
    freopen("main.out", "w", stdout);
    freopen(".log", "w", stderr);
#endif
    cin.tie(0)->sync_with_stdio(0);

    int ntest;
    cin >> ntest;
    while (ntest--) {
        DB();
        ll n, d;
        cin >> n >> d;
        clog << db(n) << db(d) << endl;
        cout << (solve(n, d) ? "YES" : "NO") << '\n';
// #ifdef LOCAL
        // cout << db(brute(n, d)) << endl;
// #endif
    }

    return 0;
}