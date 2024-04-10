#include <bits/stdc++.h>

using namespace std;

const int max_n = 111, inf = 1000111222;

int n, a[max_n];

bool ok(int k) {
    int sum = 0;
    for (int i = 0; i < n; ++i) {
        sum += k - a[i] - a[i];
    }
    return sum > 0;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n;
    int k = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        k = max(k, a[i]);
    }
    while (!ok(k)) {
        ++k;
    }
    cout << k << "\n";
    return 0;
}