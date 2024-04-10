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
const int maxn = 5*101010;
const llong rem = (llong) (998244353LL);

llong ans111[maxn];
void cal_ans111() {
    ans111[0] = 1;
    ans111[1] = 2;
    for (int i = 2; i < maxn; ++i) {
        ans111[i] = (ans111[i - 1] * 2 + ans111[i - 2] * 8) % rem;
    }
}

llong ans111_with(int len1, int dig) {
    llong ans = ans111[len1] * (dig + 1);
    if (len1 > 0) ans += ans111[len1 - 1] * (9 - dig);
    return ans % rem;
}

struct node_data {
    int pref1, suff1, first_non_1;
    llong mid_ans;
    
    node_data() {}
    node_data(int dig) {
        if (dig == 1) {
            pref1 = suff1 = 1;
            first_non_1 = -1;
            mid_ans = -1;
        } else {
            pref1 = suff1 = 0;
            first_non_1 = dig;
            mid_ans = 1;
        }
    }
    
    node_data(const node_data& u, const node_data& v) {
        if (u.mid_ans == -1 and v.mid_ans == -1) {
            mid_ans = -1;
            pref1 = suff1 = u.pref1 + v.pref1;
            return ;
        }
        
        if (u.mid_ans == -1) {
            mid_ans = v.mid_ans;
            first_non_1 = v.first_non_1;
            suff1 = v.suff1;
            pref1 = u.pref1 + v.pref1;
            return ;
        }
        
        if (v.mid_ans == -1) {
            mid_ans = u.mid_ans;
            first_non_1 = u.first_non_1;
            pref1 = u.pref1;
            suff1 = u.suff1 + v.suff1;
            return ;
        }
        
        mid_ans = u.mid_ans * v.mid_ans % rem * ans111_with(u.suff1 + v.pref1, v.first_non_1) % rem;
        pref1 = u.pref1;
        suff1 = v.suff1;
        first_non_1 = u.first_non_1;
    }
    
    llong total_ans() const {
        if (mid_ans == -1) return ans111[pref1];
        return ans111_with(pref1, first_non_1) * mid_ans % rem * ans111[suff1] % rem;
    }
};

ostream& operator<<(ostream& out, const node_data& u) {
    return out << "node_data(" << u.pref1 << ", " << u.first_non_1 << ", " << u.suff1 << ", " << u.mid_ans << ")";
}

int n, m;
string c;
node_data it[maxn * 4];
void build(int i = 1, int l = 0, int r = n) {
    if (l + 1 == r) it[i] = node_data(c[l] - '0');
    if (l + 1 >= r) return ;
    int mid = (l + r) / 2;
    build(i * 2, l, mid);
    build(i * 2 + 1, mid, r);
    it[i] = node_data(it[i * 2], it[i * 2 + 1]);
}

void update(int pos, int dig, int i = 1, int l = 0, int r = n) {
    if (l >= r or pos < l or pos >= r) return ;
    if (l + 1 == r) {
        it[i] = node_data(dig);
        return ;
    }
    int mid = (l + r) / 2;
    update(pos, dig, i * 2, l, mid);
    update(pos, dig, i * 2 + 1, mid, r);
    it[i] = node_data(it[i * 2], it[i * 2 + 1]);
}

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cal_ans111();
    cin >> n >> m;
    cin >> c;
    build();
    deb(it[1]);
    while (m--) {
        int pos, dig; cin >> pos >> dig;
        update(pos - 1, dig);
        cout << it[1].total_ans() << '\n';
        deb(it[1]);
    }

    return 0;
}

// Remember:
// - Multitest? REFRESHING the data!!!
// - Constrains for each set of data may differs. Should NOT USE the same max constant (maxn)
//   for all of them.
// vim: foldmethod=marker