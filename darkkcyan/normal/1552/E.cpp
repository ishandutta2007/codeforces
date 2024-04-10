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

const int maxn = 101;
const int maxk = 101;
const int maxnk = maxn * maxk;
int n, k;
int a[maxnk];

struct Segtree {
    vector<int> mx, lz;
    Segtree(int len): mx(len * 4), lz(len * 4) {}
    
    void push(int i, int l, int r) {
        mx[i] += lz[i];
        if (r - l > 1) {
            lz[2 * i] += lz[i];
            lz[2 * i + 1] += lz[i];
        }
        lz[i] = 0;
    }
    void upd(int from, int to, int delta, int i, int l, int r) {
        push(i, l, r);
        if (from >= r or l >= to) return ;
        if (from <= l and r <= to) {
            lz[i] += delta;
            push(i, l, r);
            return ;
        }
        int mid = (l + r) / 2;
        upd(from, to, delta, 2 * i, l, mid);
        upd(from, to, delta, 2 * i + 1, mid, r);
        mx[i] = max(mx[2 * i], mx[2 * i + 1]);
    }
    
    int get(int from, int to, int i, int l, int r) {
        push(i, l, r);
        if (from >= r or l >= to) return 0;
        if (from <= l and r <= to) return mx[i];
        int mid = (l + r) / 2;
        return max(get(from, to, 2 * i, l, mid), get(from, to, 2 * i + 1, mid, r));
    }
    
    int size() const {
        return sz(mx) >> 2;
    }
    
    void upd(int from, int to, int delta) {
        upd(from, to, delta, 1, 0, size());
    }
    int get(int from, int to) {
        return get(from, to, 1, 0, size());
    }
};

vector<pair<int, int>> solve() {
    vector<pair<int, int>>  segs;
    vector<int> prev(n, -1);
    rep(i, 0, n * k) {
        if (prev[a[i]] != -1) {
            segs.emplace_back(prev[a[i]], i);
        }
        prev[a[i]] = i;
    }
    
    sort(all(segs), [&](const auto& u, const auto& v) {
            if (u.second == v.second) return u.first > v.first;
            return u.second < v.second;
            });
    
    vector<bool> picked(n);
    vector<pair<int, int>> ans;
    
    Segtree it(n * k);
    int coef = (n + k - 2) / (k - 1);
    for (auto [l, r]: segs) {
        if (picked[a[l]]) continue;
        if (it.get(l, r + 1) == coef) continue;
        picked[a[l]] = true;
        ans.emplace_back(l, r);
        it.upd(l, r + 1, 1);
    }
    assert(sz(ans) == n);
    sort(all(ans), [&](const auto& u, const auto& v) {
            return a[u.first] < a[v.first];
            });
    return ans;
}

mt19937 rng;
#define rand() ((int)(rng() >> 1))
void check() {
    while (true) {
        n = rand() % 3 + 1;
        k = rand() % 3 + 2;
        rep(i, 0, n) rep(f, 0, k) a[i * k + f] = i;
        shuffle(a, a + n * k, rng);
        ofstream inp("main.inp");
        inp << n << ' ' << k << endl;
        rep(i, 0, n * k) inp << a[i] << ' ';
        inp.close();
        auto ans = solve();
        cout << "OK" << endl;
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
    
    cin >> n >> k;
    rep(i, 0, n * k) {
        cin >> a[i];
        --a[i];
    }
    
    auto ans = solve();
    for (auto [l, r]: ans) {
        cout << l + 1 << ' ' << r  + 1<< '\n';
    }
    
    return 0;
}

// vim: foldmethod=marker