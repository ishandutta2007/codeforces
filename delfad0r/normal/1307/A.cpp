#include <bits/stdc++.h>

using namespace std;

typedef long long LL;


void solve() {
    int N, D;
    cin >> N >> D;
    vector<int> A(N);
    for(int& a : A) {
        cin >> a;
    }
    for(int n = 1; n < N; ++n) {
        while(D >= n and A[n] > 0) {
            --A[n];
            ++A[0];
            D -= n;
        }
    }
    cout << A[0] << "\n";
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