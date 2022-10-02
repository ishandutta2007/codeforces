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

const int MAXN = 512;
int pref[MAXN];
int nn[MAXN][2];
int din[MAXN][MAXN];
int din2[MAXN][MAXN];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); // Remove in problems with online queries!

    int n, m;
    cin >> n >> m;
    string a, b;
    cin >> a >> b;

    pref[0] = -1;
    for (int i = 1; i <= m; i++) {
        pref[i] = pref[i-1];
        while (pref[i] >= 0 and b[pref[i]] != b[i-1]) pref[i] = pref[pref[i]];
        pref[i]++;
    }
    for (int i = 0; i < m; i++) {
        for (int c = 0; c <= 1; c++) {
            int j = i;
            while (j > 0 and b[j] != '0'+c) j = pref[j];
            if (b[j] == '0'+c) nn[i][c] = j+1;
            else nn[i][c] = 0;
            if (nn[i][c] == m) nn[i][c] = pref[m];
            // cout << i << " " << c << ": " << nn[i][c] << endl;
        }
    }

    for (int ma = 0; ma < m; ma++) {
        for (int q = 0; q <= n-m+1; q++) {
            din[ma][q] = q ? 1000: 0;
        }
    }
    for (int p = n-1; p >= 0; p--) {
        for (int ma = 0; ma < m; ma++) {
            // at most: n-p-(m-1-ma)
            for (int k = 0; k <= n-m+1; k++) {
                int z = 1000;
                for (int c = 0; c <= 1; c++) {
                    int cost = a[p] != '0'+c;
                    int occ = ma == m-1 and b[m-1] == '0'+c;
                    if (k >= occ) z = min(z, cost + din[nn[ma][c]][k-occ]);
                }
                din2[ma][k] = z;
            }
        }
        for (int ma = 0; ma < m; ma++) {
            for (int k = 0; k <= n-m+1; k++) {
                din[ma][k] = din2[ma][k];
            }
        }
    }
    for (int k = 0; k <= n-m+1; k++) {
        int ans = din[0][k];
        if (ans <= n) cout << ans << " ";
        else cout << -1 << " ";
    }
    cout << "\n";
}