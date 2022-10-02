#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define SZ(x) ((int)((x).size()))

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

vector<int> SortIndex(int size, std::function<bool(int, int)> compare) {
    vector<int> ord(size);
    for (int i = 0; i < size; i++) ord[i] = i;
    sort(ord.begin(), ord.end(), compare);
    return ord;
}

template <typename T>
bool MinPlace(T& a, const T& b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}

template <typename T>
bool MaxPlace(T& a, const T& b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
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
    #define dbg(...) _dbg(#__VA_ARGS__, __VA_ARGS__)
    #define dbg_arr(x, len) clog << #x << ": " << print_iterable(x, x+len, -1) << endl;
#else
    #define dbg(...)
    #define dbg_arr(x, len)
#endif

///////////////////////////////////////////////////////////////////////////
//////////////////// DO NOT TOUCH BEFORE THIS LINE ////////////////////////
///////////////////////////////////////////////////////////////////////////

int query(const vector<int>& vec) {
    cout << "? " << vec.size() << " ";
    for (int x: vec) cout << x << " ";
    cout << endl;
    int ans;
    cin >> ans;
    assert(ans != -1);
    return ans;
}

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> id(n+1);
    for (int i = 1; i <= k; i++) {
        int c;
        cin >> c;
        for (int j = 0; j < c; j++) {
            int x;
            cin >> x;
            id[x] = i;
        }
    }
    vector<int> vec(n);
    for (int i = 0; i < n; i++) vec[i] = i+1;
    int val = query(vec);
    int l = 1, r = n;
    while (l < r) {
        int m = (l+r)/2;
        vector<int> vec;
        for (int i = l; i <= m; i++) vec.push_back(i);
        if (query(vec) == val) r = m;
        else l = m+1;
    }
    vector<int> ans(k+1);
    for (int i = 1; i <= k; i++) {
        if (id[l] == i) {
            vector<int> vec;
            for (int j = 1; j <= n; j++) if (id[j] != i) vec.push_back(j);
            ans[i] = query(vec);
        } else ans[i] = val;
    }
    cout << "! ";
    for (int i = 1; i <= k; i++) cout << ans[i] << " ";
    cout << endl;
    string response;
    cin >> response;
    assert(response == "Correct");
}

int main() {
    int T;
    cin >> T;
    for (int t = 0; t < T; t++) solve();
}