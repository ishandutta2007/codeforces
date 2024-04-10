#include<bits/stdc++.h>

using namespace std;

typedef vector<int> vi;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    if (n <= 2) {
        cout << 1 << '\n';
        for (int i = 0; i < n; ++i) {
            if (i) cout << ' ';
            cout << 1;
        }
        cout << '\n';
    }
    else {
        vi V(n + 2, 0);
        for (int i = 2; i <= n + 1; ++i) {
            if (V[i]) continue;
            for (int j = 2*i; j <= n + 1; j += i) {
                V[j] = 1;
            }
        }
        
        cout << 2 << '\n';
        for (int i = 0; i < n; ++i) {
            if (i) cout << ' ';
            if (V[i + 2] == 0) cout << 1;
            else cout << 2;
        }
        cout << '\n';
    }
}