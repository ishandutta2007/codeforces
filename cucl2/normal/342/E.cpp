//
//  main.cpp
//  XeniaAndTree
//
//  Created by  on 2019/10/8.
//  Copyright  2019 . All rights reserved.
//

#include <bits/stdc++.h>
using namespace std;

int n,m;
vector<int> nei[100005];
int dist[100005];
queue<int> q;
vector<int> qs;
const int BlockSize=105;
int ceng[100005];
int fa[25][100005];

void updatelen(){
    while(q.size()){
        int x=q.front();
        q.pop();
        for(int i=0;i<nei[x].size();i++){
            int to=nei[x][i];
            if(dist[to]>dist[x]+1){
                dist[to]=dist[x]+1;
                q.push(to);
            }
        }
    }
    qs.clear();
}

void dfs(int now,int lst,int cen){
    ceng[now]=cen;
    fa[0][now]=lst;
    for(int i=0;i<nei[now].size();i++){
        int to=nei[now][i];
        if(to!=lst){
            dfs(to,now,cen+1);
        }
    }
}

int lca(int a,int b){
    if(ceng[a]>ceng[b]){
        swap(a,b);
    }
    int toup=ceng[b]-ceng[a];
    for(int i=0;i<20;i++){
        if((toup>>i)&1){
            b=fa[i][b];
        }
    }
    if(a==b){
        return a;
    }
    for(int i=19;~i;i--){
        if(fa[i][a]!=fa[i][b]){
            a=fa[i][a];
            b=fa[i][b];
        }
    }
    return fa[0][a];
}

int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<n;i++){
        int a,b;
        scanf("%d%d",&a,&b);
        nei[a].push_back(b);
        nei[b].push_back(a);
    }
    dfs(1,0,0);
    for(int i=1;i<20;i++){
        for(int j=1;j<=n;j++){
            fa[i][j]=fa[i-1][fa[i-1][j]];
        }
    }
    memset(dist,0x3f,sizeof(dist));
    q.push(1);
    dist[1]=0;
    while(q.size()){
        int x=q.front();
        q.pop();
        for(int i=0;i<nei[x].size();i++){
            int to=nei[x][i];
            if(dist[to]>dist[x]+1){
                dist[to]=dist[x]+1;
                q.push(to);
            }
        }
    }
    while(m--){
        int mode;
        scanf("%d",&mode);
        if(mode==1){
            int x;
            scanf("%d",&x);
            if(!dist[x]){
                continue;
            }
            q.push(x);
            qs.push_back(x);
            dist[x]=0;
            if(q.size()>=BlockSize){
                updatelen();
            }
        }else{
            int x;
            scanf("%d",&x);
            int ans=dist[x];
            for(int i=0;i<qs.size();i++){
                ans=min(ans,ceng[x]+ceng[qs[i]]-ceng[lca(x,qs[i])]*2);
            }
            printf("%d\n",ans);
        }
    }
    return 0;
}