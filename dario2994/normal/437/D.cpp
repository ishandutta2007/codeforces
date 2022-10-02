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

const int MAXN = 100100;

int pp[MAXN];
int ss[MAXN];
int boss(int v) {
    if (pp[v] != v) pp[v] = boss(pp[v]);
    return pp[v];
}
LL Join(int a, int b) {
    a = boss(a);
    b = boss(b);
    if (a == b) return 0;
    if (ss[a] < ss[b]) swap(a, b);
    LL res = ((LL)ss[a])*ss[b];
    ss[a] += ss[b];
    pp[b] = a;
    return res;
}

vector<int> aa[MAXN];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); // Remove in problems with online queries!

    int N, M;
    cin >> N >> M;
    for (int i = 1; i <= N; i++) pp[i] = i, ss[i] = 1;
    vector<LL> val(N+1);
    for (int i = 1; i <= N; i++) cin >> val[i];
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        aa[a].push_back(b);
        aa[b].push_back(a);
    }
    vector<int> ord(N);
    for (int i = 0; i < N; i++) ord[i] = i+1;
    sort(ord.begin(), ord.end(), [&](int i, int j) { return val[i] > val[j]; });

    LL res = 0;
    for (int v : ord) {
        for (int a : aa[v]) {
            if (val[a] < val[v]) continue;
            res += val[v] * Join(v, a);
            // cout << v << " " << a << " " << res << endl;
        }
    }
    res *= 2;
    cout.precision(20);
    cout << fixed << ((double)res)/(((LL)N)*(N-1)) << "\n";
}