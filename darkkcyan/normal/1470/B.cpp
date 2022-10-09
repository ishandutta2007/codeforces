#include <bits/stdc++.h>
using namespace std;

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

const int max_val = 1010100;
int pfac[max_val];
void sieve() {
    for (int i = 2; i < max_val; ++i) {
        if (pfac[i]) continue;
        for (int f = i; f < max_val; f += i)
            pfac[f] = i;
    }
}

vector<int> factorize_char(int num) {
    vector<int> ans;
    
    while (num > 1) {
        int p = pfac[num];
        clog << db(num) << db(p) << endl;
        int cnt = 0;
        while (num % p == 0) {
            num /= p;
            cnt ^= 1;
        }
        
        if (cnt) ans.push_back(p);
    }
    
    sort(ans.begin(), ans.end());
    return ans;
}

int main(void) {
    sieve();
#ifdef LOCAL
    freopen("main.inp", "r", stdin);
    freopen("main.out", "w", stdout);
    freopen(".log", "w", stderr);
#endif
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int ntest; cin >> ntest;
    while (ntest--) {
        int n;
        cin >> n;
        vector<int> a(n);
        rep(i, n) cin >> a[i];
        
        vector<int> dsu(n, -1);
        function<int(int)> find_set = [&](int u) {
            return dsu[u] < 0 ? u : dsu[u] = find_set(dsu[u]);
        };
        
        int cur_ans = 1;
        auto join = [&](int u, int v) {
            u = find_set(u);
            v = find_set(v);
            if (u == v) return ;
            if (-dsu[u] < -dsu[v]) swap(u, v);
            dsu[u] += dsu[v];
            dsu[v] = u;
            cur_ans = max(cur_ans, -dsu[u]);
        };
        
        map<vector<int>, int> char_id;
        vector<int> considering;
        rep(i, n) {
            auto fc = factorize_char(a[i]);
            if (char_id.count(fc)) {
                join(char_id[fc], i);
            } else {
                char_id[fc] = i;
            }
        }
        
        int ans_0 = cur_ans;
        const vector<int> empty_vec = {};
        rep(i, n) {
            if (dsu[i] >= 0) continue;
            if ((-dsu[i]) & 1) continue;
            
            if (char_id.count(empty_vec)) {
                join(char_id[empty_vec], i);
            } else {
                char_id[empty_vec] = i;
            }
        }
        int ans_1 = cur_ans;
        
        int q; cin >> q;
        while (q--){
            llong num; cin >> num;
            if (num == 0) cout << ans_0 << '\n';
            else cout << ans_1 << '\n';
        }
    }
    
    return 0;
}

// vim: foldmethod=marker