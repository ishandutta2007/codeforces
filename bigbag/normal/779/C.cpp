#include <map>
#include <set>
#include <stack>
#include <cmath>
#include <queue>
#include <vector>
#include <cstdio>
#include <string>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>

using namespace std;

const int max_n = 200111, inf = 1011111111;

int n, k;
pair<int, int> a[max_n];

bool cmp(pair<int, int> a, pair<int, int> b) {
    return a.first - a.second < b.first - b.second;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i].first);
    }
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i].second);
    }
    sort(a, a + n, cmp);
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        //cout << a[i].first << " " << a[i].second << endl;
        if (i < k || a[i].first <= a[i].second) {
            ans += a[i].first;
        } else {
            ans += a[i].second;
        }
    }
    printf("%d\n", ans);
    return 0;
}