#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
using namespace std;
#define ll long long

const int N = 100100;
int n, m;
int a[N], b[N], pre[N], suf[N], f[N];

int main(){
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; i++) scanf("%d", a + i);
    for(int i = 1; i <= m; i++) scanf("%d", b + i);
    sort(a + 1, a + n + 1);
    sort(b + 1, b + m + 1);
    pre[1] = 0, suf[n] = n;
    for(int i = 2; i <= n; i++)
        if (a[i] == a[i - 1] + 1) pre[i] = pre[i - 1]; else pre[i] = i - 1;
    for(int i = n - 1; i >= 1; i--)
        if (a[i] == a[i + 1] - 1) suf[i] = suf[i + 1]; else suf[i] = i;
    for(int i = 1, w; i <= n; i++){
        w = lower_bound(b + 1, b + m + 1, a[i]) - b;
        int best = f[i - 1];
        for(int j = w - 1; j; j--){
            int k = i - (a[i] - b[j]);
            if (k >= 1) best = max(best, f[pre[k]] + w - j); else break;
        }
        f[i] = max(f[i], best);
        for(int j = w; j <= m; j++){
            int k = i + (b[j] - a[i]);
            if (k <= n) f[suf[k]] = max(f[suf[k]], best + j - w + 1); else break;
        }
    }
    printf("%d\n", f[n]);
    return 0;
}