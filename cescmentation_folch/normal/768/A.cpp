#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    
    int M =  -1;
    int m = 1e9 + 1;
    int qM = 0;
    int qm = 0;
    
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        if (x == M) ++qM;
        if (x == m) ++qm;
        if (x > M) {
            M = x;
            qM = 1;
        }
        if (x < m) {
            m = x;
            qm = 1;
        }
    }
    
    if (m == M) cout << 0 << endl;
    else cout << n - qM - qm << endl;
    
}