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
    int a, b;
    LL w;
};

const int MAXN = 201000;
int aa[MAXN];

int ancestor(int x) {
    if (aa[aa[x]] != aa[x]) aa[x] = ancestor(aa[x]);
    return aa[x];
}

void solve() {
    int n, m;
    LL k;
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++) aa[i] = i;
    vector<Edge> edges(m);
    for (int i = 0; i < m; i++) {
        Edge e;
        cin >> e.a >> e.b >> e.w;
        edges[i] = e;
    }
    sort(edges.begin(), edges.end(), [&](Edge e1, Edge e2) { return max(e1.w-k, 0ll) < max(e2.w-k, 0ll); });

    LL cost = 0;
    for (int i = 0; i < m; i++) {
        Edge e = edges[i];
        int a = ancestor(e.a);
        int b = ancestor(e.b);
        LL c = max(0ll, e.w-k);
        if (a == b) continue;
        cost += c;
        aa[a] = b;
    }
    if (cost != 0) cout <<  cost << "\n";
    else {
        LL ans = 1e18;
        for (Edge e: edges) ans = min(ans, llabs(e.w-k));
        cout << ans << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); // Remove in problems with online queries!

    int T;
    cin >> T;

    for (int t = 0; t < T; t++) solve();
}