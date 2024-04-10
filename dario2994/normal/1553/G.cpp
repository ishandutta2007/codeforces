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

const int MAXN = 1e6 + 10;
int ppp[MAXN];
bool is_prime[MAXN];
vector<int> aa[MAXN];
bool visited[MAXN];
int component[MAXN];

vector<int> get_primes(int x) {
    vector<int> vec;
    while (x != 1) {
        int p = ppp[x];
        while (x % p == 0) x /= p;
        vec.push_back(p);
    }
    return vec;
}

int curr_comp = 0;
void dfs(int v) {
    visited[v] = true;
    component[v] = curr_comp;
    for (int a: aa[v]) if (!visited[a]) dfs(a);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); // Remove in problems with online queries!

    for (int p = 2; p < MAXN; p++) {
        if (ppp[p]) continue;
        is_prime[p] = true;
        for (int i = p; i < MAXN; i += p) ppp[i] = p;
    }
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        auto vec = get_primes(a[i]);
        for (int j = 1; j < SZ(vec); j++) {
            aa[vec[j-1]].push_back(vec[j]);
            aa[vec[j]].push_back(vec[j-1]);
        }
    }
    for (int p = 2; p < MAXN; p++) {
        if (!is_prime[p] or visited[p]) continue;
        dfs(p);
        curr_comp++;
    }
    set<pair<int,int>> good_pairs;
    for (int x: a) {
        auto vec = get_primes(x+1);
        vec.push_back(ppp[x]);
        for (int& z: vec) z = component[z];
        for (int i = 0; i < SZ(vec); i++) for (int j = i+1; j < SZ(vec); j++) {
            if (vec[i] < vec[j]) good_pairs.insert({vec[i], vec[j]});
            if (vec[j] < vec[i]) good_pairs.insert({vec[j], vec[i]});
        }
    }

    for (int _ = 0; _ < q; _++) {
        int s, t;
        cin >> s >> t;
        s = component[ppp[a[s-1]]];
        t = component[ppp[a[t-1]]];
        if (s > t) swap(s, t);
        if (s == t) cout << 0 << "\n";
        else if (good_pairs.count({s, t})) cout << 1 << "\n";
        else cout << 2 << "\n";
    }
}