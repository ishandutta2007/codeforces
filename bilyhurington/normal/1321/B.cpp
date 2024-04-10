/*
 * @Author: BilyHurington
 * @Date: 2020-02-13 19:20:46
 * @LastEditors: BilyHurington
 * @LastEditTime: 2020-03-01 21:29:16
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
int n,b[200010];
long long ans;
map<int,int> mp;
vector<int> v[200010];
void dfs(int x,long long dep){
    ans=max(ans,dep);
    for(int i=0;i<v[x].size();i++){
        dfs(v[x][i],dep+b[v[x][i]]);
    }
}
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&b[i]);
        v[mp[b[i]-i]].push_back(i);
        mp[b[i]-i]=i;
    }
    dfs(0,0);
    printf("%lld",ans);
    return 0;
}