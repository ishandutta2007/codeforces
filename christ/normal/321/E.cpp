#include <bits/stdc++.h>
using namespace std;
int dp[805][4005],N,K,a;
int psa[4005][4005];
#define getchar _getchar_nolock
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
int sum (int i, int j) {
    return psa[j][j] - psa[i-1][j] - psa[j][i-1] + psa[i-1][i-1];
}
void solve (int l, int r, int dl, int dr, int layer) {
    if (l > r) return;
    int mid = (l+r)>>1,descision=0;
    dp[layer][mid] = INT_MAX;
    for (int i = dl; i <= dr && i <= mid; i++) {
        int att = dp[layer-1][i-1]+sum(i,mid);
        if (att < dp[layer][mid]) {
            dp[layer][mid] = att;
            descision = i;
        }
    }
    solve(l,mid-1,dl,descision,layer);
    solve(mid+1,r,descision,dr,layer);
}
int main() {
    scan(N); scan(K); --K;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            scan(a);
            psa[i][j] = psa[i-1][j] + psa[i][j-1] - psa[i-1][j-1];
            if (i < j) psa[i][j] += a;
        }
    }
    for (int i = 1; i <= N; i++) dp[0][i] = psa[i][i];
    for (int i = 1; i <= K; i++) {
        solve(1,N,1,N,i);
    }
    printf ("%d\n",dp[K][N]);
    return 0;
}