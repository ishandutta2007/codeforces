#include <bits/stdc++.h>

using namespace std;

int t, a[3], n;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> t;
    while (t--) {
        cin >> a[0] >> a[1] >> n;
        a[2] = a[0] ^ a[1];
        cout << a[n % 3] << "\n";
    }
    return 0;
}