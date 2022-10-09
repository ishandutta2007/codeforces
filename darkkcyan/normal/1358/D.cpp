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

const int maxn = 201010;
int n;
llong x;
llong a[maxn];

llong hug_end_month(llong nday, llong from = 1) {
    llong ans = (nday - from + 1) * (nday + from) / 2;
    // deb(nday, from, ans);  
    return ans;
}

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> x;  
    rep(i, n) cin >> a[i];  
    
    if (x == accumulate(a, a + n, 0LL)) {
        llong ans = 0;
        rep(i, n) ans += hug_end_month(a[i]);
        cout << ans;
        return 0;
    }
    
    int end_month = 0;
    llong cnt = 0;
    llong ans = 0;
    
    llong cum_ans = 0;
    rep(start_month, n) {
        while (cnt + a[end_month] <= x) {
            cum_ans += hug_end_month(a[end_month]);
            cnt += a[end_month];
            end_month = (end_month + 1) % n;
        }
        llong left = x - cnt;
        deb(start_month, end_month, cnt, cum_ans, left);
        llong cur_ans;
        
        if (start_month == end_month) {
            cur_ans = hug_end_month(a[start_month], a[start_month] - left + 1);
        } else {
            cur_ans = cum_ans - hug_end_month(a[start_month]);
            cur_ans += hug_end_month(min(a[end_month], left + a[start_month]));
            
            llong right = a[end_month] - left + 1;
            // deb(right); 
            if (right <= a[start_month]) cur_ans += hug_end_month(a[start_month], right);
        }
        // deb(cur_ans); 
        ans = max(ans, cur_ans);
        cum_ans -= hug_end_month(a[start_month]);
        cnt -= a[start_month];
    }
    cout << ans;

    return 0;
}

// Remember:
// - Multitest? REFRESHING the data!!!
// - Constrains for each set of data may differs. Should NOT USE the same max constant (maxn)
//   for all of them.
// vim: foldmethod=marker