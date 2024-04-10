#include <cstdio>
static const int MAXN = 2e5 + 4;

int n, p[MAXN], b[MAXN];
bool vis[MAXN] = { false };

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) { scanf("%d", &p[i]); --p[i]; }
    for (int i = 0; i < n; ++i) scanf("%d", &b[i]);

    int cyc_ct = 0;
    for (int i = 0; i < n; ++i) if (!vis[i]) {
        vis[i] = true;
        for (int j = p[i]; j != i; j = p[j]) vis[j] = true;
        ++cyc_ct;
    }

    bool flip_needed = true;
    for (int i = 0; i < n; ++i) flip_needed ^= b[i];
    printf("%d\n", (cyc_ct == 1 ? 0 : cyc_ct) + flip_needed);

    return 0;
}