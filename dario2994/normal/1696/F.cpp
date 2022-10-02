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

const int MAXN = 110;
vector<int> aa[MAXN];
int dist[MAXN][MAXN];

void dfs(int v, int p, int source) {
    for (int a: aa[v]) {
        if (a == p) continue;
        dist[source][a] = 1 + dist[source][v];
        dfs(a, v, source);
    }
}

int label[MAXN][MAXN];

int get_label(int v, int i) {
    int* q = label[v];
    if (q[i] != q[q[i]]) q[i] = get_label(v, q[i]);
    return q[i];
}

void join(int v, int i, int j) {
    i = get_label(v, i);
    j = get_label(v, j);
    if (i == j) return;

    if (rand() % 2) swap(i, j);
    label[v][i] = j;
}

void solve() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) aa[i].clear();
    for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++) label[i][j] = j;

    vector<vector<string>> ss(n+1, vector<string>(n+1));
    for (int i = 1; i <= n; i++) for (int j = 1; j <= n-i; j++) {
        cin >> ss[i][j];
        for (int k = 1; k <= n; k++) {
            if (ss[i][j][k-1] == '1') join(k, i, i+j);
        }
    }

    for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++) get_label(i, j);
    // cout << label[2][1] << " " << label[2][3] << endl;


    vector<bool> alive(n+1, true);
    vector<int> matching(n+1, 0);
    for (int _ = 0; _ < n-1; _++) {
        bool found = false;
        for (int i = 1; i <= n && !found; i++)
        for (int j = i+1; j <= n && !found; j++) {
            if (!alive[i] or !alive[j]) continue;
            bool works = true;
            for (int z = 1; z <= n; z++) matching[z] = 0;
            for (int k = 1; k <= n and works; k++) {
                if (!alive[k] or k == i or k == j) continue;
                if (!matching[label[i][k]]) {
                    matching[label[i][k]] = label[j][k];
                }
                works &= matching[label[i][k]] == label[j][k];
            }
            // dbg(_, i, j, works);
            if (!works) continue;
            // dbg(i, j);

            for (int z = 1; z <= n; z++) matching[z] = 0;
            for (int k = 1; k <= n and works; k++) {
                if (!alive[k] or k == i or k == j) continue;
                if (!matching[label[j][k]]) {
                    matching[label[j][k]] = label[i][k];
                }
                works &= matching[label[j][k]] == label[i][k];
            }
            
            if (!works) continue;

            bool i_is_alone = true;
            bool j_is_alone = true;
            for (int k = 1; k <= n; k++) {
                if (!alive[k]) continue;
                if (k != i and label[j][k] == label[j][i]) i_is_alone = false;
                if (k != j and label[i][k] == label[i][j]) j_is_alone = false;
            }
            // dbg(i_is_alone, j_is_alone);
            if (i_is_alone and j_is_alone and _ != n-2) continue;
            // dbg(_, i, j);
            if (i_is_alone) {
                aa[i].push_back(j);
                aa[j].push_back(i);
                alive[j] = false;
                found = true;
            } else if (j_is_alone) {
                aa[i].push_back(j);
                aa[j].push_back(i);
                alive[i] = false;
                found = true;
            }
        }
        if (!found) {
            cout << "No\n";
            return;
        }
    }

    for (int v = 1; v <= n; v++) dfs(v, 0, v);

    // dbg(aa[1], aa[2], aa[3]);
    // cout << dist[1][1] << " " << dist[1][2] << " " << dist[2][1] << " " << dist[2][2] << endl;

    for (int i = 1; i <= n; i++) for (int j = 1; j <= n-i; j++) {
        for (int k = 1; k <= n; k++) {
            if ((dist[i][k] == dist[i+j][k]) != (ss[i][j][k-1] == '1')) {
                cout << "No\n";
                return;
            }
        }
    }
    cout << "Yes\n";
    for (int v = 1; v <= n; v++) {
        for (int a: aa[v]) {
            if (v < a) cout << v << " " << a << "\n";
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); // Remove in problems with online queries!

    int t;
    cin >> t;
    while (t--) solve();
}