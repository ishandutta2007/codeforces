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

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    set<int> alive;
    for (int i = 0; i < n; i++) alive.insert(i);
    set<int> to_remove;
    auto prev_alive = [&](int x) {
        auto it = alive.lower_bound(x);
        if (it == alive.begin()) return *alive.rbegin();
        return *prev(it);
    };
    auto next_alive = [&](int x) {
        auto it = alive.lower_bound(x);
        if (it == alive.end()) return *alive.begin();
        return *it;
    };
    auto next_remove = [&](int x) {
        auto it = to_remove.lower_bound(x);
        if (it == to_remove.end()) return *to_remove.begin();
        return *it;
    };
    vector<int> ans;
    for (int i = 0; i < n; i++) if (__gcd(a[i], a[prev_alive(i)]) == 1) to_remove.insert(i);
    int pos = 1;
    while (!to_remove.empty()) {
        int x = next_remove(pos);
        int y = next_alive(x+1);
        // dbg(x, y);
        to_remove.erase(x);
        alive.erase(x);
        to_remove.erase(y);
        ans.push_back(x);

        if (alive.empty()) break;

        if (__gcd(a[y], a[prev_alive(y)]) == 1) to_remove.insert(y);
        pos = next_alive(y+1);
    }
    cout << ans.size() << " ";
    for (int x: ans) cout << x+1 << " ";
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); // Remove in problems with online queries!

    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) solve();
}