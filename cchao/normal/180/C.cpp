#include <bits/stdc++.h>
using namespace std;

char s[100010];
int a[100010], n;
int main() {
    scanf("%s", s + 1);
    a[0] = 0;
    n = strlen(s + 1);
    for(int i = 1; i <= n; ++i)
        a[i] = a[i-1] + (isupper(s[i]) ? 0 : 1);
    int ans = a[n], tmp = 0;
    for(int i = n; i >= 1; --i) {
        tmp += islower(s[i]) ? 0 : 1;
        ans = min(ans, tmp + a[i - 1]);
    }
    printf("%d\n", ans);
    return 0;
}