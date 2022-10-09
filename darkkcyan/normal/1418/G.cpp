// #define multitest 
#ifdef LOCAL
#define testing  
#define print_brute 
#endif

#include <bits/stdc++.h>
using namespace std;

#define llong long long 
#define len(x) ((int)x.size())
#define rep(i,n) for (int i = -1; ++ i < n; )
#define rep1(i,n) for (int i = 0; i ++ < n; )
#ifdef testing
mt19937 rng(177013);
#else
mt19937 rng(chrono::system_clock::now().time_since_epoch().count());
#endif
#define rand() (int)(rng() >> 1)
#define CONCAT_(x, y) x##y/*{{{*/
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

using ans_type = llong;

int n;
vector<int> a;
void read() {
    cin >> n;
    a.resize(n);
    rep(i, n) cin >> a[i];
}

void print_ans(ostream& cout, const ans_type& ans) {
    cout << ans << '\n';
}

struct segtree {
    vector<pair<int, int>> val;
    vector<int> lz;
    
    size_t size() const { return val.size() >> 2; }
    
    segtree(int n_): val(4 * n_), lz(4 * n_) {
        build(1, 0, (int)size() - 1);
    }
    
    void build(int i, int l, int r) {
        val[i] = {0, r - l + 1};
        if (l >= r) return ;
        int mid = (l + r) / 2;
        build(i << 1, l, mid);
        build(i << 1 | 1, mid + 1, r);
    }
    
    void propagate(int i, int l, int r) {
        val[i].first += lz[i];
        if (l < r) {
            lz[i << 1] += lz[i];
            lz[i << 1 | 1] += lz[i];
        }
        lz[i] = 0;
    }
    
    pair<int, int> comb(pair<int, int> u, const pair<int, int>& v) {
        if (u.first == v.first) u.second += v.second;
        else if (u.first < v.first) u = v;
        return u;
    }
    
    void upd(int from, int to, int delta, int i, int l, int r) {
        propagate(i, l, r);
        if (from > r or l > to) return ;
        if (from <= l and r <= to) {
            lz[i] += delta;
            propagate(i, l, r);
            return ;
        }
        int mid = (l + r) / 2;
        upd(from, to, delta, i << 1, l, mid);
        upd(from, to, delta, i << 1 | 1, mid + 1, r);
        val[i] = comb(val[i << 1], val[i << 1 | 1]);
    }
    
    pair<int, int> get(int from, int to, int i, int l, int r) {
        propagate(i, l, r);
        if (from > r or l > to) return {-1, 0};
        if (from <= l and r <= to) return val[i];
        int mid = (l + r) / 2;
        return comb(get(from, to, i << 1, l, mid), get(from, to, i << 1 | 1, mid + 1, r));
    }
    
    void upd(int from, int to, int delta) {
        upd(from, to, delta, 1, 0, (int)size() - 1);
    }
    
    pair<int, int> get(int from, int to) {
        return get(from, to, 1, 0, (int)size() - 1);
    }
};

ans_type solve() {
    vector<deque<int>> pos(n + 1);
    rep(i, n) pos[a[i]].push_back(i);
    rep1(i, n) pos[i].push_back(n);
    
    segtree st(n);
    auto upd = [&](int val, int delta) {
        st.upd(0, pos[val][0] - 1, delta);
        if (len(pos[val]) > 3) {
            st.upd(pos[val][2], pos[val][3] - 1, delta);
        }
    };
    rep1(i, n) {
        upd(i, 1);
    }
    
    llong ans = 0;
    
    rep(i, n) {
        auto temp = st.get(i, n);
        if (temp.first == n) ans += temp.second;
        upd(a[i], -1);
        pos[a[i]].pop_front();
        upd(a[i], 1);
    }
    return ans;
}

// ACUTAL SOLUTION END HERE //////////////////////////////////////////////////////////////////
// FOR HACKER/READER - you don't need to care about the part below
ans_type brute();
#ifndef testing
int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int ntest = 1;
#ifdef multitest
    cin >> ntest;
#endif
    rep1(testcase, ntest) {
        DB(testcase);
        read();
        auto ans = solve();
        print_ans(cout, ans);
#ifdef print_brute
        auto br = brute();
        print_ans(cout << endl << "====" << endl, br);
        cout << endl << "==============" << endl;
#endif
    }
    return 0;
}
#else
void gen_test(int cur_test) {
    ofstream inp("main.inp");
    n = rand() % 10 + 1;
    a.resize(n);
    rep(i, n) a[i] = rand() % n + 1;
    inp << n << '\n';
    rep(i, n) inp << a[i] << ' ';
}
int main(void) {
    rep1(testcase, 10000) {
        gen_test(testcase);
        auto ans = solve();
        auto br = brute();
        assert(ans == br);
        cout << "OK " << testcase << endl;
    }
    return 0;
}
#endif

ans_type brute() {
    llong ans = 0;
    rep(i, n) {
        vector<int> cnt(n + 1);
        multiset<int> se;
        
        for (int f = i; f < n; ++f) {
            if (cnt[a[f]]) se.erase(se.find(cnt[a[f]]));
            se.insert(++cnt[a[f]]);
            if (*se.begin() == 3 and *--se.end() == 3) ++ans;
            if (*--se.end() > 3) break;
        }
    }
    return ans;
}

// vim: foldmethod=marker