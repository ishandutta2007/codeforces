#include <stdio.h>
#include<iostream>
#include<string>
#include <string.h>
#include <vector>
#include <cmath>
#include <algorithm>
#include <queue>
#include <climits>
#include <set>
#include <unordered_map>
#include <map>
using namespace std;
vector <int> v[100005];
int a[100005],mx_nxt[100005],n;
int query(int x) {
    int ans = 0;
    while (x) {
        ans = max(ans, mx_nxt[x]);
        x -= x & -x;
    }
    return ans;
}
void insert(int x,int v) {
    while (x <= n + 2) {
        mx_nxt[x] = max(v, mx_nxt[x]);
        x += x & -x;
    }
}
int main() {
    int ans = 1;
    cin >> n;
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    for (int i = 1; i <= n + 1; i++) v[i].push_back(0);
    for (int i = 1; i <= n; i++) v[a[i]].push_back(i);
    for (int i = 1; i <= n + 1; i++) v[i].push_back(n + 1);
    for (int i = 1; i <= n + 1; i++, ans++) {
        int f = 0;
        if (v[i].size() == n + 2) break;
        for (int j = 1; j < v[i].size(); j++)
            if (query(v[i][j - 1] + 1) < v[i][j])
                f = 1;
        if (!f) break;
        for (int j = 1; j < v[i].size(); j++)
            insert(v[i][j - 1] + 1, v[i][j]);
    }
    cout << ans << endl;
    return 0;
}