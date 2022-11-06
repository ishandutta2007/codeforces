#include <algorithm>
#include <cstdio>
using namespace std;
const int N = 1e6;
char s[N];
int n, x, T;
int a[N];
int sign(int x) {
    return x > 0 ? 1:-1;
}
int main() {
    scanf("%d", &T);
    while (T --) {
        scanf("%d %d", &n, &x);
        scanf("%s", s + 1);
        for (int i = 1; i <= n; i ++)
            a[i] = a[i - 1] + 1 - (s[i] - '0') * 2;
        int ans = 0;
        if (!x)ans = 1;
        for (int i = 1; i <= n; i ++) {
            if (a[n] != 0) {
                if (a[i] == x) ans ++;
                else
                    if (sign(x - a[i]) * sign(a[n]) > 0 && (x - a[i]) % a[n] == 0)
                        ans ++;
            } else {
                if (a[i] == x) ans ++;
            }
        }
        if (a[n] == 0 && ans) ans = - 1;
        printf("%d\n", ans);
    }
    return 0;
}