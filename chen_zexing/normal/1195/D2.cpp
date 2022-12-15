#include <stdio.h>
#include <iostream>
#include <queue>
#include <cstdio>
#include <stack>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <string.h>
#include <limits.h>
#include <map>
#include <string>
#include <bitset>
#include <vector>
using namespace std;
long long pre[100005][11],nxt[100005][11],a[100005];
int cnt[11];
int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        scanf("%lld", &a[i]);
        long long t = a[i], k = 0;
        while (t) {
            t /= 10;
            k++;
        }
        cnt[k]++;
        pre[i][1] = a[i] * 10;
        nxt[i][1] = (a[i] - a[i] % 10) * 10 + a[i] % 10;
        long long now = 100;
        for (int j = 2; j <= 9; j++) {
            pre[i][j] = (pre[i][j - 1] - pre[i][j - 1] % now) * 10 + pre[i][j - 1] % now;
            now *= 100;
        }
        pre[i][10]=(pre[i][9]-pre[i][9]%now)%998244353*10+pre[i][9]%now;
        for (int j = 1; j <= 10; j++) pre[i][j] %= 998244353;
        now = 1000;
        for (int j = 2; j <= 10; j++) {
            nxt[i][j] = (nxt[i][j - 1] - nxt[i][j - 1] % now) * 10 + nxt[i][j - 1] % now;
            now *= 100;
        }
        nxt[i][10]=(nxt[i][9]-nxt[i][9]%now)%998244353*10+nxt[i][9]%now;
        for (int j = 1; j <= 10; j++) nxt[i][j] %= 998244353;
    }
    long long ans = 0;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= 10; j++) {
            ans += (pre[i][j] + nxt[i][j]) * cnt[j];
            ans %= 998244353;
            //printf("%lld %lld %d %d\n",pre[i][j],nxt[i][j],i,j);
        }
    printf("%lld\n", ans);
}