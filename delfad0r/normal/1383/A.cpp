#include <bits/stdc++.h>

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

template<typename S, typename T>
ostream& operator << (ostream& out, const pair<S, T>& p) {
    return out << "{" << p.first << ", " << p.second << "}";
}

void solve() {
    int N;
    cin >> N;
    string A, B;
    cin >> A >> B;
    int ans = 0;
    for(char c = 'a'; c <= 't'; ++c) {
        char to_change = 'z';
        for(int n = 0; n < N; ++n) {
            if(A[n] == c and B[n] != c) {
                to_change = min(to_change, B[n]);
            }
        }
        if(to_change < c) {
            cout << "-1\n";
            return;
        }
        if(to_change <= 't') {
            for(int n = 0; n < N; ++n) {
                if(A[n] == c and B[n] != c) {
                    A[n] = to_change;
                }
            }
            ++ans;
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