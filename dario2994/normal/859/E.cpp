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

const int MAXN = 210000;
int N;
int to[MAXN];
vector<int> aa[MAXN];

int ciclo[MAXN];
int opening[MAXN];
int curr_time = 1;

vector<LL> cycle_size;
vector<LL> comp_size;

void FindCycle(int v) {
    if (ciclo[v]) return;
    if (opening[v] != 0) {
        ciclo[v] = curr_time - opening[v];
        cycle_size.push_back(ciclo[v]);
        return;
    }
    opening[v] = curr_time;
    curr_time++;
    if (to[v] == 0) {
        ciclo[v] = -1;
        return;
    }
    
    FindCycle(to[v]);
    ciclo[v] = ciclo[to[v]];
}

bool fatto[MAXN];
int FindCompSize(int v) {
    fatto[v] = true;
    int res = 1;
    for (int a : aa[v]) {
        if (fatto[a]) continue;
        res += FindCompSize(a);
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); // Remove in problems with online queries!

    cin >> N;
    for (int i = 0; i < N; i++) {
        int x, y;
        cin >> x >> y;
        to[x] = y;
        aa[x].push_back(y);
        aa[y].push_back(x);
    }

    for (int i = 1; i <= 2*N; i++) FindCycle(i);
    for (int v = 1; v <= 2*N; v++) {
        if (fatto[v] or ciclo[v] > 0) continue;
        comp_size.push_back(FindCompSize(v));
    }

    const LL mod = 1e9 + 7;
    LL res = 1;
    for (LL x : cycle_size) {
        if (x > 1) res = (2ll * res) % mod;
    }
    for (LL x : comp_size) res = (res * x) % mod;
    cout << res << "\n";
    // dbg_var(cycle_size);
    // dbg_var(comp_size);
    // dbg_array(ciclo, 11)
}