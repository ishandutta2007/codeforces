#include <ctime>
#include <cstdio>
#include <algorithm>
#include <ctime>
#include <iostream>
#include <queue>
#include <bitset>
#include <string>
#include <cstring>
#include <set>
#include <cmath>
using namespace std;
const int N = 1001;
int a[N][N], b[N], c[N];
int n;
bool check(int x) {
    c[1] = x;
    for (int i = 2; i <= n; i ++) {
        c[i] = a[1][i] / x;
        if (c[i] > b[i] || b[i] % c[i]) return 0;
    }
    for (int i = 2; i <= n ; i++)
        for (int j = i + 1; j <= n ; j ++)
            if (1ll * c[i] * c[j] != a[i][j])
                return 0;
    return 1;
}
int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n ; i ++) {
        for (int j = 1; j <= n; j++)
            scanf("%d", &a[i][j]);
        if (i == 1)
            b[i] = a[i][2];
        else
            b[i] = a[i][1];
        for (int j = 1;j <= n; j ++)
            if (i != j)
                b[i] = __gcd(a[i][j], b[i]);
    }
    for (int i = 1; 1ll *i * i <= b[1]; i ++)
        if (b[1] % i == 0) {
            if (check(i))
                break;
            if (check(b[1] / i))
                break;
        }
    for (int i = 1; i <= n ; i++)
        printf("%d ", c[i]);
    return 0;
}