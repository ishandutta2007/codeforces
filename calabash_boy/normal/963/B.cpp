#include<bits/stdc++.h>
using namespace std;
const int maxn = 2e5+100;
vector<int> E[maxn];
int sz[maxn];
int n;
void dfs1(int x,int fa){
    sz[x]=1;
    for (int y:E[x]){
        if (y==fa)continue;
        dfs1(y,x);
        sz[x]+=sz[y];
    }
}
void dfs2(int x,int fa){
    for (int y:E[x]){
        if (y==fa||sz[y]&1)continue;
        dfs2(y,x);
    }
    printf("%d\n",x);
    for (int y:E[x]){
        if (y==fa||sz[y]%2==0)continue;
        dfs2(y,x);
    }
}
int main(){
    scanf("%d",&n);
    for (int i=1;i<=n;i++){
        int p;
        scanf("%d",&p);
        if (p)E[p].push_back(i),E[i].push_back(p);
    }
    if (n&1){
        printf("YES\n");
        dfs1(1,-1);
        dfs2(1,-1);
    }else{
        printf("NO\n");
    }
    return 0;
}