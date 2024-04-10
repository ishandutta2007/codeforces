#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int t;
    cin >> t;
    while(t--) {
        int n, m;
        cin >> n >> m;
        if(m < n) {
            cout << "No" << '\n';
        }
        else if(n % 2 == 1) {
            cout << "Yes" << '\n';
            for(int i = 0; i < n - 1; i++) cout << 1 << ' ';
            cout << m - n + 1 << '\n';
        } else if(m % 2 == 0) {
            cout << "Yes" << '\n';
            for(int i = 0; i < n - 2; i++) cout << 1 << ' ';
            int x = (m - n + 2)/2;
            cout << x << ' ' << x << '\n';
        } else {
            cout << "No" << '\n';
        }
    }
    
    return 0;
}