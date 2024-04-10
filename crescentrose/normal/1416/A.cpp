#include <algorithm>
#include <cstdio>
using namespace std;
const int N = 3e5 + 10;
int T, n;
pair<int, int> a[N];
int f[N];
int main() {
    scanf("%d", &T);
    while (T -- ) {
        scanf("%d", &n);
        for (int i = 1; i <= n;i ++) {
            scanf("%d", &a[i].first);
            a[i].second = i;
            f[i] = 2e9;
        }
        sort(a +1, a+n + 1);
        int l = 1;
        while (l <= n){
            int r = l;
            while (r < n && a[r  +1].first == a[l].first) r ++;
            int x = 0;
            for (int i = l + 1; i <= r; i ++)
                x = max(a[i].second - a[i  -1].second, x);
            x = max(x, a[l].second);
            x = max(x, n - a[r].second + 1);
            f[x] = min(f[x], a[l].first);
            l = r + 1;
        }
        for (int i = 2; i <= n; i ++)
            f[i] = min(f[i - 1], f[i]);
        for (int i= 1; i <= n;i ++) {
            if (f[i] == 2e9) f[i] = -1;
            printf("%d%c", f[i], " \n"[i == n]);
        }
    }
    return 0;
}