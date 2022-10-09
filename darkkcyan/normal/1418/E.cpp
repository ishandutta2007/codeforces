// tell me do you play Botw???
#include <bits/stdc++.h>
using namespace std;

#define llong long long 
#define len(x) ((int)x.size())
#define rep(i,n) for (int i = -1; ++ i < n; )
#define rep1(i,n) for (int i = 0; i ++ < n; )
#define rand __rand
mt19937 rng(chrono::system_clock::now().time_since_epoch().count());  // or mt19937_64
template<class T = int> T rand(T range = numeric_limits<T>::max()) { return (T)(rng() % range); }

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
// ACTUAL SOLUTION BELOW ////////////////////////////////////////////////////////////

const llong mod = (llong)998244353;
llong mpow(llong base, llong exp) {
    llong ans = 1;
    for (; exp > 0; exp >>= 1) {
        if (exp & 1) (ans *= base) %= mod;
        (base *= base) %= mod;
    }
    return ans;
}

const int maxn = 201010;
const int maxm = maxn;
struct Query {
    int id;
    llong dura, def;
    Query() {}
    Query(int i, llong du, llong de): id(i), dura(du), def(de) {}
};

bool operator<(const Query& u, const Query& v) {
    return u.def < v.def; 
}

int n, m;
llong dam[maxn];
Query queries[maxm];
llong ans [maxn];

llong fac[maxn], ifac[maxn];

llong simu(llong dura, llong def) {
    DB(db(dura) << db(def));
    llong cur_ans = 0;
    vector<int> pos(n);
    rep(i, n) pos[i] = i;
    do {
        llong cur_dura = dura;
        llong cur_dam = 0;
        for (auto i: pos) {
            if (cur_dura == 0) (cur_dam += dam[i]) %= mod;
            else if (dam[i] >= def) cur_dura --;
        }
        clog << db(cur_dam);
        for (auto i: pos) clog << dam[i] << ' ';
        clog << endl;
        (cur_ans += cur_dam) %= mod;
    } while(next_permutation(pos.begin(), pos.end()));
    clog << db(cur_ans) << endl;
    return cur_ans * ifac[n] % mod;
}

void gen_test() {
    ofstream inp("main.inp");
    n = 4; m = 5;
    inp << n << ' ' << m << endl;
    rep(i, n) {
        dam[i] = rand(10) + 1;
        inp << dam[i] << ' ';
    }
    inp << endl;
    
    rep(i, m) {
        queries[i].dura = rand(10) + 1;
        queries[i].def = rand(10) + 1;
        queries[i].id = i;
        inp << queries[i].dura << ' ' << queries[i].def << endl;
    }
}

// #define testing   
int main(void) {
    fac[0] = 1;
    rep1(i, maxn - 1) fac[i] = fac[i - 1] * i % mod;
    rep(i, maxn) ifac[i] = mpow(fac[i], mod - 2);
    
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef testing
    cin >> n >> m;
    rep(i, n) {
        cin >> dam[i];
    }
    rep(i, m) {
        cin >> queries[i].dura >> queries[i].def;
        queries[i].id = i;
    }
    // rep(i, m) { 
        // auto expected_ans = simu(queries[i].dura, queries[i].def); 
        // cout << expected_ans << endl; 
    // } 
    // cout << endl; 
#else 
while (true)  {
        
    gen_test();
    vector<llong> expected_ans(m);
    rep(i, m) expected_ans[i] = simu(queries[i].dura, queries[i].def);
#endif
    
    sort(queries, queries + m);
    sort(dam, dam + n);
    
    llong sum_big = 0;
    llong sum_small = 0;
    rep(i, n) sum_big += dam[i];
    
    int f = 0;
    rep(i, m) {
        DB(db(i));
        while (f < n and dam[f] < queries[i].def) {
            sum_big -= dam[f];
            sum_small += dam[f];
            ++f;
        }
        
        clog << db(queries[i].id) << db(queries[i].dura) << db(queries[i].def) << endl;
        clog << db(f) << db(sum_big) << db(sum_small) << endl;
        
        llong cnt_big = n - f;
        clog << db(cnt_big) << endl;
        if (queries[i].dura > cnt_big) {
            ans[queries[i].id] = 0;
        } else {
            ans[queries[i].id] = sum_big % mod * (cnt_big - queries[i].dura) % mod * mpow(cnt_big, mod - 2) % mod;
            (ans[queries[i].id] += sum_small % mod * (cnt_big - queries[i].dura + 1) % mod *  mpow(cnt_big + 1, mod - 2) % mod) %= mod;
        }
    }
#ifndef testing
    rep(i, m) cout << ans[i] << '\n';
#else
    rep(i, m) {
        if (expected_ans[i] != ans[i]) {
            cout << "FAILED" << endl;
            cout << i << ' ' << ans[i] << ' ' << expected_ans[i] << endl;
            return 0;
        }
    }
    clog << "OK" << endl;
#endif
    
#ifdef testing
}
#endif
    

    return 0;
}

// Remember:
// - Multitest? REFRESHING the data!!!
// - Constrains for each set of data may differs. Should NOT USE the same max constant (maxn)
//   for all of them.
// vim: foldmethod=marker