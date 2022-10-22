/*
 * @Author: BilyHurington
 * @Date: 2020-07-24 21:46:09
 * @LastEditors: BilyHurington
 * @LastEditTime: 2020-07-25 10:50:44
 */ 
#include<bits/stdc++.h>
using namespace std;
long double jc[60];
void pre(){
    jc[0]=1;
    for(int i=1;i<=50;i++) jc[i]=jc[i-1]*i;
}
long double C(int x,int y){return jc[x]/jc[y]/jc[x-y];}
int n,siz[60];
vector<int> v[60];
long double f[60][60],f2[60][60],g[60][60];
void dfs(int x,int fa){
    memset(f[x],0,sizeof(f[x]));
    siz[x]=1;f[x][0]=1;
    for(int i=0;i<v[x].size();i++){
        if(v[x][i]==fa) continue;
        dfs(v[x][i],x);
        memset(f2[x],0,sizeof(f2[x]));
        for(int j=0;j<siz[x];j++){
            for(int k=0;k<=siz[v[x][i]];k++){
                f2[x][j+k]+=f[x][j]*g[v[x][i]][k]*C(siz[x]+siz[v[x][i]]-1-j-k,siz[v[x][i]]-k)*C(j+k,k);
            }
        }
        siz[x]+=siz[v[x][i]];
        for(int j=0;j<=siz[x];j++) f[x][j]=f2[x][j];
    }
    memset(g[x],0,sizeof(g[x]));
    for(int i=1;i<=siz[x];i++) g[x][i]=g[x][i-1]+0.5*f[x][i-1];
    for(int i=0;i<=siz[x];i++) g[x][i]+=(siz[x]-i)*f[x][i];
}
int main(){
    scanf("%d",&n);pre();
    for(int i=1,x,y;i<n;i++){
        scanf("%d %d",&x,&y);
        v[x].push_back(y);
        v[y].push_back(x);
    }
    for(int i=1;i<=n;i++){
        dfs(i,0);double ans=f[i][n-1]/jc[n-1];
        printf("%.15lf\n",ans);
    }
    return 0;
}