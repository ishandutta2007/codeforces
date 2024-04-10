#include <cstdio>
#include <algorithm>
static const int MAXN = 2e5 + 4;

int n, k;
bool warm[MAXN];
int freezing_ct = 0;
int seg[MAXN], seg_ct = 0;

int main()
{
    scanf("%d%d", &n, &k);
    int t_i;
    for (int i = 0; i < n; ++i) {
        scanf("%d", &t_i);
        freezing_ct += !(warm[i] = (t_i >= 0));
    }

    if (freezing_ct == 0) { puts("0"); return 0; }
    else if ((freezing_ct = k - freezing_ct) < 0) { puts("-1"); return 0; }
    int last_freezing = -1, ans = 0;
    for (int i = 0; i < n; ++i) if (!warm[i]) {
        if (!i || warm[i - 1]) ++ans;
        if (i && warm[i - 1] && last_freezing != -1) seg[seg_ct++] = i - last_freezing - 1;
        last_freezing = i;
    } else if (i && !warm[i - 1]) ++ans;
    std::sort(seg, seg + seg_ct);

    int p = 0;
    while (p < seg_ct && freezing_ct > 0) {
        if ((freezing_ct -= seg[p]) >= 0) ans -= 2, ++p;
        else { freezing_ct += seg[p]; break; }
    }
    if (warm[n - 1]) {
        seg[0] = n - last_freezing - 1;
        if (freezing_ct >= seg[0]) --ans;
    }
    printf("%d\n", ans);

    return 0;
}