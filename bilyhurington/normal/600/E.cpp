/*
 * @Author: BilyHurington
 * @Date: 2020-06-11 13:15:51
 * @LastEditors: BilyHurington
 * @LastEditTime: 2020-06-11 13:28:16
 */ 
#include<bits/stdc++.h>
using namespace std;
int n,siz[100010],son[100010];
long long ans[100010];
vector<int> v[100010];
struct Node{
    unordered_map<int,int> mp;
    int maxn;
    long long maxn_sum;
    void insert(int x,int num){
        mp[x]+=num;
        if(mp[x]==maxn) maxn_sum+=x;
        if(mp[x]>maxn) maxn=mp[x],maxn_sum=x;
    } 
    void merge(Node &Q){
        if(Q.mp.size()>mp.size()) swap(Q.mp,mp),maxn=Q.maxn,maxn_sum=Q.maxn_sum;
        for(unordered_map<int,int>::iterator it=Q.mp.begin();it!=Q.mp.end();++it){
            insert(it->first,it->second);
        }
    }
}P[100010];
void dfs1(int x,int fa){
    siz[x]=1;
    for(int i=0;i<v[x].size();i++){
        if(v[x][i]==fa) continue;
        dfs1(v[x][i],x);
        siz[x]+=siz[v[x][i]];
        if(siz[v[x][i]]>siz[son[x]]) son[x]=v[x][i];
    }
}
void dfs2(int x,int fa){
    if(!son[x]){ans[x]=P[x].maxn_sum;return;}
    for(int i=0;i<v[x].size();i++){
        if(v[x][i]==fa) continue;
        dfs2(v[x][i],x);
        P[x].merge(P[v[x][i]]);
    }
    ans[x]=P[x].maxn_sum;
}
int main(){
    scanf("%d",&n);
    for(int i=1,x;i<=n;i++) scanf("%d",&x),P[i].insert(x,1);
    for(int i=1,x,y;i<n;i++){
        scanf("%d %d",&x,&y);
        v[x].push_back(y);
        v[y].push_back(x);
    }
    dfs1(1,0);dfs2(1,0);
    for(int i=1;i<=n;i++) printf("%lld ",ans[i]);
    return 0;
}