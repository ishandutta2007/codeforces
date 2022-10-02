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
    int n, m;
    cin >> n >> m;
    vector<LL> teachers(n);
    vector<vector<LL>> groups(m);
    vector<LL> sums(m);
    vector<int> match(m);
    for (int j = 0; j < n; j++) cin >> teachers[j];
    sort(teachers.begin(), teachers.end());
    reverse(teachers.begin(), teachers.end());
    auto get_match = [&](LL age) {
        int l = -1, r = n-1;
        while (l != r) {
            int z = (l+r+1)/2;
            // dbg(n, l, r, z);
            if (teachers[z] >= age) l = z;
            else r = z-1;
        }
        return l;
    };
    for (int i = 0; i < m; i++) {
        int k;
        cin >> k;
        groups[i].resize(k);
        for (int z = 0; z < k; z++) cin >> groups[i][z], sums[i] += groups[i][z];

        LL avg = (sums[i] + (k-1))/k;
        match[i] = get_match(avg);
    }
    vector<int> vec = match;
    sort(vec.begin(), vec.end());
    bool very_false = false;
    set<int> p0, p1;
    for (int i = 0; i < m; i++) {
        if (vec[i] < i-1) very_false = true;
        if (vec[i] == i-1) p1.insert(i);
        if (vec[i] == i) p0.insert(i);
    }
    // for (int x: p1) cout << x << " ";
    // cout << endl;
    // dbg(vec);
    // dbg(match);
    for (int i = 0; i < m; i++) {
        int k = SZ(groups[i]);
        for (int _ = 0; _ < k; _++) {
            LL s = sums[i] - groups[i][_];
            LL avg = (s + (k-2))/(k-1);
            int m1 = match[i];
            int m2 = get_match(avg);
            // dbg(i, m2);
            if (m2 == -1) {
                cout << 0;
                continue;
            }
            if (very_false) cout << 0;
            if (p1.empty()) {
                auto it = p0.lower_bound(m1);
                if (it == p0.begin()) cout << 1;
                else if (m2 <= *prev(it)) cout << 0;
                else cout << 1;
            } else {
                int x = *p1.begin();
                int y = *p1.rbegin();
                if (m1 < x and y <= m2) cout << 1;
                else cout << 0;
            }
        }
    }
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); // Remove in problems with online queries!

    int t;
    cin >> t;
    for (int i = 0; i < t; i++) solve();
}