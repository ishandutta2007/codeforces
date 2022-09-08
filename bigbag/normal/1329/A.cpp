#include <bits/stdc++.h>

using namespace std;

const int max_n = 100111, inf = 1000111222;

int n, tot, len[max_n];
long long sum[max_n];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d%d", &tot, &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &len[i]);
    }
    for (int i = n - 1; i >= 0; --i) {
        sum[i] = sum[i + 1] + len[i];
    }
    if (sum[0] < tot) {
        puts("-1");
        return 0;
    }
    for (int i = 0; i < n; ++i) {
        if (i + len[i] > tot) {
            puts("-1");
            return 0;
        }
    }
    int pos = 0;
    for (int i = 0; i < n; ++i) {
        while (pos + len[i] + sum[i + 1] < tot) {
            ++pos;
        }
        printf("%d ", pos + 1);
        ++pos;
    }
    puts("");
    return 0;
}