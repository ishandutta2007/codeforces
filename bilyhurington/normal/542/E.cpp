/*
 * @Author: BilyHurington
 * @Date: 2020-09-01 20:51:02
 * @LastEditors: BilyHurington
 * @LastEditTime: 2020-09-01 21:00:29
 */
#include<bits/stdc++.h>
using namespace std;
int n,m,ans[1010],col[1010],bel[1010],bel_tot;
vector<int> G[1010];
void dfs(int x){
    bel[x]=bel_tot;
    for(int i=0;i<G[x].size();i++){
        if(col[G[x][i]]!=-1){
            if(col[G[x][i]]==col[x]) throw "Error!";
            continue;
        }
        col[G[x][i]]=col[x]^1;dfs(G[x][i]);
    }
}
int dis[1010];
void BFS(int x){
    memset(dis,-1,sizeof(dis));
    dis[x]=0;queue<int> q;q.push(x);
    while(q.size()){
        int x=q.front();q.pop();
        for(int i=0;i<G[x].size();i++){
            if(dis[G[x][i]]==-1){
                dis[G[x][i]]=dis[x]+1;
                q.push(G[x][i]);
            }
        }
    }
    for(int i=1;i<=n;i++) ans[bel[i]]=max(ans[bel[i]],dis[i]);
}
int main(){
    memset(col,-1,sizeof(col));
    scanf("%d %d",&n,&m);
    for(int i=1,x,y;i<=m;i++){
        scanf("%d %d",&x,&y);
        G[x].push_back(y);
        G[y].push_back(x);
    }
    for(int i=1;i<=n;i++){
        if(bel[i]) continue;
        bel_tot++;col[i]=0;
        try{dfs(i);}catch(const char* ch){
            printf("-1");return 0;
        }
    }
    for(int i=1;i<=n;i++) BFS(i);
    int Ans=0;for(int i=1;i<=n;i++) Ans+=ans[i];
    printf("%d",Ans);
    return 0;
}