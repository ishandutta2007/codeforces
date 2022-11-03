#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
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

template<typename S, typename T>
ostream& operator << (ostream& out, const pair<S, T>& p) {
    return out << "{" << p.first << ", " << p.second << "}";
}

template<typename I>
class iter_type {
    public:
    const I b, e;
    iter_type(I b, I e) : b(b), e(e) { }
};

template<typename I>
iter_type<I> iter(I b, I e) {
    return iter_type<I>(b, e);
}

template<typename T>
auto iter(T& v) -> iter_type<decltype(begin(v))> {
    return iter_type<decltype(begin(v))>(begin(v), end(v));
}

template<typename I>
ostream& operator << (ostream& out, const iter_type<I>& x) {
    out << "[";
    for(I it = x.b; it != x.e; ++it) {
        out << *it;
        if(next(it) != x.e) {
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


//////////////////////
// HAPPY CODING  :) //
//////////////////////

vector<int> G[100100];

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
    double S;
    cin >> N >> S;
    for(int n = 0; n + 1 < N; ++n) {
        int u, v;
        cin >> u >> v;
        --u;
        --v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    int leaves = 0;
    for(int n = 0; n < N; ++n) {
        if(G[n].size() == 1) {
            ++leaves;
        }
    }
    cout << fixed << setprecision(20) << (2 * S / double(leaves)) << "\n";
    
    return 0;
}