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

void solve(int n, int a, int b) {
    // int n, a, b;
    // cin >> n >> a >> b;
    if (n == 1 and  a == 0 and b == 0) {
        cout << 1 << "\n";
        return;
    }
    if (abs(a-b) > 1 or a+b > n-2) {
        cout << -1 << "\n";
        return;
    }
    vector<int> p;
    auto f = [&](int x) { p.push_back(x); };
    if (a == 0 and b == 0) for (int i = 1; i <= n; i++) f(i);
    else if (a > b) {
        for (int i = 1; i <= a; i++) f(i), f(n+1-i);
        for (int i = n-a; i > a; i--) f(i);
    } else if (a == b) {
        for (int i = 1; i <= a; i++) f(i), f(n+1-i);
        f(a+1);
        for (int i = a+2; i <= n-a; i++) f(i);
    } else {
        for (int i = 1; i <= b; i++) f(n+1-i), f(i);
        for (int i = b+1; i <= n-b; i++) f(i);
    }

    for (int x: p) cout << x << " ";
    cout << "\n";
    for (int i = 1; i < n-1; i++) {
        a -= p[i] > p[i-1] and p[i] > p[i+1];
        b -= p[i] < p[i-1] and p[i] < p[i+1];
    }
    assert(a == 0 and b == 0);
    sort(p.begin(), p.end());
    for (int i = 0; i < n; i++) assert(p[i] == i+1);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); // Remove in problems with online queries!

    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        // int n = 1 + rand() % 10;
        // int a = rand() % (n+1);
        // int b = rand() % (n+1);
        // cout << n << " " << a << " " << b << endl;
        int n, a, b;
        cin >> n >> a >> b;
        
        solve(n, a, b);
    }
}