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

const int MAXN = 510;
const int MAXM = 510;

bool seen[MAXN];
int C[MAXM];

const LL mod = 998244353;
LL din[MAXM][MAXM];
int fo[MAXN], lo[MAXN];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); // Remove in problems with online queries!
    int N, M;
    cin >> N >> M;
    for (int i = 1; i <= M; i++) {
        cin >> C[i];
        if (fo[C[i]] == 0) fo[C[i]] = i;
        lo[C[i]] = i; 
    }
    // bool possible = true;
    // vector<int> vals = {0};
    // for (int i = 1; i <= M; i++) {
        // cin >> C[i];
        // while (vals.back() >= C[i]) {
            // int x = vals.back();
            // if (x != C[i]) seen[x] = true;
            // vals.pop_back();
        // }
        // if (seen[C[i]]) possible = false;
        // vals.push_back(C[i]);
    // }
    // if (!possible) {
        // cout << 0 << "\n";
        // return 0;
    // }

    for (int i = 1; i <= M+5; i++) din[i][i-1] = 1;
    for (int l = 1; l <= M; l++) for (int i = 1; i+l-1 <= M; i++) {
        int j = i+l-1;
        bool works = true;
        int m = N+1;
        for (int k = i; k <= j; k++) {
            if (fo[C[k]] < i or lo[C[k]] > j) works = false;
            m = min(m, C[k]);
        }
        if (!works) continue;
        LL ris = 1;
        LL pref = 0;
        LL suff = 0;
        int ff = 1000;
        int ll = -1;
        for (int k = i; k <= j; k++) {
            if (C[k] == m) ff = min(ff, k), ll = max(ll, k);
        }
        // dbg(ris, pref, suff, ff, ll);
        for (int k = i; k <= ff; k++) pref += din[i][k-1]*din[k][ff-1] % mod;
        pref %= mod;
        for (int k = j; k >= ll; k--) suff += din[ll+1][k]*din[k+1][j] % mod;
        suff %= mod;
        // dbg(pref, suff);
        int la = -1;
        for (int k = i; k <= j; k++) {
            if (C[k] != m) continue;
            if (la != -1 and la != k-1) ris = ris * din[la+1][k-1] % mod;
            la = k;
        }
        din[i][j] = (pref * suff % mod) * ris % mod;
    }
    cout << din[1][M] << "\n";
}