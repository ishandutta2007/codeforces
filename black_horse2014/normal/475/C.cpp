#include <cstdio>
#define MX 1005
using namespace std;

inline void chkmin(int &a, int b) {
    if (b < a) a = b;
}
inline void chkmax(int &a, int b) {
    if (a < b) a = b;
}
char s[MX][MX];
int ans;
int a[MX][MX];

inline int get(int sx, int sy, int tx, int ty) {
    return (a[tx][ty] - a[tx][sy - 1] - a[sx - 1][ty] + a[sx - 1][sy - 1]);
}

int mxc[MX], mxr[MX], mic[MX], mir[MX];
int n, m;

void solve() {
    int fr, er, ec, fc, sr, sc;
    int i, j, R, C;
    
    fr = n + 1, er = 0, ec = 0, fc = m + 1;
    for (i = 1; i <= n; i++) mxc[i] = 0, mic[i] = m + 1;
    for (i = 1; i <= m; i++) mxr[i] = 0, mir[i] = n + 1;
    
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= m; j++) if (s[i - 1][j - 1] == 'X') {
            chkmax(mxc[i], j);
            chkmin(mic[i], j);
        }
        
        if (mxc[i] != 0) {
            chkmin(fr, i);
            chkmax(er, i);
        }
    }
    
    for (j = 1; j <= m; j++) {
        for (i = 1; i <= n; i++) if (s[i - 1][j - 1] == 'X') {
            chkmax(mxr[j], i);
            chkmin(mir[j], i);
        }
        
        if (mxr[j] != 0) {
            chkmin(fc, j);
            chkmax(ec, j);
        }
    }
    
    for (i = fr; i <= er; i++) {
        if (get(i, mic[i], i, mxc[i]) != mxc[i] - mic[i] + 1) return;
        for (j = i + 1; j <= er; j++) if (mxc[i] > mxc[j] || mic[i] > mic[j]) return;
    }
    for (i = fc; i <= ec; i++) {
        if (get(mir[i], i, mxr[i], i) != mxr[i] - mir[i] + 1) return;
        for (j = i + 1; j <= ec; j++) if (mxr[i] > mxr[j] || mir[i] > mir[j]) return;
    }
    
    C = mxc[fr] - mic[fr] + 1;
    for (R = 1; R <= mxr[fc] - mir[fc] + 1; R++) {
        sr = fr + R - 1, sc = mic[sr];
        while (1) {
            int flg = 0;
            if (sr == er && sc + C - 1 == mxc[er]) break;
            
            if (mxc[sr] >= sc + C && mir[sc + C] <= sr - R + 1) {
                if (sr < er && mic[sr + 1] == sc) break;
                sc++;
                continue;
            }
            if (sr < er && mic[sr + 1] == sc && mxc[sr + 1] >= sc + C - 1) {
                sr++;
                continue;
            }
            break;
        }
        if (sr == er && sc + C - 1 == mxc[er]) {
            ans = R * C;
            break;
        }
    }
    
    R = mxr[fc] - mir[fc] + 1;
    for (C = 1; C <= mxc[fr] - mic[fr] + 1; C++) {
        sr = fr + R - 1, sc = mic[sr];
        while (1) {
            int flg = 0;
            if (sr == er && sc + C - 1 == mxc[er]) break;
            
            if (mxc[sr] >= sc + C && mir[sc + C] <= sr - R + 1) {
                if (sr < er && mic[sr + 1] == sc) break;
                sc++;
                continue;
            }
            if (sr < er && mic[sr + 1] == sc && mxc[sr + 1] >= sc + C - 1) {
                sr++;
                continue;
            }
            break;
        }
        if (sr == er && sc + C - 1 == mxc[er]) {
            if (ans == -1 || ans > R * C) ans = R * C;
            break;
        }
    }
}

int main() {
//  freopen("in.txt", "r", stdin);
//  freopen("out.txt", "w", stdout);
    
    int i, j;
    scanf("%d%d", &n, &m);
    for (i = 0; i < n; i++) scanf("%s", s + i);
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= m; j++)
            a[i][j] = a[i - 1][j] + a[i][j - 1] - a[i - 1][j - 1] + (s[i - 1][j - 1] == 'X');
    }
    
    if (a[n][m] == 0) {
        puts("0");
        return 0;
    }
    
    ans = -1;
    solve();
    printf("%d\n", ans);
    
    return 0;
}