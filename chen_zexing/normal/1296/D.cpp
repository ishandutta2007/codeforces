#include <stdio.h>
#include<iostream>
#include<string>
#include <string.h>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>
#include <climits>
#include <map>
using namespace std;
int h[200005],n,a,b,k,cost[200005];
bool cmp(int a,int b) {
    return a < b;
}
int main() {
    cin >> n >> a >> b >> k;
    for (int i = 1; i <= n; i++) {
        scanf("%d", &h[i]);
        h[i] %= a + b;
        if (h[i] == 0) h[i] += a + b;
        if (h[i] <= a) cost[i] = 0;
        else {
            h[i] -= a;
            cost[i] = h[i] / a + (h[i] % a > 0);
        }
    }
    sort(cost + 1, cost + n + 1, cmp);
    int ans = 0, cnt = 0;
    while (cnt + cost[ans + 1] <= k && ans < n) cnt += cost[++ans];
    cout << ans << endl;
    return 0;
}