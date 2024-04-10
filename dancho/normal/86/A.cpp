#include <cstdio>

long long max(long long a, long long b) {
    if (a > b) return a;
    return b;
}

int l, r;
int dl, dr;

int getd(int x) {
    if (x == 0) return 0;
    return 1 + getd(x / 10);
}

long long gs(int bd) {
    if (bd == 0) return 0;
    return 9 + gs(bd - 1) * 10;
}

int main() {
    scanf("%d %d", &l, &r);
    dl = getd(l);
    dr = getd(r);
    long long ans = -1;
    for (int i = dl; i <= dr; ++i) {
        long long s = gs(i);
        if (l <= s / 2 && s / 2 <= r) {
            ans = max(ans, (s / 2) * (s - s / 2));
        }
        if (i == dl) {
            ans = max(ans, l * (s - l));
        }
        if (i == dr) {
            ans = max(ans, r * (s - r));
        }
    }
    printf("%lld\n", ans);
    return 0;
}