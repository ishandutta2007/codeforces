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
    // ifstream input_from_file("input.txt");
    // #define cin input_from_file

    #define dbg(...) _dbg(#__VA_ARGS__, __VA_ARGS__)
    #define dbg_arr(x, len) clog << #x << ": " << print_iterable(x, x+len, -1) << endl;
#else
    #define dbg(...)
    #define dbg_arr(x, len)
#endif

///////////////////////////////////////////////////////////////////////////
//////////////////// DO NOT TOUCH BEFORE THIS LINE ////////////////////////
///////////////////////////////////////////////////////////////////////////

// const int MAXN = 1e5;
// int a_secret[MAXN];
int n;

int query_and(int i, int j) {
    assert(1 <= i and i <= n);
    assert(1 <= j and j <= n);
    cout << "and " << i << " " << j << endl;
    int ans;
    cin >> ans;
    return ans;
    // return a_secret[i] & a_secret[j];
}

int query_or(int i, int j) {
    assert(1 <= i and i <= n);
    assert(1 <= j and j <= n);
    cout << "or " << i << " " << j << endl;
    int ans;
    cin >> ans;
    return ans;
    // return a_secret[i] | a_secret[j];
}

int main() {
    int k;
    cin >> n >> k;
    // for (int i = 1; i <= n; i++) a_secret[i] = rand() % 1000;
    // for (int i = 1; i <= n; i++) cout << a_secret[i] << " ";
    // cout << endl;

    vector<int> vals(n+1);

    int aa[4][4];
    int oo[4][4];
    for (int i = 1; i <= 3; i++) for (int j = i+1; j <= 3; j++) {
        aa[i][j] = query_and(i, j);
        oo[i][j] = query_or(i, j);
    }

    bool baa[4][4];
    bool boo[4][4];
    bool ans[4];
    for (int b = 0; b <= 30; b++) {
        for (int i = 1; i <= 3; i++) for (int j = i+1; j <= 3; j++) {
            baa[i][j] = (aa[i][j]&(1<<b))>0;
            boo[i][j] = (oo[i][j]&(1<<b))>0;
            baa[j][i] = baa[i][j];
            boo[j][i] = boo[i][j];
        }
        for (int i = 1; i <= 3; i++) for (int j = i+1; j <= 3; j++) {
            int k = 6-(i+j);
            if (baa[i][j] == 0 and boo[i][j] == 0) {
                ans[i] = 0, ans[j] = 0;
                ans[k] = boo[i][k];
            }
            if (baa[i][j] == 1 and boo[i][j] == 1) {
                ans[i] = 1, ans[j] = 1;
                ans[k] = baa[i][k];
            }
        }
        // dbg(ans[1], ans[2], ans[3]);
        for (int i = 1; i <= 3; i++) {
            if (ans[i]) vals[i] ^= 1<<b;
        }
    }
    for (int i = 4; i <= n; i++) {
        int a = query_and(1, i);
        int o = query_or(1, i);
        vals[i] = o^vals[1]^a;
    }
    
    // for (int i = 1; i <= n; i++) assert(a_secret[i] == vals[i]);
    sort(vals.begin()+1, vals.end());
    cout << "finish " << vals[k] << endl;
}