#include <bits/stdc++.h>

using namespace std;

const int max_n = 1000111, inf = 1000111222;

int n;
long long a[max_n], ans[max_n];

void solve() {
    long long sum = accumulate(a, a + n, 0LL);
    long long add = 1LL * n * (n - 1) / 2;
    sum -= add;
    long long start = sum / n;
    sum %= n;
    for (int i = 0; i < n; ++i) {
        ans[i] = start + i;
        ans[i] += i < sum;
    }
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%I64d", &a[i]);
    }
    solve();
    for (int i = 0; i < n; ++i) {
        printf("%I64d ", ans[i]);
    }
    puts("");
    return 0;
}