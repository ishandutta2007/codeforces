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

const int MAXN = 301000;
int N;
int d[MAXN];
string S;
int x;

int d2[MAXN];
int compute(int a, int b) {
    for (int i = 0; i < a; i++) d2[i] = d[i];
    for (int i = b; i < N; i++) d2[i] = d[i];
    int diff = 0;
    if (S[a] == S[b]) diff = 0;
    else if (S[a] == ')') diff = 2;
    else diff = -2;
    for (int i = a; i < b; i++) d2[i] = d[i] + diff;
    int mm = 1e9;
    int cnt = 0;
    for (int i = 0; i < N; i++) {
        if (d2[i] == mm) cnt++;
        if (d2[i] < mm) mm = d2[i], cnt = 1;
    }
    return cnt;
}

pair<int,pair<int,int>> solve1() {
    int a = N;
    int b = -1;
    for (int i = 0; i < N; i++) {
        if (S[i] == ')') a = i;
        if (d[i] == x) break;
    }
    for (int i = N-1; i >= 0; i--) {
        if (d[i] == x) break;
        if (S[i] == '(') b = i;
    }
    if (a > b) return {compute(0, 0), {0, 0}};
    return {compute(a, b), {a, b}};
}

pair<int,pair<int,int>> solve2() {
    int a = N;
    int b = -1;
    for (int i = 0; i < N; i++) {
        if (S[i] == ')') a = i;
        if (d[i] == x or d[i] == x+1) break;
    }
    for (int i = N-1; i >= 0; i--) {
        if (d[i] == x or d[i] == x+1) break;
        if (S[i] == '(') b = i;
    }
    // dbg(a, b);
    if (a > b) return {compute(0, 0), {0, 0}};
    return {compute(a, b), {a, b}};
}

pair<int,pair<int,int>> solve0() {
    int nomove = compute(0, 0);
    int res = nomove;
    pair<int,int> best = {0, 0};
    for (int i = 0; i < N; i++) {
        if (d[i] == x or d[i] == x+1) continue;
        int a = N;
        int b = -1;
        for (int j = i; j < N; j++) {
            if (S[j] == '(') {
                a = j;
                break;
            }
            if (d[j] == x or d[j] == x+1) break;
        }
        int last_i = i+1; // first x, x+1 (or last element!)
        for (int j = i; j < N; j++) {
            last_i = j;
            if (d[j] == x or d[j] == x+1) break;
        }
        for (int j = last_i; j >= a; j--) {
            if (S[j] == ')') {
                b = j;
                break;
            }
        }
        i = last_i;
        if (a > b) continue;
        int ris = nomove;
        for (int j = a; j < b; j++) if (d[j] == x+2) ris++;
        if (ris > res) {
            res = ris;
            best = {a, b};
        }
    }
    return {res, best};
}

pair<int,pair<int,int>> solvem1() {
    int res = 0;
    pair<int,int> best = {0, 0};
    for (int i = 0; i < N; i++) {
        if (d[i] == x) continue;
        int a = N;
        int b = -1;
        for (int j = i; j < N; j++) {
            if (S[j] == '(') {
                a = j;
                break;
            }
            if (d[j] == x) break;
        }
        int last_i = i+1; // first x (or last element!)
        for (int j = i; j < N; j++) {
            last_i = j;
            if (d[j] == x) break;
        }
        for (int j = last_i; j >= a; j--) {
            if (S[j] == ')') {
                b = j;
                break;
            }
        }
        i = last_i;
        if (a > b) continue;
        int ris = 0;
        for (int j = a; j < b; j++) if (d[j] == x+1) ris++;
        if (ris > res) {
            res = ris;
            best = {a, b};
        }
    }
    return {res, best};
}

pair<int,pair<int,int>> solve_slow() {
    pair<int,int> best;
    int res = 0;
    for (int a = 0; a < N; a++) {
        for (int b = a; b < N; b++) {
            if (res < compute(a, b)) {
                res = compute(a, b);
                best = {a, b};
            }
        }
    }
    return {res, best};
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); // Remove in problems with online queries!
    cin >> N;
    cin >> S;
    for (int i = 0; i < N; i++) {
        if (i > 0) d[i] = d[i-1];
        if (S[i] == '(') d[i]++;
        else d[i]--;
    }
    if (d[N-1] != 0) {
        cout << 0 << "\n";
        cout << 1 << " " << 1 << "\n";
        return 0;
    }
    for (int i = 0; i < N; i++) x = min(x, d[i]);

    vector<pair<int, pair<int,int>>> res(4);
    res[0] = solve1();
    res[1] = solve2();
    res[2] = solve0();
    res[3] = solvem1();
    // dbg(res);
    sort(res.begin(), res.end());
    cout << res.back().first << "\n";
    cout << res.back().second.first+1 << " " << res.back().second.second+1 << "\n";
    // dbg_arr(d, N);
    // dbg(res);
    // dbg(solve_slow());
    // assert(res.back().first == solve_slow().first);
}