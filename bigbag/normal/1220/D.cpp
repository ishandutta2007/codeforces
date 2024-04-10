#include <bits/stdc++.h>

using namespace std;

const int max_n = 200222;
const long long inf = 1000111222000111222LL;
const int max_p = 70;

int n, cnt[max_p], pw[max_n];
long long a[max_n];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%I64d", &a[i]);
        long long x = a[i];
        while (x % 2 == 0) {
            ++pw[i];
            x /= 2;
        }
        ++cnt[pw[i]];
    }
    int best = 0;
    for (int i = 0; i < max_p; ++i) {
        if (cnt[best] < cnt[i]) {
            best = i;
        }
    }
    printf("%d\n", n - cnt[best]);
    for (int i = 0; i < n; ++i) {
        if (pw[i] != best) {
            printf("%I64d ", a[i]);
        }
    }
    return 0;
}