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

int din[12+1][1<<12];
int best[12][1<<12];
vector<int> subset[1<<12];
int good[12][12];

void solve() {
    int n, m;
    cin >> n >> m;
    // dbg(n, m);
    vector<vector<int>> vec(m, vector<int>(n, 0));
    vector<int> val(m, 0);
    for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) {
        // dbg(i, j);
        cin >> vec[j][i];
        val[j] = max(val[j], vec[j][i]);
    }
    vector<int> ord = SortIndex(m, [&val](int i, int j) { return val[i] > val[j]; });
    for (int i = 0; i < min(n, m); i++) for (int j = 0; j < n; j++) good[i][j] = vec[ord[i]][j];
    for (int i = 0; i < min(n, m); i++) {
        for (int b = 0; b < (1<<n); b++) {
            int res = 0;
            for (int k = 0; k < n; k++) {
                int ris = 0;
                for (int j = 0; j < n; j++) if (b&(1<<j)) ris += good[i][(k+j)%n];
                res = max(ris, res);
            }
            best[i][b] = res;
        }
    }
    
    for (int k = 1; k <= min(n, m); k++) for (int b = 0; b < (1<<n); b++) {
        din[k][b] = 0;
        if (b%2 == 0) {
            din[k][b] = din[k][b/2];
            continue;
        }
        for (int c : subset[b]) {
            din[k][b] = max(din[k][b], best[k-1][c] + din[k-1][b^c]);
        }
    }
    cout << din[min(n, m)][(1<<n)-1] << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); // Remove in problems with online queries!
    for (int i = 0; i < (1<<12); i++) {
        for (int j = 0; j < (1<<12); j++) {
            if ((i&j) == i) subset[j].push_back(i);
        }
    }
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) solve();
}