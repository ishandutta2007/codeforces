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

const int MAXN = 510000;
bool S[MAXN];

int A[MAXN];
int B[MAXN];

LL solve(bool* T, LL n) {
    if (n == 0) return 0;
    if (n == 1) return T[0];
    int bef = -1;
    int aft = -1;
    for (int i = 0; i < n; i++) {
        if (T[i]) continue;
        if (2*i < n) bef = i;
        else if (aft == -1) {
            aft = i;
            break;
        }
    }
    if (bef == -1 and aft == -1) return (n*(n+1)*(n+2))/6;

    int it = bef;
    if (bef == -1) it = aft;
    else if (aft != -1 and n/2-bef > aft-n/2) it = aft;

    LL ris1 = solve(T, it);
    LL ris2 = solve(T+it+1, n-1-it);

    int a = it+1;
    int curr = 0;
    A[0] = 0;
    for (int i = 1; i < a; i++) {
        if (!T[it-i]) curr = 0;
        else curr++;
        A[i] = max(A[i-1], curr);
    }

    int b = n-it;
    curr = 0;
    B[0] = 0;
    for (int i = 1; i < b; i++) {
        if (!T[it + i]) curr = 0;
        else curr++;
        B[i] = max(B[i-1], curr);
    }

    LL res = 0;
    // for (int i = 0; i < a; i++) for (int j = 0; j < b; j++) res += max(A[i], B[j]);

    LL sum_larger = 0;
    int j = b-1;
    for (int i = a-1; i >= 0; i--) {
        while (j >= 0 and B[j] > A[i]) {
            sum_larger += B[j];
            j--;
        }
        res += (j+1)*((LL)A[i]) + sum_larger;
    }

    return ris1 + ris2 + res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); // Remove in problems with online queries!

    int N;
    cin >> N;
    string SS;
    cin >> SS;
    for (int i = 0; i < N; i++) S[i] = SS[i] == '1';
    cout << solve(S, N) << "\n";
}