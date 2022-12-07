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
        if(n == 3) {
            cout << -1 << '\n';
            continue;
        }
        if(n % 2 == 0) {
            for(int i = 1; i <= n; i += 2) cout << i + 1 << ' ' << i << ' ';
            cout << '\n';
        } else {
            cout << "5 4 1 2 3 ";
            for(int i = 7; i <= n; i += 2) cout << i << ' ' << i - 1 << ' ';
            cout << '\n';
        }
    }
    
    return 0;
}