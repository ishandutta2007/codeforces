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


vector<int> kmp(const string& s) {
    vector<int> ans(sz(s));
    rep(i, 1, sz(s)) {
        ans[i] = ans[i - 1];
        while (ans[i] and s[ans[i]] != s[i]) {
            ans[i] = ans[ans[i] - 1];
        }
        ans[i] += s[ans[i]] == s[i];
    }
    clog << db(s) << db(ans) << endl;
    return ans;
}

pair<vector<int>, vector<int>> match_count(const string& s, string patt, int lim) {
    if (sz(patt) > lim) patt.resize(lim);
    auto ans = kmp(patt + ' ' + s);
    vector<int> patt_kmp(ans.begin(), ans.begin() + sz(patt));
    ans.erase(ans.begin(), ans.begin() + sz(patt) + 1);
    return {patt_kmp, ans};
}

pair<vector<int>, vector<int>> reverse_match_count(string s, string t, int lim) {
    reverse(all(s));
    reverse(all(t));
    if (sz(t) > lim) t.resize(lim);
    auto [p, a] = match_count(s, t, lim);
    reverse(all(a));
    return {p, a};
}

int main() {
#ifdef LOCAL
    freopen("main.inp", "r", stdin); 
    freopen("main.out", "w", stdout);  
    freopen(".log", "w", stderr);
#endif
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    int n, m, k;
    string s, t;
    cin >> n >> m >> k; 
    cin >> s >> t; 
    // n = 500000;  
    // m = 300000;  
    // k = 200000;  
    // s = string(n, 'a');  
    // t = string(m, 'a');  
    auto [tkmp, mc] = match_count(s, t, k);
    if (m <= k) { 
        rep(i, 0, n) { 
            if (mc[i] != m) continue; 
            int min_left = max(0, i - k + 1); 
            int max_left = min(n - k, i - m + 1); 
            if (max_left >= k) { 
                cout << "Yes\n"; 
                cout << "1 " << 1 + max_left << '\n'; 
                return 0; 
            } 
            if (min_left + 2 * k <= n) { 
                cout << "Yes\n"; 
                cout << min_left + 1 << ' ' << min_left + k + 1 << '\n'; 
                return 0; 
            } 
        } 
    } 
    auto [rtkmp, rmc] = reverse_match_count(s, t, k);
    
    clog << db(mc) << endl;
    clog << db(rmc) << endl;
    
    vector<int> min_mc(m + 1, n + 1);
    vector<int> max_rmc(m + 1, -1);
    
    rep(i, k - 1, n) {
        for (int u = mc[i]; min_mc[u] == n + 1; u = tkmp[u - 1]) {
            min_mc[u] = i; 
            if (u == 0) break;
        }
    }
    
    for (int i = n - k + 1; i--; ) {
        for (int u = rmc[i]; max_rmc[u] == -1; u = rtkmp[u - 1]) {
            max_rmc[u] = i;
            if (u == 0) break;
        }
    }
    
    clog << db(min_mc) << endl;
    clog << db(max_rmc) << endl;
    
    rep(left, 0, m + 1) {
        int right = m - left;
        if (min_mc[left] >= max_rmc[right]) continue;
        cout << "Yes\n";
        cout << min_mc[left] - k + 2 << ' ' << max_rmc[right] + 1 << '\n';
        return 0;
    }
    cout << "No";
    
    
    return 0;
}

// vim: foldmethod=marker