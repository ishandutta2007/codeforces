/*
 * @Author: BilyHurington
 * @Date: 2020-09-02 13:05:34
 * @LastEditors: BilyHurington
 * @LastEditTime: 2020-09-02 14:12:21
 */
#include<bits/stdc++.h>
using namespace std;
int n,m,ed[300010][2],dfn[300010],low[300010],dfn_tot,col[300010],col_tot;
vector<int> G[300010],T[300010];
map<pair<int,int>,bool> mp;
void Tarjan(int x,int fa){
    dfn[x]=low[x]=++dfn_tot;
    for(int i=0;i<G[x].size();i++){
        if(G[x][i]==fa) continue;
        if(!dfn[G[x][i]]){
            Tarjan(G[x][i],x);
            low[x]=min(low[x],low[G[x][i]]);
            if(low[G[x][i]]>dfn[x]){
                mp[make_pair(min(G[x][i],x),max(G[x][i],x))]=1;
            }
        }
        else low[x]=min(low[x],dfn[G[x][i]]);
    }
}
void make_col(int x,int c){
    col[x]=c;
    for(int i=0;i<G[x].size();i++){
        if(!col[G[x][i]]&&!mp[make_pair(min(x,G[x][i]),max(x,G[x][i]))]) make_col(G[x][i],c);
    }
}
pair<int,int> find_farthest(int x,int dep,int fa){
    pair<int,int> ans=make_pair(dep,x);
    for(int i=0;i<T[x].size();i++){
        if(T[x][i]!=fa) ans=max(ans,find_farthest(T[x][i],dep+1,x));
    }
    return ans;
}
int main(){
    scanf("%d %d",&n,&m);
    for(int i=1;i<=m;i++){
        scanf("%d %d",&ed[i][0],&ed[i][1]);
        G[ed[i][0]].push_back(ed[i][1]);
        G[ed[i][1]].push_back(ed[i][0]);
    }
    for(int i=1;i<=n;i++) if(!dfn[i]) Tarjan(i,0);
    for(int i=1;i<=n;i++){
        if(!col[i]){
            make_col(i,++col_tot);
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=0;j<G[i].size();j++){
            if(col[G[i][j]]!=col[i]){
                T[col[i]].push_back(col[G[i][j]]);
            }
        }
    }
    printf("%d",find_farthest(find_farthest(1,0,0).second,0,0).first);
    return 0;
}