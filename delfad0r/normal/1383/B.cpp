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
    vector<int> A(N);
    vector<int> C(32);
    for(int& a : A) {
        cin >> a;
        for(int i = 0; i <= 30; ++i) {
            C[i] += ((a & (1 << i)) != 0);
        }
    }
    for(int i = 30; i >= 0; --i) {
        if(C[i] % 2) {
            if(C[i] % 4 == 1 or (N - C[i]) % 2 == 1) {
                cout << "WIN\n";
            } else {
                cout << "LOSE\n";
            }
            return;
        }
    }
    cout << "DRAW\n";
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