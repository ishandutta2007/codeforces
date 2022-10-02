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

#ifndef FENWICK
#define FENWICK

// Fenwick tree implementation to compute sum on subsegments.
// Each function requires O(log(N)).

#include <cmath>
#include <vector>
#include <iostream>
using namespace std;

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
        if (l > r) return 0;
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

#endif  // FENWICK
        


///////////////////////////////////////////////////////////////////////////
//////////////////// DO NOT TOUCH BEFORE THIS LINE ////////////////////////
///////////////////////////////////////////////////////////////////////////


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); // Remove in problems with online queries!

    int n;
    cin >> n;

    vector<LL> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    
    const int Z0 = 500;
    const int Z1 = 200;
    const int MAXVAL = 3e5 + 10;
    vector<LL> cnt(MAXVAL);
    LL sum = 0;
    Fenwick<LL> fen0(MAXVAL), fen1(MAXVAL);
    vector<LL> ans(n);
    for (int k = 0; k < n; k++) {
        LL x = a[k];

        LL ris1 = k*x; // x mod a_i.
        int up = x;
        for (int q = 1; ; q++) {
            if (up < Z0) break;
            int down = x/(q+1)+1;
            ris1 -= q*fen1.GetRange(down, up);
            up = down-1;
        }
        for (int t = 1; t <= up; t++) ris1 -= cnt[t]*t*(x/t);


        LL ris2 = 0; // a_i mod x.
        if (x < Z1) {
            for (int i = 0; i < k; i++) ris2 += a[i] % x;
        } else {
            ris2 += sum;
            for (int q = 1; ; q++) {
                int down = q*x;
                int up = (q+1)*x-1;
                if (down >= MAXVAL) break;
                up = min(up, MAXVAL-1);
                ris2 -= q*x * fen0.GetRange(down, up);
            }
        }
        ans[k] = ris1 + ris2;
        if (k > 0) ans[k] += ans[k-1];
        

        fen0.Add(x, 1);
        fen1.Add(x, x);
        cnt[x]++;
        sum += x;

        // LL ris1_correct = 0;
        // LL ris2_correct = 0;
        // for (int i = 0; i < k; i++) {
            // ris1_correct += x % a[i];
            // ris2_correct += a[i] % x;
        // }
        // assert(ris1 == ris1_correct);
        // assert(ris2 == ris2_correct);
    }

    for (int k = 0; k < n; k++) cout << ans[k] << " ";
    cout << "\n";
}