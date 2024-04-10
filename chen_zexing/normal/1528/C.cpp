#include <stdio.h>
#include <iostream>
#include <string>
#include <string.h>
#include <vector>
#include <cmath>
#include <assert.h>
#include <algorithm>
#include <queue>
#include <climits>
#include <set>
#include <unordered_map>
#include <time.h>
#include <map>
#include <stack>
#include <unordered_set>
#include <bitset>
#define hash hassh
using namespace std;
vector <int> v1[300005],v2[300005];
int id[300005],tree[1200005],lz[1200005],sz[300005],cnt,n,ans,sub[300005],add[300005],c;
void dfs2(int x){
    id[x]=++cnt;
    sz[id[x]]=1;
    for(int i=0;i<v2[x].size();i++) dfs2(v2[x][i]),sz[id[x]]+=sz[id[v2[x][i]]];
}
void pushdown(int node,int l,int r){
    if(l==r||lz[node]==-1) return;
    tree[node*2]=tree[node*2+1]=lz[node];
    lz[node*2]=lz[node*2+1]=lz[node],lz[node]=-1;
}
void modify(int node,int l,int r,int L,int R,int v){
    if(l>=L&&r<=R){
        tree[node]=v;
        lz[node]=v;
        return;
    }
    pushdown(node,l,r);
    int mid=(l+r)>>1;
    if(mid>=L) modify(node*2,l,mid,L,R,v);
    if(mid<R) modify(node*2+1,mid+1,r,L,R,v);
}
int query(int node,int l,int r,int pos){
    if(l==r) return tree[node];
    pushdown(node,l,r);
    int mid=(l+r)>>1;
    if(pos<=mid) return query(node*2,l,mid,pos);
    else return query(node*2+1,mid+1,r,pos);
}
void dfs1(int x){
    int temp=query(1,1,n,id[x]);
    //cout<<x<<" "<<temp<<" "<<c<<endl;
    if(temp){
        modify(1,1,n,temp,temp+sz[temp]-1,0),sub[x]=temp;
        if(temp>id[x]) modify(1,1,n,temp,temp+sz[temp]-1,temp),add[x]=temp;
        else modify(1,1,n,id[x],id[x]+sz[id[x]]-1,id[x]),add[x]=id[x];
    }
    else modify(1,1,n,id[x],id[x]+sz[id[x]]-1,id[x]),c++,add[x]=id[x];
    ans=max(ans,c);
    for(int i=0;i<v1[x].size();i++) dfs1(v1[x][i]);
    if(add[x]) modify(1,1,n,add[x],add[x]+sz[add[x]]-1,0);
    if(sub[x]) modify(1,1,n,sub[x],sub[x]+sz[sub[x]]-1,sub[x]);
    else c--;
}
int main() {
    int T = 1;
    cin >> T;
    while (T--) {
        cnt=0,ans=0,c=0;
        scanf("%d",&n);
        for(int i=1;i<=n;i++) v1[i].clear(),v2[i].clear(),sub[i]=add[i]=0;
        for(int i=1;i<=n*4;i++) tree[i]=0,lz[i]=-1;
        for(int i=2,x;i<=n;i++) scanf("%d",&x),v1[x].push_back(i);
        for(int i=2,x;i<=n;i++) scanf("%d",&x),v2[x].push_back(i);
        dfs2(1);
        dfs1(1);
        cout<<ans<<endl;
    }
    return 0;
}
//
/// 
//01
// 
//
//dp