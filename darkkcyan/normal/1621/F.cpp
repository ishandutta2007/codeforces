#include <bits/stdc++.h>
using namespace std;

// #define constexpr(...) (__VA_ARGS__)  
using ll = long long;
using ld = long double;
const ld eps = 1e-8;
// for matching the kactl notes
#define sz(x) ((int)x.size())
#define rep(i,a,b) for (int i = (a); i < (b); ++i) 
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

int n;
ll a, b, c;
string s;

template<class T>
struct Saver {
    T& org;
    T data;
    Saver(T& x): org(x), data(x) {}
    ~Saver() { org = data; }
};

ll solve() {
    vector<pair<int, int>> parts;
    for (char ch: s) {
        if (parts.empty() or parts.back().first != ch - '0') {
            parts.emplace_back(ch - '0', 0);
        }
        ++parts.back().second;
    }
    clog << db(parts) << endl;
    
    array<int, 2> cnt_ch = {0, 0};
    array<int, 2> cnt_part = {0, 0};
    array<vector<int>, 3> ps_sorted_parts;
    for (auto& [ch, cc]: parts) {
        cnt_part[ch] ++;
        cnt_ch[ch] += cc;
        ps_sorted_parts[ch].push_back(cc);
    }
    clog << db(cnt_ch) << endl;
    clog << db(cnt_part) << endl;
    rep(i, 0, 3) {
        clog << db(i) << db(ps_sorted_parts[i]) << endl;
    }
    if (cnt_ch[0] == n) {
        if (n >= 2) {
            return a;
        }
        return 0;
    }
    
    ps_sorted_parts[2] = ps_sorted_parts[0];
    if (parts[0].first == 0) ps_sorted_parts[2].erase(ps_sorted_parts[2].begin());
    if (parts.back().first == 0) ps_sorted_parts[2].pop_back();
    
    rep(i, 0, 3) {
        sort(all(ps_sorted_parts[i]));
    }
    if (parts[0].first == 0) ps_sorted_parts[2].push_back(parts[0].second);
    if (parts.back().first == 0) ps_sorted_parts[2].push_back(parts.back().second);
    clog << db(ps_sorted_parts) << endl;
    
    ll ans = 0;
    rep(start, 0, 2) {
        DB();
        clog << db(start) << endl;
        int del_a_pos = 0, del_b_pos = 0, del_c_pos = 0, del_b2_pos = 0;
        
        Saver _(ps_sorted_parts);
        Saver _2(cnt_ch);
        
        int single_delta = 0;
        
        ll cur_ans = 0;
        rep(i, 0, n) {
            DB();
            int cur = start ^ (i & 1);
            clog << db(i) << db(cur) << db(cnt_ch) << endl;
            clog << db(ps_sorted_parts) << endl;
            --cnt_ch[cur];
            clog << db(cnt_ch) << endl;
            if (cnt_ch[0] < 0 or cnt_ch[1] < 1) break;
            clog << db(del_a_pos) << db(del_b_pos) << db(del_c_pos) << db(del_b2_pos) << endl;
            if (cur == 0) {
                while (del_a_pos < sz(ps_sorted_parts[2]) and ps_sorted_parts[2][del_a_pos] <= 1) ++del_a_pos;
                clog << db(del_a_pos) << endl;
                if (del_a_pos == sz(ps_sorted_parts[2])) {
                    while (del_c_pos < sz(ps_sorted_parts[2]) and ps_sorted_parts[2][del_c_pos] == 0) ++ del_c_pos;
                    clog << db(del_c_pos) << endl;
                    if (del_c_pos == sz(ps_sorted_parts[2]) or ps_sorted_parts[2][del_c_pos] != 1) {
                        break;
                    }
                    --ps_sorted_parts[2][del_c_pos];
                    cur_ans -= c;
                    ++single_delta;
                } else {
                    --ps_sorted_parts[2][del_a_pos];
                    cur_ans += a;
                }
            } else {
                while (del_b_pos < sz(ps_sorted_parts[1]) and ps_sorted_parts[1][del_b_pos] <= 1) ++del_b_pos;
                if (del_b_pos == sz(ps_sorted_parts[1])) {
                    while (del_b2_pos < del_b_pos and ps_sorted_parts[1][del_b2_pos] == 0) ++ del_b2_pos;
                    if (del_b2_pos == del_b_pos) {
                        break;
                    }
                    --single_delta;
                    if (single_delta < 0) {
                        while (del_c_pos < sz(ps_sorted_parts[2]) and del_c_pos < del_b2_pos and ps_sorted_parts[2][del_c_pos] == 0) ++ del_c_pos;
                        clog << db(del_c_pos) << endl;
                        if (del_c_pos < del_b2_pos) break;
                        if (del_c_pos >= del_a_pos) break;
                        if (del_c_pos == sz(ps_sorted_parts[2]) or ps_sorted_parts[2][del_c_pos] != 1) {
                            break;
                        }
                        if (ps_sorted_parts[2][del_c_pos]) {
                            --ps_sorted_parts[2][del_c_pos];
                            cur_ans -= c;
                        }
                        if (del_a_pos != sz(ps_sorted_parts[2])) {
                            ++ps_sorted_parts[2][del_a_pos];
                            cur_ans -= a;
                        }
                        ++single_delta;
                    }
                    --ps_sorted_parts[1][del_b2_pos];
                    cur_ans += b;
                } else {
                    --ps_sorted_parts[1][del_b_pos];
                    cur_ans += b;
                }
            }
            ans = max(ans, cur_ans);
            clog << db(cur_ans) << endl;
        }
        clog << "end " << db(cur_ans) << endl;
            clog << db(ps_sorted_parts) << endl;
        ans = max(ans, cur_ans);
    }
    return ans;
}

ll brute() {
    map<pair<string, int>, ll> dp;
    function<ll(const string&, int)> cal = [&](const string& t, int par) {
        auto it = dp.find({t, par});
        if (it != dp.end()) return it->second;
        ll& cur_ans = dp[{t, par}];
        cur_ans = 0;
        rep(i, 0, sz(t) - 1) {
            if (t[i] - '0' != par) continue;
            auto x = t;
            x.erase(x.begin() + i);
            if (par == 1) {
                if (t[i + 1] != '1') continue;
                cur_ans = max(cur_ans, cal(x, !par) + b);
            } else {
                cur_ans = max(cur_ans, cal(x, !par) - c);
                if (t[i + 1] == '0') {
                    cur_ans = max(cur_ans, cal(x, !par) + a);
                }
            }
        }
        if (t.back() == '0' and par == 0) {
            auto x = t;
            x.pop_back();
            cur_ans = max(cur_ans, cal(x, !par) - c);
        }
        return cur_ans;
    };
    auto ans = max(cal(s, 0), cal(s, 1));
    clog << db(dp) << endl;
    return ans;
}

mt19937 rng;
int rand(int l, int r) {
    return l + (int)(rng() % (r - l));
}
void stress() {
    n = rand(1, 7);
    s ="";
    rep(i, 0, n) s += char('0' + rand(0, 2));
    a = rand(1, 10);
    b = rand(1, 10);
    c = rand(1, 10);
    auto ans = solve();
    auto exp = brute();
    if (ans == exp) {
        cout << "OK" << endl;
        return;
    }
    ofstream inp("main.inp");
    inp << "1\n" << n << ' ' << a << ' ' << b << ' ' << c << '\n' << s << endl;
    inp << db(ans) << db(exp) << endl;
    exit(0);
}

int main() {
    // while (1) stress();
#ifdef LOCAL
    freopen("main.inp", "r", stdin); 
    freopen("main.out", "w", stdout);  
    freopen(".log", "w", stderr);
#endif
    cin.tie(0)->sync_with_stdio(0);
    
    int ntest;
    cin >> ntest;
    while (ntest--) {
        DB();
        cin >> n >> a >> b >> c >> s;
#ifdef LOCAL
        cout << brute() << endl;
#endif
        cout << solve() << '\n';
    }
    
    return 0;
}

// vim: foldmethod=marker