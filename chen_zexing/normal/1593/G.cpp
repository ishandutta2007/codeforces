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
#include <list>
#define hash hassh
#define li __int128_t
#define ull unsigned long long
using namespace std;
struct nod{
    int len,st,ed;
}tree[4000005];
char s[1000005];
nod merge(nod a,nod b){
    if(a.len==0&&b.len==0) return nod{0,0,0};
    if(a.len==0) return b;
    if(b.len==0) return a;
    if(a.ed!=b.st) return nod{a.len+b.len,a.st,b.ed};
    else{
        if(a.len==b.len) return nod{0,0,0};
        if(a.len<b.len){
            b.len-=a.len;
            if(a.len%2) b.st=3-b.st;
            return b;
        }
        else{
            a.len-=b.len;
            if(b.len%2) a.ed=3-b.ed;
            return a;
        }
    }
}
void build(int node,int l,int r){
    if(l==r){
        tree[node].len=1;
        if(s[l]=='('||s[l]==')') tree[node].st=tree[node].ed=1;
        else tree[node].st=tree[node].ed=2;
        return;
    }
    int mid=(l+r)>>1;
    build(node*2,l,mid),build(node*2+1,mid+1,r);
    tree[node]=merge(tree[node*2],tree[node*2+1]);
}
nod query(int node,int l,int r,int L,int R){
    if(l>=L&&r<=R) return tree[node];
    int mid=(l+r)>>1;
    if(mid<L) return query(node*2+1,mid+1,r,L,R);
    else if(mid>=R) return query(node*2,l,mid,L,R);
    else return merge(query(node*2,l,mid,L,R),query(node*2+1,mid+1,r,L,R));
}
int main() {
    int T = 1;
    cin >> T;
    while(T--){
        scanf("%s",s+1);
        int n=strlen(s+1),q;
        build(1,1,n);
        scanf("%d",&q);
        for(int i=1,l,r;i<=q;i++){
            scanf("%d%d",&l,&r);
            auto temp=query(1,1,n,l,r);
            printf("%d\n",temp.len/2);
        }
    }
    return 0;
}
//
/// 
//01
//