#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define SZ(x) ((int)((x).size()))
#define all(x) (x).begin(), (x).end()

// Returns the time elapsed in nanoseconds from 1 January 1970, at 00:00:00.
LL get_time() {
    return chrono::duration_cast<chrono::nanoseconds>(
        chrono::steady_clock::now().time_since_epoch())
        .count();
}

// Returns a random integer from the range [l, r].
LL randint(LL l, LL r) {
	#if DEBUG && !ONLINE_JUDGE
	static mt19937_64 gen; // Deterministic on the local machine.
	#else
	static mt19937_64 gen(chrono::steady_clock::now().time_since_epoch().count());
	#endif
	return uniform_int_distribution<LL>(l, r)(gen);
}

template <typename Iterator>
string print_iterable(Iterator begin, Iterator end, string bef, string aft,
        function<string(typename iterator_traits<Iterator>::value_type)>* f = nullptr) {
    stringstream res;
    res << bef;
    bool is_first = true;
    for (Iterator it = begin; it != end; ++it) {
        if (!is_first) res << ", ";
        if (f != nullptr) res << (*f)(*it);
        else res << *it;
        is_first = false;
    }
    res << aft;
    return res.str();
}

template <typename S, typename T>
ostream& operator <<(ostream& out, const pair<S, T>& p) {
    out << "{" << p.first << ", " << p.second << "}";
    return out;
}

#define _define_print_container(Container, bef, aft)        \
template <typename T>                                       \
ostream& operator <<(ostream& out, const Container<T>& v) { \
    out << print_iterable(v.begin(), v.end(), bef, aft);    \
    return out;                                             \
}                                                           \

_define_print_container(vector, "[", "]");
_define_print_container(set, "{", "}");
_define_print_container(unordered_set, "{", "}");
_define_print_container(multiset, "{", "}");
_define_print_container(unordered_multiset, "{", "}");
_define_print_container(deque, "[", "]");

#define _define_print_dictionary(Dictionary, bef, aft)                      \
template <typename T1, typename T2>                                         \
ostream& operator <<(ostream& out, const Dictionary<T1, T2>& v) {           \
    out << print_iterable(v.begin(), v.end(), bef, aft);                    \
    return out;                                                             \
}                                                                           \

_define_print_dictionary(map, "{", "}");
_define_print_dictionary(unordered_map, "{", "}");

#define _define_print_container_adaptor(Adaptor, OP)                        \
template <typename T>                                                       \
ostream& operator <<(ostream& out, Adaptor<T> a) {                          \
    vector<T> v;                                                            \
    while (!a.empty()) v.push_back(a.OP()), a.pop();                        \
    out << v;                                                               \
    return out;                                                             \
}                                                                           \

_define_print_container_adaptor(stack, top)
_define_print_container_adaptor(queue, front)
_define_print_container_adaptor(priority_queue, top)

template<class TH>
void _dbg(const char* name, TH val){
    clog << name << ": " << val << endl;
}
template<class TH, class... TA>
void _dbg(const char* names, TH curr_val, TA... vals) {
    while(*names != ',') clog << *names++;
    clog << ": " << curr_val << ", ";
    _dbg(names+1, vals...);
}

#if DEBUG && !ONLINE_JUDGE
    ifstream input_from_file("input.txt");
    #define cin input_from_file

    #define dbg(...) _dbg(#__VA_ARGS__, __VA_ARGS__)
    #define dbg_arr(x, len) \
    clog << #x << ": " << print_iterable(x, x+len, "[", "]") << endl;
    #define dbg_arr1(x, len) \
    clog << #x << ": " << print_iterable(x+1, x+len+1, "[", "]") << endl;
#else
    #define dbg(...)
    #define dbg_arr(x, len)
    #define dbg_arr1(x, len)
#endif

///////////////////////////////////////////////////////////////////////////
//////////////////// DO NOT TOUCH BEFORE THIS LINE ////////////////////////
///////////////////////////////////////////////////////////////////////////

const int E = 16;
const int L = 9;

struct MaxXor {
    vector<int> vals;
    vector<bool> present;
    MaxXor(): vals(1<<(E-L), 0), present(1<<(E-L+1), false) {}
    void add(int z) {
        int x = z >> L;
        vals[x] = max(vals[x], z);
        x |= 1<<(E-L);
        for (; x; x >>= 1) present[x] = true;
    }
    int query(int x) { // x*2^L
        assert(present[1]);
        int y = 1;
        for (int e = E-L-1; e >= 0; e--) {
            int d = (x >> e) & 1;
            y <<= 1;
            y ^= present[y+(!d)] ? (!d) : d;
        }
        return vals[y ^ (1<<(E-L))] ^ (x << L);
    }
};

const int MAXN = 50010;
int depth[MAXN];
int ff[MAXN];
int ff_L[MAXN];
vector<int> aa[MAXN];

void dfs(int v, int f) {
    for (int a: aa[v]) {
        if (a == f) continue;
        ff[a] = v;
        depth[a] = depth[v] + 1;
        dfs(a, v);
    }
}

MaxXor up_range_L[MAXN];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); // Remove in problems with online queries!

    int n, q;
    cin >> n >> q;
    vector<int> a(n+1);
    for (int v = 1; v <= n; v++) cin >> a[v];
    
    for (int i = 0; i < n-1; i++) {
        int u, v;
        cin >> u >> v;
        aa[u].push_back(v);
        aa[v].push_back(u);
    }
    dfs(1, 0);
    for (int v = 1; v <= n; v++) {
        int y = v;
        for (int i = 0; i < (1<<L); i++) {
            up_range_L[v].add(a[y]^i);
            y = ff[y];
        }
        ff_L[v] = y;
    }

    vector<vector<pair<int,int>>> queries(n+1);
    for (int _ = 0; _ < q; _++) {
        int u, v;
        cin >> u >> v;
        queries[v].push_back({depth[v] - depth[u], _});
    }
    vector<int> ans(q);
    
    for (int v = 1; v <= n; v++) {
        sort(all(queries[v]));
        int t = 0;
        int s = 0;
        int ut = v;
        int us = v;
        int ans_t = 0;
        int ans_s = 0;
        for (auto pp: queries[v]) {
            int id = pp.second;
            int dist = pp.first;
            while ((t<<L) + (1<<L) <= dist) {
                ans_t = max(ans_t, up_range_L[ut].query(t));
                ans_s = 0;
                s = 0;
                t++;
                ut = ff_L[ut];
                us = ut;
            }
            while ((t<<L) + s <= dist) {
                ans_s = max(ans_s, ((t<<L)+s)^a[us]);
                us = ff[us];
                s++;
            }
            ans[id] = max(ans_t, ans_s);
        }
    }
    for (int i = 0; i < q; i++) cout << ans[i] << "\n";
}