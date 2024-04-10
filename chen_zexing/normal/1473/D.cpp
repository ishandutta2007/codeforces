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
long long tree[800005][2],pre[200005];
void build(int node,int l,int r){
    if(l==r){
        tree[node][0]=tree[node][1]=pre[l];
        return;
    }
    int mid=(l+r)>>1;
    build(node*2,l,mid);
    build(node*2+1,mid+1,r);
    tree[node][0]=min(tree[node*2][0],tree[node*2+1][0]);
    tree[node][1]=max(tree[node*2][1],tree[node*2+1][1]);
}
long long query(int node,int l,int r,int L,int R,int type){
    if(L>R){
        if(type==0) return INT_MAX;
        else return INT_MIN;
    }
    if(l>=L&&r<=R) return tree[node][type];
    int mid=(l+r)>>1;
    if(type==0) {
        long long ans=INT_MAX;
        if (mid >= L) ans=min(ans,query(node*2,l,mid,L,R,type));
        if(mid<R) ans=min(ans,query(node*2+1,mid+1,r,L,R,type));
        return ans;
    }
    else{
        long long ans=INT_MIN;
        if (mid >= L) ans=max(ans,query(node*2,l,mid,L,R,type));
        if(mid<R) ans=max(ans,query(node*2+1,mid+1,r,L,R,type));
        return ans;
    }
}
char s[200005];
int main() {
    int T=1;
    cin>>T;
    while(T--){
        int n,q;
        cin>>n>>q;
        scanf("%s",s+1);
        for(int i=1;i<=n;i++) pre[i]=pre[i-1]+(s[i]=='+'?1:-1);
        build(1,0,n);
        //cout<<query(1,0,n,0,0,0)<<endl;
        for(int i=1;i<=q;i++){
            int l,r;
            scanf("%d%d",&l,&r);
            int diff=pre[r]-pre[l-1];
            long long mn1=query(1,0,n,0,l-1,0),mx1=query(1,0,n,0,l-1,1),mn2=query(1,0,n,r+1,n,0)-diff,mx2=query(1,0,n,r+1,n,1)-diff;
            //cout<<mx1<<" "<<mn1<<" "<<mx2<<" "<<mn2<<endl;
            printf("%d\n",max(mx1,mx2)-min(mn1,mn2)+1);
        }
    }
    return 0;
}