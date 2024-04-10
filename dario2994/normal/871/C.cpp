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

const int MAXN = 200010;

int id = 0;
map<int,int> x2id;
map<int,int> y2id;
int GetX(int x) {
    if (x2id.count(x) == 0) x2id[x] = id, id++;
    return x2id[x];
}
int GetY(int y) {
    if (y2id.count(y) == 0) y2id[y] = id, id++;
    return y2id[y];
}

vector<int> aa[MAXN];

bool fatto[MAXN];
void dfs(int v, int& vertices, int& edges) {
    fatto[v] = true;
    vertices++;
    for (int a : aa[v]) {
        edges++;
        if (fatto[a]) continue;
        dfs(a, vertices, edges);
    }
}

const LL mod = 1e9 + 7;
LL pot2[MAXN];

int main() {
    pot2[0] = 1;
    for (int i = 1; i < MAXN; i++) pot2[i] = (pot2[i-1]*2ll) % mod;
    
    ios::sync_with_stdio(false);
    cin.tie(0); // Remove in problems with online queries!

    int M;
    cin >> M;
    for (int i = 0; i < M; i++) {
        int x,y;
        cin >> x >> y;
        x = GetX(x);
        y = GetY(y);
        aa[x].push_back(y);
        aa[y].push_back(x);
    }
    LL res = 1;
    for (int v = 0; v < id; v++) {
        if (fatto[v]) continue;
        int V = 0;
        int E = 0;
        dfs(v, V, E);
        assert(E%2 == 0);
        E /= 2;
        if (V > E) res *= pot2[V]-1ll;
        else res *= pot2[V];
        res %= mod;
    }
    cout << res << "\n";
}