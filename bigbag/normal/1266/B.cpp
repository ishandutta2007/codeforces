#include <bits/stdc++.h>

using namespace std;

const int max_n = 1111, inf = 1000111222;

int t;
long long n;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> t;
    while (t--) {
        cin >> n;
        if (1 <= n % 14 && n % 14 <= 6 && n >= 15) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
    return 0;
}