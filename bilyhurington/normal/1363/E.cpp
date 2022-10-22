/*
 * @Author: BilyHurington
 * @Date: 2020-05-31 22:36:40
 * @LastEditors: BilyHurington
 * @LastEditTime: 2020-05-31 23:16:19
 */ 
#include<bits/stdc++.h>
using namespace std;
int n,a[200010],b[200010],c[200010],sum[200010][2],ans[200010],minn[200010];
vector<int> v[200010];
void dfs(int x,int fa){
    if(x==1) minn[x]=a[x];
    else minn[x]=min(minn[fa],a[x]);
    if(b[x]!=c[x]) sum[x][b[x]]++;
    for(int i=0;i<v[x].size();i++){
        if(v[x][i]==fa) continue;
        dfs(v[x][i],x);
        sum[x][0]+=sum[v[x][i]][0];
        sum[x][1]+=sum[v[x][i]][1];
    }
    ans[x]=min(sum[x][0],sum[x][1]);
    sum[x][0]-=ans[x];sum[x][1]-=ans[x];
}
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d %d %d",&a[i],&b[i],&c[i]);
    for(int i=1,x,y;i<n;i++){
        scanf("%d %d",&x,&y);
        v[x].push_back(y);
        v[y].push_back(x);
    }
    dfs(1,0);
    if(sum[1][0]||sum[1][1]){printf("-1");return 0;}
    long long an=0;
    for(int i=1;i<=n;i++) an+=(long long)ans[i]*minn[i];//,printf("%d\n",ans[i]);
    printf("%lld",an*2);
    return 0;
}