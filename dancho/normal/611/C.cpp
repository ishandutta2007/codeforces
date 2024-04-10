#include <cstdio>
#include <cstring>

int h, w, q;
char t[1024][1024];

int a[2][1024][1024];

int sm[2][1024][1024];

int main() {
    scanf("%d %d", &h, &w);
    for (int i = 0; i < h; ++i) {
        scanf("%s", t[i]);
    }

    for (int i = 0; i < h; ++i) {
        for (int j = 0; j + 1 < w; ++j) {
            a[0][i][j] = (t[i][j] == '.' && t[i][j + 1] == '.');
        }
    }
    for (int i = 0; i + 1 < h; ++i) {
        for (int j = 0; j < w; ++j) {
            a[1][i][j] = (t[i][j] == '.' && t[i + 1][j] == '.');
        }
    }

    memset(sm, 0, sizeof(sm));
    for (int id = 0; id < 2; ++id) {
        for (int i = 0; i < h; ++i) {
            for (int j = 0; j < w; ++j) {
                sm[id][i + 1][j + 1] = sm[id][i][j + 1] + sm[id][i + 1][j]
                    - sm[id][i][j] + a[id][i][j];
            }
        }
    }

    scanf("%d", &q);
    for (int i = 0; i < q; ++i) {
        int r1, c1, r2, c2;
        scanf("%d %d %d %d", &r1, &c1, &r2, &c2);
        int ans = 0;
        ans += sm[0][r2][c2 - 1] - sm[0][r1 - 1][c2 - 1] - sm[0][r2][c1 - 1]
            + sm[0][r1 - 1][c1 - 1];
        ans += sm[1][r2 - 1][c2] - sm[1][r1 - 1][c2] - sm[1][r2 - 1][c1 - 1]
            + sm[1][r1 - 1][c1 - 1];
        
        printf("%d\n", ans);
    }
    
    return 0;
}