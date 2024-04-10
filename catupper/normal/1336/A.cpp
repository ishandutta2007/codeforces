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
#include<complex>
using namespace std;
#define MOD 1000000007
#define MOD2 993244353
#define INF (1<<29)
#define LINF (1LL<<60)
#define EPS (1e-10)
#define PI 3.1415926535897932384626433832795028
typedef long long Int;
typedef pair<Int, Int> P;
typedef long double Real;
typedef complex<Real> CP;

Int n, k;
Int u, v;
vector<Int > edge[220000];
vector<Int> dist(220000, 0);
vector<Int> child(220000, 0);
vector<Int> costs;
void dfs(Int x, Int last = -1){
    child[x] = 1;
    for(auto to: edge[x]){
        if(to == last)continue;
        dist[to] = dist[x] + 1;
        dfs(to ,x);
        child[x] += child[to];
    }
    costs.push_back(dist[x] - (child[x] - 1));
}

int main(){
    scanf("%lld%lld", &n, &k);
    for(Int i = 0;i < n-1;i++){
        scanf("%lld%lld", &u, &v);
        edge[u].push_back(v);
        edge[v].push_back(u);
    }
    dfs(1);
    sort(costs.rbegin(), costs.rend());
    Int ans = 0;
    for(Int i = 0;i < k;i++)ans += costs[i];
    cout << ans << endl;
    
    return 0;
}