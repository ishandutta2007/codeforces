#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int N;
    cin >> N;
    vector<int> X(N), H(N);
    for(int n = 0; n < N; ++n) {
        cin >> X[n] >> H[n];
    }
    int r = -(1 << 30);
    int ans = 0;
    for(int n = 0; n < N; ++n) {
        if(X[n] - H[n] > r) {
            ++ans;
            r = X[n];
        } else if(n + 1 >= N or X[n] + H[n] < X[n + 1]) {
            ++ans;
            r = X[n] + H[n];
        } else {
            r = X[n];
        }
    }
    cout << ans << "\n";
}