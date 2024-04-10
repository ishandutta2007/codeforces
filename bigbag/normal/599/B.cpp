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

const int max_n = 111111, inf = 1111111111;

int n, m, f[max_n], b[max_n];
vector<int> v[max_n], ans;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &f[i]);
        v[f[i]].push_back(i);
    }
    for (int i = 0; i < m; ++i) {
        scanf("%d", &b[i]);
    }
    int f = 0;
    for (int i = 0; i < m; ++i) {
        if (v[b[i]].size() == 0) {
            printf("Impossible\n");
            return 0;
        }
        if (v[b[i]].size() != 1) {
            f = 1;
        } else {
            ans.push_back(v[b[i]][0] + 1);
        }
    }
    if (f == 1) {
        printf("Ambiguity\n");
        return 0;
    }
    printf("Possible\n");
    for (int i = 0; i < m; ++i) {
        printf("%d ", ans[i]);
    }
    return 0;
}