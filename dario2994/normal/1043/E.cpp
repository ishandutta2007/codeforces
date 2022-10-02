#define _USE_MATH_DEFINES
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

template <typename Container>
int SZ(const Container& S) { return S.size(); }

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

const int MAXN = 300100;

LL sumx[MAXN], sumy[MAXN];
LL X[MAXN], Y[MAXN];
LL res[MAXN];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); // Remove in problems with online queries!
    int N, M;
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        cin >> X[i] >> Y[i];
    }
    auto ord = SortIndex(N, [&](int i, int j) { return Y[i]-X[i] < Y[j]-X[j]; });
    vector<LL> diff(N);
    for (int i = 0; i < N; i++) diff[i] = Y[i] - X[i];
    sort(diff.begin(), diff.end());
    for (int i = 1; i <= N; i++) {
        sumx[i] = X[ord[i-1]] + sumx[i-1];
        sumy[i] = Y[ord[i-1]] + sumy[i-1];
    }
    for (int i = 0; i < N; i++) {
        LL it = lower_bound(diff.begin(), diff.end(), Y[i]-X[i]) - diff.begin();
        LL ris1 = sumy[it] + sumx[N]-sumx[it];
        LL ris2 = it*X[i] + (N-it)*Y[i];
        res[i] = ris1 + ris2 - X[i] - Y[i];
    }
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        LL val = min(X[a] + Y[b], X[b] + Y[a]);
        res[a] -= val, res[b] -= val;
    }
    for (int i = 0; i < N; i++) cout << res[i] << " ";
    cout << "\n";
}