#include <cstdio>
typedef long long int64;
static const int MAXN = 100006;

int n;
int a[MAXN], p[MAXN];
int64 ans[MAXN];
int64 seg[MAXN] = { 0 }, side[MAXN];
int64 cur_max = 0;

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
    for (int i = 0; i < n; ++i) { scanf("%d", &p[i]); --p[i]; }

    for (int i = 0; i < n; ++i) side[i] = -1;
    for (int i = n - 1; i >= 0; --i) {
        ans[i] = cur_max;
        int64 new_seg = a[p[i]];
        int lside = p[i], rside = p[i];
        if (p[i] > 0) {
            new_seg += seg[p[i] - 1];
            if (side[p[i] - 1] != -1) lside = side[p[i] - 1];
        }
        if (p[i] < n - 1) {
            new_seg += seg[p[i] + 1];
            if (side[p[i] + 1] != -1) rside = side[p[i] + 1];
        }
        side[lside] = rside;
        side[rside] = lside;
        seg[lside] = seg[rside] = new_seg;
        if (cur_max < new_seg) cur_max = new_seg;
    }

    for (int i = 0; i < n; ++i) printf("%I64d\n", ans[i]);
    return 0;
}