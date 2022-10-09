#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    int ntest;
    cin >> ntest;
    while (ntest--) {
        int n;
        cin >> n;
        string a[2];
        cin >> a[0] >> a[1];
        
        bool ok = true;
        for (int i = 0; i < n and ok; ++i) {
            if (a[0][i] == '1' and a[1][i] == '1') {
                ok = false;
            }
        }
        cout << (ok ? "YES" : "NO") << '\n';
    }
    
    return 0;
}