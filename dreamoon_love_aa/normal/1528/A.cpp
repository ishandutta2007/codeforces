#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
const int SIZE = 1<<20;
int a[SIZE][2];
long long dp[SIZE][2];
vector<int> e[SIZE];
int n;
void dfs(int x,int lt){
    dp[x][0] = dp[x][1] = 0;
    for(int y: e[x]) {
        if(y == lt){ continue; }
        dfs(y, x);
        for(int i = 0; i < 2; i++) {
            dp[x][i] += max(dp[y][0] + abs(a[x][i]-a[y][0]), dp[y][1] + abs(a[x][i] - a[y][1]));
        }
    }
}
void solve() {
    dfs(1, 1);
    printf("%lld\n", max(dp[1][0], dp[1][1]));
    for(int i = 1; i <= n; i++) {
        vector<int> tmp;
        e[i].swap(tmp);
    }
}
void input() {
    scanf("%d", &n);
    for(int i = 1; i <= n; i++){
        scanf("%d%d", &a[i][0], &a[i][1]);
    }
    for(int i = 1; i < n; i++) {
        int u, v;
        scanf("%d%d", &u, &v);
        e[u].push_back(v);
        e[v].push_back(u);
    }
}
int main() {
    int T;
    scanf("%d", &T);
    for(int i = 0; i < T; i++) {
        input();
        solve();
    }
    return 0;
}