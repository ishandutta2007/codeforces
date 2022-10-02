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

LL slow_solve(vector<LL> a, vector<vector<int>> aa) {
    int N = aa.size();
    LL res = 0;
    for (int bb = 0; bb < (1<<N); bb++) {
        set<int> good;
        for (int i = 0; i < N; i++) {
            if ((bb&(1<<i)) == 0) continue;
            for (int x: aa[i]) good.insert(x);
        }
        LL sum = 0;
        for (int x: good) sum += a[x];
        res = __gcd(res, sum);
    }
    return res;
}

void solve() {
    int N, M;
    cin >> N >> M;
    vector<LL> a(N);
    vector<vector<int>> vec(N);
    vector<vector<int>> aa(N);
    for (int i = 0; i < N; i++) cin >> a[i];
    for (int i = 0; i < M; i++) {
        int u,v;
        cin >> u >> v;
        u--, v--;
        aa[u].push_back(v);
    }
    for (int i = 0; i < N; i++) {
        for (int j: aa[i]) vec[j].push_back(i);
    }
    auto ord = SortIndex(N, [&](int i, int j) {return vec[i] < vec[j]; });
    LL res = 0;
    for (int it = 0; it < N; it++) {
        int i = ord[it];
        LL sum = a[i];
        while (it < N-1 and vec[ord[it+1]] == vec[i]) {
            sum += a[ord[it+1]];
            it++;
        }
        if (!vec[i].empty()) res = __gcd(res, sum);
    }
    cout << res << "\n";
    // cout << slow_solve(a, aa) << endl;
}


int main() {
    // LL a = 3*45543598345981ll;
    // LL b = 5*45543598345981ll;
    // cout << __gcd(a, b) << endl;
    // return 0;
    
    ios::sync_with_stdio(false);
    cin.tie(0); // Remove in problems with online queries!

    int T;
    cin >> T;
    for (int i = 0; i < T; i++) solve();
}