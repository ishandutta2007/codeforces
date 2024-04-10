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
int a[100005];
long long sum[100005];
int main() {
    int T;
    cin >> T;
    while (T--) {
        int n, k, z;
        long long cnt, ans = 0;
        scanf("%d%d%d", &n, &k, &z);
        for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
        sum[0] = 0;
        for (int i = 1; i <= n; i++) sum[i] = sum[i - 1] + a[i];
        for (int j = z; j >= 0; j--) {
            if (k + 1 - 2 * j <= 0) continue;
            cnt = sum[k + 1 - 2 * j];
            int mx = 0;
            if (j * 2 < k) {
                for (int i = 2; i <= k + 1 - 2 * j; i++) mx = max(mx, a[i] + a[i - 1]);
                cnt += j * mx;
                ans = max(ans, cnt);
            }
            //cout<<j<<" "<<cnt<<endl;
            if (j) {
                cnt = sum[k + 1 - 2 * j];
                mx = 0;
                for (int i = 2; i <= k + 1 - 2 * j+1; i++) mx = max(mx, a[i] + a[i - 1]);
                cnt+=j*mx;
                ans = max(ans, cnt);
                //cout << j << " " << cnt << endl;
            }
        }
        printf("%lld\n", ans);
    }
    return 0;
}