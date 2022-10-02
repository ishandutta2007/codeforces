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

const int MAXN = 1e6 + 100;
int nn[MAXN];
int N;

bool visited[MAXN];
bool open[MAXN];
vector<int> cycle;
bool dfs(int v) {
    visited[v] = true;
    cycle.push_back(v);
    open[v] = true;
    if (visited[nn[v]] and !open[nn[v]]) {
        open[v] = false;
        cycle.pop_back();
        return false;
    }
    if (open[nn[v]]) {
        reverse(cycle.begin(), cycle.end());
        while (cycle.back() != nn[v]) cycle.pop_back();
        return true;
    }
    if (dfs(nn[v])) return true;
    open[v] = false;
    cycle.pop_back();
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); // Remove in problems with online queries!
    int T;
    cin >> T;
    for (int t = 0; t < T; t++) {
        cin >> N;
        for (int i = 1; i <= N; i++) {
            int a;
            cin >> a;
            int x = i-a;
            nn[i] = x;
        }
        cycle.clear();
        for (int i = 1; i <= N; i++) visited[i] = false, open[i] = false;
        for (int i = 1; i <= N; i++) {
            if (!visited[i]) {
                if (dfs(i)) {
                    cout << cycle.size() << "\n";
                    for (int x : cycle) cout << x << " ";
                    cout << "\n";
                    break;
                }
            }
        }
    }
}