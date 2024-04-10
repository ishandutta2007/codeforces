#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int, int> II;

template<typename T>
ostream& operator << (ostream& out, const vector<T>& v) {
    out << "[";
    for(const T& x : v) {
        out << v << ", ";
    }
    out << "]";
    return out;
}

template<typename T, typename S>
ostream& operator << (ostream& out, const pair<T, S>& p) {
    out << "{" << p.first << ", " << p.second << "}";
    return out;
}

int main() {
    #ifdef DEBUG
    freopen("input.txt", "r", stdin);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int N;
    cin >> N;
    vector<LL> M(N, 0), C(N, 0);
    for(int n = 0; n < N; ++n) {
        cin >> C[n];
        for(int i = 0; i < C[n]; ++i) {
            LL x;
            cin >> x;
            M[n] = max(M[n], x);
        }
    }
    LL global_max = *max_element(M.begin(), M.end());
    LL ans = 0;
    for(int n = 0; n < N; ++n) {
        ans += (global_max - M[n]) * C[n];
    }
    cout << ans << "\n";
    
    return 0;
}