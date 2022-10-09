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
#ifdef LOCAL_DEBUG   
int __db_level = 0;
bool __db_same_line = false;
#define clog cerr << string(!__db_same_line ? __db_level * 2 : 0, ' ')
struct debug_block {
    function<void()> fn;
    void print_name() { __db_same_line = true; fn(); clog << endl; __db_same_line = false;  }
    debug_block(function<void()> fn_): fn(fn_) { clog << "{ "; print_name(); ++__db_level; }
    ~debug_block() { --__db_level; clog << "} "; print_name(); }
};
#define DB(args...) debug_block CONCAT(dbbl, __LINE__)([=]{ clog << args; })
#define deb(...)  if (1) { (clog << "[" #__VA_ARGS__ "] = [" << __VA_ARGS__) << "]"; if (!__db_same_line) clog << endl; }
#else
#define clog if (0) cerr
#define DB(...)
#define deb(...)
#endif
template<class T>
ostream& operator,(ostream& out, const T& thing) { return out << ", " << thing; }
template<class U, class V>
ostream& operator<<(ostream& out, const pair<U, V>& p) { return (out << "(" << p.first, p.second) << ")"; }
template<class A, class B>
ostream& operator<<(ostream& out, const tuple<A, B>& t) { return (out << "(" << get<0>(t), get<1>(t)) << ")"; }
template<class A, class B, class C>
ostream& operator<<(ostream& out, const tuple<A, B, C>& t) { return (out << "(" << get<0>(t), get<1>(t), get<2>(t)) << ")"; }
template<class T> ostream& operator<<(ostream& out, const vector<T>& container) { 
    out << "{";
    if (len(container)) out << container[0];
    rep1(i, len(container) - 1) out, container[i];
    return out << "}";
}
template<class x> vector<typename x::value_type> $v(const x& a) { return vector<typename x::value_type>(a.begin(), a.end()); }
#define ptrtype(x) typename iterator_traits<x>::value_type
template<class u> vector<ptrtype(u)> $v(u a, u b) { return vector<ptrtype(u)>(a, b); }/*}}}*/
// ACTUAL SOLUTION BELOW ////////////////////////////////////////////////////////////

const int maxk = 21;
const int maxm = 1010101;

int n, m, k;
pair<int, int> sw[maxm];

llong trans(llong mask, const vector<int>& perm) {
    llong ans = 0;
    rep(i, k) {
        ans |= ((mask >> perm[i])& 1) << i;
    }
    return ans;
}

llong rev_trans(llong mask, const vector<int>& perm) {
    llong ans = 0;
    rep(i, k) {
        ans |= ((mask >> i) & 1) << perm[i];
    }
    return ans;
}

llong tomask(string s) {
    reverse(s.begin(), s.end());
    llong ans = 0;
    for (auto i: s) ans = (ans << 1) | (i == '1');
    return ans;
}

llong mu, mv;
int min_pos[1 << maxk][maxk];

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    cin >> n >> m >> k;
    deb(n, m, k);
    string s; cin >> s; mu = tomask(s);
    cin >> s; mv = tomask(s);
    deb(bitset<4>(mu), bitset<4>(mv));
    
    rep(i, n) {
        cin >> sw[i].first >> sw[i].second;
        --sw[i].first;
        --sw[i].second;
        deb(sw[i]);
    }
    
    vector<int> perm(k);
    rep(i, k) perm[i] = i;
    
    rep(i, (1 << k)) rep(f, k) {
        min_pos[i][f] = maxm;
    }
    
    min_pos[mu][0] = n;
    
    for (int i = n; i--; ) {
        swap(perm[sw[i].first], perm[sw[i].second]);
        llong nm = rev_trans(mu, perm);
        deb(bitset<4>(mu), perm, bitset<4>(nm));
        min_pos[nm][0] = min(min_pos[nm][0], i);
    }
    
    rep(i, k) {
        rep(mask, (1 << k)) {
            if (min_pos[mask][i] == maxm) continue;
            deb(bitset<4>(mask), i, min_pos[mask][i]);
            rep(bit, k) {
                int nm = mask ^ (1 << bit);
                min_pos[nm][i + 1] = min(min_pos[nm][i + 1], min_pos[mask][i]);
            }
        }
    }
    
    rep(i, k) perm[i] = i;
    tuple<int, int, int> ans;
    
    for (int i = n + 1; i--; ) {
        DB(i);
        if (i < n) swap(perm[sw[i].first], perm[sw[i].second]);
        auto nm = rev_trans(mv, perm);
        deb(perm, bitset<4>(nm));
        rep(bit, k + 1) {
            deb(bit, min_pos[nm][bit]);
            if (i - min_pos[nm][bit] < m) continue;
            ans = max(ans, {k - bit, min_pos[nm][bit], i});
        }
    }
    
    cout << get<0>(ans) << '\n' << get<1>(ans) + 1 << ' ' << get<2>(ans);
    

    return 0;
}

// Remember:
// - Multitest? REFRESHING the data!!!
// - Constrains for each set of data may differs. Should NOT USE the same max constant (maxn)
//   for all of them.
// vim: foldmethod=marker