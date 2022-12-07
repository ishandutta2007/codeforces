#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int t;
    cin >> t;
    while(t--) {
        int a;
        cin >> a;
        int b, c, d;
        int x = 0;
        cin >> b >> c >> d;
        if(b > a) x++;
        if(c > a) x++;
        if(d > a) x++;
        cout << x << '\n';
    }
    
    return 0;
}