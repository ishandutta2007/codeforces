#include <bits/stdc++.h>
#define ef else if

using namespace std;

typedef long long _;
typedef pair<_, _> _p;
typedef string str;
typedef const long long constant;

constant maxn = 5E5+8;
constant lg = 20+8;

_ n, m, a[maxn], f[lg][maxn], x, y;

int main() {

#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
#endif
    
    scanf("%lld%lld", &n, &m);
    for(; n--; ) {
        scanf("%lld%lld", &x, &y);
        a[x] = max(a[x], y);
    }
    for(_ i = 1; i <= 5E5; ++i) a[i] = max(a[i], a[i-1]);
    for(_ i = 0; i <= 5E5; ++i) f[0][i] = a[i];
    for(_ i = 1; i <= 20; ++i) for(_ j = 0; j <= 5E5; ++j) f[i][j] = f[i-1][f[i-1][j]];
    for(; m--; ) {
        scanf("%lld%lld", &x, &y);
        _ s = 0;
        for(_ i = 20; i >= 0; --i) if(f[i][x] < y) {
            s |= 1<<i;
            x = f[i][x];
        }
        if(f[0][x] >= y) printf("%lld\n", s+1);
        else puts("-1");
    }
    
    return 0;
}