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
    cin >> A;
    int ans = 0;
    vector<int> M(N + 1, 0);
    ++M[A[0]];
    ++M[A[N - 1]];
    int cnt = 0;
    vector<int> X(N + 1, 0);
    for(int n = 1; n < N; ++n) {
        if(A[n] == A[n - 1]) {
            M[A[n]] += 2;
            ++ans;
        } else {
            ++cnt;
            ++X[A[n]];
            ++X[A[n - 1]];
        }
    }
    for(int i = 1; i <= N; ++i) {
        if(M[i] <= ans + 2) {
            continue;
        }
        if(M[i] - ans - 2 > cnt - X[i]) {
            cout << "-1\n";
            return;
        } else {
            cout << (M[i] - 2) << "\n";
            return;
        }
    }
    cout << ans << "\n";
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