#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("popcnt")

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

const int MAXN = 15;
const int MAXP = 1<<MAXN;
int din[MAXN+1][MAXN][MAXP];
// din[len][pos][bb] = Smallest value of the last element of a len-partition of bb
//                   that is increasing and can end at pos or before.

void solve() {
    int n;
    cin >> n;
    int p = 1<<n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    vector<int> sums(p, 0);
    for (int bb = 0; bb < p; bb++) {
        for (int i = 0; i < n; i++) if (bb&(1<<i)) sums[bb] += a[i];
    }
    const int INF = 1e8;
    for (int len = 1; len <= n; len++) for (int i = 0; i < n; i++) {
        for (int bb = 0; bb < p; bb++) din[len][i][bb] = INF;
    }
    for (int bb = 0; bb < p; bb++) {
        for (int i = 0; i < n; i++) if (bb&(1<<i)) din[1][i][bb] = sums[bb];
        for (int i = 1; i < n; i++)
                din[1][i][bb] = min(din[1][i][bb], din[1][i-1][bb]);
    }
    
    for (int len = 2; len <= n; len++) {
        for (int bb = 0; bb < p; bb++) {
            if (__builtin_popcount(bb) < len) continue;
            // int d = __builtin_popcount(bb) - len + 1;
            for (int i = len-1; i < n; i++) {
                if ((bb&(1<<i)) == 0) continue;
                int bbi = bb^(1<<i);
                // const int max_sum = din[len][i][bb];
                for (int _cc = bbi; _cc > 0; _cc = (_cc-1)&bbi) {
                    int cc = _cc ^ (1<<i);
                    // if (__builtin_popcount(cc) > d) continue;
                    // if (sums[cc] >= din[len][i][bb]) continue;

                    if (din[len-1][i-1][bb^cc] < sums[cc])
                        din[len][i][bb] = min(din[len][i][bb], sums[cc]);
                }
                if (din[len-1][i-1][bbi] < sums[1<<i])
                    din[len][i][bb] = min(din[len][i][bb], sums[1<<i]);
            }
            for (int i = 1; i < n; i++)
                din[len][i][bb] = min(din[len][i][bb], din[len][i-1][bb]);
        }
    }
    
    vector<pair<int,int>> ans;
    int bb = p-1, val = INF, i = n, len = 1;
    while (len < n and din[len+1][i-1][bb] < val) len++;

    while (1) {
        i--;
        while (len < n and din[len+1][i][bb] < val) len++;
        while (i > 0 and din[len][i-1][bb] < val) i--;
        
        if (len == 1) {
            ans.push_back({i, bb});
            break;
        }
        for (int cc = bb; cc > 0; cc = (cc-1)&bb) {
            if (sums[cc] < val and (cc&(1<<i)) and din[len-1][i-1][bb^cc] < sums[cc]) {
                ans.push_back({i, cc});
                bb ^= cc;
                val = sums[cc];
                len--;
                break;
            }
        }
    }
    vector<int> color(n);
    for (auto pp: ans) {
        int bb = pp.second;
        int c = pp.first;
        for (int i = 0; i < n; i++) {
            if (bb&(1<<i)) color[i] = c;
        }
    }
    vector<int> pos(n);
    for (int i = 0; i < n; i++) pos[i] = i;

    cout << n-ans.size() << "\n";
    for (int i = 0; i < n; i++) {
        if (color[i] == i) continue;
        cout << pos[i]+1 << " " << pos[color[i]]+1 << "\n";
        for (int j = i+1; j < n; j++) pos[j]--;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); // Remove in problems with online queries!

    int t;
    cin >> t;
    for (int i = 0; i < t; i++) solve();
}