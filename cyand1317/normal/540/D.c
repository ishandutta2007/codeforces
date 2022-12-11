#include <stdio.h>
#define MAXCNT 103
#define MAXQUEUESIZE 22806  // 22799 really used
#define sqr(_x) ((_x) * (_x))
#define encode(_r, _s, _p) ((_r) * MAXCNT * MAXCNT + (_s) * MAXCNT + (_p))
#define decode(_c, _r, _s, _p) do { \
    int x = (_c); \
    _r = x / (MAXCNT * MAXCNT); \
    _s = (x / MAXCNT) % MAXCNT; \
    _p = x % MAXCNT; \
} while (0)

double d[MAXCNT][MAXCNT][MAXCNT] = {{{0.0}}};
int q[MAXQUEUESIZE], qfront, qtail;

void calc(int r, int s, int p)
{
    if (!r + !s + !p >= 2 || d[r][s][p] == 0.0) return;
    double deno = r * s + s * p + p * r;
    if (p && r) {
        d[r - 1][s][p] += d[r][s][p] * (p * r) / deno;
        q[(qfront++) % MAXQUEUESIZE] = encode(r - 1, s, p);
    }
    if (r && s) {
        d[r][s - 1][p] += d[r][s][p] * (r * s) / deno;
        q[(qfront++) % MAXQUEUESIZE] = encode(r, s - 1, p);
    }
    if (s && p) {
        d[r][s][p - 1] += d[r][s][p] * (s * p) / deno;
        q[(qfront++) % MAXQUEUESIZE] = encode(r, s, p - 1);
    }
    d[r][s][p] = 0.0;
}

int main()
{
    int r, s, p;
    scanf("%d%d%d", &r, &s, &p);
    d[r][s][p] = 1.0;
    qfront = 1; qtail = 0; q[0] = encode(r, s, p);
    do {
        decode(q[(qtail++) % MAXQUEUESIZE], r, s, p);
        calc(r, s, p);
    } while (qfront != qtail);

    int i; double result = 0.0;
    for (i = 0; i < MAXCNT; ++i) result += d[i][0][0];
    printf("%.12f ", result);
    result = 0.0;
    for (i = 0; i < MAXCNT; ++i) result += d[0][i][0];
    printf("%.12f ", result);
    result = 0.0;
    for (i = 0; i < MAXCNT; ++i) result += d[0][0][i];
    printf("%.12f\n", result);
    return 0;
}