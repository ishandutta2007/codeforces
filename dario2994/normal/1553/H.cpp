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

int n, k;
const int MAXN = (1<<19);
bool U[MAXN];
int ans[MAXN];

void solve(int l, int r) {
    int q = 0;
    vector<int> vals;
    for (int i = l; i <= r; i++) {
        if (U[i]) {
            q++;
            vals.push_back(i);
        }
    }
    if (q <= 1) return;

    int p = r-l+1;
    int m = (l+r)/2;
    solve(l, m);
    solve(m+1, r);
    // dbg(l, r, q, p);
    // dbg(vals);
    for (int i = l; i <= r; i++) {
        ans[i] = min(ans[i], ans[i^(p/2)]);
        // dbg(i, ans[i]);
    }
    for (int i = l; i <= r; i++) {
        int x = i-l;
        // if (x == p/2) for (int i = l; i <= m; i++) swap(U[i], U[i+p/2]);
        if (q <= ans[i]) { // complexity q
            for (int j1 = 0; j1 < q; j1++) for (int j2 = j1+1; j2 < q; j2++) {
                ans[i] = min(ans[i], abs((vals[j1]^x) - (vals[j2]^x)));
            }
        } else { // complexity ans[i]
            for (int z1 = max(l, m-ans[i]); z1 <= m; z1++) {
                if (!U[z1^x]) continue;
                for (int z2 = m+1; z2-z1 < ans[i] and z2 <= r; z2++) {
                    if (U[z2^x]) ans[i] = z2-z1;
                }
            }
        }
    }
    // for (int i = l; i <= m; i++) swap(U[i], U[i+p/2]);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); // Remove in problems with online queries!

    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        U[a] = true;
    }
    int p = 1<<k;
    for (int i = 0; i < p; i++) ans[i] = 1e6;
    solve(0, p-1);

    for (int x = 0; x < p; x++) cout << ans[x] << " ";
    cout << "\n";

    // for (int x = 0; x < p; x++) {
        // for (int a = 0; a < p
    // }
}