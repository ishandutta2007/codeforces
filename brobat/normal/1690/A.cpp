#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        int a, b, c;
        if(n % 3 == 0) {
            a = n/3;
            b = a + 1;
            c = a - 1;
        } else if(n % 3 == 1) {
            a = n/3;
            b = a + 1;
            c = a - 1;
            b++;
        } else {
            a = n/3;
            b = a + 1;
            c = a - 1;
            a++;
            b++;
        }
        cout << a << " " << b << " " << c << '\n';
    }
    
    return 0;
}