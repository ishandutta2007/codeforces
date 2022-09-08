#include <bits/stdc++.h>

using namespace std;

const int max_n = 300333, inf = 1000111222;

int n, p, k, a[max_n];
int ans;
map<int, int> cnt;

int mul(int x, int y) {
    return 1LL * x * y % p;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d%d%d", &n, &p, &k);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
        int x = mul(a[i], a[i]);
        x = mul(x, x);
        x += p - mul(k, a[i]);
        x %= p;
        ans += cnt[x]++;
    }
    printf("%d\n", ans);
    return 0;
}