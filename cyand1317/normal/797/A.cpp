#include <cstdio>

int n, k;
int ans[24], ans_sz = 0;

int main()
{
    scanf("%d%d", &n, &k);
    if (k == 1) { printf("%d\n", n); return 0; }

    for (int i = 2; i < n; ++i) {
        while (n % i == 0) {
            n /= i;
            ans[ans_sz++] = i;
            if (ans_sz == k - 1 && n != 1) { ans[ans_sz++] = n; break; }
        }
        if (ans_sz == k) break;
    }

    if (ans_sz < k) printf("-1\n");
    else for (int i = 0; i < k; ++i) printf("%d%c", ans[i], i == k - 1 ? '\n' : ' ');
    return 0;
}