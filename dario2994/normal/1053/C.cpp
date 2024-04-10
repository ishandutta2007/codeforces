#define _USE_MATH_DEFINES
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

template <typename Container>
int SZ(const Container& S) { return S.size(); }

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
        if (l > 0) return GetRange(0, r) - GetRange(0, l-1);
        Value res = 0;
        for (; r >= 0; r = (r&(r+1))-1) res += container[r];
        return res;
    }

    // Prints the current state of the Fenwick tree.
    // void Debug() {
    //     cout << "Internal container representation (size = " << size << "):\n";
    //     for (int i = 0; i < size; i++) cout << container[i] << " ";
    //     cout << "\nValues of the entries:\n";
    //     for (int i = 0; i < size; i++) cout << Get(i) << " ";
    //     cout << "\n";
    //     cout.flush();
    // }

  private:
    int size; // = container.size() (just to have a shorter name).
    int max_pow2; // = maximum integer such that (1 << max_pow2) <= N.
    // container[xxx01...1] contains the sum of all the entries from
    // xxx00...0 to xxx01...1 inclusive.
    // i.e. container[2] contains exactly the value of entry[2], whereas
    // container[3] contains the sum entry[0] + entry[1] + entry[2] + entry[3].
    vector<Value> container;
};


const LL mod = 1e9+7;

template <typename Value>
class FenwickMod {
  public:
    // The Fenwick tree is initialized leaving all entries with the value 0.
    FenwickMod(int N) :
        size(N),
        max_pow2(log2(N)),
        container(N, 0) {}

    // Initialize the Fenwick tree with the given values as entries.
    FenwickMod(const vector<Value>& initial_values) :
            FenwickMod(initial_values.size()) {
        for (int p = 0; p < size; p++) {
            int q = p | (p+1);
            container[p] += initial_values[p];
            container[p] %= mod;
            if (q < size) {
                container[q] += container[p];
                container[q] %= mod;
            }
        }
    }

    // Add x to the p-th entry.
    void Add(int p, Value x) {
        for (; p < size; p |= (p+1)) {
            container[p] += x;
            container[p] %= mod;
        }
    }

    // Get the sum on the interval [l, r].
    Value GetRange(int l, int r) {
        if (l > 0) return (GetRange(0, r) - GetRange(0, l-1))%mod;
        Value res = 0;
        for (; r >= 0; r = (r&(r+1))-1) res += container[r];
        res %= mod;
        return res;
    }

    // Prints the current state of the Fenwick tree.
    // void Debug() {
    //     cout << "Internal container representation (size = " << size << "):\n";
    //     for (int i = 0; i < size; i++) cout << container[i] << " ";
    //     cout << "\nValues of the entries:\n";
    //     for (int i = 0; i < size; i++) cout << Get(i) << " ";
    //     cout << "\n";
    //     cout.flush();
    // }

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
    int N, Q;
    cin >> N >> Q;
    vector<LL> A(N+10, 0), W(N+10, 0), AW(N+10, 0);
    for (int i = 1; i <= N; i++) cin >> A[i], A[i]-=i;
    for (int i = 1; i <= N; i++) cin >> W[i];
    for (int i = 1; i <= N; i++) AW[i] = A[i]*W[i] % mod;
    Fenwick<LL> fenw(W);
    FenwickMod<LL> fenaw(AW);
    for (int q = 0; q < Q; q++) {
        int x, y;
        cin >> x >> y;
        if (x < 0) {
            x = -x;
            fenw.Add(x, y-W[x]);
            fenaw.Add(x, (A[x]*y - A[x]*W[x]) % mod);
            W[x] = y;
        } else {
            int l = x, r = y;
            while (l < r) {
                int m = (l+r)/2;
                if (fenw.GetRange(x, m) < fenw.GetRange(m+1, y)) l = m+1;
                else r = m;
            }
            int m = l;
            // dbg_var(m);
            l = x, r = y;
            LL res1 = A[m]*(fenw.GetRange(l, m) % mod) % mod;
            LL res2 = fenaw.GetRange(l, m);
            LL res3 = A[m]*(fenw.GetRange(m, r) % mod) % mod;
            LL res4 = fenaw.GetRange(m, r);
            LL res = res1 - res2 - res3 + res4;
            res %= mod;
            if (res < 0) res += mod;
            cout << res << "\n";
        }
    }
}