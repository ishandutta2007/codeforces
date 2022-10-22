#include <bits/stdc++.h>
using namespace std;
const int MN = 105;
char grid[MN][MN];
void solve () {
    int n,m; scanf ("%d %d",&n,&m);
    for (int i = 1; i <= n; i++) {
        scanf ("%s",grid[i]+1);
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) if (grid[i][j] == 'R') {
            int goL = i - 1, goU = j - 1;
            for (int ii = 1; ii <= n; ii++)
                for (int jj = 1; jj <= m; jj++)
                    if (grid[ii][jj] == 'R' && (ii - goL < 1 || jj - goU < 1))
                        goto fail;
                printf ("YES\n");
                return;
                fail:;
        }
    }
    printf ("NO\n");
}
int main () {
    int t; scanf ("%d",&t);
    while (t--) solve();
    return 0;
}