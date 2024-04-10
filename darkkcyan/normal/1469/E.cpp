#include <bits/stdc++.h>
using namespace std;

vector<int> construct_suffarr(string s) {
    for (auto& ch: s) ch -= '0' - 1;
    int n = (int)s.size();
    const int alphabet = 3;
    vector<int> p(n), c(n), cnt(max(alphabet, n), 0);
    for (int i = 0; i < n; i++)
        cnt[s[i]]++;
    for (int i = 1; i < alphabet; i++)
        cnt[i] += cnt[i-1];
    for (int i = 0; i < n; i++)
        p[--cnt[s[i]]] = i;
    c[p[0]] = 0;
    int classes = 1;
    for (int i = 1; i < n; i++) {
        if (s[p[i]] != s[p[i-1]])
            classes++;
        c[p[i]] = classes - 1;
    }
    vector<int> pn(n), cn(n);
    for (int h = 0; (1 << h) < n; ++h) {
        for (int i = 0; i < n; i++) {
            pn[i] = p[i] - (1 << h);
            if (pn[i] < 0)
                pn[i] += n;
        }
        fill(cnt.begin(), cnt.begin() + classes, 0);
        for (int i = 0; i < n; i++)
            cnt[c[pn[i]]]++;
        for (int i = 1; i < classes; i++)
            cnt[i] += cnt[i-1];
        for (int i = n-1; i >= 0; i--)
            p[--cnt[c[pn[i]]]] = pn[i];
        cn[p[0]] = 0;
        classes = 1;
        for (int i = 1; i < n; i++) {
            pair<int, int> cur = {c[p[i]], c[(p[i] + (1 << h)) % n]};
            pair<int, int> prev = {c[p[i-1]], c[(p[i-1] + (1 << h)) % n]};
            if (cur != prev)
                ++classes;
            cn[p[i]] = classes - 1;
        }
        c.swap(cn);
    }
    return p;
}

vector<int> construct_lcp(string const& s, vector<int> const& p) {
    int n = (int)s.size();
    vector<int> rank(n, 0);
    for (int i = 0; i < n; i++)
        rank[p[i]] = i;

    int k = 0;
    vector<int> lcp(n-1, 0);
    for (int i = 0; i < n; i++) {
        if (rank[i] == n - 1) {
            k = 0;
            continue;
        }
        int j = p[rank[i] + 1];
        while (i + k < n && j + k < n && s[i+k] == s[j+k])
            k++;
        lcp[rank[i]] = k;
        if (k)
            k--;
    }
    return lcp;
}

#define llong long long 
#define len(x) ((int)x.size())
#define rep(i,n) for (int i = -1; ++ i < n; )
#define rep1(i,n) for (int i = 0; i ++ < n; )
#ifdef testing/*{{{*/
mt19937 rng(177013);
#else
mt19937 rng(chrono::system_clock::now().time_since_epoch().count());
#endif
#define rand() (int)(rng() >> 1)
#define CONCAT_(x, y) x##y
#define CONCAT(x, y) CONCAT_(x, y)
#define SPEC(name) CONCAT(name, __LINE__)
#ifdef LOCAL_DEBUG   
int __db_level = 0;
#define clog cerr << string(__db_level * 2, ' ')
struct debug_block {
    string msg;
    debug_block(const string& s): msg(s) { clog << "{ " << msg << endl; ++__db_level; }
    ~debug_block() { --__db_level; clog << "} " << msg << endl; }
};
#define DB(args...) stringstream SPEC(ss); SPEC(ss)<< args; debug_block SPEC(dbbl)(SPEC(ss).str())
#else
#define clog if (0) cerr
#define DB(...)
#endif
#define db(val) "[" #val " = " << val << "]; "
template<class U, class V> ostream& operator<<(ostream& out, const pair<U, V>& p) {
    return out << "(" << p.first << ", " << p.second << ")";
}
template<size_t i, class T> ostream& print_tuple_utils(ostream& out, const T& tup) {
    if constexpr(i == tuple_size<T>::value) return out << ")";
    else return print_tuple_utils<i + 1, T>(out << (i ? ", " : "(") << get<i>(tup), tup);
}
template<class ...U>
ostream& operator<<(ostream& out, const tuple<U...>& tup) { return print_tuple_utils<0, tuple<U...>>(out, tup); }
template<class, typename = void> struct has_const_iterator : false_type {};
template<class T> struct has_const_iterator<T, void_t<typename T::const_iterator>> : true_type {};
template<class T>
typename enable_if<has_const_iterator<T>::value && !is_same<T, string>::value, ostream&>::type
operator<<(ostream& out, const T& container) { 
    auto beg = container.begin(), end = container.end();
    out << "(" << container.size() << ") {";
    if (beg != end) out << *(beg++);
    while (beg != end) out << ", " << *(beg++);
    return out << "}";
}
#define ptrtype(x) typename iterator_traits<x>::value_type
template<class u> vector<ptrtype(u)> $v(u a, u b) { return vector<ptrtype(u)>(a, b); }/*}}}*/
// ACTUAL SOLUTION START HERE ////////////////////////////////////////////////////////////////

int l2(int num) {
    return 31 - __builtin_clz(num);
}
struct SpareTable {
    vector<vector<int>> val;
    SpareTable(const vector<int>& v): val(1, v) {
        val.resize(l2(len(v)) + 1, vector<int>(v.size()));
        for (int lv = 0; lv < len(val) - 1; ++lv) {
            for (int i = 0; i + (2 << lv) <= len(v); ++i) {
                val[lv + 1][i] = min(val[lv][i], val[lv][i + (1 << lv)]);
            }
        }
    }
    
    int get_min(int l, int r) {
        if (l >= r) return INT_MAX;
        int lv = l2(r - l);
        return min(val[lv][l], val[lv][r - (1 << lv)]);
    }
};

int main(void) {
#ifdef LOCAL
    freopen("main.inp", "r", stdin);
    freopen("main.out", "w", stdout);
    freopen(".log", "w", stderr);
#endif
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int ntest; cin >> ntest;
    while (ntest--) {
        DB("test");
        int n, k; cin >> n >> k;
        string s; cin >> s;
        clog << db(n) << db(k) << endl;
        clog << db(s) <<endl;
        s += '0' - 1;
        auto sa = construct_suffarr(s);
        auto lcp = construct_lcp(s, sa);
        auto slcp = SpareTable(lcp);
        clog << db(sa) << endl;
        vector<int> pos;
        rep(i, len(sa)) {
            if (sa[i] + k >= n + 1) continue;
            pos.push_back(i);
        }
        clog << db(pos) << endl;
        auto is_same_pref = [&](int u, int v) {
            if (u > v) swap(u, v);
            return slcp.get_min(u, v) >= k;
        };
        pos.erase(unique(pos.begin(), pos.end(), is_same_pref), pos.end());
        clog << db(pos) << endl;
        
        string ans = "";
        bool ok = true;
        int low = 0, high = len(pos);
        auto can_pick = [&](int l, int r, int had) {
            int lv = k - had;
            clog << db(l) << db(r) << db(had) << db(lv) << endl;
            if (lv > 30) return true;
            return r - l < (1 << lv);
        };
        
        while (len(ans) < k) {
            DB(db(low) << db(high));
            int l = low, r = high;
            while (l < r) {
                int mid = (l + r) / 2;
                if (s[sa[pos[mid]] + len(ans)] == '1') r = mid;
                else l = mid + 1;
            }
            clog << db(l) << endl;
            if (can_pick(l, high, len(ans) + 1)) {
                clog << "go 1" << endl;
                ans += '0';
                low = l;
                continue;
            }
            
            if (!can_pick(low, l, len(ans) + 1)) {
                ok = false;
                break;
            }
            clog << "go 0" << endl;
            ans += '1';
            high = l;
        }
        if (!ok) cout << "NO\n";
        else cout << "YES\n" << ans << '\n';
    }
    
    return 0;
}

// vim: foldmethod=marker