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

const int max_n = 202222, inf = 1011111111;

int n, ans[max_n];
pair<int, int> a[max_n], b[max_n];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i].first);
        a[i].second = i;
    }
    for (int i = 0; i < n; ++i) {
        scanf("%d", &b[i].first);
        b[i].second = i;
    }
    sort(a, a + n);
    reverse(a, a + n);
    sort(b, b + n);
    for (int i = 0; i < n; ++i) {
        ans[b[i].second] = a[i].first;
    }
    for (int i = 0; i < n; ++i) {
        printf("%d ", ans[i]);
    }
    printf("\n");
    return 0;
}