#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
const int N = 1e5+ 10;
int n, m;
int f[N][26];
char s1[N], s2[N];
int main() {
    int T;
    scanf("%d", &T);
    while (T --) {
        scanf("%s", s1 + 1);
        scanf("%s", s2 + 1);
        n = strlen(s1 + 1);
        m = strlen(s2 + 1);
        for (int i = 0; i < 26; i ++)
            f[n + 1][i] = 0;
        for (int i = n; i >= 1; i --) {
            for (int j = 0; j < 26; j ++)
                f[i][j] = f[i + 1][j];
            if (i != n)
                f[i][s1[i + 1] - 'a'] = i + 1;
        }
        for (int i = 0; i < 26; i ++)
            f[n + 1][i] = f[1][i];
        f[n + 1][s1[1] - 'a'] = 1;
        for (int i = n; i >= 1; i --) {
            for (int j = 0; j < 26; j ++)
                f[i][j] = f[i + 1][j];
            if (i != n)
                f[i][s1[i + 1] - 'a'] = i + 1;
        }
        int ans = 0;
        int l = n + 1;
        for (int i= 1; i <=m ; i ++)
            if (!f[l][s2[i]- 'a']) {
                ans = -1;
                break;
            } else {
                ans += (f[l][s2[i] - 'a'] <= l);
                l = f[l][s2[i] - 'a'];
            }
        printf("%d\n", ans);
    }
    return 0;
}