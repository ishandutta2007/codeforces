#include <cstdio>
#include <algorithm>
using namespace std;

const int N = 111111;

int n, a[N], sum[N], ans;
char str[N];

int main() {
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    sum[0] = a[0];
    for(int i = 1; i < n; i++)
        sum[i] = sum[i - 1] + a[i];
    scanf("%s", str);
    for(int i = n - 1, tmp = 0; i >= 0; i--) {
        if (str[i] == '1') {
            if (i > 0)
                ans = max(ans, tmp + sum[i - 1]);
            else
                ans = max(ans, tmp);
            tmp += a[i];
        }
        ans = max(ans, tmp);
    }
    printf("%d\n", ans);
    return 0;
}