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

const int MAXN = 2000;

int n, k;
void reset_memory() { cout << "R" << endl; }
bool taste(int c) {
    cout << "? " << c << endl;
    char ans;
    cin >> ans;
    return ans == 'Y';
}

bool original[MAXN];

void examine_pair(vector<int> A, vector<int> B) {
    reset_memory();
    assert(SZ(A) == k and SZ(B) == k);
    int a_orig = 0, b_orig = 0;
    for (int a: A) if (original[a]) assert(!taste(a)), a_orig++;
    if (a_orig == 0) return;
    int b0 = -1;
    for (int b: B) {
        if (!original[b]) continue;
        b_orig++;
        if (taste(b)) original[b] = false;
        else b0 = b;
    }
    if (b0 == -1) return;
    while (a_orig + b_orig <= 2*k) assert(taste(b0)), b_orig++;

    int q = 0;
    for (int a: A) {
        q++;
        if (q == k) break; // skip the last element of a.
        if (original[a] and taste(a)) original[a] = false;
    }
}

void examine_list(vector<int> A) {
    assert(SZ(A) == k);
    for (int a: A) if (taste(a)) original[a] = false;
}

int main() {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) original[i] = true;
    int q = n/k;
    vector<vector<int>> groups(q);
    for (int i = 0; i < q; i++) for (int j = 1; j <= k; j++)
        groups[i].push_back(k*i+j);
    for (int i = 0; i < q; i++) examine_list(groups[i]);
    for (int i = 0; i < q; i++) for (int j = i+1; j < q; j++)
        examine_pair(groups[i], groups[j]);
        
    int res = 0;
    for (int i = 1; i <= n; i++) res += original[i];
    cout << "! " << res << endl;
}