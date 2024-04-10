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
#include <time.h>
#include <map>
#include <stack>
#include <unordered_set>
#define hash hassh
using namespace std;
struct seg_tree{
    int x,y;
}tree[800005];
vector <int> v[200005];
int b[200005],a[200005],id[200005],fa[200005],top[200005],son[200005],dep[200005],sz[200005],cnt,n;
long long ans[200005],mm[200005];
void dfs(int x,int from){
    dep[x]=dep[from]+1;
    fa[x]=from;
    sz[x]=1;
    son[x]=0;
    mm[x]=0;
    for(int i=0;i<v[x].size();i++)
        if(v[x][i]!=from){
            dfs(v[x][i],x);
            sz[x]+=sz[v[x][i]];
            mm[x]+=1LL*sz[v[x][i]]*(sz[v[x][i]]-1)/2;
            if(sz[v[x][i]]>sz[son[x]]) son[x]=v[x][i];
        }
}
void dfs2(int x,int ttop){
    id[x]=++cnt;
    top[x]=ttop;
    if(son[x]) dfs2(son[x],ttop);
    for(int i=0;i<v[x].size();i++)
        if(v[x][i]!=fa[x]&&v[x][i]!=son[x])
            dfs2(v[x][i],v[x][i]);
}
int lca(int x,int y){
    while(top[x]!=top[y]){
        if(dep[fa[top[x]]]<dep[fa[top[y]]]) swap(x,y);
        x=fa[top[x]];
    }
    if(dep[x]<dep[y]) swap(x,y);
    return y;
}
int check(int x,int y,int tar){
    int l=lca(x,y);
    if(lca(tar,x)==tar&&lca(tar,l)==l) return 1;
    if(lca(tar,y)==tar&&lca(tar,l)==l) return 1;
    return 0;
}
seg_tree merge(seg_tree a,seg_tree b){
    if(b.x==0) return a;
    if(a.x==0) return b;
    int c[4];
    c[0]=a.x,c[1]=a.y,c[2]=b.x,c[3]=b.y;
    for(int i=0;i<4;i++) if(c[i]==-1) return seg_tree{-1,-1};
    //for(int i=0;i<4;i++) printf("%d ",c[i]);puts("");
    for(int i=0;i<4;i++)
        for(int j=i+1;j<4;j++){
            if(c[i]==c[j]) continue;
            int fl=1;
            for(int k=0;k<4;k++) if(!check(c[i],c[j],c[k])) fl=0;
            if(fl) return seg_tree{c[i],c[j]};
        }
    return seg_tree{-1,-1};
}
void build(int node,int l,int r){
    if(l==r){
        tree[node].x=tree[node].y=l+1;
        //cout<<l<<" "<<r<<" "<<tree[node].x<<" "<<tree[node].y<<endl;
        return;
    }
    int mid=(l+r)>>1;
    build(node*2,l,mid);
    build(node*2+1,mid+1,r);
    tree[node]=merge(tree[node*2],tree[node*2+1]);
    //cout<<l<<" "<<r<<" "<<tree[node].x<<" "<<tree[node].y<<endl;
}
void modify(int node,int l,int r,int pos,int v){
    if(l==r){
        tree[node].x=tree[node].y=v;
        return;
    }
    int mid=(l+r)>>1;
    if(pos<=mid) modify(node*2,l,mid,pos,v);
    else modify(node*2+1,mid+1,r,pos,v);
    tree[node]=merge(tree[node*2],tree[node*2+1]);
}
seg_tree query(int node,int l,int r,int pos,seg_tree temp){
    if(l==r){
        temp=merge(temp,tree[node]);
        return temp;
    }
    int mid=(l+r)>>1;
    if(pos>mid) return query(node*2+1,mid+1,r,pos,merge(temp,tree[node*2]));
    else return query(node*2,l,mid,pos,temp);
}
int main() {
    int T = 1;
    cin >> T;
    while (T--) {
        cin>>n;
        for(int i=1;i<=n;i++) v[i].clear();
        cnt=0;
        for(int i=1;i<=n;i++) a[i]=i-1;
        for(int i=1,x,y;i<n;i++){
            scanf("%d%d",&x,&y);
            x++,y++;
            v[x].push_back(y);
            v[y].push_back(x);
        }
        dfs(1,0);
        dfs2(1,1);
        //for(int i=1;i<=n;i++) cout<<son[i]<<endl;
        build(1,0,n-1);
        long long tot=1LL*n*(n-1)/2,minus=0;
        for(int i=n;i>=1;i--){
            seg_tree temp=query(1,0,n-1,i-1,seg_tree{0,0});
            //cout<<temp.x<<" "<<temp.y<<endl;
            if(temp.x==-1){
                ans[i]=0;
                continue;
            }
            if(temp.x==temp.y){
                long long c=1LL*sz[temp.x]*(n-sz[temp.x])+1LL*sz[temp.x]*(sz[temp.x]-1)/2-mm[temp.x];
                ans[i]=c-minus;
                minus=c;
            }
            else{
                long long c;
                if(lca(temp.x,temp.y)==temp.x){
                    if(lca(temp.y,son[temp.x])==son[temp.x]){
                        c=1LL*sz[temp.y]*(n-sz[son[temp.x]]);
                    }
                    else{
                        int tt=temp.y;
                        while(fa[top[tt]]!=temp.x) tt=fa[top[tt]];
                        tt=top[tt];
                        c=1LL*sz[temp.y]*(n-sz[tt]);
                    }
                }
                else if(lca(temp.x,temp.y)==temp.y){
                    swap(temp.x,temp.y);
                    if(lca(temp.y,son[temp.x])==son[temp.x]){
                        c=1LL*sz[temp.y]*(n-sz[son[temp.x]]);
                    }
                    else{
                        int tt=temp.y;
                        while(fa[top[tt]]!=temp.x) tt=fa[top[tt]];
                        tt=top[tt];
                        c=1LL*sz[temp.y]*(n-sz[tt]);
                    }
                }
                else c=1LL*sz[temp.x]*sz[temp.y];
                ans[i]=c-minus;
                minus=c;
            }
        }
        ans[0]=tot-minus;
        for(int i=0;i<=n;i++) printf("%lld ",ans[i]);
        puts("");
    }
    return 0;
}
//
/// 
//01
// 
//
//dp