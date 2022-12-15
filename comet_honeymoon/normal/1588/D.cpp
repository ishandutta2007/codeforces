#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int T;
int n;
char s[15][120];
bool qaq[15][120];
char conv(char x) {
    if (x >= 'A' && x <= 'Z') return x - 'A';
    return x - 'a' + 26;
}
char rconv(int x) {
    if (x < 26) return 'A' + x;
    else return 'a' + x - 26;
}

int pos[15][60][2];
int nxt[15][120][52];
int lst[52];

int f[52][1024];
int fac[52][1024], fas[52][1024];
int solve(int c, int s) {
    int nowpos[15];
    for (int i = 0; i < n; i++)
        if ((nowpos[i] = pos[i][c][s >> i & 1]) == -1) return -1;
    if (f[c][s] >= 0) return f[c][s];
    f[c][s] = 0;
    for (int c0 = 0; c0 < 52; c0++) {
        int tpos[15]; bool flg = 1;
        for (int i = 0; i < n; i++) {
            tpos[i] = nxt[i][nowpos[i]][c0];
            if (tpos[i] == -1) flg = 0;
        }
        if (flg == 0) continue;
        int ts = 0;
        for (int i = 0; i < n; i++) ts |= qaq[i][tpos[i]] << i;
        int tmp = solve(c0, ts) + 1;
        if (tmp > f[c][s]) {
            f[c][s] = tmp;
            fac[c][s] = c0;
            fas[c][s] = ts;
        }
    }
    return f[c][s];
}

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        for (int i = 0; i < n; i++) {
            scanf("%s", s[i] + 1);
            int m = strlen(s[i] + 1);

            memset(pos[i], -1, sizeof(pos[i]));
            memset(lst, -1, sizeof(lst));
            for (int j = 1; j <= m; j++) {
                int ts = (s[i][j] = conv(s[i][j]));
                if (pos[i][ts][0] == -1) pos[i][ts][0] = j, qaq[i][j] = 0;
                else pos[i][ts][1] = j, qaq[i][j] = 1;
            }
            for (int j = m; j; j--) {
                for (int c = 0; c < 52; c++)
                    nxt[i][j][c] = lst[c];
                lst[s[i][j]] = j;
            }
            // for (int c = 0; c < 52; c++) printf("%d ", lst[c]); printf("\n");
        }

        memset(f, 192, sizeof(f));
        int ans = 0, ansc, anss;
        for (int c = 0; c < 52; c++)
        for (int s = 0; s < 1 << n; s++) {
            int tmp = solve(c, s) + 1;
            if (tmp > ans) {
                ans = tmp;
                ansc = c;
                anss = s;
            }
        }
        printf("%d\n", ans);
        while (ans--) {
            printf("%c", rconv(ansc));
            int tc = fac[ansc][anss];
            int ts = fas[ansc][anss];
            ansc = tc; anss = ts;
        }
        printf("\n");
    }
}