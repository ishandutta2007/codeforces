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

const int MAXN = 2e5 + 10;
LL a[MAXN];
bool S[MAXN];
bool T[MAXN];
vector<int> aa[MAXN];

LL res = 0;

int dfs(int v, int p, LL cost) {
    cost = min(cost, a[v]);
    int cntS = S[v];
    int cntT = T[v];
    for (int a: aa[v]) {
        if (a == p) continue;
        int remainder = dfs(a, v, cost);
        if (remainder < 0) cntS -= remainder;
        else cntT += remainder;
    }
    // dbg(v, cntS, cntT, cost);
    int k = min(cntS, cntT);
    res += 2*k * cost;
    return cntT - cntS;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); // Remove in problems with online queries!

    int cntS = 0, cntT = 0;
    int N;
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> a[i];
        int before, after;
        cin >> before >> after;
        if (before && !after) S[i] = true, cntS++;
        if (!before && after) T[i] = true, cntT++;
    }
    if (cntS != cntT) {
        cout << -1 << "\n";
        return 0;
    }

    for (int i = 1; i < N; i++) {
        int a, b;
        cin >> a >> b;
        aa[a].push_back(b);
        aa[b].push_back(a);
    }
    dfs(1, 0, 1e10);

    cout << res << "\n";
}