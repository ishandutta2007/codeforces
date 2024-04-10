#include <stdio.h>
#include <iostream>
#include <string>
#include <string.h>
#include <vector>
#include <cmath>
#include <assert.h>
#include <algorithm>
#include <stdlib.h>
#include <queue>
#include <climits>
#include <set>
#include <unordered_map>
#include <time.h>
#include <map>
#include <stack>
#include <unordered_set>
#include <bitset>
#define hash hassh
#define li __int128_t
#define ull unsigned long long
using namespace std;
int a[300005];
long long pre[300005],mx[300005],sufans[300005],sufmn[300005],suf[300005],preans[300005],premn[300005];
int main() {
    int T = 1;
    //cin >> T;
    while (T--) {
        int n, x;
        cin >> n >> x;
        for (int i = 1; i <= n; i++) scanf("%d", &a[i]), pre[i] = pre[i - 1] + a[i];
        for (int i = n; i >= 1; i--) suf[i] = suf[i + 1] + a[i];
        for (int i = n; i >= 1; i--) sufmn[i] = min(sufmn[i + 1], suf[i]);
        for (int i = n; i >= 1; i--) sufans[i] = suf[i] - sufmn[i];
        for (int i = 1; i <= n; i++) premn[i] = min(premn[i - 1], pre[i]), preans[i] = pre[i] - premn[i];
        //for(int i=1;i<=n;i++) cout<<preans[i]<<" ";puts("");
        long long mx = 0, ans = sufans[1];
        for (int i = 1; i <= n; i++) {
            mx = max(mx, preans[i] - pre[i] * x);
            ans = max(ans, mx + sufans[i + 1] + pre[i] * x);
        }
        printf("%lld\n", ans);
    }
    return 0;
}
//
/// 
//01
//