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

llong brute(llong length, int range) {
    llong ans = 0;
    function<void(int, int, llong)> fn = [&](int i, int prev_val, llong cur) {
        if (i == length) {
            ++ans;
            return ;
        }
        for (int val = prev_val + 1; val < range; ++val) { 
            llong nxt = cur ^ val;
            if (nxt <= cur) continue;
            fn(i + 1, val, nxt);
        }
    };
    fn(0, 0, 0);
    return ans;
}

void print_brute() {
    llong prev_ans = 0;
    rep1(d, 65) {
        DB(d);
        int length = 1;
        llong ans = 0;
        llong cur_ans = 0;
        do {
            cur_ans = brute(length, d);
            ans += cur_ans;
            // deb(length, cur_ans); 
            ++length;
        } while (cur_ans);
        deb(ans, ans - prev_ans);
        prev_ans = ans;
    }
}

llong max_bit(llong num) {
    while ((num & (num - 1)) != 0) num -= num & -num;
    return num;
}

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int ntest; cin >> ntest;
    while (ntest--) {
        llong d, m; cin >> d >> m;
        DB(""; deb(ntest, d, m));

        llong ans = 0;
        vector<llong> terms = {1, 2, 3};

        llong diff = 1;
        
        llong max_lg = max_bit(d);
        deb(max_lg);
        int cur_term = 0;
        for (llong i = 1; i < max_lg; i <<= 1) {
            DB(""; deb(i));
            deb(diff);
            (ans += diff * i % m) %= m;

            ++cur_term;
            terms.push_back((3 * terms.back() - 2 * terms[len(terms) - 2]) % m);
            if (terms.back() < m) terms.back() += m;

            (diff *= terms[cur_term]) %= m;
        }
        deb(ans);
        d -= max_lg - 1;
        deb(d);
        (ans += diff * d) %= m;
        deb(ans);
        cout << ans << '\n';
    }

    return 0;
}

// vim: foldmethod=marker