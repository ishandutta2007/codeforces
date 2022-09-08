#include <bits/stdc++.h>

using namespace std;

const int max_n = -1, inf = 1000111222;

int k;
long long n, s;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n >> k >> s;
    long long mn = k;
    long long mx = (n - 1) * k;
    if (mn <= s && s <= mx) {
        puts("YES");
        int cur = 1;
        for (int i = 0; i < k; ++i) {
            int d = min(n - 1, s - k + i + 1);
            if (cur + d <= n) {
                cur += d;
            } else {
                cur -= d;
            }
            s -= d;
            printf("%d ", cur);
        }
        printf("\n");
    } else {
        puts("NO");
    }
    return 0;
}