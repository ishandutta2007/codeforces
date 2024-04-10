#include <bits/stdc++.h>

using namespace std;

const int max_n = 1011, inf = 1000111222;

int t, n, a[max_n];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        for (int i = 0; i < n; ++i) {
            scanf("%d", &a[i]);
        }
        int last = 0, l = 0, r = n - 1, num = 0;
        int x = 0, y = 0, steps = 0;
        while (l <= r) {
            int sum = 0;
            if (!num) {
                while (l <= r && sum <= last) {
                    sum += a[l++];
                }
                x += sum;
            } else {
                while (l <= r && sum <= last) {
                    sum += a[r--];
                }
                y += sum;
            }
            last = sum;
            num ^= 1;
            ++steps;
        }
        printf("%d %d %d\n", steps, x, y);
    }
    return 0;
}