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
struct interv{
    int l,r;
};
vector <interv> v[1000005];
int tree[4000005],cnt[4000005];
void add(int node,int l,int r,int L,int R,int v){
    if(l>=L&&r<=R){
        cnt[node]+=v;
        tree[node]=cnt[node]?r-l+1:tree[node*2]+tree[node*2+1];
        return;
    }
    int mid=(l+r)>>1;
    if(mid>=L) add(node*2,l,mid,L,R,v);
    if(mid<R) add(node*2+1,mid+1,r,L,R,v);
    tree[node]=cnt[node]?r-l+1:tree[node*2]+tree[node*2+1];
}
int query(int node,int l,int r,int L,int R){
    if(l>R||r<L) return 0;
    if(l>=L&&r<=R) return tree[node];
    int ans=0;
    int mid=(l+r)>>1;
    if(mid>=L) ans+=query(node*2,l,mid,L,R);
    if(mid<R) ans+=query(node*2+1,mid+1,r,L,R);
    return ans;
}
int check(int n,int m,int wmax){
    int r=0,ans=wmax-1;
    for(int i=1;i<=wmax;i++){
        while(query(1,1,m,1,m)!=m&&r<wmax) {
            r++;
            for (int j = 0; j < v[r].size(); j++) add(1, 1, m, v[r][j].l, v[r][j].r, 1);
        }
        if(query(1,1,m,1,m)!=m) break;
        ans=min(ans,r-i);
        for(int j=0;j<v[i].size();j++) add(1,1,m,v[i][j].l,v[i][j].r,-1);
    }
    return ans;
}
int main() {
    int T = 1;
    //cin >> T;
    while (T--) {
        int n,m,wmax=0;
        cin>>n>>m;
        m--;
        for(int i=1,l,r,w;i<=n;i++){
            scanf("%d%d%d",&l,&r,&w),r--;
            if(l>r) continue;
            v[w].push_back(interv{l,r}),wmax=max(wmax,w);
        }
        printf("%d\n",check(n,m,wmax));
    }
    return 0;
}
//
/// 
//01
// 
//
//dp
//!