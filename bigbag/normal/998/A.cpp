#include <bits/stdc++.h>

using namespace std;

const int max_n = 11, inf = 1000111222;

int n, sum, a[max_n];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        sum += a[i];
    }
    if (n == 1 || (n == 2 && a[0] == a[1])) {
        cout << -1 << endl;
    } else {
        if (a[0] * 2 != sum) {
            cout << 1 << endl << 1 << endl;
        } else {
            cout << 2 << endl << "1 2" << endl;
        }
    }
    return 0;
}