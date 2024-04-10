#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        if(n % 2) {
            cout << n << ' ';
            n--;
        }
        for(int i = n/2; i >= 1; i--) cout << i << ' ' << n/2 + i << ' ';
        cout << '\n';
    }
    
    return 0;
}