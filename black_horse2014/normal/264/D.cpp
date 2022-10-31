#include <bits/stdc++.h>
using namespace std;

const int N = 1100000;

const char str[] = "RGB";

#define next as

char s[N], t[N];
int seen[3];
int next[N][3];
int cnt[N][3][3];

int main() {
    scanf("%s%s", s+1, t+1);
    int n = strlen(s + 1), m = strlen(t + 1);
    seen[0] = seen[1] = seen[2] = m + 1;
    for (int i = m; i > 0; i--) {
        int u = strchr(str, t[i]) - str;
        seen[u] = i;
        for (int j = 0; j < 3; j++) next[i][j] = seen[j];
    }
    for (int i = 1; i <= m; i++) {
        int u = strchr(str, t[i]) - str;
        int v = strchr(str, t[i-1]) - str;
        for (int j = 0; j < 3; j++) for (int k = 0; k < 3; k++) cnt[i][j][k] = cnt[i-1][j][k];
        if (i > 1) cnt[i][u][v]++;
    }
    int L, R;
    long long ans = 0;
    for (int i = 1; i <= n; i++) {
        int u = strchr(str, s[i]) - str;
        int v = strchr(str, s[i-1]) - str;
        if (i == 1) {
            L = 1, R = min(m, next[i][u]);
        } else {
            int l = L, r = R;
            if (r == m && t[r] == s[i-1]) r--;
            if (l > r) {
                cout << ans << endl;
                return 0;
            }
            if (t[r] == s[i-1]) r++;
            if (t[l] == s[i-1]) l++;
            L = l, R = min(m, next[r][u]);
            if (s[i] != s[i-1]) {
                ans -= cnt[R][v][u] - cnt[L-1][v][u];
            }
        }
        if (L > R) break;
        ans += R - L + 1;
//        cout << L << ' ' << R << endl;
    }
    cout << ans << endl;
    return 0;
}