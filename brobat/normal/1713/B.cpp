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
        vector <int> v(n);
        for(int i = 0; i < n; i++) {
            cin >> v[i];
        }
        bool pos = true;
        int prev_max = v[0];
        for(int i = 1; i < n - 1; i++) {
            if(v[i] < prev_max && v[i] < v[i + 1]) {
                pos = false;
            }
            prev_max = max(prev_max, v[i]);
        }
        cout << (pos ? "YES" : "NO") << '\n';
    }
    
    return 0;
}