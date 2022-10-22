/*
 * @Author: BilyHurington
 * @Date: 2020-02-13 19:20:46
 * @LastEditors: BilyHurington
 * @LastEditTime: 2020-04-12 23:15:03
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
int n,cnt[100010],dep[100010];
vector<int> v[100010];
bool pd;
void dfs(int x,int fa){
    dep[x]=dep[fa]+1;
    if(fa&&v[x].size()==1){if(dep[x]%2==0) pd=1;}
    for(int i=0;i<v[x].size();i++){
        if(v[x][i]==fa) continue;
        dfs(v[x][i],x);
    } 
}
int main(){
    scanf("%d",&n);
    for(int i=1,x,y;i<n;i++){
        scanf("%d %d",&x,&y);
        v[x].push_back(y);
        v[y].push_back(x);
    }
    int ans1=0,ans2=n-1,rt;
    for(int i=1;i<=n;i++) if(v[i].size()==1){rt=i;break;}
    dfs(rt,0);
    if(pd) ans1=3;
    else ans1=1;
    for(int i=1;i<=n;i++){
        if(v[i].size()==1) cnt[v[i][0]]++;
    }
    for(int i=1;i<=n;i++) if(cnt[i]>=2) ans2-=cnt[i]-1;
    printf("%d %d",ans1,ans2);
    return 0;
}