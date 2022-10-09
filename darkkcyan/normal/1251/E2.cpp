#include <bits/stdc++.h>
using namespace std;

#define jalsol_orz main

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

struct Voter {
    ll p;
    int m;
    struct CmpByP {
        bool operator()(const Voter &u, const Voter &v) const {
            if (u.p == v.p)
                return u.m > v.m;
            return u.p < v.p;
        }
    };

    struct CmpByM {
        bool operator()(const Voter &u, const Voter &v) const {
            if (u.m == v.m)
                return u.p > v.p;
            return u.m < v.m;
        }
    };

    friend print_op(Voter) {
        return out << "{p: " << u.p << ", m: " << u.m << "}";
    }
};

bool operator==(const Voter &u, const Voter &v) {
    return u.p == v.p and u.m == v.m;
}

struct VoterBIT {
    vector<multiset<Voter, Voter::CmpByP>> data;
    VoterBIT(int len) : data(len + 10) {}

    Voter get(int i) {
        DB();
        clog << "get" << endl;
        Voter ans = {-1, 0};
        for (++i; i > 0; i -= i & -i) {
            if (data[i].size()) {
                clog << db(i) << db(data[i]) << endl;
                ans = max(ans, *--data[i].end(), Voter::CmpByP());
            }
        }
        return ans;
    }

    void erase(int i, Voter v) {
        for (++i; i < sz(data); i += i & -i)
            data[i].erase(data[i].find(v));
    }
    void insert(int i, Voter v) {
        for (++i; i < sz(data); i += i & -i)
            data[i].insert(v);
    }
};

ll solve(vector<Voter> a) {
    int n = sz(a);
    multiset<Voter, Voter::CmpByP> remain_by_p(a.begin(), a.end());
    multiset<Voter, Voter::CmpByM> remain_by_m(a.begin(), a.end());
    VoterBIT bought(n);

    int cnt_voted = 0;
    ll sum = 0;
    auto add_free_voter = [&]() {
        while (remain_by_m.size() and remain_by_m.begin()->m <= cnt_voted) {
            auto t = *remain_by_m.begin();
            remain_by_m.erase(remain_by_m.begin());
            remain_by_p.erase(remain_by_p.find(t));
            ++cnt_voted;
        }
    };
    add_free_voter();
    clog << db(remain_by_p) << endl;
    clog << db(remain_by_m) << endl;
    clog << db(cnt_voted) << endl;
    while (cnt_voted < n) {
        DB();
        auto t = *remain_by_p.begin();
        clog << db(t) << endl;
        remain_by_p.erase(remain_by_p.begin());
        remain_by_m.erase(remain_by_m.find(t));

        auto opt = bought.get(cnt_voted);
        if (opt.p != -1) {
            clog << "remove " << opt << endl;
            sum -= opt.p;
            bought.erase(opt.m, opt);
        }
        bought.insert(t.m, t);
        ++cnt_voted;
        sum += t.p;
        clog << db(cnt_voted) << endl;
        clog << db(sum) << endl;

        add_free_voter();
        clog << db(remain_by_p) << db(remain_by_m) << endl;
        clog << db(cnt_voted) << endl;
    }
    return sum;
}

ll brute(const vector<Voter>& a) {
    ll ans = LLONG_MAX;
    rep(mask, 0, (1 << sz(a))) {
        vector<int> remain;
        ll cur_ans = 0;
        rep(i, 0, sz(a)) {
            if ((mask >> i) & 1) {
                cur_ans += a[i].p;
            } else {
                remain.push_back(a[i].m);
            }
        }
        sort(remain.begin(), remain.end());
        int cnt_voted = __builtin_popcount(mask);
        for (auto m: remain) {
            if (m > cnt_voted) {
                break;
            }
            ++cnt_voted;
        }
        if (cnt_voted == sz(a)) ans = min(ans, cur_ans);
    }
    return ans;
}

mt19937 rng;
int rand(int l, int r) {
    return l + (int)(rng() % (r - l + 1));
}

void check() {
    ofstream inp("main.inp");
    int n = rand(1, 5);
    inp << "1\n" << n << endl;;
    vector<Voter> a(n);
    for (auto& [p, m]: a) {
        p = rand(1, 20);
        m = rand(0, n - 1);
        inp << m << ' ' << p << endl;
    }
    auto ans = solve(a);
    auto exp = brute(a);
    inp << db(ans) << db(exp) << endl;
    inp.close();
    if (ans == exp) {
        cout << "OK" << endl;
    } else {
        cout << "NAH" << endl;
        exit(0);
    }
}

int jalsol_orz() {
#ifdef LOCAL
    // while (1) check();
    freopen("main.inp", "r", stdin);
    freopen("main.out", "w", stdout);
    freopen(".log", "w", stderr);
#endif
    cin.tie(0)->sync_with_stdio(0);

    int ntest;
    cin >> ntest;
    while (ntest--) {
        int n;
        DB();
        cin >> n;
        vector<Voter> a(n);
        for (auto &[p, m] : a)
            cin >> m >> p;
        cout << solve(a) << '\n';
#ifdef LOCAL
        cout << brute(a) << '\n';
#endif
    }

    return 0;
}