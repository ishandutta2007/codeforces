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

const int MAXN = 1e6;
vector<int> aa[MAXN];
vector<int> ww[MAXN];
int depth[MAXN];

void dfs(int v, int father) {
    for (int a: aa[v]) {
        if (a == father) continue;
        depth[a] = depth[v] + 1;
        dfs(a, v);
    }
}

// int worst;
// void checking(int path, int v, int father) {
    // path ^= v;
    // dbg(path, v, father);
    // worst = max(worst, path);
    // for (int i = 0; i < SZ(aa[v]); i++) {
        // int w = ww[v][i];
        // int a = aa[v][i];
        // if (a == father) continue;
        // dbg(v, a, w, path^w);
        // worst = max(worst, path^w);
        // checking(path^w, a, v);
    // }
// }

void solve() {
    int p;
    cin >> p;
    int n = 1 << p;
    vector<int> from(n-1), to(n-1);
    for (int i = 0; i < n-1; i++) {
        cin >> from[i] >> to[i];
        aa[from[i]].push_back(to[i]);
        aa[to[i]].push_back(from[i]);
    }
    dfs(n, -1);

    
    cout << n << "\n";
    // v < n
    // odd depth -> v
    // even depth -> n + v
    for (int v = 1; v <= n; v++) {
        if (v == n) cout << n << "\n";
        else if (depth[v] % 2) cout << v << " ";
        else cout << v + n << " ";
    }

    // dbg_arr1(depth, n);
    for (int i = 0; i < n-1; i++) {
        int x = (depth[from[i]] < depth[to[i]]) ? to[i] : from[i];
        if (depth[x] % 2) cout << n + x << " ";
        else cout << x << " ";
        // ww[from[i]].push_back(z);
        // ww[to[i]].push_back(z);
    }
    cout << "\n";

    // worst = 0;
    // checking(0, n, -1);
    // cout << "ANS = " << worst << endl;

    for (int v = 1; v <= n; v++) aa[v].clear(), depth[v] = 0, ww[v].clear();
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); // Remove in problems with online queries!

    int t;
    cin >> t;
    while (t--) solve();
}