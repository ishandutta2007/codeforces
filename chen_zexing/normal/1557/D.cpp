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
#define li __int128_t
using namespace std;
struct seg{
    int l,r;
};
vector <seg> v[300005];
int b[600005];
struct nod{
    int id,mx;
}tree[2400005],lz[2400005];
int from[300005],dp[300005];
void pushdown(int node,int l,int r){
    if(lz[node].mx==0||l==r) return;
    tree[node*2]=tree[node*2+1]=lz[node*2]=lz[node*2+1]=lz[node];
    lz[node].mx=0;
}
void modify(int node,int l,int r,int L,int R,nod temp){
    if(l>=L&&r<=R){
        tree[node]=lz[node]=temp;
        return;
    }
    pushdown(node,l,r);
    int mid=(l+r)>>1;
    if(mid>=L) modify(node*2,l,mid,L,R,temp);
    if(mid<R) modify(node*2+1,mid+1,r,L,R,temp);
    if(tree[node*2].mx>=tree[node*2+1].mx) tree[node]=tree[node*2];
    else tree[node]=tree[node*2+1];
}
nod query(int node,int l,int r,int L,int R){
    if(l>=L&&r<=R) return tree[node];
    pushdown(node,l,r);
    int mid=(l+r)>>1;
    nod ans=nod{0,0};
    if(mid>=L){
        nod temp=query(node*2,l,mid,L,R);
        if(temp.mx>ans.mx) ans=temp;
    }
    if(mid<R){
        nod temp=query(node*2+1,mid+1,r,L,R);
        if(temp.mx>ans.mx) ans=temp;
    }
    return ans;
}
int f[300005];
int main() {
    int T = 1;
    //cin >> T;
    while (T--){
        int n,m,c=0;
        cin>>n>>m;
        for(int i=1,x,l,r;i<=m;i++) scanf("%d%d%d",&x,&l,&r),v[x].push_back(seg{l,r}),b[++c]=l,b[++c]=r;
        sort(b+1,b+c+1);
        for(int i=1;i<=n;i++)
            for(int j=0;j<v[i].size();j++)
                v[i][j].l=lower_bound(b+1,b+c+1,v[i][j].l)-b,v[i][j].r=lower_bound(b+1,b+c+1,v[i][j].r)-b;
        for(int i=1;i<=n;i++){
            nod temp=nod{0,0};
            for(int j=0;j<v[i].size();j++){
                nod t=query(1,1,m*2,v[i][j].l,v[i][j].r);
                if(t.mx>temp.mx) temp=t;
            }
            from[i]=temp.id,dp[i]=dp[temp.id]+1;
            for(int j=0;j<v[i].size();j++) modify(1,1,m*2,v[i][j].l,v[i][j].r,nod{i,dp[i]});
        }
        int ans=0,p=-1;
        for(int i=1;i<=n;i++) if(ans<dp[i]) ans=dp[i],p=i;
        printf("%d\n",n-ans);
        while(p) f[p]=1,p=from[p];
        for(int i=1;i<=n;i++) if(!f[i]) printf("%d ",i);
        puts("");
    }
    return 0;
}
//
/// 
//01
//
//!