#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    int ntest;
    cin >> ntest;
    while (ntest--) {
        int x;
        cin >> x;
        --x;
        int a[3];
        for (int i = 0; i < 3; ++i) {
            cin >> a[i];
            --a[i];
        }
        
        if (a[x] == -1 or a[a[x]] == -1) {
            cout << "NO\n";
            continue;
        }
        cout << "YES\n";
    }
    
    return 0;
}