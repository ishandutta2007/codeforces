#include<bits/stdc++.h>
using namespace std;
const int MN = 40+5;
void solve () {
    int n,m; scanf ("%d %d",&n,&m);
    vector<vector<int>> a(n+1,vector<int>(m+1));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            scanf ("%d",&a[i][j]);
        }
    }
    vector<vector<int>> mx(n+1,vector<int>(m+1)), mn(n+1,vector<int>(m+1));
    mx[1][1] = mn[1][1] = a[1][1];
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) if(i>1||j>1) {
            mx[i][j] = INT_MIN; mn[i][j] = INT_MAX;
            if (i > 1) {
                mx[i][j] = max(mx[i][j],mx[i-1][j] + a[i][j]);
                mn[i][j] = min(mn[i][j],mn[i-1][j] + a[i][j]);
            }
            if (j > 1) {
                mx[i][j] = max(mx[i][j],mx[i][j-1] + a[i][j]);
                mn[i][j] = min(mn[i][j],mn[i][j-1] + a[i][j]);
            }
        }
    }
    if (mn[n][m] <= 0 && mx[n][m] >= 0 && (n+m+1) % 2 == 0) {
        printf ("yEs\n");
    } else {
        printf ("nO\n");
    }
}
int main () {
    int t; scanf ("%d",&t);
    while (t--) solve();
    return 0;
}