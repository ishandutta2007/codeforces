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

Int n, m, u, v, q;
bool come[330000];
vector<Int> edge[330000];
Int parent[330000];
Int group[330000];
Int g_min[330000];
Int g_max[330000];
Int limit[330000];
Int l_sum[330000];
Int dep[330000];
void dfs(Int x, Int last = -1){
    come[x] = true;
    for(auto to: edge[x]){
        if(come[to]){
            if(dep[to] < dep[x] - 1){
                for(Int now = x;;now = parent[now]){
                    group[now] = x;
                    if(now == to)break;
                }
            }
            continue;
        }
        parent[to] = x;
        dep[to] = dep[x] + 1;
        dfs(to, x);
    }
}

void calc(){
    for(Int i = 1;i <= n;i++)g_min[i] = n;
    for(Int i = 1;i <= n;i++){
        if(!come[i])dfs(i);
        g_min[group[i]] = min(g_min[group[i]], i);
        g_max[group[i]] = max(g_max[group[i]], i);
    }
//    for(Int i = 1;i <= n;i++)cout << i << " " << g_min[group[i]] << " " << g_max[group[i]] << endl;
    limit[0] = 1;
    set<Int> groups = {group[1]};
    for(Int i = 1;i <= n;i++){
        limit[i] = limit[i-1];
        Int &l = limit[i];
        while(true){
            if(l == n || (g_max[group[l+1]] == l+1 && groups.count(group[l+1])))break;
            l++;
            if(g_min[group[l]] == l)groups.insert(group[l]);
        }
        l_sum[i] = l_sum[i-1] + (l - i + 1);
//        cout << i << " " << l << endl;
        if(g_min[group[i]] == i)groups.erase(group[i]);
    }
}

void solve(){
    Int l, r;
    scanf("%lld%lld", &l, &r);
    Int bottom = l;
    Int top = r;
    if(limit[l] >= r){
        top = l;
        bottom = l-1;    }
    while(top - bottom > 1){
        Int mid = (bottom + top) / 2;
        if(limit[mid] >= r)top = mid;
        else bottom = mid;
    }
    Int ans = (r - top + 1) * (r - top + 2) / 2;
    ans += l_sum[bottom] - l_sum[l-1];
    printf("%lld\n", ans);
}

int main(){
    scanf("%lld%lld", &n, &m);
    for(Int i = 1;i <= n;i++)group[i] = i;
    for(Int i = 0;i < m;i++){
        scanf("%lld%lld", &u, &v);
        edge[u].push_back(v);
        edge[v].push_back(u);
    }
    calc();

    scanf("%lld", &q);
    for(Int i = 0;i < q;i++)solve();
    return 0;
}