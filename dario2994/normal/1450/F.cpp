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

typedef pair<int,int> pii;

int slow_solve(int n, vector<int> a) {
    vector<int> p(n);
    int ans = n+1;
    for (int i = 0; i < n; i++) p[i] = i;
    do {
        bool works = true;
        int cost = 0;
        for (int i = 0; i < n-1; i++) {
            works &= a[p[i]] != a[p[i+1]];
            cost += abs(p[i]-p[i+1]) != 1;
        }
        if (works) ans = min(ans, cost);
    } while (next_permutation(p.begin(), p.end()));

    return ans;
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    map<int,int> mm;
    for (int x: a) mm[x]++;
    int max_occ = 0;
    for (auto pp: mm) max_occ = max(max_occ, pp.second);
    if (max_occ > (n+1)/2) {
        cout << -1 << "\n";
        return;
    }
    vector<pii> vec;
    for (int i = 0; i < n; i++) {
        int j = i;
        while (j + 1 < n and a[j+1] != a[j]) j++;
        vec.push_back({a[i], a[j]});
        i = j;
    }

    mm.clear();
    for (auto pp: vec) mm[pp.first]++, mm[pp.second]++;
    max_occ = 0;
    int best = 0;
    for (auto pp: mm) {
        if (max_occ < pp.second) {
            max_occ = pp.second;
            best = pp.first;
        }
    }
    int zero = 0, one = 0, two = 0;
    for (auto pp: vec) {
        int cnt = (pp.first == best) + (pp.second == best);
        if (cnt == 0) zero++;
        if (cnt == 1) one++;
        if (cnt == 2) two++;
    }
    int ans = vec.size()-1;
    // dbg(vec, zero, one, two);
    if (one+two <= 1) {
        cout << ans << "\n";
        return;
    }
    int bonus = 2;
    int b2 = min(two, bonus);
    bonus -= b2;
    two -= b2;
    one += b2;
    int b1 = min(one, bonus);
    one -= b1;
    zero += b1;

    int bad = (two+1) - zero;
    if (bad >= 0) ans += bad;

    // assert(slow_solve(n, a) == ans);
    cout << ans << "\n";
    // cout << slow_solve(n, a) << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); // Remove in problems with online queries!

    int T;
    cin >> T;
    for (int t = 0; t < T; t++) solve();
    
}