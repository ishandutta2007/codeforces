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
    size_t sz;
public:
    iter_type(I b, I e, const size_t& sz) : b(b), e(e), sz(sz) { }
    I begin() const {
        return b;
    }
    I end() const {
        return e;
    }
    size_t size() const {
        return sz;
    }
};

template<typename I>
iter_type<I> iter(I b, I e, const size_t& sz) {
    return iter_type<I>(b, e, sz);
}

template<typename I>
iter_type<I> iter(I b, I e) {
    return iter_type<I>(b, e, e - b);
}

template<typename T>
auto iter(T& v) -> iter_type<decltype(begin(v))> {
    return iter_type<decltype(begin(v))>(begin(v), end(v), end(v) - begin(v));
}


// Range iterator

template<typename T>
class range_iterator;

template<typename T>
iter_type<range_iterator<T>> range(const T& begin, const T& end) {
    return iter(range_iterator<T>(begin), range_iterator<T>(end), end - begin);
}

template<typename T>
iter_type<range_iterator<T>> to_infinity(const T& begin = T(0)) {
    return iter(range_iterator<T>(begin), range_iterator<T>(T(-1)), -1);
}

template<typename T>
class range_iterator {
    friend iter_type<range_iterator<T>> range<>(const T&, const T&);
    friend iter_type<range_iterator<T>> to_infinity<>(const T&);
public:
    T operator *() const {
        return i_;
    }
    const range_iterator& operator ++() {
        ++i_;
        return *this;
    }
    range_iterator operator ++(int) {
        range_iterator copy(*this);
        ++i_;
        return copy;
    }
    bool operator ==(const range_iterator& other) const {
        return i_ == other.i_;
    }
    bool operator !=(const range_iterator& other) const {
        return i_ != other.i_;
    }
protected:
    range_iterator(const T& start) :
        i_(start) { }
private:
    T i_;
};



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
    for(I it = x.begin(); it != x.end(); ++it) {
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

template<typename T, typename Op = plus<T>>
class fenwick_t {
    int N, max_pow2;
    vector<T> ft;
    const Op op;
public:
    fenwick_t(int N, const T& val = T(), const Op& op = Op()) :
        N(N), max_pow2(log2(N)), ft(N, val), op(op) { }
    template<typename I>
    fenwick_t(const iter_type<I>& it, const Op& op = Op()) :
        fenwick_t(it.size(), T(), op) {
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
            if(ans + i - 1 < int(N) and op(total, ft[ans + i - 1]) <= x) {
                total = op(total, ft[ans + i - 1]);
                ans += i;
            }
        }
        return ans;
    }
};



//////////////////////
// HAPPY CODING  :) //
//////////////////////

int main() {
    // remove in interactive problems
    #ifdef DEBUG
    freopen("input.txt", "r", stdin);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    //
    
    int N;
    cin >> N;
    vector<int> a(N);
    vector<LL> pref(N);
    cin >> a;
    sort(a.begin(), a.end(), greater<int>());
    pref[0] = a[0];
    for(int k = 1; k < N; ++k) {
        pref[k] = pref[k - 1] + a[k];
    }
    fenwick_t<LL> ft(iter(a));
    fenwick_t<int> ft_cnt(N, 0);
    vector<LL> L(N + 2), M(N + 2);
    // L[k] = F(k,k)
    // M[k] = F(k - 1, k)
    for(int k = N + 1, i = 0; k >= 0; --k) {
        while(i < N and a[i] > k) {
            ft.update(i, -a[i]);
            ft_cnt.update(i, 1);
            ++i;
        }
        if(k <= N) {
            L[k] = ft.get_range(k, N) + LL(k) * ft_cnt.get_range(k, N);
        }
        if(k > 0) {
            M[k] = ft.get_range(k - 1, N) + LL(k) * ft_cnt.get_range(k - 1, N);
        }
    }
    //~ cerr << a << endl;
    //~ cerr << L << endl << M << endl;
    LLLL interval = LLLL(0, N);
    for(LL k = 0; k < N; ++k) {
        LLLL i1, i2;
        LL r = (k + 2) * (k + 1) + M[k + 2] - pref[k];
        LL l = pref[k] - (k + 1) * k - L[k + 1];
        i1 = LLLL(a[k] + 1, max(LL(a[k]), r));
        if(k + 1 < l) {
            i2 = LLLL(a[k] + 1, a[k] + 1);
        } else {
            i2 = LLLL(min(LL(a[k] + 1), l), a[k]);
        }
        //~ cerr << k << " " << a[k] << " " << r << " " << M[k + 2] << " " << pref[k] << endl;
        interval.first = max(interval.first, i2.first);
        interval.second = min(interval.second, i1.second);
    }
    vector<int> ans;
    for(int A = interval.first; A <= interval.second; ++A) {
        LL t = upper_bound(a.begin(), a.end(), A, greater<int>()) - a.begin();
        if(((t == N) ? (pref[N - 1]) : (pref[t] - a[t])) + A <= t * (t + 1) + M[t + 1] and (A + pref[N - 1]) % 2 == 0) {
            ans.push_back(A);
        }
    }
    if(ans.size()) {
        for(int u : ans) {
            cout << u << " ";
        }
        cout << "\n";
    }
    else {
        cout << "-1\n";
    }
    
    return 0;
}