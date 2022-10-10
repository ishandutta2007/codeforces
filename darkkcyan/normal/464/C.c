#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define long long long
#define NN 501010
#define mod ((long)1e9 + 7)
int n;
char s[NN], t[NN], c[NN], * b[NN];
long p[10], len[10];

long mpow(long base, long m) {
    long ans = 1;
    for (; m > 0; m >>= 1) {
        if (m & 1) ans = (ans * base) % mod;
        base = (base * base) % mod;
    }
    return ans;
}

void process(char* s, long* val, long* l) {
    *val = *l = 0;
    int i = 0; while (s[i]) ++i;
    while (i --) {
        *val = (*val + (p[s[i] - '0'] * mpow(10, *l)) % mod) % mod;
        *l = (*l + len[s[i] - '0']) % (mod - 1);
    }
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("transform.inp", "r", stdin);
    freopen("transform.out", "w", stdout);
    #endif

    int i;
    memset(t, 0, sizeof(t));
    char *pt = t;
    scanf("%s", s);
    scanf("%d", &n);
    b[0] = s;
    c[0] = 0;
    for (i = 1; i <= n; ++i) {
        scanf("%s", pt);
        c[i] = pt[0] - '0';
        b[i] = pt + 3;
        while (*pt) ++pt;
        ++pt;
    }

    for (i = 0; i < 10; ++i) {
        p[i] = i;
        len[i] = 1;
    }

    for (i = n; i >= 0; --i) {
        long f, g;
        process(b[i], &f, &g);
        p[(int)c[i]] = f; len[(int)c[i]] = g;
    }

    printf("%d", (int)p[0]);

    return 0;
}