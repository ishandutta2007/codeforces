#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;

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

#if DEBUG && !ONLINE_JUDGE
    ifstream input_from_file("input.txt");
    #define cin input_from_file

    #define dbg_var(x) clog << #x  << ": " << x << endl;
    #define dbg_array(x, len) clog << #x << ": " << print_iterable(x, x+len, -1) << endl;
#else
    #define dbg_var(x)
    #define dbg_array(x, len)
#endif

///////////////////////////////////////////////////////////////////////////
//////////////////// DO NOT TOUCH BEFORE THIS LINE ////////////////////////
///////////////////////////////////////////////////////////////////////////

const int MAXN = 1<<19;
LL sum[2*MAXN];
LL pref[2*MAXN];

void update(int index, LL val) {
    int v = MAXN + index;
    sum[v] = val;
    pref[v] = min(0ll, val);
    v = v/2;
    while (v >= 1) {
        sum[v] = sum[2*v] + sum[2*v+1];
        pref[v] = min(pref[2*v], sum[2*v] + pref[2*v+1]);
        v /= 2;
    }
}

void init() {
    for (int v = MAXN; v < 2*MAXN; v++) sum[v] = 1;
    for (int v = MAXN-1; v >= 1; v--) sum[v] = sum[2*v] + sum[2*v+1];
}

LL P[MAXN];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); // Remove in problems with online queries!

    init();
    int N;
    cin >> N;
    for (int i = 0; i < N; i++) cin >> P[i];
    vector<int> ord = SortIndex(N, [&](int i, int j) {
        if (P[i] != P[j]) return P[i] > P[j];
        return i > j;
    });
    LL res = 0;
    for (int i = 0; i < N; i++) res -= P[i];
    for (int it = 0; it < N; it++) {
        int index = ord[it];
        update(index, 0);
        if (pref[1] < 0) update(index, 1);
        else {
            res += P[index];
            update(index, -1);
            if (pref[1] < 0) update(index, 0);
            else res += P[index];
        }
    }
    cout << res << "\n";
}