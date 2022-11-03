#include <bits/stdc++.h>

using namespace std;

typedef long long LL;


template<typename T>
ostream& operator << (ostream& out, const vector<T>& v) {
    out << "[";
    for(const auto& x : v) {
        out << x << ", ";
    }
    return out << "]";
}

template<typename T, typename S>
ostream& operator << (ostream& out, const pair<T, S>& p) {
    return out << "{" << p.first << ", " << p.second << "}";
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int N;
    cin >> N;
    map<int, LL> M;
    for(int n = 0; n < N; ++n) {
        int b;
        cin >> b;
        M[b - n] += b;
    }
    LL ans = 0;
    for(auto [i, j] : M) {
        ans = max(ans, j);
    }
    cout << ans << "\n";
    
    
    
    return 0;
}