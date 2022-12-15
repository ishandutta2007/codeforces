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
int a[200005],b[200005],cnt[200005];
int tree[800005];
void build(int node,int l,int r){
    if(l==r){
        tree[node]=cnt[l];
        return;
    }
    int mid=(l+r)>>1;
    build(node*2,l,mid);
    build(node*2+1,mid+1,r);
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
        else return -1;
    }
    int mid=(l+r)>>1,temp=-1;
    if(mid>=L) temp=query(node*2,l,mid,L,R);
    if(mid<R) {
        if (temp!=-1) return temp;
        else return query(node * 2 + 1, mid + 1, r, L, R);
    }
    else return temp;
}
void update(int node,int l,int r,int pos){
    if(l==r){
        tree[node]--;
        return;
    }
    int mid=(l+r)>>1;
    if(pos<=mid) update(node*2,l,mid,pos);
    else update(node*2+1,mid+1,r,pos);
    tree[node]=tree[node*2]+tree[node*2+1];
}
int main() {
    int T = 1;
    //cin >> T;
    while (T--) {
        int n;
        cin>>n;
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        for(int i=1;i<=n;i++) scanf("%d",&b[i]),cnt[b[i]]++;
        build(1,0,n-1);
        for(int i=1;i<=n;i++){
            int tar=(n-a[i])%n;
            int temp=query(1,0,n-1,tar,n-1);
            if(temp==-1) temp=query(1,0,n-1,0,tar-1);
            printf("%d ",(a[i]+temp)%n),update(1,0,n-1,temp);
        }
    }
    return 0;
}
//
/// 
//01
//