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

const int MAXN = 101000;
vector<int> aa[MAXN];

int get_dist(int v, int p, int goal) {
    if (v == goal) return 0;
    for (int a: aa[v]) {
        if (a == p) continue;
        int d = get_dist(a, v, goal);
        if (d != -1) return 1+d;
    }
    return -1;
}

int depth[MAXN];
void fill_depth(int v, int p) {
    for (int a: aa[v]) {
        if (a == p) continue;
        depth[a] = 1 + depth[v];
        fill_depth(a, v);
    }
}

void solve() {
    int N;
    int a, b;
    int da, db;
    cin >> N >> a >> b >> da >> db;
    for (int i = 1; i <= N; i++) aa[i].clear();
    for (int i = 0; i < N-1; i++) {
        int u,v;
        cin >> u >> v;
        aa[u].push_back(v);
        aa[v].push_back(u);
    }
    int init_dist = get_dist(a, 0, b);
    if (init_dist <= da) {
        cout << "Alice\n";
        return;
    }
    depth[1] = 0;
    fill_depth(1, 0);
    int best = 1;
    for (int i = 1; i <= N; i++) if (depth[i] > depth[best]) best = i;
    depth[best] = 0;
    fill_depth(best, 0);
    for (int i = 1; i <= N; i++) if (depth[i] > depth[best]) best = i;
    int diam = depth[best];
    db = min(db, diam);
    da = min(da, diam);
    if (2*da >= db) cout << "Alice\n";
    else cout << "Bob\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); // Remove in problems with online queries!

    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) solve();
}