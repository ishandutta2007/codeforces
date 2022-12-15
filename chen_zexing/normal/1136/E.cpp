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
int a[100005],k[100005],n;
long long tree[400005],lz[400005];
void build(int node,int l,int r){
    if(l==r){
        tree[node]=a[l];
        return;
    }
    int mid=(l+r)>>1;
    build(node*2,l,mid);
    build(node*2+1,mid+1,r);
    tree[node]=tree[node*2]+tree[node*2+1];
}
void pushdown(int node,int l,int r){
    if(lz[node]){
        int mid=(l+r)>>1;
        tree[node*2]+=lz[node]*(mid-l+1),tree[node*2+1]+=lz[node]*(r-mid);
        lz[node*2]+=lz[node],lz[node*2+1]+=lz[node],lz[node]=0;
    }
}
void update(int node,int l,int r,int L,int R,int v){
    if(l>=L&&r<=R){
        tree[node]+=1LL*v*(r-l+1);
        lz[node]+=v;
        return;
    }
    pushdown(node,l,r);
    int mid=(l+r)>>1;
    if(mid>=L) update(node*2,l,mid,L,R,v);
    if(mid<R) update(node*2+1,mid+1,r,L,R,v);
    tree[node]=tree[node*2]+tree[node*2+1];
}
long long query(int node,int l,int r,int L,int R){
    if(l>=L&&r<=R) return tree[node];
    pushdown(node,l,r);
    int mid=(l+r)>>1;
    long long ans=0;
    if(mid>=L) ans+=query(node*2,l,mid,L,R);
    if(mid<R) ans+=query(node*2+1,mid+1,r,L,R);
    return ans;
}
struct seg_tree{//
    int tree[400005];
    void build(int node,int l,int r){
        if(l==r){
            tree[node]=1;
            return;
        }
        int mid=(l+r)>>1;
        build(node*2,l,mid);
        build(node*2+1,mid+1,r);
        tree[node]=tree[node*2]+tree[node*2+1];
    }
    void build(){
        build(1,1,n-1);
    }
    void update(int node,int l,int r,int pos){
        if(l==r){
            tree[node]^=1;
            return;
        }
        int mid=(l+r)>>1;
        pos<=mid?update(node*2,l,mid,pos):update(node*2+1,mid+1,r,pos);
        tree[node]=tree[node*2]+tree[node*2+1];
    }
    int find(int node,int l,int r){
        if(l==r) return l;
        int mid=(l+r)>>1;
        if(tree[node*2]) return find(node*2,l,mid);
        else return find(node*2+1,mid+1,r);
    }
    int query(int node,int l,int r,int L,int R){
        if(l>=L&&r<=R){
            if(tree[node]) return find(node,l,r);
            else return 0;
        }
        int mid=(l+r)>>1;
        if(mid<L) return query(node*2+1,mid+1,r,L,R);
        else if(mid>=R) return query(node*2,l,mid,L,R);
        else{
            int temp=query(node*2,l,mid,L,R);
            if(temp) return temp;
            else return query(node*2+1,mid+1,r,L,R);
        }
    }
    int get(int node,int l,int r,int pos){
        if(l==r) return tree[node];
        return pos<=(l+r)/2?get(node*2,l,(l+r)/2,pos):get(node*2+1,(l+r)/2+1,r,pos);
    }
    int query(int pos){
        return query(1,1,n-1,pos,n-1);
    }
}Tr;

int main() {
    int T = 1;
    //cin >> T;
    while (T--) {
        int q,x,y;
        char c;
        cin>>n;
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        for(int i=1;i<n;i++) scanf("%d",&k[i]);
        cin>>q;
        Tr.build();
        build(1,1,n);
        for(int i=1;i<=q;i++){
            c='-';
            while(c!='+'&&c!='s') scanf("%c",&c);
            scanf("%d%d",&x,&y);
            if(c=='+'){
                long long now=x,v=y;
                if(now>1&&Tr.get(1,1,n-1,now-1)==0) Tr.update(1,1,n-1,now-1);
                while(now<=n){
                    //cout<<now<<" "<<v<<endl;
                    if(now==n){
                        update(1,1,n,now,now,v);
                        now++;
                    }
                    else{
                        int nxt=Tr.query(now);
                        if(nxt==0){
                            update(1,1,n,now,n,v);
                            break;
                        }
                        update(1,1,n,now,nxt,v);
                        long long temp=query(1,1,n,nxt,nxt),tt=query(1,1,n,nxt+1,nxt+1);
                        if(temp+k[nxt]>tt){
                            Tr.update(1,1,n-1,nxt);
                            v=temp+k[nxt]-tt,now=nxt+1;
                        }
                        else break;
                    }
                }
            }
            else printf("%lld\n",query(1,1,n,x,y));
            //for(int j=1;j<=n;j++) printf("%lld ",query(1,1,n,j,j));puts("");
        }
    }
    return 0;
}
//
/// 
//01
//