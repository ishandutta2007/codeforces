#include <bits/stdc++.h>

using namespace std;

const int max_n = 111, inf = 1000111222;

int t, n, a[max_n];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        sort(a, a + n);
        int sum = accumulate(a, a + n - 1, 0);
        if (sum < a[n - 1]) {
            puts("T");
        } else {
            int tot = sum + a[n - 1];
            if (tot % 2) {
                puts("T");
            } else {
                puts("HL");
            }
        }
    }
    return 0;
}