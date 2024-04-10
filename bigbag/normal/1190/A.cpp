#include <bits/stdc++.h>

using namespace std;

const int max_n = 100111, inf = 1000111222;

int n;
long long tot, k, a[max_n];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%I64d%d%I64d", &tot, &n, &k);
    for (int i = 0; i < n; ++i) {
        scanf("%I64d", &a[i]);
        --a[i];
    }
    int ans = 0;
    for (int i = 0; i < n; ) {
        int pos = i, del = i;
        while (i < n && (a[i] - del) / k == (a[pos] - del) / k) {
            ++i;
        }
        ++ans;
    }
    printf("%d\n", ans);
    return 0;
}