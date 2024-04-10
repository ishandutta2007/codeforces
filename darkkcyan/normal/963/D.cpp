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

vector<int> suffix_arr(const string& s) {
    int n = sz(s) + 1;
    vector<int> rank(n), sa(n);
    rep(i, 0, n) {
        rank[i] = s[i];
        sa[i] = i;
    }
    
    auto rank_count_sort = [&] {
        static vector<int> cnt;
        cnt.assign(max(256, n), 0);
        rep(i, 0, n) cnt[rank[i]] ++;
        rep(i, 1, sz(cnt)) cnt[i] += cnt[i - 1];
        static vector<int> nsa;
        nsa.resize(n);
        for (int i = n; i--; ) {
            nsa[--cnt[rank[sa[i]]]] = sa[i];
        }
        swap(sa, nsa);
    };
    rank_count_sort();
    for (int len = 2; ; len <<= 1) {
        // DB(); 
        // rep(i, 0, sz(sa)) { 
            // clog << db(i) << db(sa[i]) << db(rank[sa[i]]) << s.substr(sa[i]) << endl; 
        // } 
        rotate(rank.begin(), rank.begin() + len / 2, rank.end());
        rank_count_sort();
        rotate(rank.rbegin(), rank.rbegin() + len / 2, rank.rend());
        rank_count_sort();
        vector<int> new_rank(n);
        new_rank[sa[0]] = 0;
        rep(i, 1, n) new_rank[sa[i]] = new_rank[sa[i - 1]] +
            (rank[sa[i]] != rank[sa[i - 1]] or rank[(sa[i] + len / 2) % n] != rank[(sa[i - 1] + len / 2 % n)]);
        swap(rank, new_rank);
        if (len >= n) break;
    }
    return sa;
}

int cmp(const string& s, const string& patt, int start) {
    rep(i, 0, sz(patt)) {
        if (start >= sz(s)) return -1;
        if (patt[i] != s[start]) return s[start] - patt[i];
        ++start;
    }
    return 0;
}

int main() {
#ifdef LOCAL
    freopen("main.inp", "r", stdin); 
    freopen("main.out", "w", stdout);  
    freopen(".log", "w", stderr);
#endif
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    string s;
    cin >> s;
    auto sa = suffix_arr(s);
    // rep(i, 0, sz(sa)) { 
        // clog << db(i) << db(sa[i]) << s.substr(sa[i]) << endl; 
    // } 
    
    int q; cin >> q;
    
    auto solve_query = [&](int k, const string& m) {
        DB();
        clog << db(k) << db(m) << endl;
        int first, last;
        {
            int l = 0, r = sz(sa);
            while (l < r) {
                int mid = (l + r) / 2;
                if (cmp(s, m, sa[mid]) >= 0) {
                    r = mid;
                } else {
                    l = mid + 1;
                }
            }
            first = l;
        }
        {
            int l = 0, r = sz(sa);
            while (l < r) {
                int mid = (l + r) / 2;
                if (cmp(s, m, sa[mid]) > 0) {
                    r = mid;
                } else {
                    l = mid + 1;
                }
            }
            last = l;
        }
        clog << db(first) << db(last) << endl;
        if (last - first < k) return -1;
        vector<int> pos(sa.begin() + first, sa.begin() + last);
        sort(all(pos));
        int ans = INT_MAX;
        rep(i, 0, sz(pos) - k + 1) {
            ans = min(ans, pos[i + k - 1] - pos[i]);
        }
        return ans + sz(m);
    };
    while (q--) {
        int k;
        string m;
        cin >> k >> m;
        cout << solve_query(k, m) << '\n';
    }
    
    return 0;
}

// vim: foldmethod=marker