#include <bits/stdc++.h>
using namespace std;
#define MAXN 4005
#define MAXK 805
#define INF 1061109567

inline int getint(){
	char c;
	while((c=getchar())<'0'||c>'9'); return c-'0';
}

int n, k;
int arr[MAXN][MAXN];
int cost[MAXN][MAXN];
int dp[MAXK][MAXN]; //k, n

void calc(int lvl, int l, int r, int tl, int tr){
    if(l > r) return;
    int mid = (l+r)>>1;
    pair<int, int> best = {INF, -1};
    for(int i = tl; i<=min(mid, tr); i++){
        best = min(best, {dp[lvl-1][i-1]+cost[i][mid], i});
    }
    dp[lvl][mid] = best.first;
    int tm = best.second;
    calc(lvl, l, mid-1, tl, tm);
    calc(lvl, mid+1, r, tm, tr);
}

int main(){
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    scanf("%d %d", &n, &k);
    for(int i = 1; i<=n; i++){
        for(int j = 1; j<=n; j++) arr[i][j] = getint();
    }
    for(int len = 1; len<=n; len++){
        for(int i = 1; i+len-1<=n; i++){
            int j = i+len-1;
            cost[i][j]=cost[i+1][j]+cost[i][j-1]-cost[i+1][j-1]+arr[i][j];
        }
    }
    memset(dp, 0x3f3f3f3f, sizeof dp);
    for(int i = 1; i<=n; i++) dp[1][i] = cost[1][i];
    for(int i = 2; i<=k; i++) calc(i, i, n, 1, n);
    printf("%d \n", dp[k][n]);
}