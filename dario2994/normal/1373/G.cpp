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

struct Node {
    int sum;
    int max_suff;
    Node(): sum(0), max_suff(0) {}
};

const int MAXN = 1<<19;
Node ff[2*MAXN];

Node Join(Node A, Node B) {
    Node C;
    C.sum = A.sum + B.sum;
    C.max_suff = max(B.max_suff, B.sum + A.max_suff);
    return C;
}

void update(int v, int val) {
    v += MAXN;
    ff[v].sum  += val;
    ff[v].max_suff = max(ff[v].sum, 0);
    v >>= 1;
    for (; v >= 1; v >>= 1) ff[v] = Join(ff[2*v], ff[2*v+1]);
}

Node query(int v, int l, int r, int a, int b) {
    if (a <= l and r <= b) return ff[v];
    if (r < a or b < l) return Node();
    int m = (l+r)/2;
    return Join(query(2*v, l, m, a, b), query(2*v+1, m+1, r, a, b));
}

void init() {
    for (int v = MAXN; v < 2*MAXN; v++) {
        ff[v].sum = -1;
        ff[v].max_suff = 0;
    }
    for (int v = MAXN-1; v >= 1; v--) ff[v] = Join(ff[2*v], ff[2*v+1]);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); // Remove in problems with online queries!

    init();

    int N, k, M;
    cin >> N >> k >> M;
    set<pair<int,int>> pawns;
    multiset<int> positions;
    for (int i = 0; i < M; i++) {
        int x, y;
        cin >> x >> y;
        bool present = pawns.count({x, y});
        int pos = y + llabs(x-k);
        if (!present) {
            pawns.insert({x, y});
            positions.insert(pos);
            update(pos, 1);
        } else {
            pawns.erase({x, y});
            positions.erase(positions.find(pos));
            update(pos, -1);
        }
        if (positions.empty()) {
            cout << 0 << "\n";
            continue;
        }
        int largest_pos = *positions.rbegin();
        int max_suff = query(1, 0, MAXN-1, 0, largest_pos).max_suff;
        // dbg(largest_pos, max_suff);
        cout << max(0, largest_pos + max_suff - N) << "\n";
    }
}