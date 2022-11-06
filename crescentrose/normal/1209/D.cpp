#include <ctime>
#include <cstdio>
#include <random>
#include <algorithm>
#include <ctime>
#include <iostream>
#include <queue>
#include <bitset>
#include <string>
#include <cstring>
#include <cmath>
#include <unordered_map>
using namespace std;
const int N = 1e5  +1;
int a[N * 10][2], g[N],stack[N], dfn[N], low[N], gg[N];
bool instack[N];
void ins(int x, int y, int *g) {
    static int sum = 1;
    a[++sum][0] = y, a[sum][1] = g[x], g[x] = sum;
    a[++sum][0] = x, a[sum][1] = g[y], g[y] = sum;
}
int ans;
int n, k, tot;
void dfs(int x, int y) {
    static int calc = 0;
    dfn[x] = low[x] = ++calc;
    stack[++stack[0]] = x;
    instack[x] = 1;
    for (int i= g[x]; i ; i = a[i][1])
        if (i != y) {
            if (!dfn[a[i][0]]) {
                dfs(a[i][0], i ^ 1);
                low[x] = min(low[x], low[a[i][0]]);
            } else
                if (instack[a[i][0]])
                    low[x] = min(low[x], dfn[a[i][0]]);
        }
    if (low[x] == dfn[x]) {
        int sum = 0;
        ++tot;
        do {
            ++sum;
            instack[stack[stack[0]]] = 0;
            stack[0] --;
        }while (stack[stack[0] + 1] != x);
        ans += sum - 1;
    }
}
int main() {
    scanf("%d %d", &n, &k);
    for (int i = 1; i <= k; i++){
        int x, y;
        scanf("%d %d", &x, &y);
        ins(x, y, g);
    }
    for (int i = 1; i <= n ; i++)
        if (!dfn[i] && g[i]) {
            tot = 0;
            dfs(i, 0);
            ans += tot - 1;
        }
    printf("%d\n", k - ans);
    return 0;
}