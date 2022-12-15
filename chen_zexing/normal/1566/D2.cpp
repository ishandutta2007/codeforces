#include <stdio.h>
#include <iostream>
#include <string>
#include <string.h>
#include <vector>
#include <cmath>
#include <assert.h>
#include <algorithm>
#include <stdlib.h>
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
#define li __int128_t
#define ull unsigned long long
using namespace std;
int a[400005],b[400005];
struct pos{
    int x,y,cnt;
};
struct nod{
    int id,v;
}p[400005];
bool cmp1(nod a,nod b){
    return a.v<b.v||a.v==b.v&&a.id<b.id;
}
bool cmp2(nod a,nod b){
    return a.id<b.id;
}
int tree[800005],lz[800005],pos[800005];
int st[400005],ed[400005],n,m;
void build(int node,int l,int r){
    if(l==r){
        if(l%m==0) tree[node]=0;
        else tree[node]=m-l%m;
        pos[node]=l;
        return;
    }
    int mid=(l+r)>>1;
    build(node*2,l,mid);
    build(node*2+1,mid+1,r);
    if(tree[node*2]<=tree[node*2+1]) tree[node]=tree[node*2],pos[node]=pos[node*2];
    else tree[node]=tree[node*2+1],pos[node]=pos[node*2+1];
}
void pushdown(int node){
    if(lz[node]){
        tree[node*2]+=lz[node],tree[node*2+1]+=lz[node];
        lz[node*2]+=lz[node],lz[node*2+1]+=lz[node],lz[node]=0;
    }
}
void update(int node,int l,int r,int L,int R,int v){
    //cout<<l<<" "<<r<<" "<<L<<" "<<R<<endl;
    if(l>=L&&r<=R){
        tree[node]+=v,lz[node]+=v;
        return;
    }
    pushdown(node);
    int mid=(l+r)>>1;
    if(mid>=L) update(node*2,l,mid,L,R,v);
    if(mid<R) update(node*2+1,mid+1,r,L,R,v);
    if(tree[node*2]<=tree[node*2+1]) tree[node]=tree[node*2],pos[node]=pos[node*2];
    else tree[node]=tree[node*2+1],pos[node]=pos[node*2+1];
}
pair<int,int> query(int node,int l,int r,int L,int R){
    if(l>=L&&r<=R) return make_pair(tree[node],pos[node]);
    pushdown(node);
    int mid=(l+r)>>1,mn=INT_MAX,p=-1;
    if(mid>=L){
        auto temp=query(node*2,l,mid,L,R);
        if(mn>temp.first) mn=temp.first,p=temp.second;
    }
    if(mid<R){
        auto temp=query(node*2+1,mid+1,r,L,R);
        if(mn>temp.first) mn=temp.first,p=temp.second;
    }
    return make_pair(mn,p);
}
int main() {
    int T = 1;
    cin >> T;
    while (T--) {
        cin>>n>>m;
        for(int i=1;i<=n*m*4;i++) tree[i]=lz[i]=0;
        for(int i=1;i<=n*m;i++) scanf("%d",&a[i]),b[i]=a[i];
        sort(b+1,b+n*m+1);
        for(int i=1;i<=n*m;i++) p[i].id=i,p[i].v=lower_bound(b+1,b+n*m+1,a[i])-b;
        sort(p+1,p+n*m+1,cmp1);
        for(int i=1;i<=n*m;i++) ed[p[i].v]=i;
        for(int i=n*m;i>=1;i--) st[p[i].v]=i;
        build(1,1,n*m);
        sort(p+1,p+n*m+1,cmp2);
        int ans=0;
        for(int i=1;i<=n*m;i++){
            assert(p[i].v<=1e5&&p[i].v>=1);
            int l=st[p[i].v],r=ed[p[i].v];
            auto temp=query(1,1,n*m,l,r);
            //cout<<temp.first<<" "<<temp.second<<endl;
            ans+=temp.first,update(1,1,n*m,temp.second,temp.second,1e5);
            if(temp.second%m!=1&&m!=1) update(1,1,n*m,(temp.second-1)/m*m+1,temp.second-1,-1);
        }
        printf("%d\n",ans);
    }
    return 0;
}
//
/// 
//01
//