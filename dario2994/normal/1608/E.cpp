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

// A structure able to perform the following operation on an array A:
// 1. Sum x to A[i].
// 2. Get the sum A[l] + A[l+1] + ... + A[r].
// Both the operation are O(log(N)).
// Everything is 0-based.
template <typename Value>
class Fenwick {
  public:
    // The Fenwick tree is initialized leaving all entries with the value 0.
    Fenwick(int N) :
        size(N),
        max_pow2(log2(N)),
        container(N, 0) {}

    // Initialize the Fenwick tree with the given values as entries.
    Fenwick(const vector<Value>& initial_values) :
            Fenwick(initial_values.size()) {
        for (int p = 0; p < size; p++) {
            int q = p | (p+1);
            container[p] += initial_values[p];
            if (q < size) container[q] += container[p];
        }
    }

    // Add x to the p-th entry.
    void Add(int p, Value x) {
        for (; p < size; p |= (p+1)) container[p] += x;
    }

    // Get the sum on the interval [l, r].
    Value GetRange(int l, int r) {
        if (l > 0) return GetRange(0, r) - GetRange(0, l-1);
        Value res = 0;
        for (; r >= 0; r = (r&(r+1))-1) res += container[r];
        return res;
    }

    // Get the value of the p-th entry.
    Value Get(int p) {
        return GetRange(p, p);
    }
    
    // Get the smallest p >= 0 such that GetRange(0, p) >= x.
    // If such a p does not exist, it returns size.
    // ACHTUNG: Works only if all values are nonnegative.
    int LowerBound(Value x) {
        Value sum = 0;
        int res = 0;
        for(int i = 1 << max_pow2; i > 0; i >>= 1) {
            if(res + i - 1 < size and sum + container[res + i - 1] < x) {
                sum += container[res + i - 1];
                res += i;
            }
        }
        return res;
    }

    // Set the p-th entry to x.
    void Set(int p, Value x) {
        Add(p, x - Get(p));
    }

    // Prints the current state of the Fenwick tree.
    void Debug() {
        cout << "Internal container representation (size = " << size << "):\n";
        for (int i = 0; i < size; i++) cout << container[i] << " ";
        cout << "\nValues of the entries:\n";
        for (int i = 0; i < size; i++) cout << Get(i) << " ";
        cout << "\n";
        cout.flush();
    }
    
  private:
    int size; // = container.size() (just to have a shorter name).
    int max_pow2; // = maximum integer such that (1 << max_pow2) <= N.
    // container[xxx01...1] contains the sum of all the entries from
    // xxx00...0 to xxx01...1 inclusive.
    // i.e. container[2] contains exactly the value of entry[2], whereas
    // container[3] contains the sum entry[0] + entry[1] + entry[2] + entry[3].
    vector<Value> container;
};

///////////////////////////////////////////////////////////////////////////
//////////////////// DO NOT TOUCH BEFORE THIS LINE ////////////////////////
///////////////////////////////////////////////////////////////////////////

const int MAXN = 1e5 + 10;
int x[MAXN], y[MAXN];
int c[MAXN];
int c2[MAXN];

int n;
int solve() {
    Fenwick<int> A(n+2), B(n+2);
    for (int i = 0; i < n; i++) {
        if (c[i] == 1) A.Add(y[i], 1);
        if (c[i] == 2) B.Add(y[i], 1);
    }

    vector<int> ord(n);
    for (int i = 0; i < n; i++) ord[i] = i;
    sort(ord.begin(), ord.end(), [&](int i, int j) { return x[i] < x[j]; });
    int zero_aft = n/3;
    int one_bef = 0;
    int two_bef = 0;
    int it = 0;
    int res = 1e6;
    int hard_aft = -1;
    for (int _ = 0; _ <= n; _++) {
        bool changed = false;
        while (it < n and x[ord[it]] == _) {
            int i = ord[it];
            it++;
            if (c[i] == 0) zero_aft--;
            if (c[i] == 1) {
                one_bef++;
                A.Add(y[i], -1);
                changed = true;
            }
            if (c[i] == 2) {
                two_bef++;
                B.Add(y[i], -1);
                changed = true;
            }
        }
        if (hard_aft == -1 or changed) {
            int l = 0;
            int r = n;
            while (l < r) {
                int m = (l+r)/2;
                if (A.GetRange(0, m) + one_bef < B.GetRange(m+1, n) + two_bef) l = m+1;
                else r = m;
            }
            hard_aft = max(A.GetRange(0, l) + one_bef, B.GetRange(l+1, n) + two_bef);
        }
        res = min(res, max(zero_aft, hard_aft));
    }
    
    return res;
}

int solve2() {
    Fenwick<int> A(n+2), B(n+2);
    for (int i = 0; i < n; i++) {
        if (c[i] == 1) A.Add(x[i], 1);
        if (c[i] == 2) B.Add(x[i], 1);
    }

    vector<int> ord(n);
    for (int i = 0; i < n; i++) ord[i] = i;
    sort(ord.begin(), ord.end(), [&](int i, int j) { return x[i] < x[j]; });
    int zero_aft = n/3;
    int one_bef = 0;
    int two_bef = 0;
    int it = 0;
    int res = 1e6;
    int hard_aft = -1;
    for (int _ = 0; _ <= n; _++) {
        bool changed = false;
        while (it < n and x[ord[it]] == _) {
            int i = ord[it];
            it++;
            if (c[i] == 0) zero_aft--;
            if (c[i] == 1) {
                one_bef++;
                A.Add(x[i], -1);
                changed = true;
            }
            if (c[i] == 2) {
                two_bef++;
                B.Add(x[i], -1);
                changed = true;
            }
        }
        if (hard_aft == -1 or changed) {
            int l = 0;
            int r = n;
            while (l < r) {
                int m = (l+r)/2;
                if (A.GetRange(0, m) + one_bef < B.GetRange(m+1, n) + two_bef) l = m+1;
                else r = m;
            }
            hard_aft = max(A.GetRange(0, l) + one_bef, B.GetRange(l+1, n) + two_bef);
        }
        res = min(res, max(zero_aft, hard_aft));
    }
    
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); // Remove in problems with online queries!

    cin >> n;
    vector<int> xx(n);
    vector<int> yy(n);
    for (int i = 0; i < n; i++) {
        cin >> x[i] >> y[i] >> c2[i];
        xx[i] = x[i];
        yy[i] = y[i];
        c2[i]--;
    }
    sort(xx.begin(), xx.end());
    xx.erase(unique(xx.begin(), xx.end()), xx.end());

    sort(yy.begin(), yy.end());
    yy.erase(unique(yy.begin(), yy.end()), yy.end());

    for (int i = 0; i < n; i++) {
        x[i] = lower_bound(xx.begin(), xx.end(), x[i]) - xx.begin();
        y[i] = lower_bound(yy.begin(), yy.end(), y[i]) - yy.begin();
    }

    int res = 1e6;
    for (int _ = 0; _ < 4; _++) {
        vector<int> perm = {0, 1, 2};
        do {
            for (int i = 0; i < n; i++) c[i] = perm[c2[i]];
            res = min(res, solve());
            if (_ < 2) res = min(res, solve2());
        } while (next_permutation(perm.begin(), perm.end()));
        // ROTATE STUFF
        for (int i = 0; i < n; i++) {
            swap(x[i], y[i]);
            x[i] = n-1-x[i];
        }
    }

    cout << n - 3*res << "\n";
    
}