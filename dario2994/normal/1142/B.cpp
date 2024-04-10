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

const int MAXN = 1<<18;
const int MAXL = 19;

int ff[MAXN][MAXL];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); // Remove in problems with online queries!
    int N, M, Q;
    cin >> N >> M >> Q;
    vector<int> P(N);
    for (int i = 0; i < N; i++) cin >> P[i];
    vector<int> nn(N+1);
    for (int i = 0; i < N; i++) nn[P[i]] = P[(i+1)%N];
    vector<int> A(M);
    for (int i = 0; i < M; i++) cin >> A[i];

    vector<int> last_appear(N+1, M);
    for (int i = 0; i < MAXL; i++) ff[M][i] = M;

    for (int i = M-1; i >= 0; i--) {
        int x = A[i];
        ff[i][0] = last_appear[nn[x]];
        last_appear[x] = i;
    }
    for (int j = 1; j < MAXL; j++) {
        for (int i = 0; i < M; i++) {
            ff[i][j] = ff[ff[i][j-1]][j-1];
        }
    }
    vector<int> best(M);
    for (int i = 0; i < M; i++) {
        int it = N-1;
        int ans = i;
        for (int j = MAXL-1; j >= 0; j--) {
            if ((1<<j) <= it) {
                it -= 1<<j;
                ans = ff[ans][j];
            }
        }
        best[i] = ans;
    }
    for (int i = M-2; i >= 0; i--) best[i] = min(best[i], best[i+1]);
    for (int i = 0; i < Q; i++) {
        int l, r;
        cin >> l >> r;
        l--, r--;
        if (best[l] <= r) cout << "1";
        else cout << "0";
    }
    cout << "\n";
}