#include <algorithm>
#include <cstdio>
using namespace std;
int a[1000000];
int main() {
    int T;
    scanf("%d", &T);
    int lastmx = 0;
    //int mn = 0;
    for (int i = 1; i <= T; i ++) {
        int x;
        scanf("%d", &x);
        a[i] = lastmx + x;
        lastmx = max(a[i], lastmx);
    //    mn = min(a[i], mn);
    }
    for (int i = 1; i <= T; i ++)
        printf("%d ", a[i]);
    return 0;
}