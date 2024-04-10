#include <algorithm>
#include <cstdio>
#include <random>
#include <chrono>
std::mt19937 rnd(std::chrono::steady_clock().now().time_since_epoch().count());

int n;
inline int ask(int x, int y) {
    printf("? %d %d\n", x, y); fflush(stdout);
    int z; scanf("%d", &z); return z;
}

inline int Rand(int x) {
    int y = rnd() % n + 1;
    while(y == x) y = rnd() % n + 1;
    return y;
}

inline int val(int x) {
    int TIM = 15, ret = ask(x, Rand(x));
    while(TIM --) ret &= ask(x, Rand(x));
    return ret;
}
int ans[1 << 12 | 5], pos[1 << 12 | 5];
int main() {
    scanf("%d", &n); 
    for (int i = 1;i <= n;++ i) pos[i] = i;
    std::shuffle(pos + 1, pos + n + 1, rnd);
    int p = pos[1], t = val(pos[1]);
    for (int i = 2;i <= n;++ i)
        if(ask(p, pos[i]) == t)
            t = val(p = pos[i]);
    for (int i = 1;i <= n;++ i) {
        if(i == p) ans[i] = t;
        else ans[i] = ask(i, p);
    }
    printf("!"); for (int i = 1;i <= n;++ i) printf(" %d", ans[i]);
    printf("\n"); fflush(stdout);

}