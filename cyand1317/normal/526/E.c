#include <stdio.h>
#define MAXN 1000004

int main()
{
    int n, q, i, a[MAXN];
    long long b;
    scanf("%d%d", &n, &q);
    for (i = 0; i < n; i++) scanf("%d", &a[i]);

    int blocklen[MAXN];
    while (q--) {
        scanf("%I64d", &b);

        // Preprocessing, find the block with minimal length
        int minblockstart, head = 0, tail = 0;
        long long curblockval = 0, maxblockval = -1;
        while (head < n && curblockval <= b) curblockval += a[head++];
        curblockval -= a[(--head + n) % n];
        blocklen[0] = head % n == 0 ? n : head; minblockstart = 0;
        maxblockval = curblockval;
        while (tail < n - 1) {
            curblockval -= a[tail++];
            while (head < n + n && curblockval <= b) curblockval += a[(head++) % n];
            curblockval -= a[(--head + n) % n];
            blocklen[tail] = head - tail;
            if (curblockval > maxblockval ||
              curblockval == maxblockval && blocklen[tail] < blocklen[minblockstart]) {
                maxblockval = curblockval;
                minblockstart = tail;
            }
        }

        // Iterate over the beginning of the block in the minimal block
        // See the official editorial
        int ans = n + 1, cur, j;
        for (i = minblockstart; i < minblockstart + blocklen[minblockstart]; i++) {
            cur = 0; j = i;
            while (j < i + n) {
                cur++;
                j += blocklen[j % n];
            }
            if (cur < ans) ans = cur;
        }
        printf("%d\n", ans);
    }

    return 0;
}