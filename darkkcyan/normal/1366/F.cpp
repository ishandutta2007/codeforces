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

struct point {
    llong x, y;
    point() {}
    point(llong x_, llong y_): x(x_), y(y_) {}
};

point operator-(const point& u, const point& v) {
    return point(u.x - v.x, u.y - v.y);
}

llong cross(const point& u, const point& v) {
    return u.x * v.y - u.y * v.x;
}

struct line: point {
    using point::point;
    llong operator()(llong x_) { return x * x_ + y; }
};

bool is_lower(const line& left, const line& mid, const line& right) {
    return cross(right - mid, left - mid) >= 0;
}

const int maxn = 2020;
const llong inf = (llong)1e15;
const llong rem = (llong)(1e9 + 7);
int n, m;
llong q;

vector<tuple<int, int, llong>> edge_list;

llong cur_dist[2][maxn];

llong mpow(llong base, llong exp) {
    llong ans = 1;
    for (; exp > 0; exp >>= 1) {
        if (exp & 1) (ans *= base) %= rem;
        (base *= base) %= rem;
    }
    return ans;
}

void custom_input() {
    n = 2000;
    m = 1999;
    q = (int)1e9;
    
    rep(i, m) {
        edge_list.emplace_back(i + 1, i + 2, 999999);
    }
}

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m >> q;  
    rep(i, m) {  
        int u, v, c; cin >> u >> v >> c;  
        edge_list.emplace_back(u, v, c);  
    }  
    // custom_input();   
    
    rep1(u, n) cur_dist[0][u] = -inf;
    cur_dist[0][1] = 0;
    
    llong ans = 0;
    int state;
    rep1(i, m * 3) {
        state = i & 1;
        rep1(u, n) cur_dist[state][u] = -inf;
        for (auto [u, v, c]: edge_list) {
            cur_dist[state][v] = max(cur_dist[state][v], cur_dist[!state][u] + c);
            cur_dist[state][u] = max(cur_dist[state][u], cur_dist[!state][v] + c);
        }
        
        llong cur_ans = 0;
        rep1(u, n) {
            cur_ans = max(cur_ans, cur_dist[state][u]);
        }
        (ans += cur_ans) %= rem;
        --q;
        if (q == 0) {
            cout << ans;
            return 0;
        }
    }
    
    vector<line> hull;
    rep1(u, n) {
        deb(u, cur_dist[state][u]);
        hull.emplace_back(-inf, cur_dist[state][u]);
    }
    
    for (auto [u, v, c]: edge_list) {
        hull[u - 1].x = max(hull[u - 1].x, c);
        hull[v - 1].x = max(hull[v - 1].x, c);
    }
    
    hull.resize(remove_if(hull.begin(), hull.end(), [](const line&u) { return u.y < 0; } ) - hull.begin());
    
    sort(hull.begin(), hull.end(), [](const line& u, const line& v) {
            if (u.x == v.x) return u.y < v.y;
            return u.x < v.x;
    });
    
    
    int new_len = 1;
    for (int i = 1; i < len(hull); ++i) {
        while (new_len and hull[new_len - 1].x == hull[i].x) --new_len;
        hull[new_len++] = hull[i];
    }
    
    hull.resize(new_len);
    hull.insert(hull.begin(), line(0, 0));
    new_len = min(2, len(hull));
    
    for (int i = 2; i < len(hull); ++i) {
        while (new_len > 2 and is_lower(hull[new_len - 2], hull[new_len - 1], hull[i])) {
            --new_len;
        }
        hull[new_len++] = hull[i];
    }
    
    hull.resize(new_len);
    
    // if (edge_list[0] == make_tuple(166, 93, 44)) { 
        // cout << q << endl; 
    // } 
    //  
    llong inv2 = mpow(2, rem - 2);
    llong pos = 1;
    for (int i = 0; i < len(hull) - 1 and pos <= q; ++i) {
        llong left = pos, right = q + 1;
        while (left < right) {
            llong mid = (left + right) / 2;
            if (hull[i + 1](mid) > hull[i](mid)) right = mid;
            else left = mid + 1;
        }
        
        llong cnt = (left - pos) % rem;
        deb(cnt, hull[i].x, hull[i].y);
        
        llong t = cnt * (pos + left - 1) % rem * inv2 % rem;
        (ans += cnt * hull[i].y % rem) %= rem;
        (ans += t * hull[i].x % rem) %= rem;
        //  
        // if (edge_list[0] == make_tuple(166, 93, 44)) { 
            // cout << ans << ' ' << cnt << ' ' << hull[i].x << ' ' << hull[i].y << pos << ' ' << left << endl; 
        // } 
        
        pos = left;
    }
    //  
    // if (edge_list[0] == make_tuple(414,435,18)) { 
        // cout << len(hull) << endl; 
        // for (auto i: hull) { 
            // cout << i.x << ' ' << i.y << '\n'; 
        // } 
    // } 
    
    deb(q);
    llong cnt = (q - pos + 1) % rem;
    llong t = cnt * (q + pos) % rem * inv2 % rem;
    deb(cnt, hull.back().x, hull.back().y);
    (ans += cnt * hull.back().y % rem) %= rem;
    (ans += t * hull.back().x % rem) %= rem;
    cout << ans;
    
    return 0;
}

// Remember:
// - Multitest? REFRESHING the data!!!
// - Constrains for each set of data may differs. Should NOT USE the same max constant (maxn)
//   for all of them.
// vim: foldmethod=marker