#include "bits/stdc++.h"

#define all_of(x) std::begin(x), std::end(x)
#ifdef _GLIBCXX_DEBUG
    #define debug(x) cerr << #x << ": " << x << endl
#else
    #define debug(x) 
#endif

using namespace std;

using LL = long long;

template<typename T>
ostream& operator << (ostream& out, const vector<T>& v) {
    out << "[";
    for(const auto& x : v) {
        out << x << ", ";
    }
    return out << "]";
}
template<typename T>
istream& operator >> (istream& in, vector<T>& v) {
    for(auto& x : v) {
        in >> x;
    }
    return in;
}

template<typename S, typename T>
ostream& operator << (ostream& out, const pair<S, T>& p) {
    return out << "{" << p.first << ", " << p.second << "}";
}

struct queue_t {
    LL i, x, decr;
};
bool operator < (const queue_t& u, const queue_t& v) {
    return u.decr < v.decr;
}

inline LL f(LL a, LL x) {
    return (a + (a % x)) * (a / x) + (a % x);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int N, K;
    cin >> N >> K;
    vector<LL> A(N);
    cin >> A;
    priority_queue<queue_t> Q;
    LL ans = 0;
    for(int i = 0; i < N; ++i) {
        Q.push(queue_t{i, 1, f(A[i], 1) - f(A[i], 2)});
        ans += f(A[i], 1);
    }
    for(int t = 0; t < K - N; ++t) {
        auto q = Q.top();
        Q.pop();
        ans -= q.decr;
        Q.push(queue_t{q.i, q.x + 1, f(A[q.i], q.x + 1) - f(A[q.i], q.x + 2)});
    }
    cout << ans << "\n";
    
    
    
    return 0;
}