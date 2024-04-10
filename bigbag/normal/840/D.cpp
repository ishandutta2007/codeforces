#include <ctime>
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

const int max_n = 300333, inf = 1011111111;

const int it = 100;

int my_rand() {
    int x = rand();
    x <<= 16;
    x += rand();
    return x;
}

int my_rand(int mx) {
    return my_rand() % mx;
}

int n, m, a[max_n], k[max_n], ans[max_n], res[max_n][it], cnt[max_n];
int x[max_n][it];
vector<int> q[max_n];

int main() {
    srand(time(NULL));
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &a[i]);
    }
    for (int i = 0; i < m; ++i) {
        int l, r;
        scanf("%d%d%d", &l, &r, &k[i]);
        k[i] = (r - l + 1) / k[i];
        q[l - 1].push_back(-i - 1);
        q[r].push_back(i);
        for (int j = 0; j < it; ++j) {
            int pos = l + my_rand(r - l + 1);
            x[i][j] = a[pos];
        }
    }
    for (int i = 0; i <= n; ++i) {
        ++cnt[a[i]];
        for (int j = 0; j < q[i].size(); ++j) {
            int id;
            if (q[i][j] < 0) {
                id = -q[i][j] - 1;
            } else {
                id = q[i][j];
            }
            for (int k = 0; k < it; ++k) {
                if (q[i][j] < 0) {
                    res[id][k] -= cnt[x[id][k]];
                } else {
                    res[id][k] += cnt[x[id][k]];
                }
            }
        }
    }
    for (int i = 0; i < m; ++i) {
        int ans = inf;
        for (int j = 0; j < it; ++j) {
            if (res[i][j] > k[i]) {
                ans = min(ans, x[i][j]);
            }
        }
        if (ans == inf) {
            ans = -1;
        }
        printf("%d\n", ans);
    }
    return 0;
}