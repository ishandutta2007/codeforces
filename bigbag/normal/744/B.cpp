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

const int max_n = 1111, inf = 1111111111;

int n, ans[max_n], f[max_n];

void proc() {
    vector<int> q;
    for (int i = 0; i < n; ++i) {
        if (f[i]) {
            q.push_back(i);
        }
    }
    if (q.size()) {
        printf("%d\n", q.size());
        for (int i = 0; i < q.size(); ++i) {
            printf("%d ", q[i] + 1);
        }
        printf("\n");
        fflush(stdout);
        for (int i = 0; i < n; ++i) {
            int res;
            scanf("%d", &res);
            if (f[i] == 0) {
                ans[i] = min(ans[i], res);
            }
        }
    }
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        ans[i] = inf;
    }
    int N = 1024, sz = 512;
    for (int i = 0; i < 10; ++i) {
        memset(f, 0, sizeof(f));
        for (int j = 0; j < N; j += 2 * sz) {
            for (int k = j; k < j + sz; ++k) {
                f[k] = 1;
            }
        }
        proc();
        for (int j = 0; j < N; ++j) {
            f[j] ^= 1;
        }
        proc();
        sz /= 2;
    }
    printf("-1\n");
    for (int i = 0; i < n; ++i) {
        printf("%d ", ans[i]);
    }
    printf("\n");
    fflush(stdout);
    return 0;
}