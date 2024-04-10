#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define SZ(x) ((int)((x).size()))

template <typename T1, typename T2>
string print_iterable(T1 begin_iter, T2 end_iter, int counter) {
    bool done_something = false;
    stringstream res;
    res << "[";
    for (; begin_iter != end_iter and counter; ++begin_iter) {
        done_something = true;
        counter--;
        res << *begin_iter << ", ";
    }
    string str = res.str();
    if (done_something) {
        str.pop_back();
        str.pop_back();
    }
    str += "]";
    return str;
}

vector<int> SortIndex(int size, std::function<bool(int, int)> compare) {
    vector<int> ord(size);
    for (int i = 0; i < size; i++) ord[i] = i;
    sort(ord.begin(), ord.end(), compare);
    return ord;
}

template <typename T>
bool MinPlace(T& a, const T& b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}

template <typename T>
bool MaxPlace(T& a, const T& b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}

template <typename S, typename T>
ostream& operator <<(ostream& out, const pair<S, T>& p) {
    out << "{" << p.first << ", " << p.second << "}";
    return out;
}

template <typename T>
ostream& operator <<(ostream& out, const vector<T>& v) {
    out << "[";
    for (int i = 0; i < (int)v.size(); i++) {
        out << v[i];
        if (i != (int)v.size()-1) out << ", ";
    }
    out << "]";
    return out;
}

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
    #define dbg_arr(x, len) clog << #x << ": " << print_iterable(x, x+len, -1) << endl;
#else
    #define dbg(...)
    #define dbg_arr(x, len)
#endif

///////////////////////////////////////////////////////////////////////////
//////////////////// DO NOT TOUCH BEFORE THIS LINE ////////////////////////
///////////////////////////////////////////////////////////////////////////

struct Edge {
    int u, v, id;
    int t;
};

int N, Q;
const int MAXN = 1<<19; // 1<<19;
int dep[MAXN];
vector<int> aa[MAXN];
vector<int> ids[MAXN];
Edge edges[MAXN];
int queries[MAXN];
vector<int> prequery;
void dfs(int v, int p) {
    for (int a: aa[v]) {
        if (a == p) continue;
        dep[a] = dep[v]+1;
        dfs(a, v);
    }
}

int from[MAXN];
int to[MAXN];

int cnt;
int dist[MAXN];
int ff0[2*MAXN], ff1[2*MAXN];
void preproc(int v, int p) {
    cnt++;
    int id = cnt;
    ff0[MAXN+id] = dist[v];
    for (int i = 0; i < SZ(aa[v]); i++) {
        int a = aa[v][i];
        if (a == p) continue;
        dist[a] = dist[v]+1;
        from[ids[v][i]] = cnt+1;
        preproc(a, v);
        to[ids[v][i]] = cnt;
    }
}

bool flag[2*MAXN];
void f(int v, int l, int r, int a, int b) {
    if (a <= l and r <= b) {
        swap(ff0[v], ff1[v]);
        flag[v] ^= 1;
        return;
    }
    if (r < a or b < l) return;
    if (flag[v]) {
        flag[v] = false;
        swap(ff0[2*v], ff1[2*v]);
        swap(ff0[2*v+1], ff1[2*v+1]);
        flag[2*v] ^= 1, flag[2*v+1] ^= 1;
    }
    int m = (l+r)/2;
    f(2*v, l, m, a, b);
    f(2*v+1, m+1, r, a, b);
    ff0[v] = max(ff0[2*v], ff0[2*v+1]);
    ff1[v] = max(ff1[2*v], ff1[2*v+1]);
}

void process(int x) {
    f(1, 0, MAXN-1, from[x], to[x]);
}

vector<int> solve(int root) {
    dist[root] = 0;
    cnt = 0;
    for (int i = 1; i < 2*MAXN; i++) ff0[i] = ff1[i] = 0, flag[i] = false;
    preproc(root, -1);
    for (int i = MAXN-1; i >= 1; i--) {
        ff0[i] = max(ff0[2*i], ff0[2*i+1]);
    }
    // for (int i = 1; i <= N-1; i++) dbg(i, from[i], to[i]);
    for (int q: prequery) process(q);
    vector<int> ans(Q);
    for (int q = 0; q < Q; q++) {
        // dbg(from[queries[q]], to[queries[q]]);
        // dbg("BEFORE");
        // for (int i = 1; i < 2*MAXN; i++) dbg(i, ff0[i], ff1[i], flag[i]);
        process(queries[q]);
        // dbg("AFTER");
        // for (int i = 1; i < 2*MAXN; i++) dbg(i, ff0[i], ff1[i]);
        // exit(0);
        ans[q] = ff0[1];
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); // Remove in problems with online queries!

    cin >> N;
    for (int i = 0; i < N-1; i++) {
        int u, v, t;
        cin >> u >> v >> t;
        aa[u].push_back(v);
        aa[v].push_back(u);
        // dbg(u, v);
        ids[u].push_back(i+1);
        ids[v].push_back(i+1);
        if (t) prequery.push_back(i+1);
    }
    dfs(1, 0);
    int A = 1;
    for (int v = 2; v <= N; v++) if (dep[v] > dep[A]) A = v;
    dep[A] = 0;
    dfs(A, 0);
    int B = 1;
    for (int v = 2; v <= N; v++) if (dep[v] > dep[B]) B = v;

    cin >> Q;
    for (int i = 0; i < Q; i++) cin >> queries[i];

    vector<int> ans1 = solve(A);
    // dbg(ans1);
    vector<int> ans2 = solve(B);
    // dbg(ans2);
    // dbg(A, B);
    // dbg(ans1, ans2);
    for (int i = 0; i < Q; i++) cout << max(ans1[i], ans2[i]) << "\n";
}