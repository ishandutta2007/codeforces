/*
 * @Author: BilyHurington
 * @Date: 2020-10-05 21:26:48
 * @LastEditors: BilyHurington
 * @LastEditTime: 2020-10-05 21:48:10
 */
#include<bits/stdc++.h>
using namespace std;
int n,m,ed[100010][3];
vector<int> G[20010];
bool vis[20010];
pair<int,int> operator + (pair<int,int> p1,pair<int,int> p2){return make_pair(p1.first+p2.first,p1.second+p2.second);}
pair<int,int> dfs(int x){
    pair<int,int> pr;vis[x]=1;
    if(x<=n) pr=make_pair(1,0);
    else pr=make_pair(0,1);
    for(int i=0;i<G[x].size();i++){
        if(vis[G[x][i]]) continue;
        pr=pr+dfs(G[x][i]);
    }
    return pr;
}
bool check(int mid){
    for(int i=1;i<=2*n;i++) G[i].clear(),vis[i]=0;
    for(int i=1;i<=m;i++){
        if(ed[i][2]<=mid){
            G[ed[i][0]].push_back(ed[i][1]);
            G[ed[i][1]].push_back(ed[i][0]);
        }
    }
    for(int i=1;i<=n;i++){
        if(vis[i]) continue;
        pair<int,int> ans=dfs(i);
        if(ans.first!=ans.second) return 0;
    }
    return 1;
}
int main(){
    scanf("%d %d",&n,&m);
    for(int i=1;i<=m;i++){
        scanf("%d %d %d",&ed[i][0],&ed[i][1],&ed[i][2]);
        ed[i][1]+=n;
    }
    int L=0,R=1.01e9,mid;
    while(L<R){
        mid=(L+R)>>1;
        if(check(mid)) R=mid;
        else L=mid+1;
    }
    printf("%d",L>1e9?-1:L);
    return 0;
}