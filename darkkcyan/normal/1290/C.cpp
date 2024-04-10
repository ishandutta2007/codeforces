// vim: foldmethod=marker
#include <bits/stdc++.h>
using namespace std;

#define llong long long 
#define len(x) ((int)x.size())
#define rep(i,n) for (int i = -1; ++ i < n; )
#define rep1(i,n) for (int i = 0; i ++ < n; )
#define rand __rand
mt19937 rng(chrono::system_clock::now().time_since_epoch().count());  // or mt19937_64
template<class T = int> T rand(T range = numeric_limits<T>::max()) { return (T)(rng() % range); }

/*{{{*/
#define CONCAT_(x, y) x##y
#define CONCAT(x, y) CONCAT_(x, y)
#ifdef LOCAL_DEBUG   
int debug = 1;
#define DB(...) stringstream CONCAT(ss, __LINE__); CONCAT(ss, __LINE__) << __VA_ARGS__; debug_block CONCAT(dbbl, __LINE__)(CONCAT(ss, __LINE__).str())
#else
int debug = 0;
#define DB(...)
#endif
int __db_level = 0;
#define clog if (debug) cerr << string(__db_level * 2, ' ')
struct debug_block {
    string name;
    debug_block(const string& name_): name(name_) { clog << "{ " << name << endl; ++__db_level; }
    ~debug_block() { --__db_level; clog << "} " << name << endl; }
};
#define deb(...) "[" << #__VA_ARGS__ << "] = [" << __VA_ARGS__ << "]"
#define debln(...)  clog << "[" << #__VA_ARGS__ << "] = [" << __VA_ARGS__ << "]" << endl
#define _ << ", " <<
template<class U, class V>
ostream& operator<<(ostream& out, const pair<U, V>& p) { return out << "(" << p.first _ p.second << ")"; }
template<class A, class B>
ostream& operator<<(ostream& out, const tuple<A, B>& t) { return out << "(" << get<0>(t) _ get<1>(t) << ")"; }
template<class A, class B, class C>
ostream& operator<<(ostream& out, const tuple<A, B, C>& t) { return out << "(" << get<0>(t) _ get<1>(t) _ get<2>(t) << ")"; }
template<class T> ostream& operator<<(ostream& out, const vector<T>& container) { 
    out << "{";
    if (len(container)) out << container[0];
    rep1(i, len(container) - 1) out _ container[i];
    return out << "}";
}
template<class x> vector<typename x::value_type> $v(const x& a) { return vector<typename x::value_type>(a.begin(), a.end()); }
#define ptrtype(x) typename iterator_traits<x>::value_type
template<class u> vector<ptrtype(u)> $v(u a, u b) { return vector<ptrtype(u)>(a, b); }
/*}}}*/
// ACTUAL SOLUTION BELOW ////////////////////////////////////////////////////////////

#define maxn 301010
int n, k;
string state;
vector<int> container[maxn];

int force_ans, force_not_ans;

set<vector<int>> con_sig;

int dsu[maxn * 2];
int cnt[maxn * 2];
int findp(int u) { return dsu[u] == u ? u : dsu[u] = findp(dsu[u]); }

void join(int u, int v) {
    DB("JOIN");
    debln(u _ v);
    debln(cnt[findp(u)] _ cnt[findp(v)]);
    debln(u / 2 _ u % 2);
    debln(v / 2 _ v % 2);
    u = findp(u), v = findp(v);
    if (u == v) return ;
    if (rand(2)) swap(u, v);
    dsu[u] = v;
    cnt[v] += cnt[u];
}

int cur_ans = 0;
void rem(int u) {
    DB("rem");
    debln(u);
    if (findp(force_ans) == findp(2 * u)) {
        clog << "force_ans " << 2 * u << endl;
        // cur_ans -= cnt[findp(2 * u)]; 
    }
    if (findp(force_ans) == findp(2 * u + 1)) {
        clog << "force_ans " << 2 * u + 1 << endl;
        // cur_ans -= cnt[findp(2 * u + 1)]; 
    }
    if (findp(force_ans) != findp(2 * u) and findp(force_not_ans) != findp(2 * u)) {
        clog << "not force ans" << endl;
        cur_ans -= min(cnt[findp(2 * u)], cnt[findp(2 * u + 1)]);
    }
}

void add(int u) {
    if (findp(force_ans) == findp(2 * u)) {
        clog << "force_ans " << 2 * u << endl;
        // cur_ans += cnt[findp(2 * u)]; 
    }
    if (findp(force_ans) == findp(2 * u + 1)) {
        clog << "force_ans " << 2 * u + 1 << endl;
        // cur_ans += cnt[findp(2 * u + 1)]; 
    }
    if (findp(force_ans) != findp(2 * u) and findp(force_not_ans) != findp(2 * u)) {
        clog << "not force ans" << endl;
        cur_ans += min(cnt[findp(2 * u)], cnt[findp(2 * u + 1)]);
    }
}

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> k;
    cin >> state;
    rep(i, k) {
        int c; cin >> c;
        rep(f, c) {
            int u; cin >> u;
            --u;
            container[u].push_back(i);
        }
    }

    rep(i, n) sort(container[i].begin(), container[i].end());

    rep(i, 2 * k + 2) dsu[i] = i;
    rep(i, 2 * k) {
        cnt[i] = i & 1;
    }
    force_ans = 2 * k;
    force_not_ans = 2 * k + 1;
    debln(force_ans);
    debln(force_not_ans);

    rep(i, n) {
        DB(i);
        if (con_sig.count(container[i])) {
            cout << cur_ans + cnt[findp(force_ans)] << '\n';
            continue;
        }
        con_sig.insert(container[i]);
        if (len(container[i]) == 1) {
            int c = container[i][0];
            debln(c);
            rem(c);
            if (state[i] == '1') {
                join(force_ans, 2 * c);
                join(force_not_ans, 2 * c + 1);
            } else {
                join(force_ans, 2 * c + 1);
                join(force_not_ans, 2 * c);
            }
            add(c);
        } else if (len(container[i]) == 2) {
            int u = container[i][0], v = container[i][1];
            if (findp(2 * u) != findp(2 * v) and findp(2 * u + 1) != findp(2 * v)) {
                debln(u _ v);
                rem(u);
                rem(v);
                if (state[i] == '1') {
                    join(2 * u, 2 * v);
                    join(2 * u + 1, 2 * v + 1);
                } else {
                    join(2 * u + 1, 2 * v);
                    join(2 * v + 1, 2 * u);
                }
                add(u);
            }
        }
        cout << cur_ans + cnt[findp(force_ans)] << '\n';
    }

    return 0;
}