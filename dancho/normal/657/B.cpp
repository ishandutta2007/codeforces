#include <cstdio>
#include <cstring>

int n;
long long k;
long long a[200220];
long long A[200220];

long long ia(long long x) {
    if (x < 0) {
        return -x;
    }
    return x;
}

int main() {
    memset(a, 0, sizeof(a));
    scanf("%d %lld", &n, &k);
    for (int i = 0; i <= n; ++i) {
        scanf("%lld", &a[i]);
    }
    memcpy(A, a, sizeof(a));
    for (int i = 0; i <= n; ++i) {
        long long x = ia(A[i]);
        long long st = x / 2;
        if (A[i] < 0) {
            A[i] += st * 2;
            A[i + 1] -= st;
        } else if (A[i] > 0) {
            A[i] -= st * 2;
            A[i + 1] += st;
        }

        while (A[i] < 0) {
            A[i] += 2;
            A[i + 1] -= 1;
        }
        while (A[i] > 1) {
            A[i] -= 2;
            A[i + 1] += 1;
        }
    }
    int i = n + 1;
    while (true) {
        if (ia(A[i]) <= 1) {
            break;
        }
        long long x = ia(A[i]);
        long long st = x / 2;

        if (A[i] < 0) {
            A[i] += st * 2;
            A[i + 1] -= st;
        } else if (A[i] > 0) {
            A[i] -= st * 2;
            A[i + 1] += st;
        }

        while (A[i] < 0) {
            A[i] += 2;
            A[i + 1] -= 1;
        }
        while (A[i] > 1) {
            A[i] -= 2;
            A[i + 1] += 1;
        }
        ++i;
    }
    int m = i;
    int fnz = 0;
    for (int i = 0; i <= m; ++i) {
        if (A[i] != 0) {
            fnz = i;
            break;
        }
    }
    if (fnz > n) {
        fnz = n;
    }
    long long ans = 0;
    long long tar = 0;
    for (int i = m; i >= 0; --i) {
        tar = tar * 2 + A[i];
        // printf("%d %lld %d\n", i, tar, fnz);
        if (i <= fnz) {
            // printf("LT fnz --> %lld\n", a[i] - tar);
            if (a[i] - tar <= k && a[i] - tar >= -k) {
                if (i != n || a[i] - tar != 0) {
                    ++ans;
                }
            }
        }
        if (tar > 2LL * k) {
            break;
        }
        if (tar < -2LL * (k + 10)) {
            break;
        }
    }
    printf("%lld\n", ans);
    return 0;
}