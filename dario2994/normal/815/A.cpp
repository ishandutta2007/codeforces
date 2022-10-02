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

#define INF 1<<30
#define eps 1e-9

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

// This should not compile if used.
const int MAXN = 110;

int N, M;
int val[MAXN][MAXN];
vector<pair<string, int>> moves;

void MoveOnRows() {
    for (int i = 0; i < N; i++) {
        int min_row = 1000;
        for (int j = 0; j < M; j++) MinPlace(min_row, val[i][j]);
        for (int j = 0; j < M; j++) val[i][j] -= min_row;
        for (int k = 0; k < min_row; k++) moves.push_back({"row", i});
    }
}

void MoveOnCols() {
    for (int j = 0; j < M; j++) {
        int min_col = 1000;
        for (int i = 0; i < N; i++) MinPlace(min_col, val[i][j]);
        for (int i = 0; i < N; i++) val[i][j] -= min_col;
        for (int k = 0; k < min_col; k++) moves.push_back({"col", j});
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); // Remove in online problems!
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> val[i][j];
        }
    }

    if (N < M) {
        MoveOnRows();
        MoveOnCols();
    } else {
        MoveOnCols();
        MoveOnRows();
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (val[i][j] != 0) {
                cout << -1 << "\n";
                return 0;
            }
        }
    }

    cout << moves.size() << "\n";
    for (auto m : moves) {
        cout << m.first << " " << (m.second + 1) << "\n";
    }
}