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

int n, a, b, da, db;

int depa[110000], depb[110000];
vector<vector<int> > edge;

void dfs(int *dep, int x, int last = -1, int d = 0){
    dep[x] = d;
    for(auto to:edge[x]){
        if(to == last)continue;
        dfs(dep, to, x, d + 1);
    }
}

int dp2[110000];
int dp3[110000];

void dfs2(int x, int last = -1){
    dp2[x] = 0;
    for(auto to:edge[x]){
        if(to == last)continue;
        dfs2(to, x);
        dp2[x] = max(dp2[x], dp2[to] + 1);
    }
}

int far[110000];
void dfs3(int x, int last = -1){
    if(last == -1)dp3[x] = 0;
    vector<int> val;
    for(auto to:edge[x]){
        if(to == last)continue;
        val.push_back(dp2[to] + 1);
    }
    vector<int> lmax(val.size() + 1, 0), rmax(val.size() + 1, 0);
    for(int i = 0;i < val.size();i++){
        lmax[i+1] = max(lmax[i], val[i]);
    }
    for(int i = val.size();i > 0;i--){
        rmax[i-1] = max(rmax[i], val[i-1]);
    }
    int ind = 0;
    for(auto to:edge[x]){
        if(to == last)continue;
        dp3[to] = max({lmax[ind], rmax[ind+1], dp3[x]}) + 1;
        dfs3(to, x);
        ind++;
    }
    far[x] = max(dp2[x], dp3[x]);
}

void solve(){
    scanf("%d%d%d%d%d", &n, &a, &b, &da, &db);
    a--,b--;
    edge.clear();
    edge.resize(n,{});
    for(int i = 0;i < n-1;i++){
        int u, v;
        scanf("%d%d", &u, &v);u--,v--;
        edge[u].push_back(v);
        edge[v].push_back(u);
    }
    if(da * 2 >= db){
        puts("Alice");
        return;
    }
    dfs(depa, a);
    if(depa[b] <= da){
        puts("Alice");
        return;
    }
    dfs(depb, b);
    dfs2(a);
    dfs3(a);
    for(int i = 0;i < n;i++){
        if(depb[i] > da * 2){
            puts("Bob");
            return;
        }
        if(depa[i] > da && far[i] > da*2){
            puts("Bob");
            return;
        }
    }
    puts("Alice");
    return;
}

int main(){
    int T;
    scanf("%d", &T);
    while(T--)solve();
    return 0;
}