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

vector<int> edge[110000];

Int dp[110000];
Int d[110000];
Int dep[110000];

void dfs(int x, int last =-1){
    if(d[x] == 1)return;
    int leafcnt = 0;
    for(auto to:edge[x]){
        if(to == last)continue;
        if(d[to] == 1)leafcnt++;
        dep[to] = dep[x]+1;
        dfs(to, x);
        dp[x] += dp[to] + 1;
    }
    dp[x] -= leafcnt;
    if(leafcnt)dp[x]++;
}

int main(){
    int n, x, y;
    scanf("%d", &n);
    for(int i = 0;i < n-1;i++){
        scanf("%d%d", &x, &y);
        edge[x].push_back(y);
        edge[y].push_back(x);
        d[x]++;d[y]++;
    }
    int r = 1;
    while(d[r] == 1)r++;
    set<int> dd;
    int small = 1;
    dfs(r);
    for(int i = 1;i <= n;i++){
        if(d[i]==1)dd.insert(dep[i] % 2);
    }
    if(dd.size() != 1)small = 3;
    cout << small  << " " << dp[r] << endl;
    return 0;
}