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




int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); // Remove in problems with online queries!

    int n;
    cin >> n;
    
    vector<int> sum(n);
    vector<int> min_pref(n);
    vector<vector<int>> eq0(n);

    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        int k = s.size();
        vector<int> pref(k+1, 0);
        for (int j = 1; j <= k; j++) pref[j] = pref[j-1] + ((s[j-1] == '(')?1:-1);
        sum[i] = pref[k];
        for (int j = 1; j <= k; j++) min_pref[i] = min(min_pref[i], pref[j]);
        const int ZERO = k+5;
        vector<vector<int>> occ(ZERO + k+5);
        for (int j = 1; j <= k; j++) occ[ZERO+pref[j]].push_back(j);

        eq0[i].resize(k+1, 0);

        int last = k+1;
        for (int x = k; x >= 0; x--) {
            if (occ[ZERO-x].empty()) continue;
            
            for (int p: occ[ZERO-x]) eq0[i][x] += p < last; 
            last = min(occ[ZERO-x][0], last);
        }
    }

    int res = 0;
    vector<int> din(1<<n, -1);
    din[0] = 0;
    for (int bb = 0; bb < (1<<n); bb++) {
        if (din[bb] < 0) continue;
        int s = 0;
        for (int i = 0; i < n; i++) if (bb&(1<<i)) s += sum[i];
        for (int p = 0; p < n; p++) {
            if (bb&(1<<p)) continue;
            int add = (s < SZ(eq0[p]))?eq0[p][s]:0;
            res = max(res, din[bb] + add);
            if (s + min_pref[p] >= 0) {
                din[bb|(1<<p)] = max(din[bb|(1<<p)], din[bb] + add);
            }
        }
    }
    cout << res << "\n";
}