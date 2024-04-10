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

const int MAXN = 2e5 + 100;
vector<int> aa[MAXN];

priority_queue<int>* dfs(int v, int p) {
    priority_queue<int>* q = new priority_queue<int>();
    q->push(0);
    for (int a: aa[v]) {
        if (a == p) continue;
        auto qa = dfs(a, v);
        if (qa->size() > q->size()) swap(q, qa);
        while (!qa->empty()) {
            q->push(qa->top());
            qa->pop();
        }
    }
    int x = q->top();
    q->pop();
    q->push(x+1);
    return q;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); // Remove in problems with online queries!

    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n-1; i++) {
        int a, b;
        cin >> a >> b;
        aa[a].push_back(b);
        aa[b].push_back(a);
    }

    int leaves = 0;
    for (int v = 2; v <= n; v++) leaves += aa[v].size() == 1;
    if (leaves <= k) {
        LL res = -1e18;
        for (LL r = leaves; r <= k; r++) res = max(res, r*(n-r));
        cout << res << "\n";
        return 0;
    }
    auto q = dfs(1, 0);
    int B = n;
    for (int i = 0; i < k; i++) B -= q->top(), q->pop();

    LL res = 1e18;
    for (LL b = 0; b <= B; b++) res = min(res, (n-k-b)*(k-b));
    cout << res << "\n";
    
}