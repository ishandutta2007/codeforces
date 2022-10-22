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
#define MOD 1000000007
#define INF (1<<29)
#define LINF (1LL<<60)
#define EPS (1e-10)
typedef long long Int;
typedef pair<Int, Int> P;

Int u[220000];

void init(Int n){
    for(Int i = 0;i < n;i++)u[i] = i;
}

Int r(Int x){
    if(u[x] == x)return x;
    else return u[x] = r(u[x]);
}

void unite(Int x, Int y){
    x = r(x);
    y = r(y);
    u[x] = y;           
}

vector<Int> edge[220000];
bool witha[220000];
bool withb[220000];

void solve(){
    Int n, m, a, b, u, v;
    cin >> n >> m >> a >> b;a--,b--;
    init(n);
    for(Int i = 0;i < n;i++){
        edge[i].clear();
        witha[i] = false;
        withb[i] = false;
    }
    for(Int i = 0;i < m;i++){
        cin >> u >> v;
        u--, v--;
        edge[u].push_back(v);
        edge[v].push_back(u);
        if (u == a || u == b || v == a || v == b)continue;
        unite(u, v);
    }
    for(auto to: edge[a]){
        witha[r(to)] = true;
    }
    for(auto to: edge[b]){
        withb[r(to)] = true;
    }
    Int onlywitha = 0, onlywithb = 0;
    for(Int i = 0;i < n;i++){
        if (i == a || i == b)continue;
        witha[i] = witha[r(i)];
        withb[i] = withb[r(i)];
        if(witha[i] && !withb[i])onlywitha++;
        if(!witha[i] && withb[i])onlywithb++;
    }
    cout << onlywitha * onlywithb << endl;
}

int main(){
    Int t;
    cin >> t;
    while(t--)solve();
    return 0;
}