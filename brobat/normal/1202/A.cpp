#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int t;
    cin >> t;
    while(t--) {
        string x, y;
        cin >> x >> y;
        int a = 0;
        int b = 0;
        reverse(y.begin(), y.end());
        reverse(x.begin(), x.end());
        int i = 0;
        while(true) {
            if(y[i] == '1') {
                a = i;
                break;
            }
            i++;
        }
        i = a;
        while(true) {
            if(x[i] == '1') {
                b = i;
                break;
            }
            i++;
        }
        cout << b - a << '\n';
    }
    
    return 0;
}