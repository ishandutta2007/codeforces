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

const int max_n = 100111, inf = 1000111222;

int n, c = 26, g[33][33], used[33];
char a[max_n], b[max_n];
vector<char> q, ans[2];

void dfs(int v) {
    used[v] = 1;
    q.push_back(v);
    for (int i = 0; i < c; ++i) {
        if (g[v][i] && used[i] == 0) {
            dfs(i);
        }
    }
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d%s%s", &n, a, b);
    for (int i = 0; i < n; ++i) {
        if (a[i] != b[i]) {
            g[a[i] - 'a'][b[i] - 'a'] = 1;
            g[b[i] - 'a'][a[i] - 'a'] = 1;
        }
    }
    for (int i = 0; i < c; ++i) {
        if (used[i] == 0) {
            q.clear();
            dfs(i);
            for (int j = 0; j + 1 < q.size(); ++j) {
                ans[0].push_back(q[j] + 'a');
                ans[1].push_back(q[j + 1] + 'a');
            }
        }
    }
    printf("%d\n", ans[0].size());
    for (int i = 0; i < ans[0].size(); ++i) {
        printf("%c %c\n", ans[0][i], ans[1][i]);
    }
    return 0;
}