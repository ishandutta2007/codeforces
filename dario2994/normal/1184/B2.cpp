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

const int MAXN = 150;
const int INF  = 1e9 + 10;
int dist[MAXN][MAXN];

struct SS {
    int x, a, f;
};

struct BB {
    int x, d;
};

bool can_attack(SS S, BB B) {
    return S.a >= B.d and dist[S.x][B.x] <= S.f;
}



class MaximumMatching {
  public:
    const static int NOT_MATCHED = -1;
    // The edges vector stores the edges that goes from left to right.
    MaximumMatching(int left_num, int right_num, const vector<vector<int>>& edges) :
            left_num(left_num),
            right_num(right_num),
            edges(edges),
            computed_matching(false),
            matching_size(0),
            left2right(left_num, NOT_MATCHED),
            right2left(right_num, NOT_MATCHED) {}

    // Get matching size.
    int GetSize() {
        ComputeMaximumMatching();
        return matching_size;
    }

    vector<int> GetMatching() {
        ComputeMaximumMatching();
        return left2right;
    }
  private:
    int left_num;
    int right_num;
    // Edges go from left vertices to right vertices. 
    const vector<vector<int>>& edges;  // Not owned.
    // Whether the matching has already been computed.
    bool computed_matching;
    int matching_size;
    // If the a-th left vertex is matched to the b-th right then
    // left2right[a] = b. If the a-th left vertex is not matched to any
    // right vertex then left2right[a] = NOT_MATCHED.
    // The same (inverting left and right) is true for right2left. 
    vector<int> left2right;  // size = left_num.
    vector<int> right2left;  // size = right_num.

    // Tries to find an augmenting path starting from the left vertex v.
    // Returns true if it has found an augmenting path, false otherwise.
    bool FindAugmentingPath(
            int v, vector<bool>& left_done, vector<bool>& right_done){
        if (left_done[v]) return false;
        left_done[v] = true;

        for (int a : edges[v]) {
            if (right_done[a] or left2right[v] == a) continue;
            right_done[a] = true;

            if (right2left[a] == NOT_MATCHED ||
                FindAugmentingPath(right2left[a], left_done, right_done)) {
                right2left[a] = v;
                left2right[v] = a;
                return true;
            }
        }
        return false;
    }

    // Computes the maximum matching and stores the result in left2right and
    // right2left.
    void ComputeMaximumMatching() {
        if (computed_matching) return;

        bool matching_augmented = true;
        while (matching_augmented) {
            matching_augmented = false;
            vector<bool> left_done(left_num, false);
            vector<bool> right_done(right_num, false);
            for (int v = 0; v < left_num; v++) {
                if (left2right[v] == NOT_MATCHED) {
                    bool updated = FindAugmentingPath(v, left_done, right_done);
                    matching_augmented |= updated;
                    matching_size += updated;
                }
            }
        }
        computed_matching = true;
    }
};

const int MaximumMatching::NOT_MATCHED;  // Needed for the linker.

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); // Remove in problems with online queries!

    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++) dist[i][j] = INF;
    for (int i = 1; i <= n; i++) dist[i][i] = 0;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        dist[u][v] = 1;
        dist[v][u] = 1;
    }
    for (int k = 1; k <= n; k++) for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++) dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
    int s, b;
    LL k, h;
    cin >> s >> b >> k >> h;
    vector<SS> spaces(s);
    vector<BB> bases(b);
    for (SS& S : spaces) cin >> S.x >> S.a >> S.f;
    for (BB& B : bases) cin >> B.x >> B.d;

    vector<vector<int>> edges(s);
    for (int i = 0; i < s; i++) for (int j = 0; j < b; j++) {
        if (can_attack(spaces[i], bases[j])) edges[i].push_back(j);
    }
    LL MF = MaximumMatching(s, b, edges).GetSize();
    // dbg(MF, k, b, h);
    cout << min(MF*k, s*h) << "\n";
}