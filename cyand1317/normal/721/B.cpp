#include <cstdio>
#include <algorithm>
static const int MAXN = 104;
static const int MAXK = 104;

int n, k;
int len[MAXN];
int corr_len;

int main()
{
    scanf("%d%d", &n, &k); getchar();
    for (int i = 0; i < n; ++i) {
        len[i] = 0;
        while (getchar() != '\n') ++len[i];
    }
    corr_len = 0;
    while (getchar() != '\n') ++corr_len;

    std::sort(len, len + n);
    int ans = 0, i = 0, ct = 0;
    while (len[i] < corr_len) {
        ++ct; ans += 1;
        if (ct == k) { ans += 5; ct = 0; }
        ++i;
    }
    printf("%d ", ans + 1);
    while (len[i] == corr_len) {
        ++ct; ans += 1;
        if (ct == k && i < n && len[i + 1] == corr_len) { ans += 5; ct = 0; }
        ++i;
    }
    printf("%d\n", ans);

    return 0;
}