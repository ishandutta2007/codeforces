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

const int maxn = 35000 + 100;
const int maxk = 111;
const ll inf = 1e15;

struct IT {
    vector<ll> val, lz;
    size_t size() const {
        return sz(val) >> 2;
    }
    
    IT(int n): val(n << 2), lz(n << 2) {}
    IT(const vector<ll>& a): IT(sz(a)) {
        build(1, 0, sz(a), a);
    }
    
    void build(int i, int l, int r, const vector<ll>& a) {
        if (r - l <= 0) return ;
        if (r - l == 1) {
            val[i] = a[l];
            return ;
        }
        int mid = (l + r) / 2;
        build(2 * i, l, mid, a);
        build(2 * i + 1, mid, r, a);
        val[i] = min(val[2 * i], val[2 * i + 1]);
    }
    
    void push(int i, int l, int r) {
        val[i] += lz[i];
        if (r - l > 1) {
            lz[2 * i] += lz[i];
            lz[2 * i + 1] += lz[i];
        }
        lz[i] = 0;
    }
    
    void upd(int from, int to, ll del, int i, int l, int r) {
        push(i, l, r);
        if (from >= r or l >= to) return; 
        if (from <= l and r <= to) {
            lz[i] += del;
            push(i, l, r);
            return ;
        }
        int mid = (l + r) / 2;
        upd(from, to, del, 2 * i, l, mid);
        upd(from, to, del, 2 * i + 1, mid, r);
        val[i] = min(val[2 * i], val[2 * i + 1]);
    }
    
    ll get(int from, int to, int i, int l, int r) {
        push(i, l, r);
        if (from >= r or l >= to) return inf;
        if (from <= l and r <= to) return val[i];
        int mid = (l + r)  / 2;
        return min(get(from, to, 2 * i, l, mid), get(from, to, 2 * i +1, mid, r));
    }
    
    void upd(int from, int to, ll del) {
        clog << "upd" << db(from) << db(to) << db(del) << endl;
        upd(from, to, del, 1, 0, (int)size());
    }
    
    ll get(int from, int to) {
        return get(from, to, 1, 0, (int)size());
    }
    
    void print(ostream& out, int i, int l, int r) {
        push(i, l, r);
        if (r - l <= 0) return ;
        if (r - l == 1) {
            out << val[i] << ' ';
            return ;
        }
        int mid = ( l + r) / 2;
        print(out, 2 * i, l, mid);
        print(out, 2 * i + 1, mid, r);
    }
    
    void print(ostream& out) {
        print(out, 1, 0, (int)size());
    }
    
    void log() {
#ifdef DEBUG_LOCAL
            clog << "";
            print(cerr);
            clog << endl;
#endif
    }
};


int n, k;
int a[maxn];
int prev_pos[maxn], pos[maxn];

int main() {
#ifdef LOCAL
    freopen("main.inp", "r", stdin); 
    freopen("main.out", "w", stdout);  
    freopen(".log", "w", stderr);
#endif
    
    cin >> n >> k;
    memset(pos, 0, sizeof(pos));
    rep(i, 1, n + 1) {
        cin >> a[i];
        prev_pos[i] = pos[a[i]];
        pos[a[i]] = i;
        clog << db(i) << db(prev_pos[i]) << endl;
    }
    
    
    vector<ll> dp(n + 1, inf);
    dp[0] = 0;
    
    rep(step, 0, k) {
        DB();
        clog << db(step) << endl;
        IT it(dp);
        
        dp[0] = inf;
        
        it.log();
        
        rep(i, 1, n + 1) {
            if (prev_pos[i] != 0) {
                it.upd(0, prev_pos[i], i - prev_pos[i]);
            }
            it.log();
            
            dp[i] = it.get(0, i);
        }
        clog << db(dp) << endl;
    }
    
    cout << dp[n] << '\n';
    
    return 0;
}

// vim: foldmethod=marker