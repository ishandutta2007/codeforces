#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector <int> x(n), y(n);
        int a = 0, b = 0, c = 0, d = 0;
        for(int i = 0; i < n; i++) {
            cin >> x[i] >> y[i];
            a = max(a, x[i]);
            c = max(c, y[i]);
            b = min(b, x[i]);
            d = min(d, y[i]);
        }
        cout << (a - b + c - d)*2 << '\n';
    }
    
    return 0;
}