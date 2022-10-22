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

int n, m;
Int c[110000];
Int ans[110000];
vector<Int> edge[110000];
vector<Int> edges;
int u, v;
bool come[110000];
Int dep[110000];
Int parent[110000];
Int odd = -1;
Int odd_a, odd_b;
void dfs(int x){
    come[x] = true;
    for(auto e:edge[x]){
        int to = edges[e] - x;
        if(come[to]){
            if((dep[x] - dep[to]) % 2 == 0){
                odd = e;
                odd_a = x;
                odd_b= to;
            }
            continue;
        }
        dep[to] = dep[x] + 1;
        parent[to] = x;
        dfs(to);
        ans[e] += c[to];
        c[x] -= c[to];
        c[to] = 0;
    }
}

int main(){
    scanf("%d%d", &n, &m);
    for(int i = 0;i < n;i++)cin >> c[i];
    for(int i = 0;i < m;i++){
        scanf("%d%d", &u, &v);u--,v--;
        edges.push_back(u+v);
        edge[u].push_back(i);
        edge[v].push_back(i);
    }

    dfs(0);
    if(odd == -1 && c[0] != 0){
        cout << "NO" << endl;
        return 0;
    }
    if(odd == -1){
        cout << "YES" << endl;
        for(int i = 0;i < m;i++)printf("%lld\n", ans[i]);
        return 0;
    }
    Int ex = c[0] / 2;
    if(dep[odd_a] % 2 == 1)ex = -ex;
    ans[odd] += ex;
    c[odd_a] -= ex;
    c[odd_b] -= ex;
    fill(come, come + n, false);
    dfs(0);
    cout << "YES" << endl;
    for(int i = 0;i < m;i++)printf("%lld\n", ans[i]);
    return 0;
}