#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cassert>
#include<cmath>
#include<vector>
#include<map>
#include<set>
#include<string>
#include<queue>
#include<stack>
using namespace std;
#define MOD 1000000007
#define MOD2 998244353
#define INF ((1<<30)-1)
#define LINF (1LL<<60)
#define EPS (1e-10)
typedef long long Int;
typedef pair<Int, Int> P;


int dp[110000][2];
int ans;
vector<int> edge[110000];

void dfs(int x, int last = -1){
    dp[x][0] = edge[x].size();
    dp[x][1] = 1;
    for(int to:edge[x]){
        if(to == last)continue;
        dfs(to, x);
        ans = max(ans, dp[x][0] - 1 + dp[to][1]);
        ans = max(ans, dp[x][0] - 1 + dp[to][0] - 1);
        ans = max(ans, dp[x][1] + dp[to][0] - 1);
        dp[x][0] = max(dp[x][0], int(dp[to][0] - 1 + edge[x].size() - 1));
        dp[x][0] = max(dp[x][0], int(dp[to][1] + edge[x].size() - 1));
        dp[x][1] = max(dp[x][1], int(dp[to][0]));
    }
//    cout << x << " " << dp[x][0] << " " << dp[x][1] << endl;
    ans = max(ans, dp[x][0]);
    ans = max(ans, dp[x][1]);
}


int main(){
    int n, u, v;
    scanf("%d", &n);
    for(int i = 0;i < n-1;i++){
        scanf("%d%d", &u, &v);
        edge[u].push_back(v);
        edge[v].push_back(u);
    }
    dfs(1);
    printf("%d\n", ans);
    return 0;
}