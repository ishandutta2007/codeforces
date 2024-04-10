#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;

const int N = 2222;
const int inf = 2000000000;
const double eps = 1e-6;
int f[N]; 
int a[N];
double delta[N][N];
int n, k;

int check(int limit) {
    f[0] = 0;
    for(int i = 1; i <= n; i++) {
        f[i] = i - 1;
        for(int j = 1; j < i; j++) {
            if (delta[i][j] < limit + eps)
                f[i] = min(f[i], f[j] + (i - j - 1));
        }
        if (f[i] + n - i <= k)
            return 1;
    }
    return 0;
}

int main() {
    scanf("%d %d", &n, &k);
    for(int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    int upper = 0;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j < i; j++) {
            delta[i][j] = 1.0 * abs(a[i] - a[j]) / (i - j);
            upper = max(upper, abs(a[i] - a[j]));
        }
    int l = 0, r = upper, mid;
    while(l < r) {
        mid = (1LL * l + r) / 2;
        if (check(mid))
            r = mid;
        else
            l = mid + 1;
    }
    printf("%d\n", l);
    return 0;
}