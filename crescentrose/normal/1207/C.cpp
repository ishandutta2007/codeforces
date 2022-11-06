#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;
long long f[400001][2];
char s[400001];
int n, a, b;
int main(){
    int T;
    scanf("%d", &T);
    while (T --) {
        scanf("%d %d %d", &n, &a, &b);
        scanf("%s", s);
        f[0][0] = b;
        f[0][1] = 1e18;
        for (int i = 1; i <= n ; i ++){
            int l = 0, r = 1;
            if ( (i < n && s[i]=='1') || s[i -1] == '1') l = 1;
            for (int j =0; j < 2; j ++)
                f[i][j] = 1e18;
            for (int j1 = 0; j1 < 2; j1 ++)
                for (int j = l; j <= r; j ++) {
                    f[i][j]= min(f[i][j], f[i-1][j1] + (j + 1) * b + a * (1 + (j1 != j)));
                }
        }
        printf("%lld\n", f[n][0]);
    }
    return 0;
}