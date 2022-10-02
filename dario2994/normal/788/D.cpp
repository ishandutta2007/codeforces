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

const int L = 1e8;
namespace hidden {
set<int> xx, yy;
int query_num;
};

int closer(int x, const set<int>& S) {
    auto it = S.lower_bound(x);
    int res = 1e9;
    if (it != S.end()) res = min(res, *it - x);
    if (it != S.begin()) res = min(res, x-*prev(it));
    return res;
}

// int query(int x, int y) {
    // assert(-L <= x and x <= L);
    // assert(-L <= y and y <= L);
    // hidden::query_num++;
    // return min(closer(x, hidden::xx), closer(y, hidden::yy));
// }

int query(int x, int y) {
    cout << 0 << " " << x << " " << y << endl;
    int ans;
    cin >> ans;
    return ans;
}

void solve1d(int pos, const function<int(int)>& ask) {
    const int C = 64;
    if (pos > L) return;
    int q = ask(pos);
    if (q != 0) solve1d(pos + q, ask);
    else if (pos + C <= L) {
        if (ask(pos + C) == C) solve1d(pos + 2*C, ask);
        else solve1d(pos+1, ask);
    }
    else solve1d(pos+1, ask);
}

int main() {
    std::mt19937 rng;
    std::uniform_int_distribution<int> rand_coord(-L, L);

    // hidden::xx = {1, 2};
    // hidden::yy = {-L, 0, L};
    // while (hidden::xx.size() < 10000) hidden::xx.insert(rand_coord(rng));
    // while (hidden::yy.size() < 10000) hidden::yy.insert(rand_coord(rng));

    // cout << "GENERATED" << endl;

    int x0, y0;
    int best = 0;
    for (int i = 0; i < 500; i++) {
        int x = rand_coord(rng);
        int y = rand_coord(rng);
        int q = query(x, y);
        if (q > best) x0 = x, y0 = y, best = q;
    }

    set<int> xx, yy;
    auto find_x = [&](int x) {
        int q = query(x, y0);
        if (q == 0) xx.insert(x);
        return q;
    };
    auto find_y = [&](int y) {
        int q = query(x0, y);
        if (q == 0) yy.insert(y);
        return q;
    };
    solve1d(-L, find_x);
    solve1d(-L, find_y);

    cout << 1 << " " << xx.size() << " " << yy.size() << endl;
    for (int x: xx) cout << x << " ";
    cout << endl;
    for (int y: yy) cout << y << " ";
    cout << endl;
    
    // dbg(xx, yy);
    // assert(xx == hidden::xx);
    // assert(yy == hidden::yy);
    // cout << hidden::query_num << endl;
}