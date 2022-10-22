/*
 * @Author: BilyHurington
 * @Date: 2020-02-13 19:20:46
 * @LastEditors: BilyHurington
 * @LastEditTime: 2020-04-15 22:52:11
 */
#include<cstdio>
#include<cmath>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<iostream>
#include<set>
#include<map>
#include<vector>
#include<queue>
using namespace std;
int n,k,siz[200010],val[200010],a[200010];
vector<int> v[200010];
priority_queue<int> q;
void dfs(int x,int fa,int dep){
    siz[x]=1;
    for(int i=0;i<v[x].size();i++){
        if(v[x][i]==fa) continue;
        dfs(v[x][i],x,dep+1);
        siz[x]+=siz[v[x][i]];
    }
    val[x]=dep-siz[x];
    q.push(val[x]);
}
int main(){
    scanf("%d %d",&n,&k);
    for(int i=1,x,y;i<n;i++){
        scanf("%d %d",&x,&y);
        v[x].push_back(y);
        v[y].push_back(x);
    }
    dfs(1,0,1);
    long long ans=0;
    while(k--) ans+=q.top(),q.pop();
    printf("%lld",ans);
    return 0;
}