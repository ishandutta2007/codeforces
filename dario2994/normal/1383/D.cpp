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


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); // Remove in problems with online queries!

    int H, W;
    cin >> H >> W;
    vector<bool> is_row(H*W+1);
    vector<bool> is_col(H*W+1);
    vector<int> mrow(H, 0), mcol(W, 0);
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            int x;
            cin >> x;
            mrow[i] = max(mrow[i], x);
            mcol[j] = max(mcol[j], x);
        }
    }
    for (int i = 0; i < H; i++) is_row[mrow[i]] = true;
    for (int j = 0; j < W; j++) is_col[mcol[j]] = true;

    int r = 0;
    int c = 0;
    vector<vector<int>> ans(H, vector<int>(W));
    queue<pair<int,int>> cells;
    for (int z = H*W; z >= 1; z--) {
        if (!is_row[z] and !is_col[z]) {
            auto pp = cells.front();
            cells.pop();
            ans[pp.first][pp.second] = z;
            continue;
        }
        if (is_row[z] and is_col[z]) {
            for (int j = c-1; j >= 0; j--) cells.push({r, j});
            for (int i = r-1; i >= 0; i--) cells.push({i, c});
            ans[r][c] = z;
            r++, c++;
            continue;
        }
        if (is_row[z]) {
            for (int j = c-2; j >= 0; j--) cells.push({r, j});
            ans[r][c-1] = z;
            r++;
        }
        if (is_col[z]) {
            for (int i = r-2; i >= 0; i--) cells.push({i, c});
            ans[r-1][c] = z;
            c++;
        }
    }
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) cout << ans[i][j] << " ";
        cout << "\n";
    }

    // return 0;
    for (int i = 0; i < H; i++) {
        bool decreasing = false;
        for (int j = 1; j < W; j++) {
            decreasing |= ans[i][j-1] > ans[i][j];
            if (decreasing) assert(ans[i][j-1] > ans[i][j]);
        }
    }
    for (int j = 0; j < W; j++) {
        bool decreasing = false;
        for (int i = 1; i < H; i++) {
            decreasing |= ans[i-1][j] > ans[i][j];
            if (decreasing) assert(ans[i-1][j] > ans[i][j]);
        }
    }

    vector<int> mrow2(H, 0), mcol2(W, 0);
    for (int i = 0; i < H; i++) for (int j = 0; j < W; j++) {
        mrow2[i] = max(mrow2[i], ans[i][j]);
        mcol2[j] = max(mcol2[j], ans[i][j]);
    }
    sort(mrow.begin(), mrow.end());
    sort(mcol.begin(), mcol.end());
    sort(mrow2.begin(), mrow2.end());
    sort(mcol2.begin(), mcol2.end());
    assert(mrow == mrow2);
    assert(mcol == mcol2);
}