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
        cout << n << '\n';
        vector<int> v(n);
        iota(v.begin(), v.end(), 1);
        for(int i = 0; i < n; i++) cout << v[i] << ' '; cout << '\n';
        swap(v[n - 1], v[n - 2]);
        for(int i = 0; i < n; i++) cout << v[i] << ' '; cout << '\n';
        for(int i = n - 3; i >= 0; i--) {
            swap(v[i], v[n - 1]);
            for(int i = 0; i < n; i++) cout << v[i] << ' '; cout << '\n';
        }
    }
    
    return 0;
}