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

int l2(int num) {
    return 31 - __builtin_clz(num);
}

template<int alpha = 256>
struct SuffixArray {
    vector<vector<int>> rank;
    vector<int> sa;
    
    void resort(const vector<int>& r) {
        static vector<int> cnt;
        cnt.assign(max(sz(r), alpha), 0);
        rep(i, 0, sz(r)) cnt[r[i]]++;
        rep(i, 1, sz(cnt)) cnt[i] += cnt[i - 1];
        static vector<int> nsa;
        nsa.resize(sz(sa));
        for (int i = sz(sa); i--; ) 
            nsa[--cnt[r[sa[i]]]] = sa[i];
        swap(nsa, sa);
    }
    
    SuffixArray(const string& s): rank(l2(sz(s)) + 1, vector<int>(sz(s) + 1)), sa(sz(s) + 1) {
        rep(i, 0, sz(s) + 1) sa[i] = i;
        rep(i, 0, sz(s) + 1) rank[0][i] = s[i];
        resort(rank[0]);
        rep(lv, 1, sz(rank)) {
            auto& pr = rank[lv - 1], &cr = rank[lv];
            int half = 1 << (lv - 1);
            rotate(pr.begin(), pr.begin() + half, pr.end());
            resort(pr);
            rotate(pr.rbegin(), pr.rbegin() + half, pr.rend());
            resort(pr);
            rep(i, 1, sz(sa)) {
                int u = sa[i], v = sa[i - 1];
                cr[u] = cr[v];
                if (pr[u] != pr[v] or pr[(u + half) % sz(sa)] != pr[(v + half) % sz(sa)]) {
                    ++cr[u];
                }
            }
        }
        rep(i, 0, sz(sa)) {
            clog << db(i) << '\t' << sa[i] << '\t' << quoted(s.substr(sa[i])) << endl;
        }
    }
    
    int lcp(int u, int v) const {
        int ans = 0;
        for (int i = sz(rank); i--; ) {
            if (rank[i][u] == rank[i][v]) {
                ans += (1 << i);
                u += 1 << i;
                v += 1 << i;
                while (u >= sz(sa)) u -= sz(sa);
                while (v >= sz(sa)) v -= sz(sa);
            }
        }
        return ans;
    }
    
    pair<int, int> get_rank(int u, int len) const {
        int lv = l2(len);
        return {rank[lv][u], rank[lv][u + len - (1 << lv)]};
    }
};

int main() {
#ifdef LOCAL
    freopen("main.inp", "r", stdin); 
    freopen("main.out", "w", stdout);  
    freopen(".log", "w", stderr);
#endif
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    int n;
    string s;
    cin >> n >> s;
    SuffixArray sa(s);
    
    vector<vector<int>> add_evts(sz(s));
    rep(i, 0, sz(s) / 2) {
        int f = sz(s) - i - 1;
        int max_ml = i + 1;
        int l = 0, r = max_ml;
        while (l < r) {
            int mid = (l + r + 1) / 2;
            if (sa.get_rank(i - mid + 1, 2 * mid - 1) == sa.get_rank(f - mid + 1, 2 * mid - 1)) {
                l = mid;
            } else {
                r = mid - 1;
            }
        }
        clog << db(i) << db(l) << endl;
        
        if (l != 0) {
            add_evts[i - l + 1].push_back(i);
        }
    }
    
    vector<int> ans((n + 1) / 2, -1);
    set<int> se;
    rep(i, 0, sz(ans)) {
        se.insert(all(add_evts[i]));
        if (sz(se)) {
            int cur_len = *se.rbegin() - i;
            clog << db(se) << db(cur_len) << endl;
            ans[i] = cur_len * 2 + 1;
        }
        se.erase(i);
    }
    
    // reverse(all(ans)); 
    for (auto i: ans) cout << i << ' ' ;

    return 0;
}

// vim: foldmethod=marker