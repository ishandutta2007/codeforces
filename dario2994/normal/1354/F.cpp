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

void solve() {
    int N, K;
    cin >> N >> K;
    vector<int> a(N);
    vector<int> b(N);
    for (int i = 0; i < N; i++) cin >> a[i] >> b[i];
    vector<int> ord = SortIndex(N, [&](int i, int j) { return b[i] < b[j]; });
    vector<vector<int>> din(N+1, vector<int>(N+1, -1e9));
    din[0][0] = 0;
    for (int i = 0; i < N; i++) {
        int it = ord[i];
        din[i+1][0] = din[i][0] + (K-1)*b[it];
        for (int j = 1; j <= N; j++) {
            din[i+1][j] = max(din[i][j] + (K-1)*b[it], din[i][j-1] + (j-1)*b[it] + a[it]);
        }
    }
    vector<bool> destroyed(N+1, false);
    int cnt = K;
    for (int i = N-1; i >= 0; i--) {
        int it = ord[i];
        if (din[i+1][cnt] == din[i][cnt] + (K-1)*b[it]) {
            destroyed[i] = true;
        } else cnt--;
    }
    assert(cnt == 0);

    vector<int> ans;
    int last;
    for (int i = 0; i < N; i++) {
        if (!destroyed[i]) {
            if (SZ(ans) < K-1) ans.push_back(ord[i] + 1);
            else last = ord[i];
        }
    }
    for (int i = 0; i < N; i++) {
        if (destroyed[i]) {
            ans.push_back(ord[i] + 1);
            ans.push_back(-ord[i] - 1);
        }
    }
    ans.push_back(last + 1);

    cout << ans.size() << "\n";
    for (int x: ans) cout << x << " ";
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); // Remove in problems with online queries!

    int T;
    cin >> T;
    for (int t = 0; t < T; t++) solve();
}