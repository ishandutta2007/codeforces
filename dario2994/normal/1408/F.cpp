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

vector<pair<int,int>> res;

void make_equal(int l, int r) {
    if (l + 1 == r) {
        res.emplace_back(l, r);
        return;
    }
    int m = (l+r)/2;
    for (int i = l; i <= m; i++) {
        res.emplace_back(i, i + (r-l+1)/2);
    }
    make_equal(l, m);
    make_equal(m+1, r);
}

ULL fun(ULL x, ULL y) {
    return (x^y)+x*y+1045354ull*x;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); // Remove in problems with online queries!

    int N;
    cin >> N;

    if (N <= 2) {
        cout << 0 << "\n";
        return 0;
    }
    
    int pot = 1;
    while (2*pot <= N) pot *= 2;
    make_equal(1, pot);
    make_equal(N-pot+1, N);

    cout << res.size() << "\n";
    for (auto pp: res) cout << pp.first << " " << pp.second << "\n";

    // vector<ULL> a(N+1);
    // for (int i = 1; i <= N; i++) a[i] = i;
    // for (auto pp: res) {
        // int i = pp.first, j = pp.second;
        // ULL t = fun(a[i], a[j]);
        // a[i] = t, a[j] = t;
    // }
    // set<ULL> vals;
    // for (int i = 1; i <= N; i++) vals.insert(a[i]);
    // assert(vals.size() <= 2);
}