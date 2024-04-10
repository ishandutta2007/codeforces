#include <bits/stdc++.h>

using namespace std;

int t, n;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 2; i <= n; ++i) {
            cout << i << " ";
        }
        cout << "1\n";
    }
    return 0;
}