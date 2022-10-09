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

struct BIT {
    vector<int> cnt;
    vector<llong> sum;
    int n;
    
    BIT(int n_): cnt(n_), sum(n_), n(n_) {
    }
    
    void add(int i, llong val) {
        i = n - i - 5;
        int delta = val > 0 ? 1 : -1;
        for (++i; i < n; i += i & -i) {
            cnt[i] += delta;
            sum[i] += val;
        }
    }
    
    llong get_sum(int k) {
        deb(cnt);
        deb(sum);
        int acc = 0;
        llong ans = 0;
        int p = 0;
        for (int i = 20; i --; ) {
            int np = p + (1 << i);
            if (np >= n) continue;
            if (acc + cnt[np] > k) continue;
            acc += cnt[np];
            ans += sum[np];
            p = np;
        }
        deb(acc, ans, p);
        return ans;
    }
};

const int maxn = 201010;
int n;
vector<llong> vals;
llong what[maxn];
int type[maxn];

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    rep1(i, n) {
        cin >> type[i] >> what[i];
        vals.push_back(abs(what[i]));
    }
    
    sort(vals.begin(), vals.end());
    vals.resize(unique(vals.begin(), vals.end()) - vals.begin());
    
    BIT bit(len(vals) + 10);
    
    llong sum = 0;
    
    set<llong> lightings;
    
    rep1(i, n) {
        DB(""; deb(i));
        int p = (int)(lower_bound(vals.begin(), vals.end(), abs(what[i])) - vals.begin());
        if (type[i] == 1) {
            if (what[i] > 0) lightings.insert(what[i]);
            else lightings.erase(-what[i]);
        }
        sum += what[i];
        bit.add(p, what[i]);
        llong ans = sum;
        if (len(lightings)) {
            llong sm  = *lightings.begin();
            deb(sm);
            p = (int)(lower_bound(vals.begin(), vals.end(), sm) - vals.begin());
            bit.add(p, -sm);
            ans = sum + bit.get_sum(len(lightings));
            bit.add(p, sm);
        }
        cout << ans << '\n';
    }

    return 0;
}

// Remember:
// - Multitest? REFRESHING the data!!!
// - Constrains for each set of data may differs. Should NOT USE the same max constant (maxn)
//   for all of them.
// vim: foldmethod=marker