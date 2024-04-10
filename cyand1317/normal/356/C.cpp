#include <cstdio>
#include <algorithm>
static const int INF = 0x3fffffff;

int n;
int a_i, ct[5] = { 0 };

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) { scanf("%d", &a_i); ++ct[a_i]; }

    int merges = std::min(ct[1], ct[2]);
    ct[1] -= merges;
    ct[2] -= merges;
    ct[3] += merges;

    int ans = merges;
    if (ct[1] > 0) {
        merges = ct[1] / 3;
        ct[1] -= merges * 3;
        ct[3] += merges;
        ans += merges * 2;
        switch (ct[1]) {
            case 2:
                if (ct[3] >= 2) ans += 2;
                else if (ct[4] >= 1) ans += 2;
                else ans = INF;
                break;
            case 1:
                if (ct[3] >= 1) ans += 1;
                else if (ct[4] >= 2) ans += 2;
                else ans = INF;
                break;
            case 0: default: break;
        }
    } else if (ct[2] > 0) {
        merges = ct[2] / 3;
        ct[2] -= merges * 3;
        ct[3] += merges * 2;
        ans += merges * 2;
        switch (ct[2]) {
            case 2:
                ans += 2; break;
            case 1:
                if (ct[4] >= 1) ans += 1;
                else if (ct[3] >= 2) ans += 2;
                else ans = INF;
                break;
            case 0: default: break;
        }
    }

    printf("%d\n", ans >= INF / 2 ? -1 : ans);
    return 0;
}