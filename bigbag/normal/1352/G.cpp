#include <bits/stdc++.h>

using namespace std;

int t, n;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> t;
    while (t--) {
        cin >> n;
        if (n <= 3) {
            cout << "-1\n";
        } else if (n == 4) {
            cout << "3 1 4 2\n";
        } else {
            for (int i = 1; i <= n; i += 2) {
                cout << i << " ";
            }
            int x = n - n % 2;
            if (n % 2) {
                cout << x - 2 << " " << x << " ";
                x -= 4;
            } else {
                cout << x - 4 << " " << x << " " << x - 2 << " ";
                x -= 6;
            }
            while (x) {
                cout << x << " ";
                x -= 2;
            }
            cout << "\n";
        }
    }
    return 0;
}