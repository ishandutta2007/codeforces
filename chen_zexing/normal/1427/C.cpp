#include <stdio.h>
#include<iostream>
#include<string>
#include <algorithm>
#include <string.h>
#include <vector>
#include <cmath>
#include <map>
#include <unordered_map>
#include <climits>
#include <queue>
using namespace std;
int ans[100005],x[100005],y[100005],t[100005],n,r,mx[100005];
int main() {
    cin >> r >> n;
    x[0] = y[0] = 1;
    for (int i = 1; i <= n; i++) scanf("%d%d%d", &t[i], &x[i], &y[i]);
    for (int i = 1; i <= n; i++) {
        for (int j = max(0, i - 2 * r); j < i; j++)
            if ((j == 0 || ans[j]) && t[i] - t[j] >= abs(x[i] - x[j]) + abs(y[i] - y[j]))
                ans[i] = max(ans[i], ans[j] + 1);
        if (i > 2 * r) ans[i] = max(ans[i], mx[i - 2 * r - 1] + 1);
        mx[i] = max(ans[i], mx[i - 1]);
    }
    cout << mx[n] << endl;
    return 0;
}