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

int n, q, k, a[max_n], b[max_n], num[max_n];
vector<int> all[max_n];

int bigger(int num, int pos) {
    return all[num].end() - lower_bound(all[num].begin(), all[num].end(), pos);
}

bool check(int pos) {
    int cnt = 0;
    for (int i = 0; i < k; ++i) {
        cnt += bigger(num[i], pos);
    }
    return cnt == n - pos;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d%d", &a[i], &b[i]);
        all[a[i]].push_back(i);
    }
    scanf("%d", &q);
    while (q--) {
        scanf("%d", &k);
        for (int i = 0; i < k; ++i) {
            scanf("%d", &num[i]);
        }
        int l = -1, r = n;
        while (r - l > 1) {
            int mid = (l + r) / 2;
            if (check(mid)) {
                r = mid;
            } else {
                l = mid;
            }
        }
        if (l == -1) {
            printf("0 0\n");
            continue;
        }
        int ans = a[l];
        printf("%d ", ans);
        num[k] = a[l];
        ++k;
        l = -1, r = all[ans].size() - 1;
        while (r - l > 1) {
            int mid = (l + r) / 2;
            if (check(all[ans][mid])) {
                r = mid;
            } else {
                l = mid;
            }
        }
        printf("%d\n", b[all[ans][r]]);
    }
    return 0;
}