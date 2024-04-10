#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;

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

#if DEBUG && !ONLINE_JUDGE
    ifstream input_from_file("input.txt");
    #define cin input_from_file
    #define endl "\n";

    #define dbg_var(x) clog << #x  << ": " << x << endl;
    #define dbg_vec(x) clog << #x << ": " << print_iterable(x.begin(), x.end(), -1) << endl;
    #define dbg_array(x, len) clog << #x << ": " << print_iterable(x, x+len, -1) << endl;
#else
    #define dbg_var(x) 
    #define dbg_vec(x)
    #define dbg_array(x, len)
#endif

///////////////////////////////////////////////////////////////////////////
//////////////////// DO NOT TOUCH BEFORE THIS LINE ////////////////////////
///////////////////////////////////////////////////////////////////////////

// This should not compile if used.
const int MAXN = 1000010;
vector<int> aa[MAXN];
int deg[MAXN];
LL N, M, L;

bool visited[MAXN];
bool to_visit[MAXN];

void dfs(int v) {
    visited[v] = 1;
    for (int a: aa[v]) {
        if (visited[a]) continue;
        dfs(a);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin >> N >> M;
    L = 0;
    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        to_visit[u] = true;
        to_visit[v] = true;
        if (u == v) L++;
        else {
            aa[u].push_back(v);
            aa[v].push_back(u);
            deg[u]++;
            deg[v]++;
        }
    }
    if (M < 2) {
        cout << 0;
        return 0;
    }
    for (int i = 0; i < N; i++) {
        if (to_visit[i] == false) continue;
        dfs(i);
        break;
    }
    for (int i = 0; i < N; i++) {
        if (to_visit[i] and !visited[i]) {
            cout << 0;
            return 0;
        }
    }
    LL sumdeg = 0;
    for (int i = 0; i < N; i++) {
        LL d = deg[i];
        if (d == 0) continue;
        sumdeg += (d * (d-1ll)) / 2ll;
    }
    cout << sumdeg + L*(M-L) + (L*(L-1ll)) / 2ll;
}