#include <stdio.h>
#include<iostream>
#include <string>
#include <string.h>
#include <vector>
#include <cmath>
#include <algorithm>
#include <queue>
#include <climits>
#include <set>
#include <unordered_map>
#include <map>
#include <stack>
#define hash hassh
using namespace std;
vector <int> v[100005];
int n,dep[100005],son[100005],cnt[100005],top[100005],fa[100005];
void dfs1(int x,int from){
    dep[x]=dep[from]+1;
    cnt[x]=1;
    fa[x]=from;
    if(v[x].size()==1&&x!=1) return;
    int mx=0;
    for(int i=0;i<v[x].size();i++)
        if(v[x][i]!=from){
            dfs1(v[x][i],x);
            cnt[x]+=cnt[v[x][i]];
            if(mx<cnt[v[x][i]]){
                mx=cnt[v[x][i]];
                son[x]=v[x][i];
            }
        }
}
void dfs2(int x,int from,int ttop){
    top[x]=ttop;
    if(v[x].size()==1&&x!=1) return;
    dfs2(son[x],x,ttop);
    for(int i=0;i<v[x].size();i++)
        if(v[x][i]!=from&&v[x][i]!=son[x]){
            dfs2(v[x][i],x,v[x][i]);
        }
}
int dis(int x,int y){
    if(top[x]==top[y]) return abs(dep[x]-dep[y]);
    int ans=0;
    if(dep[fa[top[x]]]>dep[fa[top[y]]]) ans+=abs(dep[fa[top[x]]]-dep[x]),x=fa[top[x]];
    else ans+=abs(dep[fa[top[y]]]-dep[y]),y=fa[top[y]];
    return ans+dis(x,y);
}
int main() {
    cin>>n;
    int x,y;
    for(int i=1;i<n;i++){
        scanf("%d%d",&x,&y);
        v[x].push_back(y);
        v[y].push_back(x);
    }
    dfs1(1,0);
    dfs2(1,0,1);
    //for(int i=1;i<=n;i++) cout<<dep[i]<<endl;
    int a,b,k,q;
    cin>>q;
    while(q--){
        scanf("%d%d%d%d%d",&x,&y,&a,&b,&k);
        //cout<<dis(a,b)<<" "<<dis(a,y)<<" "<<dis(a,x)<<endl;
        if(dis(a,b)<=k&&dis(a,b)%2==k%2) puts("YES");
        else if(dis(a,x)+dis(b,y)+1<=k&&(dis(a,x)+dis(b,y)+1)%2==k%2) puts("YES");
        else if(dis(a,y)+dis(b,x)+1<=k&&(dis(a,y)+dis(b,x)+1)%2==k%2) puts("YES");
        else puts("NO");
    }
    return 0;
}