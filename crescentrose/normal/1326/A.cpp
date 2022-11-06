#include <algorithm>
#include <cstdio>
using namespace std;
int main() {
    int T;
    scanf("%d", &T);
    while (T --) {
        int n;
        scanf("%d", &n);
        if (n == 1) {
            puts("-1");
            continue;
        }
        printf("2");
        n--;
        while (n --) {
            printf("3");
        }
        puts("");
    }
    return 0;
}