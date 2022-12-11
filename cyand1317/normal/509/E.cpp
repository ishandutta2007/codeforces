// You have submitted exactly the same code before
#include <cstdio>
static const int MAXN = 5e5 + 4;

int n = 0;
bool s[MAXN];
int pfx[MAXN];
double inv_sum[MAXN];

int main()
{
    bool end = false;
    while (!end) switch (getchar()) {
        case 'A': case 'E': case 'I': case 'O': case 'U': case 'Y': s[n++] = true; break;
        case '\n': end = true; break;
        default: s[n++] = false; break;
    }

    pfx[0] = s[0]; for (int i = 1; i < n; ++i) pfx[i] = pfx[i - 1] + s[i];
    inv_sum[0] = 0; for (int i = 1; i < MAXN; ++i) inv_sum[i] = inv_sum[i - 1] + 1.0 / i;

    double ans = 0;
    double ww = 0;
    for (int i = 0; i < n; ++i) ww += pfx[i];
    for (int i = 0; i < n; ++i) { ans += (double)ww / (i + 1); ww -= pfx[i]; }
    for (int i = 0; i < n; ++i) ans -= pfx[i] * inv_sum[n - 1 - i];

    printf("%.8lf\n", ans);
    return 0;
}