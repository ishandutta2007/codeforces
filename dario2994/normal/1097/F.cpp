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

const int MAXA = 7010;
const int MAXN = 1e5+100;

bitset<7168> divi[MAXA];
bitset<7168> precomp[MAXA];
bitset<7168> bb[MAXN];
bool is_squarefree[MAXA];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); // Remove in problems with online queries!
    for (int i = 1; i < MAXA; i++) is_squarefree[i] = true;
    for (int d = 2; d * d < MAXA; d++) {
        for (int k = d*d; k < MAXA; k += d*d) is_squarefree[k] = false;
    }
    for (int d = 1; d < MAXA; d++) {
        for (int i = d; i < MAXA; i += d) {
            divi[i][d] = true;
            precomp[d][i] = is_squarefree[i/d];
        }
    }
    int N, Q;
    cin >> N >> Q;
    bitset<7168> tx;
    for (int q = 0; q < Q; q++) {
        // dbg(q);
        // for (int j = 1; j <= N; j++) {
        //     cout << j << ": ";
        //     for (int i = 1; i <= 7000; i++) if (bb[j][i]) cout << i << " ";
        //     cout << endl;
        // }
        int t;
        cin >> t;
        if (t == 1) {
            int x, v;
            cin >> x >> v;
            bb[x] = divi[v];
        } else if (t == 2) {
            int x, y, z;
            cin >> x >> y >> z;
            bb[x] = bb[y] ^ bb[z];
        } else if (t == 3) {
            int x, y, z;
            cin >> x >> y >> z;
            bb[x] = bb[y] & bb[z];
        } else if (t == 4) {
            int x, v;
            cin >> x >> v;
            tx.reset();
            tx = bb[x] & precomp[v];
            cout << tx.count() % 2;
        }
    }
}