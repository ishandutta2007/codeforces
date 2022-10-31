#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    cout << k * (5 + (n - 1) * 6) << endl;

    for(int i = 0, j = 0; i < n; ++i, j += 6) {
        printf("%d %d %d %d\n", (1 + j)*k, (2 + j)*k, (3 + j)*k, (5 + j)*k);
    }
    return 0;
}