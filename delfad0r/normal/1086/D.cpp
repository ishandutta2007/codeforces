#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <cstring>
#include <cmath>
#include <complex>
#include <cstdio>
#include <deque>
#include <fstream>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector> 
#include <tuple>

using namespace std;

typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> II;
typedef pair<int, LL> ILL;
typedef pair<LL, int> LLI;
typedef pair<LL, LL> LLLL;


// Generic iterables

template<typename I>
class iter_type {
    const I b, e;
public:
    iter_type(I b, I e) : b(b), e(e) { }
    I begin() const {
        return b;
    }
    I end() const {
        return e;
    }
    size_t size() const {
        return e - b;
    }
};

template<typename I>
iter_type<I> iter(I b, I e) {
    return iter_type<I>(b, e);
}

template<typename T>
auto iter(T& v) -> iter_type<decltype(begin(v))> {
    return iter_type<decltype(begin(v))>(begin(v), end(v));
}


// I/O for pairs and iterables

template<typename S, typename T>
ostream& operator << (ostream& out, const pair<S, T>& p) {
    return out << "{" << p.first << ", " << p.second << "}";
}

template<typename S, typename T>
istream& operator >> (istream& in, pair<S, T>& p) {
    return in >> p.first >> p.second;
}

template<typename I>
ostream& operator << (ostream& out, const iter_type<I>& x) {
    out << "[";
    for(auto it = x.begin(); it != x.end(); ++it) {
        out << *it;
        if(next(it) != x.end()) {
            out << ", ";
        }
    }
    return out << "]";
}

template<typename I>
istream& operator >> (istream& in, const iter_type<I>& x) {
    for(I it = x.b; it != x.e; ++it) {
        in >> *it;
    }
    return in;
}

template<typename T>
ostream& operator << (ostream& out, const vector<T>& v) {
    return out << iter(v);
}

template<typename T>
istream& operator >> (istream& in, vector<T>& v) {
    return in >> iter(v);
}

template<typename T>
ostream& operator << (ostream& out, const set<T>& v) {
    return out << iter(v);
}

template<typename S, typename T>
ostream& operator << (ostream& out, const map<S, T>& v) {
    return out << iter(v);
}

template<typename T>
ostream& operator << (ostream& out, const unordered_set<T>& v) {
    return out << iter(v);
}

template<typename S, typename T>
ostream& operator << (ostream& out, const unordered_map<S, T>& v) {
    return out << iter(v);
}


// Fenwick tree

template<typename T, typename op_t = plus<T>>
class fenwick_t {
    int N, max_pow2;
    vector<T> ft;
    const op_t op;
public:
    fenwick_t(int N, const T& val = T(), const op_t& op = op_t()) :
        N(N), max_pow2(log2(N)), ft(N, val), op(op) { }
    template<typename I>
    fenwick_t(const iter_type<I>& it, const op_t& op = op_t()) :
        fenwick_t(it.size(), op) {
        int p = 0, q;
        for(auto x : it) {
            q = p | (p + 1);
            ft[p] = op(ft[p], x);
            if(q < N) {
                ft[q] = op(ft[q], ft[p]);
            }
            ++p;
        }
    }
    void update(int p, const T& v) {
        for(; p < N; p |= p + 1) {
            ft[p] = op(ft[p], v);
        }
    }
    T get_prefix(int r) {   // [0, r)
        --r;
        T ans = T();
        for(; r >= 0; r = (r & (r + 1)) - 1) {
            ans = op(ans, ft[r]);
        }
        return ans;
    }
    T get_range(int l, int r) { // [l, r)
        return get_prefix(r) - get_prefix(l);
    }
    T get(int p) {
        return get_range(p, p + 1);
    }
    int lower_bound(const T& x) {   // min{p : get_prefix(p) >= x}, assuming get_prefix(p) is an increasing function of p
        T total = T();
        int ans = 0;
        for(int i = 1 << max_pow2; i > 0; i >>= 1) {
            if(ans + i - 1 < int(N) and op(total, ft[ans + i - 1]) < x) {
                total = op(total, ft[ans + i - 1]);
                ans += i;
            }
        }
        return ans;
    }
};

int char_to_int[300];

int main() {
    // remove in interactive problems
    #ifdef DEBUG
    freopen("input.txt", "r", stdin);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    //
    
    int N, Q;
    cin >> N >> Q;
    string S;
    cin >> S;
    set<int> A[3];
    memset(char_to_int, -1, sizeof(char_to_int));
    char_to_int['P'] = 0;
    char_to_int['R'] = 1;
    char_to_int['S'] = 2;
    vector<fenwick_t<int>> ft;
    for(int i = 0; i < 3; ++i) {
        ft.emplace_back(N);
    }
    for(int n = 0; n < N; ++n) {
        int i = char_to_int[S[n]];
        A[i].insert(n);
        ft[i].update(n, 1);
    }
    for(int q = 0; q <= Q; ++q) {
        int ans = N;
        for(int i = 0; i < 3; ++i) {
            if(A[(i + 2) % 3].size()) {
                if(A[(i + 1) % 3].size()) {
                    int l1 = *A[(i + 2) % 3].begin(), r2 = *A[(i + 2) % 3].rbegin();
                    int l2 = *A[(i + 1) % 3].begin(), r1 = *A[(i + 1) % 3].rbegin();
                    if(l1 < l2) {
                        ans -= ft[i].get_range(l1, l2);
                    }
                    if(r1 < r2) {
                        ans -= ft[i].get_range(r1, r2);
                    }
                } else {
                    ans -= ft[i].get_range(0, N);
                }
            }
        }
        cout << ans << "\n";
        if(q < Q) {
            int n;
            char c;
            cin >> n >> c;
            --n;
            int i = char_to_int[S[n]], j = char_to_int[c];
            S[n] = c;
            A[i].erase(n);
            A[j].insert(n);
            ft[i].update(n, -1);
            ft[j].update(n, 1);
        }
    }
    
    return 0;
}