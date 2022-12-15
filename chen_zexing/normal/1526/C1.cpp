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
int a[200005],n;
long long tree[800005],lz[800005];
void pushdown(int node,int l,int r){
    tree[node*2]+=lz[node],tree[node*2+1]+=lz[node];
    lz[node*2]+=lz[node],lz[node*2+1]+=lz[node],lz[node]=0;
}
void add(int node,int l,int r,int L,int R,int v){
    if(l>=L&&r<=R){
        tree[node]+=v;
        lz[node]+=v;
        return;
    }
    pushdown(node,l,r);
    int mid=(l+r)>>1;
    if(mid>=L) add(node*2,l,mid,L,R,v);
    if(mid<R) add(node*2+1,mid+1,r,L,R,v);
    tree[node]=min(tree[node*2],tree[node*2+1]);
}
long long query(int node,int l,int r,int L,int R){
    if(l>=L&&r<=R){
        return tree[node];
    }
    pushdown(node,l,r);
    int mid=(l+r)>>1;
    long long ans=LLONG_MAX;
    if(mid>=L) ans=min(ans,query(node*2,l,mid,L,R));
    if(mid<R) ans=min(ans,query(node*2+1,mid+1,r,L,R));
    return ans;
}
struct pos{
    int pos,v;
}b[200005];
int cmp(pos a,pos b){
    return a.v>b.v;
}
int main() {
    int T = 1;
    //cin >> T;
    while (T--) {
        cin>>n;
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        int ans=0,x=0;
        for(int i=1;i<=n;i++){
            if(a[i]>=0) add(1,1,n,i,n,a[i]),ans++;
            else b[++x]=pos{i,a[i]};
        }
        if(!x){
            printf("%d\n",ans);
            continue;
        }
        sort(b+1,b+x+1,cmp);
        for(int i=1;i<=x;i++){
            add(1,1,n,b[i].pos,n,b[i].v);
            //cout<<query(1,1,n,1,n)<<endl;
            if(query(1,1,n,1,n)<0){
                add(1,1,n,b[i].pos,n,-b[i].v);
            }
            else ans++;
        }
        printf("%d\n",ans);
    }
    return 0;
}
//
/// 
//01
// 
//
//dp