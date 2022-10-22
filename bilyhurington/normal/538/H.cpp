/*
 * @Author: BilyHurington
 * @Date: 2020-11-06 13:21:36
 * @LastEditors: BilyHurington
 * @LastEditTime: 2020-11-06 13:51:53
 */
#include<bits/stdc++.h>
using namespace std;
int n,m,tmin,tmax,L[100010],R[100010];
vector<int> G[100010];
int col[100010];
bool dfs(int x){
    for(auto to:G[x]){
        if(col[to]==-1){
            col[to]=col[x]^1;
            if(!dfs(to)) return 0;
        }
        else if(col[to]==col[x]) return 0;
    }
    return 1;
}
int main(){
    scanf("%d %d %d %d",&tmin,&tmax,&n,&m);
    int N1=2e9,N2=0;
    for(int i=1;i<=n;i++){
        scanf("%d %d",&L[i],&R[i]);
        N2=max(N2,L[i]);
        N1=min(N1,R[i]);
        col[i]=-1;
    }
    if(N1+N2<tmin) N2=tmin-N1;
    if(N1+N2>tmax) N1=tmax-N2;
    if(N1<0||N2<0){
        puts("IMPOSSIBLE");
        return 0;
    }
    for(int i=1;i<=n;i++){
        bool t1=(L[i]<=N1&&N1<=R[i]);
        bool t2=(L[i]<=N2&&N2<=R[i]);
        // printf("%d %d\n",1+t1,1+t2);
        if(!t1&&!t2){
            puts("IMPOSSIBLE");
            return 0;
        }
        if(t1&&!t2) col[i]=0;
        if(!t1&&t2) col[i]=1;
    }
    for(int i=1,x,y;i<=m;i++){
        scanf("%d %d",&x,&y);
        G[x].push_back(y);
        G[y].push_back(x);
    }
    for(int i=1;i<=n;i++){
        if(col[i]!=-1&&!dfs(i)){
            puts("IMPOSSIBLE");
            return 0;
        }
    }
    for(int i=1;i<=n;i++){
        if(col[i]==-1){
            col[i]=0;
            if(!dfs(i)){
                puts("IMPOSSIBLE");
                return 0;
            }
        }
    }
    puts("POSSIBLE");
    printf("%d %d\n",N1,N2);
    for(int i=1;i<=n;i++) printf("%d",col[i]+1);
    return 0;
}