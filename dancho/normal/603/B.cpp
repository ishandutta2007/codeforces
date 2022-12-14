#include <cstdio>
#include <cstring>

const int mod = 1000000007;

int p, k;
bool us[1 << 20];

void go(int v) {
    if (us[v]) return;
    us[v] = 1;
    go(((long long) v * k) % p);
}

int main() {
    scanf("%d %d", &p, &k);
    if (k == 1) {
        long long ans = 1;
        for (int i = 0; i < p; ++i) {
            ans = (ans * p) % mod;
        }
        printf("%lld\n", ans);
        return 0;
    }
    if (k == 0) {
        long long ans = 1;
        for (int i = 0; i + 1 < p; ++i) {
            ans = (ans * p) % mod;
        }
        printf("%lld\n", ans);
        return 0;
    }
    // f(0) = 0
    
    long long ans = 1;
    memset(us, 0, sizeof(us));
    for (int i = 1; i < p; ++i) {
        if (!us[i]) {
            go(i);
            ans = (ans * p) % mod;
        }
    }
    printf("%lld\n", ans);
    return 0;
}