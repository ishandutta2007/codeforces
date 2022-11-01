#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;

const int inf = 1000000000;
const int N = 5555;

int a[N], b[N], c[N], d[N], add[N];
int ans[N], upper[N];
int n, m;

int main() {
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= m; i++) {
        scanf("%d %d %d %d", &a[i], &b[i], &c[i], &d[i]);
    }   
    for(int i = 1; i <= n; i++)
        upper[i] = inf;
    for(int i = 1; i <= m; i++) {
        if (a[i] == 2) {
            for(int j = b[i]; j <= c[i]; j++) {
                upper[j] = min(upper[j], d[i] - add[j]);
            }
        } else {
            for(int j = b[i]; j <= c[i]; j++) {
                add[j] += d[i];
            }
        }
    }
    for(int i = 1; i <= n; i++)
        ans[i] = upper[i];
     
    for(int i = 1; i <= m; i++) {
        if (a[i] == 2) {
            int mx = -inf;
            for(int j = b[i]; j <= c[i]; j++) {
                mx = max(mx, ans[j]);
            }
            if (mx != d[i]) {
                printf("NO\n");
                return 0;
            }
        } else {
            for(int j = b[i]; j <= c[i]; j++) {
                ans[j] += d[i];
            }
        }
    }
    printf("YES\n");
    for(int i = 1; i <= n; i++) {
        printf("%d ", upper[i]);
    }
    return 0;
}