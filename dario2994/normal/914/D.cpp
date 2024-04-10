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

const int MAXN = 1<<19;

int N;
int a[MAXN];
int seg[2*MAXN];

void BuildSeg() {
    for (int i = 0; i <= N; i++) seg[MAXN+i] = a[i];
    for (int i = MAXN-1; i >= 1; i--) seg[i] = __gcd(seg[2*i], seg[2*i+1]);
}

void Update(int v, int x) {
    v += MAXN;
    seg[v] = x;
    while (v > 1) {
        v /= 2;
        seg[v] = __gcd(seg[2*v], seg[2*v+1]);
    }
}

// The greatest, before v such that x does not divide a[v].
int FirstFalse(int pos, int x) {
    int v = pos + MAXN;
    while (1) {
        if (seg[v] % x == 0) {
            while (v % 2 == 0) v /= 2;
            v--;
        } else {
            if (v >= MAXN) return v-MAXN;
            if (seg[2*v+1] % x != 0) v = 2*v+1;
            else v = 2*v;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); // Remove in problems with online queries!
    cin >> N;
    for (int i = 1; i <= N; i++) cin >> a[i];
    a[0] = 1;
    BuildSeg();

    int Q;
    cin >> Q;
    for (int ii = 0; ii < Q; ii++) {
        int t;
        cin >> t;
        if (t == 1) {
            int l, r, x;
            cin >> l >> r >> x;
            if (x == 1) {
                cout << "YES\n";
            } else {
                int m = FirstFalse(r, x);
                if (m <= l) cout << "YES\n";
                else {
                    m = FirstFalse(m-1, x);
                    if (m < l) cout << "YES\n";
                    else cout << "NO\n";
                }
            }
        } else {
            int i, y;
            cin >> i >> y;
            Update(i, y);
        }
    }
}