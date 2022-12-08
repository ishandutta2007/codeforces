#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

using namespace std;

typedef long long ll;

const ll MOD = 998244353;

int n, k;
vector<int> link[5002];
int DP[5002][5002];
int mult[5002][5002];
int maxDepth[5002];

inline void dfs(int x, int par = -1){
    int total = 0;
    bool hasChild = false;
    for(int i=0; i<=k; i++) mult[x][i] = 1;
    maxDepth[x] = 1;

    if(par != -1) link[x].erase(find(link[x].begin(), link[x].end(), par));
    for(auto y: link[x]){
        hasChild = true;
        dfs(y, x);

        for(int i=0; i<=k; i++){
            DP[y][i] = (DP[y][i] + (i==0 ? 0 : DP[y][i-1])) % MOD;
            mult[x][i] = ll(mult[x][i]) * DP[y][i] % MOD;
        }

        maxDepth[x] = max(maxDepth[y]+1, maxDepth[x]);
    }

    if(!hasChild){
        DP[x][0] = DP[x][1] = 1;
        return;
    }

    for(int i=0; i<=k && i <= maxDepth[x] + 1; i++){
        if(i*2 <= k){
            DP[x][i] = (mult[x][i] - (i==0 ? 0 : mult[x][i-1]) + MOD) % MOD;
        }
        else{
            vector<int> vecA (1, 1), vecB (1, 1);
            int s = (int)link[x].size();
            for(auto y: link[x]){
                vecA.push_back(ll(vecA.back()) * DP[y][k-i] % MOD);
            }
            for(int j=s-1; j>=0; j--){
                int y = link[x][j];
                vecB.push_back(ll(vecB.back()) * DP[y][k-i] % MOD);
            }
            reverse(vecB.begin(), vecB.end());

            for(int j=0; j<s; j++){
                DP[x][i] += ll(vecA[j]) * vecB[j+1] % MOD * (DP[link[x][j]][i] - (i==0 ? 0 : DP[link[x][j]][i-1]) + MOD) % MOD;
                DP[x][i] %= MOD;
            }
        }
        total += DP[x][i];
        total %= MOD;
    }
    for(int i=k-1; i>=0; i--) DP[x][i+1] = DP[x][i];
    DP[x][0] = total;
}

int main(){
    scanf("%d %d", &n, &k);
    if(k==0){
        printf("1");
        return 0;
    }

    for(int i=1; i<n; i++){
        int x, y;
        scanf("%d %d", &x, &y);
        link[x].push_back(y);
        link[y].push_back(x);
    }

    dfs(1);
    ll ans = 0;
    for(int i=1; i<=k; i++) ans = (ans + DP[1][i]) % MOD;

    printf("%d", DP[1][0]);
}