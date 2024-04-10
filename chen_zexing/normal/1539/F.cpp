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
int a[200005];
long long tree[800005][2],lz[800005][2],n;
int ans[200005];
void build(int node,int l,int r,int id){
    lz[node][id]=0;
    if(l==r){
        tree[node][id]=id==0?l:n-l+1;
        return;
    }
    int mid=(l+r)>>1;
    build(node*2,l,mid,id);
    build(node*2+1,mid+1,r,id);
    tree[node][id]=max(tree[node*2][id],tree[node*2+1][id]);
}
void pushdown(int node,int l,int r,int id){
    if(l==r) return;
    if(lz[node][id]){
        tree[node*2][id]+=lz[node][id],tree[node*2+1][id]+=lz[node][id];
        lz[node*2][id]+=lz[node][id],lz[node*2+1][id]+=lz[node][id],lz[node][id]=0;
    }
}
void modify(int node,int l,int r,int L,int R,int id,int v){
    if(l>=L&&r<=R){
        tree[node][id]+=v;
        lz[node][id]+=v;
        return;
    }
    pushdown(node,l,r,id);
    int mid=(l+r)>>1;
    if(mid>=L) modify(node*2,l,mid,L,R,id,v);
    if(mid<R) modify(node*2+1,mid+1,r,L,R,id,v);
    tree[node][id]=max(tree[node*2][id],tree[node*2+1][id]);
}
long long query(int node,int l,int r,int L,int R,int id){
    if(l>=L&&r<=R) return tree[node][id];
    pushdown(node,l,r,id);
    int mid=(l+r)>>1;
    long long ans=INT_MIN;
    if(mid>=L) ans=max(ans,query(node*2,l,mid,L,R,id));
    if(mid<R) ans=max(ans,query(node*2+1,mid+1,r,L,R,id));
    return ans;
}
vector <int> v[200005];
int main() {
    int T = 1;
    //cin >> T;
    while (T--) {
        cin>>n;
        for(int i=1;i<=n;i++) scanf("%d",&a[i]),v[a[i]].push_back(i);
        build(1,1,n,0),build(1,1,n,1);
        for(int i=1;i<=n;i++){
            for(int j=0;j<v[i].size();j++){
                int pos=v[i][j];
                int temp=query(1,1,n,1,pos,1)-query(1,1,n,pos,pos,1)+query(1,1,n,pos,n,0)-query(1,1,n,pos,pos,0);
                ans[pos]=max(ans[pos],(temp+1)/2);
            }
            for(int j=0;j<v[i].size();j++) modify(1,1,n,v[i][j],n,0,-2),modify(1,1,n,1,v[i][j],1,-2);
        }
        build(1,1,n,0),build(1,1,n,1);
        for(int i=n;i>=1;i--){
            for(int j=0;j<v[i].size();j++){
                int pos=v[i][j];
                int temp=query(1,1,n,1,pos,1)-query(1,1,n,pos,pos,1)+query(1,1,n,pos,n,0)-query(1,1,n,pos,pos,0);
                ans[pos]=max(ans[pos],temp/2);
                //cout<<v[i][j]<<" "<<i<<" "<<temp<<endl;
            }
            for(int j=0;j<v[i].size();j++) modify(1,1,n,v[i][j],n,0,-2),modify(1,1,n,1,v[i][j],1,-2);
        }
        for(int i=1;i<=n;i++) printf("%d ",ans[i]);
    }
    return 0;
}
//
/// 
//01
// 
//
//dp