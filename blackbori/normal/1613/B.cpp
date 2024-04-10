#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int A[202020];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t, n, i, m, j;
    
    for (cin >> t; t--; ) {
        cin >> n;
        for (i = 1; i <= n; i++) {
            cin >> A[i];
        }
        m = *min_element(A + 1, A + n + 1);
        j = n >> 1;
        for (i = 1; i <= n && j; i++) {
            if (A[i] != m) {
                cout << A[i] << " " << m << "\n";
                j--;
            }
        }
    }
    
    return 0;
}