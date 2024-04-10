#include <bits/stdc++.h>

using namespace std;

int main() {
    int t, n, a[211111];
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        n *= 2;
        for (int i = 0; i < n; ++i) {
            scanf("%d", &a[i]);
        }
        sort(a, a + n);
        cout << abs(a[n / 2] - a[n / 2 - 1]) << "\n";
    }
    return 0;
}