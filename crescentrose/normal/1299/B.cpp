#include <algorithm>
#include <cstdio>
using namespace std;
const int N = 1e5 + 10;
int a[N][2];
int n;
int id(int x) {
    return x > n ? x - n : x;
}
int main(){
    scanf("%d", &n);
    for (int i = 1; i <= n; i ++)
        scanf("%d %d", &a[i][0], &a[i][1]);
    if (n & 1) {
        puts("NO");
        return 0;
    }
    for (int i = 1; i <= n / 2; i ++) {
        int x = a[i][0] - a[i + 1][0], y = a[i][1] - a[i + 1][1];
        int j = i + n / 2;
        int xx = a[j][0] - a[id(j + 1)][0], yy = a[j][1] - a[id(j + 1)][1];
        if (x != -xx || y != -yy) {
            puts("NO");
            return 0;
        }
    }
    puts("YES");
    return 0;
}