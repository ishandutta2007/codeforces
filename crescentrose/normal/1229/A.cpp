#include <ctime>
#include <cstdio>
#include <algorithm>
#include <ctime>
#include <iostream>
#include <queue>
#include <bitset>
#include <string>
#include <cstring>
#include <set>
#include <cmath>
using namespace std;
const int N = 1e5;
bool bz[N];
pair<long long, long long> a[N];
int n;
int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n ; i ++)
        scanf("%lld", &a[i].first);
    for (int i = 1; i <= n ; i ++)
        scanf("%lld", &a[i].second);
    sort(a+1, a+n + 1);
    int tot = 0;
    for (int i = 1; i <= n; i ++)
        if (tot == 0 || a[i].first != a[tot].first) {
            a[++tot] = a[i];
        } else
            a[tot].second += a[i].second, bz[tot] = 1;
    long long ans = 0;
    for (int i = tot; i >= 1 ; i--)
        if (bz[i]) {
            ans += a[i].second;
        } else {
            for (int j = i + 1; j <= tot; j ++)
                if ((a[j].first & a[i].first) == a[i].first && bz[j] ) {
                    bz[i] = 1;
                    ans += a[i].second;
                    break;
                }
        }
    cout << ans;
    return 0;
}