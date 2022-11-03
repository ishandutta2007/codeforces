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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int R, N;
    cin >> R >> N;
    vector<int> X(N + 1), Y(N + 1), T(N + 1);
    vector<int> ans(N + 1, -(1 << 30));
    X[0] = Y[0] = 1;
    T[0] = 0;
    ans[0] = 0;
    for(int n = 1; n <= N; ++n) {
        cin >> T[n] >> X[n] >> Y[n];
    }
    int max_ans_prev = -(1 << 30);
    for(int n = 1; n <= N; ++n) {
        ans[n] = max_ans_prev + 1;
        debug(n);
        debug(max_ans_prev);
        for(int i = max(0, n - 2 * R); i < n; ++i) {
            if(abs(X[i] - X[n]) + abs(Y[i] - Y[n]) <= T[n] - T[i]) {
                ans[n] = max(ans[n], ans[i] + 1);
            }
        }
        if(n >= 2 * R) {
            max_ans_prev = max(max_ans_prev, ans[n - 2 * R]);
        }
    }
    debug(ans);
    cout << *max_element(all_of(ans)) << "\n";
    
    
    
    return 0;
}