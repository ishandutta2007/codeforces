#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define SZ(x) ((int)((x).size()))

// Returns the time elapsed in nanoseconds from 1 January 1970, at 00:00:00.
LL get_time() {
    return chrono::duration_cast<chrono::nanoseconds>(
        chrono::steady_clock::now().time_since_epoch())
        .count();
}

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

const int MAXN = 601;
struct Edge {
    int to;
    int cost;
};

vector<Edge> aa[MAXN];

int N;
int vec[MAXN];
void compute(int v, int t) {
    t %= N;
    for (int i = 0; i < N; i++) vec[i] = 2e9;
    int best = 0;
    for (auto e: aa[v]) {
        int id = (e.to + t) % N;
        vec[id] = e.cost;
        if (vec[id] < vec[best]) best = id;
    }

    int enz = (best + N-1)%N;
    for (int i = best; i != enz; i = (i+1)%N) {
        int j = (i+1)%N;
        vec[j] = min(vec[j], vec[i]+1);
    }
}

int dist[MAXN];
bool processed[MAXN];
void solve(int source) {
    for (int v = 0; v < N; v++) processed[v] = false, dist[v] = 2e9;
    dist[source] = 0;
    for (int _ = 0; _ < N; _++) {
        int u = -1;
        for (int v = 0; v < N; v++) {
            if (!processed[v] and (u == -1 or dist[v] < dist[u])) u = v;
        }
        processed[u] = true;
        compute(u, dist[u]);
        for (int v = 0; v < N; v++) dist[v] = min(dist[v], dist[u] + vec[v]);
    }
    for (int v = 0; v < N; v++) cout << dist[v] << " ";
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); // Remove in problems with online queries!

    int m;
    cin >> N >> m;
    for (int i = 0; i < m; i++) {
        Edge e;
        int v;
        cin >> v >> e.to >> e.cost;
        aa[v].push_back(e);
    }
    
    for (int v = 0; v < N; v++) solve(v);
}