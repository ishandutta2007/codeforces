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

void solve() {
    int N;
    cin >> N;
    vector<int> A(N);
    vector<int> D(N + 1, -1);
    vector<int> last_occ(N + 1, -1);
    cin >> A;
    for(int n = 0; n < N; ++n) {
        D[A[n]] = max(D[A[n]], n - last_occ[A[n]]);
        last_occ[A[n]] = n;
    }
    vector<int> ans(N + 1, N + 1);
    for(int x = 1; x <= N; ++x) {
        D[x] = max(D[x], N - last_occ[x]);
        if(D[x] >= 0 and D[x] <= N) {
            ans[D[x]] = min(ans[D[x]], x);
        }
    }
    for(int n = 2; n <= N; ++n) {
        ans[n] = min(ans[n], ans[n -1]);
    }
    for(int n = 1; n <= N; ++n) {
        cout << ((ans[n] <= N) ? (ans[n]) : (-1)) << " ";
    }
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int T;
    cin >> T;
    while(T--) {
        solve();
    }
    
    return 0;
}