#include <cstdio>
#include <cstring>

int p, q;

int a[1 << 22];

int ld;
char d[32];

void getd(int x) {
    ld = 0;
    while (x) {
        d[ld++] = x % 10;
        x /= 10;
    }
}

int main() {
    scanf("%d %d", &p, &q);

    memset(a, 0, sizeof(a));
    for (int i = 2; i < (1 << 22); ++i) {
        if (!a[i]) {
            for (int j = i + i; j < (1 << 22); j += i) {
                a[j] = 1;
            }
        }
    }

    int npr, npal;
    npr = npal = 0;
    int ans = -1;
    for (int i = 1; i < (1 << 22); ++i) {
        if (i >= 2 && !a[i]) {
            ++npr;
        }
        getd(i);
        bool isp = 1;
        for (int j = ld - 1; j >= 0; --j) {
            if (d[j] != d[ld - 1 - j]) {
                isp = 0;
            }
        }
        if (isp) {
            npal++;
        }
        if ((long long)q * npr <= (long long) p * npal) {
            ans = i;
        }
    }
    printf("%d\n", ans);
    return 0;
}