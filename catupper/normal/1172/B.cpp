#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<vector>
#include<map>
#include<set>
#include<string>
#include<queue>
#include<stack>
using namespace std;
#define MOD 998244353
#define INF (1<<29)
#define LINF (1LL<<60)
#define EPS (1e-10)
typedef long long Int;
typedef pair<Int, Int> P;

vector<Int> edge[216000];

Int sz[216000];
Int deg[216000];
Int dfs(Int x, Int last = -1){
    sz[x] = 1;
    vector<Int> szs;
    Int res = 1;
    for(Int to:edge[x]){
        if(to == last)continue;
        deg[x]++;
        Int tmp = dfs(to, x);
        res = res * tmp % MOD;
        res = res * (deg[to] + 1) % MOD;
    }
    for(int i = 1;i <= deg[x];i++){
        res = res * i % MOD;
    }
    return res;       
}

Int u, v;
Int n;

int main(){
    cin >> n;
    for(int i = 1;i < n;i++){
        cin >>u >> v;
        edge[u].push_back(v);
        edge[v].push_back(u);
    }
    cout << dfs(1) * n % MOD << endl;
    return 0;
}