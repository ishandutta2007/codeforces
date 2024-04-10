#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t; cin >> t;
    while(t--) {
        int a, b, c, d, k; cin >> a >> b >> c >> d >> k;
        int x = 1+(a-1)/c, y = 1+(b-1)/d;
        if(x+y > k) cout << -1 << endl;
        else cout << x << ' ' << y << endl;
    }
}