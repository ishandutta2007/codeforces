#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    int l = 0;
    int r = 10000000;
    while (l + 1 < r) {
        int a = (l + r) / 2;
        // can I do a ?
        //
        int c2 = a / 2 - a / 6;
        int c3 = a / 3 - a / 6;
        int need2 = max(n - c2, 0);
        int need3 = max(m - c3, 0);
        if (need2 + need3 <= a / 6) {
            r = a;
        } else {
            l = a;
        }
    }
    printf("%d\n", r);
    return 0;
}