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

const int MAXN = 260;

int N, M;
char G[MAXN][MAXN];
int val[MAXN][MAXN];

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

bool IsOutOrBlocked(int x, int y) {
    if (x < 0 or N <= x) return true;
    if (y < 0 or M <= y) return true;
    return G[x][y] == '*';
}

bool fatto[MAXN][MAXN];
void PropagaRumore(int xx, int yy, int rum) {
    vector<pair<int, int>> visitati;
    queue<pair<pair<int,int>, int>> coda;

    fatto[xx][yy] = true;
    visitati.push_back({xx, yy});
    coda.push({{xx, yy}, rum});
    while (!coda.empty()) {
        auto p = coda.front();
        coda.pop();
        int x = p.first.first;
        int y = p.first.second;
        int r = p.second;
        if (r == 0) continue;
        val[x][y] += r;
        for (int i = 0; i < 4; i++) {
            int x1 = x + dx[i];
            int y1 = y + dy[i];
            int r1 = r/2;
            if (IsOutOrBlocked(x1, y1)) continue;
            if (fatto[x1][y1]) continue;
            
            fatto[x1][y1] = true;
            visitati.push_back({x1, y1});
            coda.push({{x1, y1}, r1});
        }
    }
    for (auto p : visitati) fatto[p.first][p.second] = false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); // Remove in problems with online queries!

    int P, Q;
    cin >> N >> M >> Q >> P;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) cin >> G[i][j];
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if ('A' <= G[i][j] and G[i][j] <= 'Z') {
                int rumore = Q * ((int)(G[i][j] - 'A') + 1);
                PropagaRumore(i, j, rumore);
            }
        }
    }
    int res = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) res += (val[i][j] > P);
    }
    cout << res << "\n";

    // for (int i = 0; i < N; i++) {
        // for (int j = 0; j < M; j++) cout << val[i][j] << " ";
        // cout << endl;
    // }
}