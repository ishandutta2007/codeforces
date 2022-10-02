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

const int MAXN = 1e6 + 10;
ULL h[MAXN];
bool iscomp[MAXN];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); // Remove in problems with online queries!

    mt19937 rng(13);
    std::uniform_int_distribution<ULL> distr;

    for (int p = 2; p < MAXN; p++) {
        if (iscomp[p]) continue;
        h[p] = distr(rng);
        for (int i = 2; p*i < MAXN; i++) h[p*i] = h[p] ^ h[i], iscomp[p*i] = true;
    }
    // dbg_arr(h, 5);
    for (int i = 2; i < MAXN; i++) h[i] ^= h[i-1];
    // dbg_arr(h, 5);
    // return 0;

    int N;
    cin >> N;
    unordered_map<ULL,int> hh;
    ULL tot = 0;
    for (int i = 1; i <= N; i++) hh[h[i]] = i, tot ^= h[i];
    vector<int> bad;
    if (tot == 0) bad = {};
    else if (hh.count(tot)) bad = {hh[tot]};
    else {
        bool found = false;
        for (int i = 1; i <= N; i++) {
            if (hh.count(tot^h[i])) {
                bad = {i, hh[tot^h[i]]};
                found = true;
            }
        }
        if (!found) {
            assert(N % 2);
            bad = {N, N/2, 2};
        }
    }
    cout << N - bad.size() << "\n";
    for (int i = 1; i <= N; i++) {
        bool good = true;
        for (int x: bad) good &= x != i;
        if (good) cout << i << " ";
    }
    cout << "\n";
}