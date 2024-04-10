#include <iostream>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <set>

using namespace std;

const int N = 205;
int R, G, B;
int r[N], g[N], b[N];
long long dp[N][N][N];

long long dfs(int x, int y, int z) {
    if(dp[x][y][z]) return dp[x][y][z];
    if(x && y) dp[x][y][z] = max(dp[x][y][z], dfs(x - 1, y - 1, z) + r[x] * g[y]);
    if(x && z) dp[x][y][z] = max(dp[x][y][z], dfs(x - 1, y, z - 1) + r[x] * b[z]);
    if(z && y) dp[x][y][z] = max(dp[x][y][z], dfs(x, y - 1, z - 1) + b[z] * g[y]);// max
    return dp[x][y][z];
}

int main() {
    cin >> R >> G >> B;
    for(int i = 1; i <= R; i++) scanf("%d", r + i);
    for(int i = 1; i <= G; i++) scanf("%d", g + i);
    for(int i = 1; i <= B; i++) scanf("%d", b + i);
    sort(r + 1, r + R + 1);
    sort(g + 1, g + G + 1);
    sort(b + 1, b + B + 1);
    cout << dfs(R, G, B);
    return 0;
}