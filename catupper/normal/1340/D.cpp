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
#define MOD2 998244353
#define INF (1<<29)
#define LINF (1LL<<60)
#define EPS (1e-10)
#define PI 3.1415926535897932384626433832795028
typedef long long Int;
typedef pair<Int, Int> P;
typedef long double Real;
typedef complex<Real> CP;

int n, u, v;
vector<int> edge[110000];
vector<P> ans;

void dfs(int x, int num, int last = -1){
    ans.emplace_back(x, num);
    int maximum =  max(num, (int)edge[x].size() + (x==1));
    if(num == maximum){
        num -= edge[x].size();
        ans.emplace_back(x, num);
    }
    for(auto to:edge[x]){
        if(to == last)continue;
        dfs(to, ++num, x);
        ans.emplace_back(x, num);
        if(num == maximum){
            num -= edge[x].size();
            ans.emplace_back(x, num);
        }
    }
}

int main(){
    scanf("%d", &n);
    for(int i = 0;i < n-1;i++){
        scanf("%d%d", &u, &v);
        edge[u].push_back(v);
        edge[v].push_back(u);
    }
    dfs(1,0);
    printf("%d\n", (int)ans.size());
    for(auto p:ans){
        printf("%lld %lld\n", p.first, p.second);
    }
    return 0;
}