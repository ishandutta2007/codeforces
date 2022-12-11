#include <cstdio>
static const int MAXN = 205;
static const int ROW = 512;

int n, sum = 0, ct[MAXN * ROW * 2] = { 0 };
int ans = 0;

int main()
{
    scanf("%d", &n); getchar();
    ct[MAXN * ROW] = 1;
    for (int i = 2; i <= n + 1; ++i) {
        switch (getchar()) {
            case 'U': sum += ROW; break;
            case 'D': sum -= ROW; break;
            case 'L': sum -= 1; break;
            case 'R': sum += 1; break;
            default: puts("(` )");
        }
        ans += ct[MAXN * ROW + sum];
        ct[MAXN * ROW + sum]++;
    }
    printf("%d\n", ans);
    return 0;
}