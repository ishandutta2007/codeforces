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

const int MAXN = 1<<18;
int N;

set<int> ss[3];
int val[256];

int get_first(set<int>& x) {
    if (x.empty()) return -1;
    return *x.begin();
}
int get_last(set<int>& x) {
    if (x.empty()) return -1;
    return *x.rbegin();
}


vector<int> seg_tree[3];
void update(vector<int>& st, int v, int x) {
    // cout << v << " " << x << endl;
    v += MAXN;
    st[v] = x;
    while (v != 1) {
        v >>= 1;
        st[v] = st[2*v] + st[2*v+1];
    }
}

int query(vector<int>& st, int v, int a, int b, int l, int r) {
    if (b < l or r < a) return 0;
    if (l <= a and b <= r) return st[v];
    int m = (a+b)/2;
    return query(st, 2*v, a, m, l, r) + query(st, 2*v+1, m+1, b, l, r);
}

int S[MAXN];

int solve2(vector<int>& st, set<int>& bad, set<int>& good) {
    int a = get_first(bad), b = get_first(good);
    int c = get_last(good), d = get_last(bad);
    if (a == -1 and b == -1) return 0;
    if (a == -1) return 0;
    if (b == -1) return st[1];
    if (a <= b and c <= d and c <= b) {
        int from = min(a, c);
        int to = max(b, d);
        if (from <= to) return query(st, 1, 0, MAXN-1, from, to);
        else return 0;
    } else {
        int res = 0;
        if (a <= b) res += query(st, 1, 0, MAXN-1, a, b);
        if (c <= d) res += query(st, 1, 0, MAXN-1, c, d);
        return res;
    }
}

int solve() {
    int res = 0;
    for (int i = 0; i < 3; i++) {
        res += solve2(seg_tree[i], ss[(i+1)%3], ss[(i+2)%3]);
    }
    return N - res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); // Remove in problems with online queries!
    for (int i = 0; i < 3; i++) seg_tree[i].resize(2*MAXN, 0);

    val['R'] = 0, val['P'] = 1, val['S'] = 2;
    int Q;
    cin >> N >> Q;
    for (int i = 0; i < N; i++) {
        char c;
        cin >> c;
        ss[val[c]].insert(i);
        update(seg_tree[val[c]], i, 1);
        S[i] = val[c];
    }

    cout << solve() << "\n";
    for (int i = 0; i < Q; i++) {
        int it;
        char c;
        cin >> it >> c;
        it--;
        ss[S[it]].erase(it);
        update(seg_tree[S[it]], it, 0);
        ss[val[c]].insert(it);
        update(seg_tree[val[c]], it, 1);
        S[it] = val[c];
        cout << solve() << "\n";
    }
}