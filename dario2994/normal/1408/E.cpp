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

const int MAXN = 201000;
int anc[MAXN];
int sz[MAXN];

int ancestor(int v) {
    if (anc[anc[v]] != anc[v]) anc[v] = ancestor(anc[v]);
    return anc[v];
}

bool join(int u, int v) {
    u = ancestor(u), v = ancestor(v);
    if (u == v) return false;

    if (sz[u] < sz[v]) swap(u, v);

    sz[u] += sz[v];
    anc[v] = u;
    
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); // Remove in problems with online queries!

    int M, N;
    cin >> M >> N;
    vector<LL> A(M), B(N);
    // LL suma = 0, sumb = 0;
    for (int i = 0; i < M; i++) cin >> A[i];
    for (int i = 0; i < N; i++) cin >> B[i];

    for (int i = 0; i < N+M; i++) anc[i] = i, sz[i] = 1;

    LL tot_sum = 0;

    LL sum = 0;
    vector<pair<LL,pair<int,int>>> edges;

    for (int i = 0; i < M; i++) {
        int q;
        cin >> q;
        for (int j = 0; j < q; j++) {
            int x;
            cin >> x;
            edges.push_back({A[i] + B[x-1], {i, x + M-1}});
            tot_sum += A[i] + B[x-1];
        }
    }

    sort(edges.begin(), edges.end());
    reverse(edges.begin(), edges.end());
    for (auto pp: edges) {
        LL cost = pp.first;
        int u = pp.second.first, v = pp.second.second;
        if (join(u, v)) sum += cost;
    }
    cout << tot_sum - sum << "\n";
}