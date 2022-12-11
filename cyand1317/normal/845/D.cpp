#include <cstdio>
#include <algorithm>
static const int MAXN = 2e5 + 4;
static const int MAXS = 304;

int n;

int prohibit_ct = 0;
int cur_spd = 0;
int lmt[MAXN] = { MAXS }, lmt_top = 1;

int main()
{
    scanf("%d", &n);

    int ans = 0;
    for (int i = 0, t, s; i < n; ++i) {
        scanf("%d", &t);
        switch (t) {
            case 3:
                scanf("%d", &s); lmt[lmt_top++] = s; break;
            case 4:
                prohibit_ct = 0; break;
            case 5:
                lmt[lmt_top++] = MAXS; break;
            case 6:
                ++prohibit_ct; break;
            case 1:
                scanf("%d", &cur_spd); break;
            case 2:
                ans += prohibit_ct; prohibit_ct = 0; break;
            default: puts("> <");
        }
        while (lmt_top > 0 && lmt[lmt_top - 1] < cur_spd) {
            --lmt_top; ++ans;
        }
    }

    printf("%d\n", ans);
    return 0;
}