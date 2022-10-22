//
// Created by Junjie Wu on 2021/2/18.
//

#include <bits/stdc++.h>

int L, R;
int left[50];
std::vector<std::vector<int>> ans;

int main() {
    scanf("%d%d", &L, &R);

    int n = 22; // 2^20 > 1e6, so n = 19+2+1 = 22
    /*
     * [1, n - 1] forms a complete graph
     * each node i \in [2, n - 1] connect to n, can contribute 2^{i-2} path
     * those path's length is at least 2
     * so, if L = 1, we connect 1 and n, then solve problem [L + 1, R]
     */

    if (L == 1) {
        if (++L > R) {
            printf("YES\n");
            printf("2 1\n");
            printf("1 2 1\n");
            return 0;
        }
        ans.push_back({1, n, 1});
    }

    int path = R - L + 1;

    /*
     * node 1 is [0, 0]
     * if (node i connect to n)
     *     node i should be with range [right_after_last_connected_node, ...]
     * else
     *     node i should be with range [1, ...]
     */
    int now = 1;
    left[1] = 0;
    for (int i = 2; i < n; ++i) {
        bool connectedToN = (path >> (i - 2)) & 1;
        if (connectedToN) {
            ans.push_back({i, n, L - 1});
            left[i] = now;
            now += (1 << (i - 2));
        } else {
            left[i] = 1;
        }

        int tmp = left[i];
        for (int j = 1; j < i; ++j) {
            int c = tmp - left[j];
            ans.push_back({j, i, c});
            tmp += (j == 1) ? 1 : (1 << (j - 2));
        }
    }

    printf("YES\n");
    printf("%d %lu\n", n, ans.size());
    for (auto &edge : ans) {
        printf("%d %d %d\n", edge[0], edge[1], edge[2]);
    }
    return 0;
}