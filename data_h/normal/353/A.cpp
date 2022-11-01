#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;

const int N = 111;

int a[N], b[N];

int main() {
    int n, sa = 0, sb = 0, flag = 0;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++)
        scanf("%d %d", &a[i], &b[i]), sa += a[i], sb += b[i], flag |= ((a[i] % 2) != (b[i] % 2));
    if (sa % 2 == 0 && sb % 2 == 0) {
        printf("0\n");
        return 0;
    } else if (sa % 2 == sb % 2 && flag) {
        printf("1\n");
        return 0;
    } else {
        printf("-1\n");
    }
    return 0;
}