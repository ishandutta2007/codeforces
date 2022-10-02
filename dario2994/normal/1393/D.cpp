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

const int MAXN = 2010;
char mat[MAXN][MAXN];
const int INF = 1e9;
int dist[MAXN][MAXN];
int ans[MAXN][MAXN];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); // Remove in problems with online queries!
    int N, M;
    cin >> N >> M;
    for (int i = 0; i < N; i++) for (int j = 0; j < M; j++) {
        cin >> mat[i][j];
        ans[i][j] = min(min(i+1, j+1), min(N-i, M-j));
    }
    // for (char c = 'a'; c <= 'z'; c++) {
        queue<pair<int,int>> q;
        for (int x = 0; x < N; x++) for (int y = 0; y < M; y++) {
            dist[x][y] = INF;
            for (int t = 0; t < 4; t++) {
                int x1 = x + dx[t], y1 = y + dy[t];
                if (x1 < 0 or x1 >= N or y1 < 0 or y1 >= M) continue;
                if (mat[x][y] != mat[x1][y1]) {
                    dist[x][y] = 1;
                    q.push({x, y});
                    break;
                }
            }
        }
        while (!q.empty()) {
            auto pp = q.front();
            q.pop();
            int x = pp.first, y = pp.second;
            for (int t = 0; t < 4; t++) {
                int x1 = x + dx[t], y1 = y + dy[t];
                if (x1 < 0 or x1 >= N or y1 < 0 or y1 >= M) continue;
                if (dist[x1][y1] < INF) continue;
                dist[x1][y1] = dist[x][y] + 1;
                q.push({x1, y1});
            }
        }
        for (int i = 0; i < N; i++) for (int j = 0; j < M; j++) {
            ans[i][j] = min(ans[i][j], dist[i][j]);
        }
    // cout << ans[2][2] << endl;
    LL res = 0;
    for (int i = 0; i < N; i++) for (int j = 0; j < M; j++) res += ans[i][j];
    cout << res << "\n";
}