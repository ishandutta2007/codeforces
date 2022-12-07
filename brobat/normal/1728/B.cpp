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
        if(n % 2) {
            cout << "1 2 3 ";
            for(int i = 4; i <= n - 2; i += 2) cout << i + 1 << ' ' << i << ' ';
            cout << n - 1 << ' ' << n << '\n';
        } else {
            for(int i = 2; i <= n - 2; i += 2) cout << i << ' ' << i - 1 << ' ';
            cout << n - 1 << ' ' << n << '\n'; 
        }
    }
    
    return 0;
}