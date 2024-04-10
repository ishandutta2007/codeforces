/*
 * @Author: BilyHurington
 * @Date: 2020-02-13 19:20:46
 * @LastEditors: BilyHurington
 * @LastEditTime: 2020-03-01 22:02:55
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
int n,m,k,ed[200010][2],dis[200010],p[200010],siz[200010];
vector<int> v[200010];
map<int,int> mp[200010]; 
queue<int> q;
int main(){
    scanf("%d %d",&n,&m);
    for(int i=1;i<=m;i++){
        scanf("%d %d",&ed[i][0],&ed[i][1]);
        v[ed[i][1]].push_back(ed[i][0]);
    }
    scanf("%d",&k);
    for(int i=1;i<=k;i++) scanf("%d",&p[i]);
    q.push(p[k]);
    dis[p[k]]=1;
    while(q.size()){
        int x=q.front();
        q.pop();
        for(int i=0;i<v[x].size();i++){
            if(!dis[v[x][i]]){
                dis[v[x][i]]=dis[x]+1;
                q.push(v[x][i]);
            }
        }
    }
    int ans1=0,ans2=0;
    for(int i=1;i<=m;i++){
        if(dis[ed[i][0]]==dis[ed[i][1]]+1) mp[ed[i][0]][ed[i][1]]=1,siz[ed[i][0]]++;
    }
    for(int i=1;i<k;i++){
        int x=p[i],y=p[i+1];
        if(!mp[x][y]) ans1++,ans2++;
        else if(siz[x]>1) ans2++;  
    }
    printf("%d %d\n",ans1,ans2);
    return 0;
}