#include <algorithm>
#include <cstdio>
using namespace std;
int main() {
    int T;
    scanf("%d", &T);
    while (T --) {
        int n, m;
        bool the_same = 0;
        int mx = 0;
        scanf("%d %d", &n, &m);
        while (n --) {
            int x;
            scanf("%d", &x);
            the_same|=(x == m);
            mx = max(mx, x);
        }
        if (the_same) {
            puts("1");
            continue;
        }
        printf("%d\n", max(2, (m / mx) + (m % mx > 0)));
    }
    return 0;
}