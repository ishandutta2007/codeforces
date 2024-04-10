#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define SZ(x) ((int)((x).size()))

// Returns the time elapsed in nanoseconds from 1 January 1970, at 00:00:00.
LL get_time() {
    return chrono::duration_cast<chrono::nanoseconds>(
        chrono::steady_clock::now().time_since_epoch())
        .count();
}

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

const int MAXN = 1600;
int A[MAXN][MAXN];
int B[MAXN][MAXN];
int jump_cnt[MAXN];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); // Remove in problems with online queries!

    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) cin >> A[i][j];
    for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) cin >> B[i][j];
    for (int i = 0; i < n-1; i++) for (int j = 0; j < m; j++) jump_cnt[j] += B[i][j] > B[i+1][j];
    vector<int> ans;
    vector<bool> used(m, false);
    vector<bool> splitting(n, false);
    while (1) {
        bool found = false;
        for (int j = 0; j < m; j++) {
            if (used[j] or jump_cnt[j] > 0) continue;
            used[j] = true;
            found = true;
            ans.push_back(j);
            for (int i = 0; i < n-1; i++) {
                if (!splitting[i] and B[i][j] != B[i+1][j]) {
                    splitting[i] = true;
                    for (int j2 = 0; j2 < m; j2++) {
                        if (B[i][j2] > B[i+1][j2]) jump_cnt[j2]--;
                    }
                }
            }
            break;
        }
        if (!found) break;
    }
    vector<int> ord(n);
    for (int i = 0; i < n; i++) ord[i] = i;
    reverse(ans.begin(), ans.end());
    for (int j: ans) {
        stable_sort(ord.begin(), ord.end(), [&](int i1, int i2) {
            return A[i1][j] < A[i2][j];
        });
    }
    bool works = true;
    for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) works &= A[ord[i]][j] == B[i][j];
    if (!works) cout << -1 << "\n";
    else {
        cout << ans.size() << "\n";
        for (int j: ans) cout << j+1 << " ";
        cout << "\n";
    }
}