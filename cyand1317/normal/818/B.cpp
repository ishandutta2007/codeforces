#include <cstdio>
static const int MAXN = 102;

int n, m;
int p[MAXN];
int b[MAXN];
bool occ[MAXN] = { false };

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; ++i) scanf("%d", &b[i]);

    for (int i = 1; i <= n; ++i) p[i] = -1;
    for (int i = 1; i < m; ++i) {
        int val = (b[i] - b[i - 1] + n) % n;
        if (val == 0) val = n;
        //printf("%d | %d\n", b[i - 1], val);
        if ((!occ[val] && p[b[i - 1]] == -1) || p[b[i - 1]] == val) {
            p[b[i - 1]] = val; occ[val] = true;
        } else {
            puts("-1"); return 0;
        }
    }

    int ptr = 0;
    for (int i = 1; i <= n; ++i) if (!occ[i]) {
        while (p[ptr] != -1) ++ptr;
        p[ptr] = i;
    }
    for (int i = 1; i <= n; ++i) printf("%d%c", p[i], i == n ? '\n' : ' ');
    return 0;
}