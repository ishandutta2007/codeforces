#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
int T, n;
int cnt[31];
int a[199999];
int main() {
    scanf("%d", &T);
    while (T --) {
        scanf("%d", &n);
        memset(cnt, 0 ,sizeof(cnt));
        for (int i = 1; i <= n; i ++){
            int x;
            scanf("%d", &x);
            a[i] = x;
            for (int j = 0; j < 30; j ++)
                if ((x >> j) & 1)
                    cnt[j] ++;
        }
        bool sig = 0;
        for (int i = 29; i >= 0; i --)
            if (cnt[i])
            {
                if (n & 1) {
                    if ((cnt[i] & 1)) {
                        if ((cnt[i] / 2) & 1) {
                            puts("LOSE");
                            sig = 1;
                        } else {
                            puts("WIN");
                            sig = 1;
                        }
                        break;
                    } else {
                    }
                } else {
                    if ((cnt[i])& 1 ) {
                        if ((cnt[i] / 2) & 1) {
                            puts("WIN");
                            sig = 1;
                        } else {
                            puts("WIN");
                            sig = 1;
                        }
                        break;
                    }
                }
            }
        if (!sig) puts("DRAW");
    }
    return 0;
}