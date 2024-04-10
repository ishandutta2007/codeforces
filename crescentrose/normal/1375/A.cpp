#include <algorithm>
#include <cstdio>
using namespace std;
int main() {
    int T;
    scanf("%d", &T);
    while (T --) {
        int n;
        scanf("%d", &n);
        while (n --) {
            int x;
            scanf("%d", &x);
            if (n & 1)
                printf("%d ", -abs(x));
            else
                printf("%d ", abs(x));
        }
        puts("");
    }
    return 0;
}