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

const int maxn = 101010;
int n;
llong ca, cr, cm;
llong a[maxn];

llong cal(llong cnt_add, llong cnt_rem) {
    llong cnt_move = min(cnt_add, cnt_rem);
    cnt_add -= cnt_move;
    cnt_rem -= cnt_move;
    return cnt_add * ca + cnt_rem * cr + cnt_move * cm;
}

pair<llong, llong> count_add_rem(llong pivot) {
    llong cnt_add = 0;
    llong cnt_rem = 0;
    rep(i, n) {
        if (a[i] < pivot) cnt_add += pivot - a[i];
        else cnt_rem += a[i] - pivot;
    }
    return {cnt_add, cnt_rem};
}
    
llong cal_ans(llong pivot) {
    auto [cnt_add, cnt_rem] = count_add_rem(pivot);
    return cal(cnt_add, cnt_rem);
}

llong find_ans() {
    llong l = 0, r = *max_element(a, a + n);
    
    while (l < r) {
        llong mid = (l + r) / 2;
        if (cal_ans(mid) <= cal_ans(mid + 1)) r = mid;
        else l = mid + 1;
    }
    return cal_ans(l);
}

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> ca >> cr >> cm;
    rep(i, n) cin >> a[i];
    
    cm = min(cm, ca + cr);
    // sort(a, a + n, greater<llong>()); 
    //  
    // llong sum = 0; 
    // rep(i, n) sum += a[i]; 
    //  
    // llong ans = min(ca * (a[0] * 1ll * n - sum), cr * (sum - 1ll * a[n - 1] * n)); 
    //  
    // llong pref_sum = 0; 
    // rep(i, n - 1) { 
        // pref_sum += a[i]; 
        // llong suff_sum = sum - pref_sum; 
        //  
        // llong cnt_add = pref_sum - a[i + 1] * (i + 1); 
        // llong cnt_rem = a[i + 1] * (n - i) - suff_sum; 
        //  
        // deb(pref_sum, suff_sum); 
        //  
        //  
        // ans = min(ans, cal(cnt_add, cnt_rem)); 
    // } 
    //  
    // for (llong special = find_special_point(), pivot = max(special - 10, 0LL); pivot <= special + 10; ++pivot) { 
        // auto [cnt_add, cnt_rem] = count_add_rem(pivot); 
        // ans = min(ans, cal(cnt_add, cnt_rem)); 
    // } 
    
    cout << find_ans();
    

    return 0;
}

// Remember:
// - Multitest? REFRESHING the data!!!
// - Constrains for each set of data may differs. Should NOT USE the same max constant (maxn)
//   for all of them.
// vim: foldmethod=marker