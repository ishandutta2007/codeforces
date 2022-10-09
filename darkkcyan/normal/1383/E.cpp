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

const llong rem = (llong)(1e9 + 7);
string s;


int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> s;
    vector<int> parts;
    char prev = ' ';
    for (auto i: s) {
        if (i == prev) ++parts.back();
        else {
            parts.push_back(1);
            prev = i;
        }
    }
    
    llong head0 = 0, tail0 = 0;
    if (s[0] == '0') {
        head0 = parts[0];
        parts.erase(parts.begin());
    }
    
    if (head0 == len(s)) {
        cout << len(s);
        return 0;
    }
    
    if (s.back() == '0') {
        tail0 = parts.back();
        parts.pop_back();
    }
    
    int total_ones = parts.back();
    parts.pop_back();
    vector<llong> next0(len(s) + 1);
    
    llong total_next0 = 0;
    llong ans = total_ones;
    llong sum_for_ones = 0;
    
    while (len(parts)) {
        int last0 = parts.back(); parts.pop_back();
        int last1 = parts.back(); parts.pop_back();
        
        rep1(i, last0) {
            (total_next0 -= next0[i]) %= rem;
            if (total_next0 < 0) total_next0 += rem;
            next0[i] = ans;
            (total_next0 += next0[i]) %= rem;
        }
        
        (sum_for_ones += last1 * total_next0 % rem) %= rem;
        total_ones += last1;
        (ans = sum_for_ones + total_ones) %= rem;
    }
    
    cout << (head0 + 1) * (tail0 + 1) % rem * ans % rem;
    

    return 0;
}

// Remember:
// - Multitest? REFRESHING the data!!!
// - Constrains for each set of data may differs. Should NOT USE the same max constant (maxn)
//   for all of them.
// vim: foldmethod=marker