#include <algorithm>
#include <cstdio>
using namespace std;
int bz[1000000];
int tag = 0;
int main() {
    int T;
    scanf("%d", &T);
    while (T --) {
        bool sig = 1;
        int n;
        scanf("%d", &n);
        int last;
        scanf("%d", &last);
        last = (last % n + n) % n;
        ++tag;
        bz[last] = tag;
        for (int i = 2; i <= n; i ++) {
            int x;
            scanf("%d", &x);
            x = ((x + (i - 1)) % n  + n) % n;
            if (bz[x] == tag)
                sig = 0;
            bz[x] = tag;
        }
        sig?puts("YES"):puts("NO");
    }
    return 0;
}