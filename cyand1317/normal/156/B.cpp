#include <cstdio>
static const int MAXN = 1e5 + 4;

int n, m;
int a[MAXN];
int ct[MAXN][2] = {{ 0 }};
int possible_ct = 0;
bool possible[MAXN] = { false };

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
        if (a[i] > 0) ++ct[a[i] - 1][1]; else ++ct[-a[i] - 1][0];
    }

    int truth_ct = 0;
    for (int i = 0; i < n; ++i) truth_ct += ct[i][0];
    for (int i = 0; i < n; ++i) {
        if (i) truth_ct -= (ct[i - 1][1] - ct[i - 1][0]);
        truth_ct += (ct[i][1] - ct[i][0]);
        if (truth_ct == m) ++possible_ct, possible[i] = true;
    }

    for (int i = 0; i < n; ++i) {
        if (a[i] > 0) {
            puts(possible[a[i] - 1] ? (possible_ct == 1 ? "Truth" : "Not defined") : "Lie");
        } else {
            puts(possible[-a[i] - 1] ? (possible_ct == 1 ? "Lie" : "Not defined") : "Truth");
        }
    }

    return 0;
}