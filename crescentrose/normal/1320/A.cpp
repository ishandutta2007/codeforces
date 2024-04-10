#include <algorithm>
#include <cstdio>
#include <map>
using namespace std;
const int N = 2e5 + 10;
int a[N * 2];
map<int, long long> all;
long long ans = 0;
int main() {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i ++) {
        int x;
        scanf("%d", &x);
    //    if (x >= i)
        ans = max(all[x - i] += x, ans);
    }
    printf("%lld\n", ans);
    return 0;
}