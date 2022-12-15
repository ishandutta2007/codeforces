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
int a[200005],to[200005],len[200005],mx[200005];
bool cmp(int a,int b)
{
    return a<b;
}
int main() {
    int T;
    cin >> T;
    while (T--) {
        int n, k, t, ans = 0;
        cin >> n >> k;
        for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
        for (int i = 1; i <= n + 1; i++) mx[i] = 0;
        for (int i = 1; i <= n; i++) scanf("%d", &t);
        sort(a + 1, a + n + 1, cmp);
        int st = 1, ed = 1;
        while (st <= n) {
            while (ed <= n && a[ed] - a[st] <= k) ed++;
            to[st] = ed - 1;
            len[st] = ed - st;
            st++;
        }
        for (int i = n; i >= 1; i--) mx[i] = max(mx[i + 1], len[i]);
        for (int i = 1; i <= n; i++) ans = max(ans, len[i] + mx[to[i] + 1]);
        cout << ans << endl;
    }
    return 0;
}