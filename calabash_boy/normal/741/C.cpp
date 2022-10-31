#include<bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 10;
vector<int> E[maxn];
int n;
int ans[maxn];
pair<int,int> Q[maxn];
void dfs(int u,int c){
    ans[u] = c;
    for (int v : E[u]){
        if (ans[v])continue;
        dfs(v,3 - c);
    }
}
int main(){
    scanf("%d",&n);
    for (int i=1;i<=n;i++){
        E[2 * i].push_back(2 * i - 1);
        E[2 * i - 1].push_back(2 * i);
    }
    for (int i=1;i<=n;i++){
        int a,b;
        scanf("%d%d",&a,&b);
        Q[i] = make_pair(a,b);
        E[a].push_back(b);
        E[b].push_back(a);
    }
    for (int i = 1;i <= 2 * n;i ++){
        if (!ans[i])dfs(i,1);
    }
    for (int i=1;i <=n;i++){
        int a,b;
        tie(a,b) = Q[i];
        printf("%d %d\n",ans[a],ans[b]);
    }
    return 0;
}