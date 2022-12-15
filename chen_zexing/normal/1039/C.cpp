#include <stdio.h>
#include<iostream>
#include<string>
#include <string.h>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>
#include <climits>
using namespace std;
long long mod=1000000007;
long long c[500005];
int fa[500005],used[500005],have[500005];
struct edge
{
    int a,b;
    long long x;
}a[500005];
bool cmp(edge a,edge b)
{
    return a.x<b.x;
}
int find(int x)
{
    if(fa[x]==x) return x;
    return fa[x]=find(fa[x]);
}
long long quick_pow(long long a,long long b)
{
    long long ans=1;
    while(b)
    {
        if(b&1) ans*=a;
        b>>=1;
        ans%=mod;
        a*=a;
        a%=mod;
    }
    return ans;
}
int main() {
    int n, m, k, cnt = 0;
    long long ans = 0;
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++) scanf("%lld", &c[i]);
    for (int i = 1; i <= n; i++) fa[i] = i;
    for (int i = 1; i <= m; i++) {
        scanf("%d%d", &a[i].a, &a[i].b);
        a[i].x = c[a[i].a] ^ c[a[i].b];
    }
    sort(a + 1, a + m + 1, cmp);
    for (int i = 1; i <= m; i++) {
        int x = 0;
        used[++x] = a[i].a;
        if (have[a[i].a]) x--;
        else have[a[i].a] = 1;
        used[++x] = a[i].b;
        if (have[a[i].b]) x--;
        else have[a[i].b] = 1;
        fa[a[i].b] = a[i].a;
        long long v = a[i].x;
        while (a[i + 1].x == v && i < m) {
            i++;
            used[++x] = a[i].a;
            if (have[a[i].a]) x--;
            else have[a[i].a] = 1;
            used[++x] = a[i].b;
            if (have[a[i].b]) x--;
            else have[a[i].b] = 1;
            if (find(a[i].a) != find(a[i].b))
                fa[find(a[i].b)] = find(a[i].a);
        }
        cnt++;
        int num = n;
        for (int j = 1; j <= x; j++) {
            if (fa[used[j]] != used[j]) {
                num--;
                fa[used[j]] = used[j];
            }
            have[used[j]] = 0;
        }
        ans += quick_pow(2, num);
        ans %= mod;
    }
    long long t = quick_pow(2, k);
    t -= cnt;
    t %= mod;
    long long p = quick_pow(2, n);
    ans += t * p;
    ans %= mod;
    printf("%lld\n", ans);
    return 0;
}