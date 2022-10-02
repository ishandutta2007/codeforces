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


const int MAXN = 5100;
int color[MAXN];
vector<int> aa[MAXN];
int comp[MAXN];
bool works = true;
pair<int,int> curr;
int curr_comp = 0;
int ans[MAXN];
void dfs(int v) {
    comp[v] = curr_comp;
    if (color[v] == 1) curr.first++;
    else curr.second++;
    for (int a: aa[v]) {
        if (!color[a]) {
            color[a] = 3-color[v];
            dfs(a);
        }
        if (color[a] + color[v] != 3) works = false;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); // Remove in problems with online queries!

    int N, M;
    cin >> N >> M;
    int n1, n2, n3;
    cin >> n1 >> n2 >> n3;
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        aa[a].push_back(b);
        aa[b].push_back(a);
    }
    vector<pair<int,int>> sz;
    for (int v = 1; v <= N; v++) {
        if (color[v]) continue;
        curr = {0, 0};
        color[v] = 1;
        dfs(v);
        sz.push_back(curr);
        curr_comp++;
    }
    if (!works) {
        cout << "NO" << "\n";
        return 0;
    }
    int L = sz.size();
    assert(L == curr_comp);
    vector<vector<bool>> reachable(L+1, vector<bool>(N+1, false));
    reachable[0][0] = true;
    for (int it = 0; it < L; it++) {
        int x = sz[it].first, y = sz[it].second;
        for (int i = 0; i <= N; i++) {
            if (i >= y and reachable[it][i-y]) reachable[it+1][i] = true;
            if (i >= x and reachable[it][i-x]) reachable[it+1][i] = true;
        }
    }
    if (!reachable[L][n2]) {
        cout << "NO" << "\n";
        return 0;
    }

    // dbg(sz);
    for (int it = L-1; it >= 0; it--) {
        int x = sz[it].first, y = sz[it].second;
        // dbg(it, x, y, n1, n2, n3);
        if (n2 >= x and reachable[it][n2-x]) {
            for (int v = 1; v <= N; v++) {
                if (comp[v] == it) {
                    if (color[v] == 1) ans[v] = 2;
                    else {
                        if (n1 > 0) {
                            ans[v] = 1;
                            n1--;
                        } else {
                            ans[v] = 3;
                            n3--;
                        }
                    }
                }
            }
            n2 -= x;
        } else {
            for (int v = 1; v <= N; v++) {
                if (comp[v] == it) {
                    if (color[v] == 2) ans[v] = 2;
                    else {
                        if (n1 > 0) {
                            ans[v] = 1;
                            n1--;
                        } else {
                            ans[v] = 3;
                            n3--;
                        }
                    }
                }
            }
            n2 -= y;
        }
    }
    assert(n1 == 0 and n2 == 0 and n3 == 0);
    cout << "YES\n";
    for (int v = 1; v <= N; v++) cout << ans[v];
    cout << "\n";
}