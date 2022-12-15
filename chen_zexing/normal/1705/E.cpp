#pragma GCC optimize("Ofast,unroll-loops")
#include <iostream>
#include <unordered_map>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <climits>
#include <algorithm>
#include <complex>
#include <string.h>
#include <iomanip>
#include <assert.h>
#include <random>
using namespace std;
int a[200005],cnt[300005];
int tree[1200005][2],lz[1200005];
void build(int node,int l,int r){
    if(l==r){
        tree[node][cnt[l]]=1;
        return;
    }
    int mid=(l+r)>>1;
    build(node*2,l,mid),build(node*2+1,mid+1,r);
    tree[node][0]=tree[node*2][0]+tree[node*2+1][0];
    tree[node][1]=tree[node*2][1]+tree[node*2+1][1];
}
void pushdown(int node,int l,int r){
    if(lz[node]!=-1){
        int mid=(l+r)>>1;
        tree[node*2][lz[node]]=mid-l+1,tree[node*2][lz[node]^1]=0;
        tree[node*2+1][lz[node]]=r-mid,tree[node*2+1][lz[node]^1]=0;
        lz[node*2]=lz[node*2+1]=lz[node],lz[node]=-1;
    }
}
void update(int node,int l,int r,int L,int R,int v){
    if(L>R) return;
    if(l>=L&&r<=R){
        tree[node][v]=r-l+1,tree[node][v^1]=0;
        lz[node]=v;
        return;
    }
    pushdown(node,l,r);
    int mid=(l+r)>>1;
    if(mid>=L) update(node*2,l,mid,L,R,v);
    if(mid<R) update(node*2+1,mid+1,r,L,R,v);
    tree[node][0]=tree[node*2][0]+tree[node*2+1][0];
    tree[node][1]=tree[node*2][1]+tree[node*2+1][1];
}
int query(int node,int l,int r,int pos,int v){
    if(l>=pos&&tree[node][v]==0) return -1;
    if(l==r){
        if(tree[node][v]) return l;
        else return -1;
    }
    pushdown(node,l,r);
    int mid=(l+r)>>1;
    if(pos>mid) return query(node*2+1,mid+1,r,pos,v);
    else{
        int temp=query(node*2,l,mid,pos,v);
        if(temp!=-1) return temp;
        else return query(node*2+1,mid+1,r,pos,v);
    }
}
int query_mx(int node,int l,int r){
    if(l==r) return l;
    pushdown(node,l,r);
    int mid=(l+r)>>1;
    if(tree[node*2+1][1]) return query_mx(node*2+1,mid+1,r);
    else return query_mx(node*2,l,mid);
}
void add(int pos){
    int p=query(1,1,300000,pos,0);
    //cout<<p<<endl;
    update(1,1,300000,pos,p-1,0);
    update(1,1,300000,p,p,1);
}
void mnus(int pos){
    int p=query(1,1,300000,pos,1);
    //cout<<p<<" ";
    update(1,1,300000,pos,p-1,1);
    update(1,1,300000,p,p,0);
}
int main() {
    int T = 1, kase = 0;
    //cin >> T;
    while (T--) {
        int n,q;
        cin>>n>>q;
        memset(lz,-1,sizeof(lz));
        for(int i=1;i<=n;i++) scanf("%d",&a[i]),cnt[a[i]]++;
        for(int i=1;i<=300000;i++) cnt[i+1]+=cnt[i]/2,cnt[i]%=2;
        build(1,1,300000);
        //cout<<query_mx(1,1,300000)<<endl;
        for(int i=1,x,y;i<=q;i++){
            scanf("%d%d",&x,&y);
            mnus(a[x]),a[x]=y,add(a[x]);
            printf("%d\n",query_mx(1,1,300000));
        }
    }
    return 0;
}
//unordered_map
//cf