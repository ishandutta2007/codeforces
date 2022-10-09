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

const int maxm = 10101;
const int maxg = 1001;
int n, m;
int g, r;
int d[maxm];

int dist[maxm][maxg];

struct fake_stack {
    int data[maxg];
    int size;
    fake_stack() : size(0) {}

    inline
    void push(int u) {
        data[size++] = u;
    }

    inline
    int pop() {
        return data[--size];
    }
};

#define queue qu

fake_stack queue[maxg];

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    rep(i, m) cin >> d[i];
    cin >> g >> r;
    sort(d, d + m);
    memset(dist, -1, sizeof(dist));

    dist[0][g] = 0;
    queue[g].push(0);
    while (true) {
        for (int cur_time = g; cur_time > 0; --cur_time) {
            while (queue[cur_time].size) {
                int u = queue[cur_time].pop();
                deb(u, dist[u][cur_time]);
                if (u == m - 1) {
                    cout << dist[u][cur_time];
                    exit(0);
                }
                for (auto v: {u - 1, u + 1}) {
                    if (v < 0 or v >= m) continue;
                    int ds = abs(d[u] - d[v]);
                    int nt = cur_time - ds;
                    if (nt < 0) continue;
                    if (dist[v][nt] != -1) continue;
                    dist[v][nt] = dist[u][cur_time] + ds;
                    queue[nt].push(v);
                }
            }
        }
        if (!queue[0].size) {
            cout << -1;
            exit(0);
        }
        while (queue[0].size) {
            int u = queue[0].pop();
            deb(u, dist[u][0]);
            if (u == m - 1) {
                cout << dist[u][0];
                exit(0);
            }
            if (dist[u][g] != -1) continue;
            dist[u][g] = dist[u][0] + r;
            queue[g].push(u);
        }
    }

    return 0;
}

// vim: foldmethod=marker