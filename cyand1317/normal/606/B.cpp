#include <cstdio>
static const int MAXN = 512;

int r, c, r0, c0, vis_cnt = 0;
bool vis[MAXN][MAXN] = {{ false }};

int main()
{
    scanf("%d%d%d%d", &r, &c, &r0, &c0); getchar();
    char ch, next_ch;
    printf("1 ");
    vis[r0][c0] = true; ++vis_cnt;
    ch = getchar();
    while ((next_ch = getchar()) != '\n') {
        switch (ch) {
            case 'U': if (r0 > 1) --r0; break;
            case 'D': if (r0 < r) ++r0; break;
            case 'L': if (c0 > 1) --c0; break;
            case 'R': if (c0 < c) ++c0; break;
            default: break;
        }
        if (!vis[r0][c0]) {
            printf("1 ");
            vis[r0][c0] = true; ++vis_cnt;
        } else {
            printf("0 ");
        }
        ch = next_ch;
    }
    printf("%d\n", r * c - vis_cnt);
    return 0;
}