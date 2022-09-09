#include<bits/stdc++.h>
#define SZ(X) ((int)(X).size())
#define MP make_pair
#define PB push_back
using namespace std;
const int SIZE = 200001;
int n;
vector<int> e[SIZE];
vector<int> fac[SIZE];
int a[SIZE];
int an = 1;
vector<int> dp[SIZE];
void dfs(int x ,int lt){
    dp[x].assign(fac[a[x]].size(), 1);
    for(int y: e[x]) {
        if(y == lt) continue;
        dfs(y, x);
        int it = 0;
        for(int i = 0; i < (int)dp[y].size(); i++) {
            while(it < dp[x].size() && fac[a[x]][it] < fac[a[y]][i]) it++;
            if(it != dp[x].size() && fac[a[x]][it] == fac[a[y]][i]) {
                an = max(an, dp[x][it] + dp[y][i]);
                dp[x][it] = max(dp[x][it], dp[y][i] + 1);
            }
        }
    }
}
int main(){
    for(int i = 2; i < SIZE; i++) {
        if(SZ(fac[i]) == 0) {
            for(int j = i; j < SIZE; j += i) fac[j].push_back(i);
        }
    }
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
    if(count(a + 1, a + n + 1, 1) == n) {
        puts("0");
        return 0;
    }
    for(int i = 1; i < n; i++) {
        int x, y; 
        scanf("%d%d", &x, &y);
        e[x].push_back(y);
        e[y].push_back(x);
    }
    dfs(1, 1);
    printf("%d\n", an);
    return 0;
}