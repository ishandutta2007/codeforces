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
int a[200005],b[200005],p[200005],cnt[200005];
int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    for (int i = 1; i <= n; i++) scanf("%d", &b[i]);
    for (int i = 1; i <= n; i++) p[a[i]] = i;
    for (int i = 1; i <= n; i++) cnt[(p[b[i]] + n - i) % n]++;
    int mx = INT_MIN;
    for (int i = 0; i < n; i++) mx = max(mx, cnt[i]);
    cout << mx << endl;
    return 0;
}