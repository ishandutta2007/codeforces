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

struct Node {
    int one[3];
    int two[2];
    int three;
    Node() {}
    Node(char c) {
        int x = c - 'a';
        one[0] = one[1] = one[2] = 0;
        one[x] = 1;
        two[0] = two[1] = 0;
        three = 0;
    }
};

Node Join(Node A, Node B) {
    Node C;
    for (int i = 0; i < 3; i++) C.one[i] = A.one[i] + B.one[i];
    C.two[0] = min(A.two[0] + B.one[1], A.one[0] + B.two[0]);
    C.two[1] = min(A.two[1] + B.one[2], A.one[1] + B.two[1]);
    C.three = A.two[0] + B.two[1];
    C.three = min(C.three, A.one[0] + B.three);
    C.three = min(C.three, A.three + B.one[2]);
    return C;
}


const int MAXN = 1<<20;
Node st[2*MAXN];

void update(int v, char c) {
    st[v] = Node(c);
    while (v != 1) {
        v /= 2;
        st[v] = Join(st[2*v], st[2*v+1]);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); // Remove in problems with online queries!

    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;
    st[MAXN] = Node('c');
    for (int i = 1; i <= n; i++) st[MAXN + i] = Node(s[i-1]);
    for (int i = n+1; i < MAXN; i++) st[MAXN + i] = Node('a');
    for (int i = MAXN-1; i >= 1; i--) st[i] = Join(st[2*i], st[2*i+1]);
    // cout << st[1].three << "\n";
    // cout << st[3].one[2] << "\n";
    // cout << st[2].two[0] << "\n";
    // cout << st[2]
    for (int i = 0; i < q; i++) {
        int p;
        char c;
        cin >> p >> c;
        update(MAXN+p, c);
        cout << st[1].three << "\n";
    }
}