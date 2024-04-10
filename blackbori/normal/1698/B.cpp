#include <bits/stdc++.h>

using namespace std;

int A[202020];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t, n, k;
    
    cin >> t;
    for (int i = 0; i < t; i++) {
        cin >> n >> k;
        for (int j = 1; j <= n; j++) {
            cin >> A[j];
        }
        if (k == 1) {
            cout << ((n - 1) / 2) << "\n";
        }
        else {
            int cnt = 0;
            for (int j = 2; j <= n - 1; j++) {
                if (A[j] > A[j - 1] + A[j + 1]) {
                    cnt++;
                }
            }
            cout << cnt << "\n";
        }
    }
    return 0;
}