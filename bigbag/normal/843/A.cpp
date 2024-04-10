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

const int max_n = 101111, inf = 1011111111;

int n, pos[max_n], used[max_n];
pair<int, int> a[max_n];
vector<int> ans, all;

void dfs(int v) {
    ans.push_back(v);
    used[v] = 1;
    if (used[pos[v]] == 0) {
        dfs(pos[v]);
    }
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i].first);
        a[i].second = i;
    }
    sort(a, a + n);
    for (int i = 0; i < n; ++i) {
        pos[a[i].second] = i;
    }
    for (int i = 0; i < n; ++i) {
        if (used[i] == 0) {
            dfs(i);
            all.push_back(ans.size());
        }
    }
    printf("%d\n", all.size());
    int last = 0;
    for (int i = 0; i < all.size(); ++i) {
        printf("%d ", all[i] - last);
        for (int j = last; j < all[i]; ++j) {
            printf("%d ", ans[j] + 1);
        }
        printf("\n");
        last = all[i];
    }
    return 0;
}