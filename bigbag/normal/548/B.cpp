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

const int max_n = 555, inf = 1111111111;

int n, m, q, a[max_n][max_n], res[max_n];
multiset<int> ans;

void proc(int i) {
    res[i] = 0;
    for (int j = 0; j < m; ++j) {
        int cnt = 0;
        while (j < m && a[i][j] == 1) {
            ++cnt;
            ++j;
        }
        res[i] = max(res[i], cnt);
    }
    ans.insert(res[i]);
}
int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d%d%d", &n, &m, &q);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            scanf("%d", &a[i][j]);
        }
        proc(i);
    }
    while (q--) {
        int x, y;
        scanf("%d%d", &x, &y);
        --x;
        --y;
        a[x][y] ^= 1;
        ans.erase(ans.find(res[x]));
        proc(x);
        printf("%d\n", *ans.rbegin());
    }
    return 0;
}