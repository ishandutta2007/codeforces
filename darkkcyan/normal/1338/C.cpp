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

vector<llong> brute(int n, int limit = 100) {
    set<llong> has;
    vector<llong> ans;
    for (int a = 1; a < limit and len(has) < n; ++a) {
        if (has.count(a)) continue;
        for (int b = a + 1; b < limit and len(has) < n; ++b) {
            if (has.count(b)) continue;
            if (has.count(a ^ b)) continue;
            has.insert(a);
            has.insert(b);
            has.insert(a ^ b);
            ans.push_back(a);
            ans.push_back(b);
            ans.push_back(a ^ b);
            break;
        }
    }
    return ans;
}

llong find_base_b(llong id, llong length) {
    DB(""; deb(id, length));
    if (length <= 1) return 0;
    
    llong ans = 0;
    while (length > 1) {
        assert(length % 4 == 0);
        
        llong quater = length / 4;
        llong cnt = id / quater;
        ans <<= 2;
        
        switch (cnt) {
            case 0:
                break;
            case 1:
                ans += 2;
                break;
            case 2:
                ans += 3;
                break;
            case 3: 
                ans += 1;
                break;
        }
        length = quater;
        id %= quater;
    }
    return ans;
}

array<llong, 3> find_trip(llong n_trip) {
    llong base = 1;
    while (n_trip - base > 0) {
        n_trip -= base;
        base *= 4;
    }
    llong group_id = n_trip - 1;
    llong a = base + group_id;
    llong b = (2 * base);
    b += find_base_b(group_id, base);
    return {a, b, a ^ b};
}

void check() {
    auto br = brute(500, 2000);
    for (int i = 0, n = 1; i < len(br); i += 3, ++n) {
        auto [a, b, c] = find_trip(n);
        cout << br[i] << ":" <<  a << " , " << br[i + 1] << ":" << b << " , " << br[i + 2] << ":" << c << endl;
    }

}

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    // check(); 
    int ntest; cin >> ntest;
    while (ntest--) {
        llong n; cin >> n;
        --n;
        llong n_trip = n / 3 + 1;
        cout << find_trip(n_trip)[n % 3] << '\n';
    }
    
    return 0;
}

// Remember:
// - Multitest? REFRESHING the data!!!
// - Constrains for each set of data may differs. Should NOT USE the same max constant (maxn)
//   for all of them.
// vim: foldmethod=marker