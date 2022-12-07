#include <bits/stdc++.h>
using namespace std;
#define int long long

int query(int a, int b, bool dig) {
    int x;
    if(dig) cout << "DIG " << a << " " << b << endl;
    else cout << "SCAN " << a << " " << b << endl;
    cin >> x;
    return x;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int t;
    cin >> t;
    while(t--) {
        int n, m;
        cin >> n >> m;
        int a = query(1, 1, false);
        int b = query(1, m, false);
        int A = (a + 4 + b + 2 - 2*m)/2; // r1 + r2
        int B = (a + 4 - b - 2 + 2*m)/2; // c1 + c2
        int x = query(A/2, 1, false);
        int r1 = (x + 2 - B + A)/2;
        int r2 = (A - x - 2 + B)/2;
        int y = query(1, B/2, false);
        int c1 = (y + 2 - A + B)/2;
        int c2 = (B - y - 2 + A)/2;
        int ans = query(r1, c1, true);
        if(ans) {
            query(r2, c2, true);
        } else {
            query(r1, c2, true);
            query(r2, c1, true);
        }
    }
    
    return 0;
}