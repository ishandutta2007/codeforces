#define _USE_MATH_DEFINES
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

template <typename Container>
int SZ(const Container& S) { return S.size(); }

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

#if DEBUG && !ONLINE_JUDGE
    ifstream input_from_file("input.txt");
    #define cin input_from_file

    #define dbg_var(x) clog << #x  << ": " << x << endl;
    #define dbg_array(x, len) clog << #x << ": " << print_iterable(x, x+len, -1) << endl;
#else
    #define dbg_var(x)
    #define dbg_array(x, len)
#endif

///////////////////////////////////////////////////////////////////////////
//////////////////// DO NOT TOUCH BEFORE THIS LINE ////////////////////////
///////////////////////////////////////////////////////////////////////////

const int MAXN = 100100;
const int MAXM = 11;
int perm[MAXM][MAXN];
int invperm[MAXM][MAXN];
int has_prev[MAXN];
int len[MAXN];
int N, M;

int get_next(int x, int q) {
    return perm[q][invperm[q][x]+1];
}

int dfs(int x) {
    if (len[x] > 0) return len[x];
    len[x] = 1;
    int succ = get_next(x, 0);
    if (succ > N) return 1;
    for (int i = 1; i < M; i++) {
        if (get_next(x, i) != succ) return 1;
    }
    has_prev[succ] = true;
    len[x] += dfs(succ);
    return len[x];
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); // Remove in problems with online queries!
    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> perm[i][j];
            invperm[i][perm[i][j]] = j;
        }
        perm[i][N+1] = N + 100;
    }
    for (int i = 1; i <= N; i++) dfs(i);
    LL res = 0;
    for (int i = 1; i <= N; i++) {
        if (!has_prev[i]) {
            LL x = len[i];
            res += x*(x+1)/2;
        }
    }
    cout << res << "\n";
}