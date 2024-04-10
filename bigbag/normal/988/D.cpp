#include <bits/stdc++.h>

using namespace std;

const int max_n = 200222, inf = 1000111222;

int n, a[max_n], p[max_n];
vector<int> ans;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }
    sort(a, a + n);
    ans = {a[0]};
    for (long long pw = 1; pw < 2 * inf; pw *= 2) {
        int cur = 0;
        for (int i = 0; i < n; ++i) {
            while (a[cur] + pw < a[i]) {
                ++cur;
            }
            p[i] = -1;
            if (a[cur] + pw == a[i]) {
                p[i] = cur;
            }
        }
        for (int i = 0; i < n; ++i) {
            if (p[i] != -1 && p[p[i]] != -1) {
                ans = {a[p[p[i]]], a[p[i]], a[i]};
                break;
            }
            if (p[i] != -1) {
                ans = {a[p[i]], a[i]};
            }
        }
        if (ans.size() == 3) {
            break;
        }
    }
    printf("%d\n", ans.size());
    for (int x : ans) {
        printf("%d ", x);
    }
    printf("\n");
    return 0;
}