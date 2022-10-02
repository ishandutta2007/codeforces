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

const int MAXN = 200100;

vector<int> aa[MAXN];
int num[MAXN];
int id[MAXN];

bool visited[MAXN];
void dfs(int v, int k) {
    // dbg(v, aa[v]);
    num[v] = k;
    visited[v] = true;
    for (int a : aa[v]) {
        if (visited[a]) continue;
        dfs(a, k);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); // Remove in problems with online queries!
    int T;
    cin >> T;
    for (int t = 0; t < T; t++) {
        int N;
        cin >> N;
        for (int i = 1; i <= N; i++) aa[i].clear(), id[i] = 0;
        int M;
        cin >> M;
        int x, y;
        cin >> x >> y;
        for (int i = 0; i < M; i++) {
            int u, v;
            cin >> u >> v;
            aa[u].push_back(v);
            aa[v].push_back(u);
        }
        for (int i = 1; i <= N; i++) num[i] = 0, visited[i] = false;
        visited[x] = true;
        int k = 0;
        for (int a : aa[x]) {
            // dbg(a, visited[a]);
            if (!visited[a]) {
                k++;
                dfs(a, k);
            }
        }
        for (int i = 1; i <= N; i++) if (num[i] != num[y]) id[i] ^= 1;
        // dbg_arr(num, N+1);

        for (int i = 1; i <= N; i++) num[i] = 0, visited[i] = false;
        visited[y] = true;
        k = 0;
        for (int a : aa[y]) {
            if (!visited[a]) {
                k++;
                dfs(a, k);
            }
        }
        // dbg_arr(num, N+1);
        for (int i = 1; i <= N; i++) if (num[i] != num[x]) id[i] ^= 2;

        vector<LL> cnt(4, 0);
        for (int i = 1; i <= N; i++) if (i != x and i != y) cnt[id[i]]++;
        // dbg(N, cnt);
        cout << cnt[0]*cnt[3] + cnt[1]*cnt[2] << "\n";
    }
}