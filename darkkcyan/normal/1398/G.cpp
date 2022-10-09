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

#define cpl complex<double>
#define vcpl vector<cpl>
const double pi = atan(1) * 4;

inline vcpl fftmul(vcpl u, vcpl v) {
    unsigned cnt = 0;
    while ((1u << cnt) < max(u.size(), v.size())) ++cnt;
    ++cnt;

    auto fft = [&](vector<cpl>& a, bool inv) -> void {
        vcpl b = a;
        int n = 1 << cnt;
        for (int i = n; i--; ) {
            int f = 0, t = cnt;
            while (t--) f |= ((i >> t) & 1) << (cnt - t - 1);
            a[i] = b[f];
        }

        for (int step = 2; step <= n; step <<= 1) {
            for (int i = 0; i < n; i += step) {
                double ang = 2 * pi / step * (inv ? -1 : 1);
                cpl w(1), pw(cos(ang), sin(ang));
                for (int f = 0; f < step / 2; ++f) {
                    cpl x = a[i + f], y = a[i + f + step / 2] * w;
                    a[i + f] = x + y;
                    a[i + f + step / 2] = x - y;
                    w *= pw;
                }
            }
        }
        if (inv) for (int i = n; i--; ) a[i] /= n;
    };

    u.resize(1 << cnt);
    v.resize(1 << cnt);

    fft(u, 0);
    fft(v, 0);
    for (int i = (1 << cnt); i--; ) u[i] *= v[i];
    fft(u, 1);
    return u;
}


const int maxn = 501010;
int n, y;
int x[maxn], w[maxn];
bool possible[maxn * 2];

void process(int l, int r) {
    if (l == r) {
        possible[w[l]] = true;
        return ;
    }
    if (l > r) return ;
    int mid = (l+ r) / 2;
    process(l, mid);
    process(mid + 1, r);
    
    int cur = 0;
    vcpl u, v;
    
    for (int i = mid; i >= l; --i) {
        cur += w[i];
        while (len(u) <= cur) u.push_back(0);
        u[cur] = 1;
    }
    
    cur = 0;
    for (int i = mid + 1; i <= r; ++i) {
        cur += w[i];
        while (len(v) <= cur) v.push_back(0);
        v[cur] = 1;
    }
    
    u[0] = v[0] = 1;
    auto t = fftmul(u, v);
    rep(i, len(t)) {
        if (round(t[i].real()) > 0) possible[i] = true;
    }
}

const int maxl = 1001010;
llong max_ans[maxl];

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> y >> y;
    rep(i, n + 1) {
        cin >> x[i];
    }
    
    rep1(i, n) w[i] = x[i] - x[i - 1];
    process(1, n);
    
    memset(max_ans, -1, sizeof(max_ans));
    
    for (int i = 1; i < 2 * maxn; ++i) {
        if(!possible[i]) continue;
        int d = y + i;
        deb(d);
        for (int f = d; 2 * f < maxl; f += d) {
            max_ans[2 * f] = max(max_ans[2 * f], (llong)2 * d);
        }
    }
    
    int q ;cin >> q;
    while (q--) {
        int l; cin >> l;
        cout << max_ans[l] << ' ';
    }

    return 0;
}

// Remember:
// - Multitest? REFRESHING the data!!!
// - Constrains for each set of data may differs. Should NOT USE the same max constant (maxn)
//   for all of them.
// vim: foldmethod=marker