#include <algorithm>
#include <cstdio>
using namespace std;
int main() {
    int T;
    scanf("%d", &T);
    while (T --) {
        int x;
        scanf("%d", &x);
        if (x & 1) {
            putchar('7');
            for (int i = 1; i < x / 2; i ++)
                putchar('1');
            puts("");
        } else {
            for (int i = 1; i <= x / 2; i ++)
                putchar('1');
            puts("");
        }
    }
    return 0;
}