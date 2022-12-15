#include <cstdio>
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
using namespace std;
long long tot[1000005];
struct node{
    long long color,st,v;
}tree[4000005];
void build(int node,int l,int r){
    tree[node].color=1,tree[node].st=tree[node].v=0;
    if(l==r) return;
    int mid=(l+r)>>1;
    build(node*2,l,mid),build(node*2+1,mid+1,r);
}
void pushdown(int node){
    if(tree[node].color){
        tree[node*2].color=tree[node*2+1].color=tree[node].color;
        tree[node*2].st=tree[node*2+1].st=tree[node].st;
    }
}
void cover(int node,int l,int r,int c){
    if(tree[node].color){
        tree[node].v+=tot[tree[node].color]-tree[node].st;
        tree[node].color=c,tree[node].st=tot[c];
        return;
    }
    int mid=(l+r)>>1;
    cover(node*2,l,mid,c),cover(node*2+1,mid+1,r,c);
    tree[node].color=c,tree[node].st=tot[c];
}
void modify(int node,int l,int r,int L,int R,int c){
    if(l>=L&&r<=R){
        cover(node,l,r,c);
        return;
    }
    pushdown(node);
    int mid=(l+r)>>1;
    if(mid>=L) modify(node*2,l,mid,L,R,c);
    if(mid<R) modify(node*2+1,mid+1,r,L,R,c);
    tree[node].color=0;
}
void add(int c,int x){
    tot[c]+=x;
}
long long query(int node,int l,int r,int pos,long long sum){
    sum+=tree[node].v;
    if(l==r) return sum+tot[tree[node].color]-tree[node].st;
    pushdown(node);
    int mid=(l+r)>>1;
    return pos<=mid?query(node*2,l,mid,pos,sum):query(node*2+1,mid+1,r,pos,sum);
}
int main() {
    int T = 1;
    //cin >> T;
    while (T--) {
        int n,m;
        cin>>n>>m;
        build(1,1,n);
        for(int i=1;i<=m;i++){
            char s[10];
            scanf("%s",s+1);
            if(s[1]=='C'){
                int l,r,c;
                scanf("%d%d%d",&l,&r,&c);
                modify(1,1,n,l,r,c);
            }
            else if(s[1]=='A'){
                int c,x;
                scanf("%d%d",&c,&x);
                add(c,x);
            }
            else{
                int x;
                scanf("%d",&x);
                printf("%lld\n",query(1,1,n,x,0));
            }
        }
    }
    return 0;
}
//unordered_map