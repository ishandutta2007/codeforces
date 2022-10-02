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

const int MAXN = 1<<14;

// bitset<10000> stb[2*MAXN];
vector<int> st[2*MAXN];

bitset<10010> ans;

void modify(int v, int a, int b, int l, int r, int x) {
    // cout << v << " " << a << " " << b << " " << l << " " << r << " " << x << endl;
    if (b < l or r < a) return;
    if (l <= a and b <= r) {
        // cout << "modify: " << v << " " << x << endl;
        st[v].push_back(x);
        return;
    }
    int m = (a+b)/2;
    modify(2*v, a, m, l, r, x);
    modify(2*v+1, m+1, b, l, r, x);
}

void dfs(int v, bitset<10010> curr) {
    // cout << v << endl;
    for (int x : st[v]) {
        // cout << "dfs: " << v << " " << x << endl;
        curr |= curr<<x;
    }
    ans |= curr;
    if (v >= MAXN) return;
    dfs(2*v, curr);
    dfs(2*v+1, curr);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); // Remove in problems with online queries!
    int N, Q;
    cin >> N >> Q;
    for (int i = 0; i < Q; i++) {
        int l, r, x;
        cin >> l >> r >> x;
        modify(1, 0, MAXN-1, l, r, x);
    }
    bitset<10010> curr;
    curr[0] = 1;
    dfs(1, curr);
    int res = 0;
    for (int i = 1; i <= N; i++) res += ans[i];
    cout << res << "\n";
    for (int i = 1; i <= N; i++) if (ans[i]) cout << i << " ";
    cout << "\n";
    // dbg_var(ans[1]);
}