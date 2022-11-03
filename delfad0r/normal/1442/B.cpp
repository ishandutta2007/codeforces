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

constexpr int MOD = 998244353;

void solve() {
    int N, K;
    cin >> N >> K;
    vector<int> A(N), B(K);
    cin >> A >> B;
    vector<int> pos(N + 1);
    for(int n = 0; n < N; ++n) {
        pos[A[n]] = n;
    }
    vector<bool> taken(N, false);
    int ans = 1;
    reverse(all_of(B));
    for(int b : B) {
        assert(not taken[pos[b]]);
        int l = (pos[b] > 0 and not taken[pos[b] - 1]);
        int r = (pos[b] < N -1 and not taken[pos[b] + 1]);
        if(l + r == 0) {
            ans = 0;
            break;
        } else if(l + r == 2) {
            ans = (ans * 2) % MOD;
        }
        taken[pos[b]] = true;
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