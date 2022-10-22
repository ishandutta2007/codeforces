/*
 * @Author: BilyHurington
 * @Date: 2020-09-03 14:02:34
 * @LastEditors: BilyHurington
 * @LastEditTime: 2020-09-04 13:20:45
 */
#include<bits/stdc++.h>
using namespace std;
int n;
long long edge[2010][2010],dis[2010];
bool vis[2010];
int main(){
    scanf("%d",&n);
    int st=0;long long minn=1e18;
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            scanf("%lld",&edge[i][j]);
            edge[j][i]=edge[i][j];
            if(edge[i][j]<minn) minn=edge[i][j],st=i;
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i^j) edge[i][j]-=minn;
        }
    }
    for(int i=1;i<=n;i++){
        dis[i]=edge[st][i];
        for(int j=1;j<i;j++) dis[i]=min(dis[i],2*edge[j][i]);
        for(int j=i+1;j<=n;j++) dis[i]=min(dis[i],2*edge[i][j]);
    }
    for(int ti=1;ti<=n;ti++){
        long long minn=1e18;int x=0;
        for(int i=1;i<=n;i++){
            if(!vis[i]&&minn>dis[i]) minn=dis[i],x=i;
        }
        vis[x]=1;
        for(int i=1;i<=n;i++){
            dis[i]=min(dis[i],dis[x]+edge[x][i]);
        }
    }
    for(int i=1;i<=n;i++) printf("%lld\n",dis[i]+(n-1)*minn);
    return 0;
}