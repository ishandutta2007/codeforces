#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    int ntest;
    cin >> ntest;
    while (ntest--) {
        int n;
        cin >> n;
        cout << n;
        for (int i = 1; i < n; ++i) {
            cout << ' ' << i;
        }
        cout << '\n';
    }
    
    return 0;
}