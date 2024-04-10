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

// Concave function
// min(a1 + s, a2 + 2s)
struct TwoSlopes {
    LL a1, a2;
    TwoSlopes(): a1(1e17), a2(1e17) {}
    void add1(LL a) {
        a1 = min(a, a1);
    }
    void add2(LL a) {
        a2 = min(a, a2);
    }
    LL query(LL x) {
        return min(a1+x, a2+2*x);
    }
    void modify(LL c, LL d, LL e) {
        add1(c+2*d-e);
        add2(c+d-2*e);
    }
};

void solve() {
    int n, m;
    cin >> n >> m;
    vector<LL> p(n);
    for (int i = 0; i < n; i++) cin >> p[i];
    n += 2;
    p.push_back(-1e10);
    p.push_back(1e10);
    sort(p.begin(), p.end());
    vector<pair<LL,LL>> r(m);
    for (int j = 0; j < m; j++) cin >> r[j].first >> r[j].second;
    sort(r.begin(), r.end());


    TwoSlopes TS;
    TS.add1(-p[0]);
    int j0 = 0;
    for (int i = 0; i < n-1; i++) {
        vector<LL> a;
        vector<LL> b;
        vector<LL> fea; // first_end_after
        a.push_back(p[i]), b.push_back(p[i]);
        while (j0 < m and r[j0].first < p[i+1]) {
            LL from = r[j0].first, to = r[j0].second;
            j0++;
            if (from <= p[i]) continue;
            if (to >= p[i+1]) continue;
            a.push_back(from), b.push_back(to);
        }
        fea.resize(a.size());
        fea.back() = p[i+1];
        for (int j = SZ(fea)-2; j >= 0; j--) {
            fea[j] = min(fea[j+1], b[j+1]);
        }
        TwoSlopes TS2;
        for (int j = 0; j < SZ(a); j++) {
            TS2.modify(TS.query(a[j]), p[i+1]-fea[j], p[i+1]);
        }
        TS = TS2;
    }
    cout << TS.query(p.back()) << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); // Remove in problems with online queries!

    int t;
    cin >> t;
    for (int i = 0; i < t; i++) solve();
}