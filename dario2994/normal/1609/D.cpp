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

void erase_one(multiset<int>& S, int x) {
    S.erase(S.find(x));
}

struct MegaSet {
    int k;
    int sum;
    multiset<int> large;
    multiset<int> small;
    void add(int x) {
        
    }
    void remove(int x) {
        if (small.count(x)) erase_one(small, x);
        else {
            erase_one(large, x);
            sum -= x;
            k--;
        }
    }
    int large_sum(int k0) {
        assert(k0 >= k);
        while (k < k0) {
            int x = *small.rbegin();
            large.insert(x);
            k++;
            sum += x;
            erase_one(small, x);
        }
        return sum;
    }
};

const int MAXN = 1e6 + 10;
int sz[MAXN];
int anc[MAXN];
int ancestor(int v) {
    if (anc[anc[v]] != anc[v]) anc[v] = ancestor(anc[v]);
    return anc[v];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); // Remove in problems with online queries!

    int n, d;
    cin >> n >> d;
    for (int i = 1; i <= n; i++) anc[i] = i, sz[i] = 1;
    int q = 1;
    for (int _ = 1; _ <= d; _++) {
        int a, b;
        cin >> a >> b;
        a = ancestor(a);
        b = ancestor(b);
        if (a == b) q++;
        else {
            sz[a] += sz[b];
            sz[b] = 0;
            anc[b] = a;
        }
        vector<int> z;
        for (int i = 1; i <= n; i++) if (sz[i] != 0) z.push_back(sz[i]);
        sort(z.begin(), z.end());
        reverse(z.begin(), z.end());
        assert(q <= SZ(z));
        int res = 0;
        for (int i = 0; i < q; i++) res += z[i];
        cout << res - 1 << "\n";
    }
}