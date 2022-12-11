#include <stdio.h>
#define MAXT 102

int main()
{
    int v1, v2, t, d;
    scanf("%d%d%d%d", &v1, &v2, &t, &d);
    int dv[MAXT], v3, i;
    for (i = 1; i < t; ++i) dv[i] = d;
    v3 = v1 + d * (t - 1);
    while (v3 > v2) {
        --v3;
        i = t - 1;
        while (i && dv[i] == -d) --i;
        --dv[i];
    }
    int ans = v1; dv[0] = v1;
    for (i = 1; i < t; ++i) {
        dv[i] = dv[i - 1] + dv[i];
        ans += dv[i];
    }
    printf("%d\n", ans);
    return 0;
}