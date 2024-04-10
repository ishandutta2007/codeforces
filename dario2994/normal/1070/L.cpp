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

const int MAXN = 2048;

bitset<MAXN> mat[MAXN];
int N;

void print_mat() {
    for (int i = 0; i < N; i++) {
        string s = mat[i].to_string();
        reverse(s.begin(), s.end());
        cout << s << endl;
    }
    cout << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); // Remove in problems with online queries!

    int T;
    cin >> T;
    for (int tt = 0; tt < T; tt++) {
        int  M;
        cin >> N >> M;
        vector<int> deg(N, 0);
        for (int i = 0; i < M; i++) {
            int u, v;
            cin >> u >> v;
            u--, v--;
            mat[u][v] = 1;
            mat[v][u] = 1;
            // dbg_var(u);
            // dbg_var(v);
            deg[u]++, deg[v]++;
        }
        bool works = true;
        for (int v = 0; v < N; v++) {
            if (deg[v] % 2) mat[v][v] = 1, mat[v][N] = 1, works = false;
        }
        // print_mat();
        if (works) {
            cout << 1 << "\n";
            for (int i = 0; i < N; i++) cout << 1 << " ";
            cout << "\n";
            for (int i = 0; i < N; i++) mat[i].reset();

            continue;
        }
        for (int j = 0; j < N; j++) {
            if (mat[j][j] == 0) {
                for (int i = j+1; i < N; i++) {
                    if (mat[i][j]) {
                        swap(mat[i], mat[j]);
                        break;
                    }
                }
            }
            // print_mat();
            if (mat[j][j] == 0) continue;
            for (int i = j+1; i < N; i++) {
                if (mat[i][j]) {
                    mat[i] ^= mat[j];
                }
            }
            // print_mat();
        }
        // print_mat();
        vector<int> ans(N+1, 0);
        ans[N] = 1;
        for (int i = N-1; i >= 0; i--) {
            if (mat[i][i] == 0) continue;
            for (int j = i+1; j <= N; j++) ans[i] ^= mat[i][j]*ans[j];
        }
        for (int i = 0; i < N; i++) mat[i].reset();
        cout << 2 << "\n";
        for (int i = 0; i < N; i++) cout << ans[i] + 1 << " ";
        cout << "\n";
    }
}