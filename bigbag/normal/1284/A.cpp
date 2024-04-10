#include <bits/stdc++.h>

using namespace std;

const int max_n = 33, inf = 1000111222;

int n, m, q;
string a[max_n], b[max_n];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < m; ++i) {
        cin >> b[i];
    }
    cin >> q;
    while (q--) {
        int x;
        cin >> x;
        x--;
        cout << a[x % n] << b[x % m] << "\n";
    }
    return 0;
}