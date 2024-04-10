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
#include <unordered_set>
#define hash hassh
using namespace std;
long long tree[1200005],lz[1200005],tree2[1200005],tree3[1200005],lz3[1200005];
void build(int node,int l,int r){
    if(l==r){
        tree[node]=INT_MAX;
        return;
    }
    int mid=(l+r)>>1;
    build(node*2,l,mid);
    build(node*2+1,mid+1,r);
    tree[node]=min(tree[node*2],tree[node*2+1]);
}
void pushdown(int node,int l,int r) {
    int mid = (l + r) >> 1;
    if (l == r||!lz[node]) return;
    tree[node * 2] = lz[node];
    tree[node * 2 + 1] = lz[node];
    lz[node * 2] = lz[node], lz[node * 2 + 1] = lz[node], lz[node] = 0;
}
void update(int node,int l,int r,int L,int R,long long v) {
    if (l >= L && r <= R) {
        tree[node] = v;
        lz[node] = v;
        return;
    }
    pushdown(node, l, r);
    int mid = (l + r) >> 1;
    if (mid >= L) update(node * 2, l, mid, L, R, v);
    if (mid < R) update(node * 2 + 1, mid + 1, r, L, R, v);
    tree[node] = min(tree[node * 2], tree[node * 2 + 1]);
}
long long query(int node,int l,int r,int L,int R) {
    if (l >= L && r <= R) {
        return tree[node];
    }
    pushdown(node, l, r);
    int mid = (l + r) >> 1;
    long long ans = INT_MAX;
    if (mid >= L) ans = min(ans, query(node * 2, l, mid, L, R));
    if (mid < R) ans = min(ans, query(node * 2 + 1, mid + 1, r, L, R));
    return ans;
}
void update2(int node,int l,int r,int pos,long long v){
    if(l==r){
        tree2[node]+=v;
        return;
    }
    int mid=(l+r)>>1;
    if(pos<=mid) update2(node*2,l,mid,pos,v);
    else update2(node*2+1,mid+1,r,pos,v);
    tree2[node]=max(tree2[node*2],tree2[node*2+1]);
}
long long query2(int node,int l,int r,int L,int R) {
    if(L>R) return INT_MIN;
    if (l >= L && r <= R) {
        return tree2[node];
    }
    int mid = (l + r) >> 1;
    long long ans = LLONG_MIN;
    if (mid >= L) ans = max(ans, query2(node * 2, l, mid, L, R));
    if (mid < R) ans = max(ans, query2(node * 2 + 1, mid + 1, r, L, R));
    return ans;
}
void pushdown3(int node,int l,int r) {
    int mid = (l + r) >> 1;
    if (l == r||!lz3[node]) return;
    tree3[node * 2] = lz3[node];
    tree3[node * 2 + 1] = lz3[node];
    lz3[node * 2] = lz3[node], lz3[node * 2 + 1] = lz3[node], lz3[node] = 0;
}
void update3(int node,int l,int r,int L,int R,long long v) {
    if (l >= L && r <= R) {
        tree3[node] = v;
        lz3[node] = v;
        return;
    }
    pushdown3(node, l, r);
    int mid = (l + r) >> 1;
    if (mid >= L) update3(node * 2, l, mid, L, R, v);
    if (mid < R) update3(node * 2 + 1, mid + 1, r, L, R, v);
    tree3[node] = max(tree3[node * 2], tree3[node * 2 + 1]);
}
long long query3(int node,int l,int r,int L,int R) {
    if(L>R) return LLONG_MIN/10;
    if (l >= L && r <= R) {
        return tree3[node];
    }
    pushdown3(node, l, r);
    int mid = (l + r) >> 1;
    long long ans = LLONG_MIN;
    if (mid >= L) ans = max(ans, query3(node * 2, l, mid, L, R));
    if (mid < R) ans = max(ans, query3(node * 2 + 1, mid + 1, r, L, R));
    return ans;
}
long long dp[300005];
long long h[300005],b[300005];
int main() {
    int T=1;
    //cin>>T;
    while(T--) {
        int n;
        cin>>n;
        build(1,1,n);
        for(int i=1;i<=n;i++) scanf("%lld",&h[i]);
        for(int i=1;i<=n;i++) scanf("%lld",&b[i]);
        dp[1]=b[1];
        update2(1,1,n,1,dp[1]);
        update(1,1,n,1,1,h[1]);
        update3(1,1,n,1,1,dp[1]);
        for(int i=2;i<=n;i++){
            int l=1,r=i;
            while(l<r){
                int mid=(l+r)>>1;
                if(query(1,1,n,mid,i)>h[i]) r=mid;
                else l=mid+1;
            }
            dp[i]=dp[l-1]+b[i];
            dp[i]=max(dp[i],query2(1,1,n,max(l-1,1),i-1)+b[i]);
            //cout<<query2(1,1,n,l,i-1)<<" "<<l<<" "<<i-1<<endl;
            dp[i]=max(dp[i],query3(1,1,n,1,l-1));
            update2(1,1,n,i,dp[i]);
            update(1,1,n,l,i,h[i]);
            update3(1,1,n,l,i,dp[i]);
            //cout<<dp[i]<<endl;
        }
        printf("%lld\n",dp[n]);
    }
    return 0;
}
//
/// 
//01
// 
//
//dp