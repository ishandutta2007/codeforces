#include <bits/stdc++.h>
using namespace std;
#define int long long

const int B = 30;

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int t;
    cin >> t;
    while(t--) {
        int n, m;
        cin >> n >> m;
        // find smallest x such that n^x > m.
        int x = 0;
        m++;
        for(int i = B - 1; i >= 0; i--) {
            if((n^x) >= m) break;
            int a = (n >> i) & 1;
            int b = (m >> i) & 1;
            if(a != b) {
                x += (1<<i);
            }
        }
        cout << x << '\n';
    }
    
    return 0;
}