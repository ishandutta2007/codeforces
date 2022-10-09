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
#define print_op(type) ostream& operator<<(ostream& out, const type& u)
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


vector<int> kmp(string str) {
    int n = (int)str.length();
    vector<int> pi(n);
    for (int i = 1; i < n; i++) {
        int j = pi[i-1];
        while (j > 0 && str[i] != str[j])
            j = pi[j-1];
        if (str[i] == str[j])
            j++;
        pi[i] = j;
    }
    return pi;
}

string s;
string solve() {
    array<int, 26> occ;
    occ.fill(0);
    int n = sz(s);
    rep(i, 0, n) occ[s[i] - 'a']++;
    
    int single = 0;
    while (single < 26 and occ[single] != 1) ++single;
    if (single < 26) {
        string ans(1, char(single + 'a'));
        --occ[single];
        rep(i, 0, 26) {
            ans += string(occ[i], char(i + 'a'));
        }
        return ans;
    }
    
    int smallest = 0;
    while (!occ[smallest]) ++smallest;
    
    clog << db(occ) << endl;
    clog << db(smallest) << endl;
    if (occ[smallest] == n) {
        return s;
    }
    
    string ans(1, char(smallest + 'a'));
    if (occ[smallest] - 1 <= (n - occ[smallest] + 1)) {
        --occ[smallest];
        int cur = smallest + 1;
        while (occ[smallest]--) {
            ans += char(smallest + 'a');
            while (cur < 26 and !occ[cur]) ++ cur;
            if (cur == 26) break;
            ans += char(cur + 'a');
            --occ[cur];
        }
        while (cur < 26) {
            while (cur < 26 and !occ[cur]) ++cur;
            if (cur == 26) break;
            ans += char(cur + 'a');
            --occ[cur];
        }
        return ans;
    }
    int sec_smallest = smallest + 1;
    while (sec_smallest < 26 and !occ[sec_smallest]) ++ sec_smallest;
    assert(sec_smallest != 26);
    if (occ[smallest] + occ[sec_smallest] == n) {
        ans += string(occ[sec_smallest], char(sec_smallest + 'a'));
        ans += string(occ[smallest] - 1, char(smallest + 'a'));
        return ans;
    }
    
    ans += char(sec_smallest + 'a');
    ans += string(occ[smallest] - 1, char(smallest + 'a'));
    int third_smallest = sec_smallest + 1;
    while (third_smallest < 26 and !occ[third_smallest]) ++ third_smallest;
    assert(third_smallest < 26);
    ans += char(third_smallest + 'a');
    --occ[sec_smallest];
    --occ[third_smallest];
    rep(i, sec_smallest, 26) {
        if (occ[i]) ans += string(occ[i], char(i + 'a'));
    }
    return ans;
}

string brute() {
    vector<int> pos;
    int n = sz(s);
    rep(i, 0, n) pos.push_back(i);
    
    pair<int, string> ans = {INT_MAX, ""};
    clog << db(s) << endl;
    
    do {
        string cur = "";
        rep(i, 0, n) cur += s[pos[i]];
        auto cur_kmp = kmp(cur);
        auto k = *max_element(all(cur_kmp));
        ans = min(ans, {k, cur});
    } while (next_permutation(all(pos)));
    return ans.second;
}

mt19937 rng;
#define rand() ((int)(rng() >> 1))
void check() {
    while (true) {
        int n = 6;
        s = "";
        rep(i, 0, n) s += char(rand() % 26 + 'a') ;
        auto ans = solve();
        auto exp = brute();
        ofstream("main.inp") << 1 << endl << s << endl << db(ans) << endl << db(exp) << endl;
        if (ans == exp) {
            cout << "OK" << endl;
            continue;
        } 
        cout << "FAILED" << endl;
        exit(0);
    }
}

int main() {
    // check();  
#ifdef LOCAL
    freopen("main.inp", "r", stdin); 
    freopen("main.out", "w", stdout);  
    freopen(".log", "w", stderr);
#endif
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int ntest; cin >> ntest;
    while (ntest--) {
        DB();
        cin >> s;
        clog << db(s) << endl;
        auto ans = solve();
        cout << ans << '\n';
// #ifdef LOCAL 
        // cout << brute() << endl; 
// #endif 
    }
    
    return 0;
}

// vim: foldmethod=marker
// resubmit for testing