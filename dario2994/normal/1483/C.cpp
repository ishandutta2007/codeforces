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

const LL INF = 1e16;
const int MAXN = 1<<19;
LL ff[2*MAXN];

LL query(int v, int l, int r, int a, int b) {
    if (r < a or b < l) return -INF;
    if (a <= l and r <= b) return ff[v];
    int m = (l+r)/2;
    return max(query(2*v, l, m, a, b), query(2*v+1, m+1, r, a, b));
}

void assign(int v, LL val) {
    v += MAXN;
    ff[v] = val;
    while (v != 1) {
        v /= 2;
        ff[v] = max(ff[2*v], ff[2*v+1]);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); // Remove in problems with online queries!

    int n;
    cin >> n;
    vector<int> h(n, 0);
    vector<LL> b(n, 0);
    for (int i = 0; i < n; i++) cin >> h[i];
    for (int i = 0; i < n; i++) cin >> b[i];
    vector<LL> ans(n, 0);
    stack<int> running_min;
    multiset<LL> ans_in_rm;
    for (int i = n-1; i >= 0; i--) {
        while (!running_min.empty() and h[running_min.top()] > h[i]) {
            ans_in_rm.erase(ans_in_rm.find(ans[running_min.top()]));
            // cerr << "running_min.pop() " << running_min.top() << endl;
            running_min.pop();
        }
        LL max_rm = running_min.empty() ? -INF : *ans_in_rm.rbegin();
        int from = i+1;
        int to = running_min.empty() ? n-1 : running_min.top()-1;
        LL max_int = (from <= to) ? query(1, 0, MAXN-1, from, to) : -INF;
        ans[i] = b[i] + max(max_rm, max_int);
        if (running_min.empty()) ans[i] = max(ans[i], b[i]);
        // dbg(ans[i], b[i], max_rm, max_int);
        ans_in_rm.insert(ans[i]);
        running_min.push(i);
        assign(i, ans[i]);
    }
    
    cout << *ans_in_rm.rbegin() << "\n";
}