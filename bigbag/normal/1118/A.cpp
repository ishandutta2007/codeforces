#include <bits/stdc++.h>

using namespace std;

int q;
long long n, a, b;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> q;
    while (q--) {
        cin >> n >> a >> b;
        if (2 * a <= b) {
            cout << n * a << endl;
        } else {
            cout << b * (n / 2) + a * (n % 2) << endl;
        }
    }
    return 0;
}