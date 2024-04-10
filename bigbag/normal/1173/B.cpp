#include <bits/stdc++.h>

using namespace std;

const int max_n = 1111, inf = 1000111222;

int n, a[max_n][max_n];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n;
    int m = n / 2 + 1;
    cout << m << endl;
    for (int i = 1; i <= (n + 1) / 2; ++i) {
        cout << 1 << " " << i << endl;
    }
    for (int i = (n + 3) / 2; i <= n; ++i) {
        cout << m << " " << i - n / 2 << endl;
    }
    return 0;
}