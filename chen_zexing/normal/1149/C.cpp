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
struct nod{
    int premax,sufmin,sum;
    int preans,sufans,compans,ans;
}tree[800005];
char s[200005];
int a[200005];
void pushup(int node){
    tree[node].sum=tree[node*2].sum+tree[node*2+1].sum;
    tree[node].premax=max(tree[node*2].premax,tree[node*2].sum+tree[node*2+1].premax);
    tree[node].sufmin=min(tree[node*2+1].sufmin,tree[node*2+1].sum+tree[node*2].sufmin);
    tree[node].preans=max(tree[node*2].preans,max(tree[node*2].compans+tree[node*2+1].premax,tree[node*2+1].preans-tree[node*2].sum));
    tree[node].sufans=max(tree[node*2+1].sufans,max(tree[node*2+1].compans-tree[node*2].sufmin,tree[node*2].sufans+tree[node*2+1].sum));
    tree[node].compans=max(tree[node*2].compans+tree[node*2+1].sum,tree[node*2+1].compans-tree[node*2].sum);
    tree[node].ans=max(max(tree[node*2].ans,tree[node*2+1].ans),max(tree[node*2].sufans+tree[node*2+1].premax,tree[node*2+1].preans-tree[node*2].sufmin));
}
void assign(int node,int v){
    tree[node].sum=v,tree[node].premax=max(v,0),tree[node].sufmin=min(v,0);
    tree[node].preans=tree[node].sufans=tree[node].compans=tree[node].ans=v;
}
void build(int node,int l,int r){
    if(l==r){
        assign(node,a[l]);
        return;
    }
    int mid=(l+r)>>1;
    build(node*2,l,mid);
    build(node*2+1,mid+1,r);
    pushup(node);
}
void update(int node,int l,int r,int pos){
    if(l==r){
        assign(node,a[pos]);
        return;
    }
    int mid=(l+r)>>1;
    if(pos<=mid) update(node*2,l,mid,pos);
    else update(node*2+1,mid+1,r,pos);
    pushup(node);
}
int main() {
    int T = 1;
    //cin >> T;
    while (T--) {
        int n,q;
        cin>>n>>q;
        scanf("%s",s+1);
        for(int i=1;i<=n*2-2;i++) a[i]=(s[i]=='('?1:-1);
        build(1,1,n*2-2);
        printf("%d\n",tree[1].ans);
        for(int i=1,x,y;i<=q;i++){
            scanf("%d%d",&x,&y);
            swap(a[x],a[y]);
            update(1,1,n*2-2,x),update(1,1,n*2-2,y);
            printf("%d\n",tree[1].ans);
        }
    }
    return 0;
}
//
/// 
//01
//