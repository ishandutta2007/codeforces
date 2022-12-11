#include <cstdio>
#include <cstring>
static const int MAXN = 1004;

int _s[10] = { 0 }, _m[10] = { 0 };
int sh[10] = { 0 }, mo[10] = { 0 };

int main()
{
    int n;
    scanf("%d", &n); getchar();
    for (int i = 0; i < n; ++i) ++_s[getchar() - '0']; getchar();
    for (int i = 0; i < n; ++i) ++_m[getchar() - '0']; getchar();

    // Subproblem 1: minimize M's flicks
    memcpy(sh, _s, sizeof _s);
    memcpy(mo, _m, sizeof _m);
    int ans1 = 0, accum = 0;
    for (int i = 0; i < 10; ++i) {
        accum += sh[i];
        if (accum >= mo[i]) {
            accum -= mo[i];
        } else {
            mo[i] -= accum; accum = 0;
            ans1 += mo[i];
            for (int j = 9; j >= 0; --j) if (sh[j]) {
                sh[j] -= mo[i]; break;
            }
        }
    }
    printf("%d\n", ans1);

    // Subproblem 2: maximize S's flicks
    memcpy(sh, _s, sizeof _s);
    memcpy(mo, _m, sizeof _m);
    int ans2 = 0; accum = 0;
    for (int i = 8; i >= 0; --i) {
        accum += mo[i + 1];
        if (accum >= sh[i]) {
            accum -= sh[i]; ans2 += sh[i];
        } else {
            sh[i] -= accum; ans2 += accum; accum = 0;
        }
    }
    printf("%d\n", ans2);

    return 0;
}