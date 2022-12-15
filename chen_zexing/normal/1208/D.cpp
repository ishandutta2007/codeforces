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
long long tree[800005],lz[800005],a[200005];
long long fac=2e5+5,n;
void build(int node,int l,int r) {
    if (l == r) {
        tree[node] = a[l]*fac+(n-l);
        return;
    }
    int mid = (l + r) >> 1;
    build(node * 2, l, mid);
    build(node * 2 + 1, mid + 1, r);
    tree[node] = min(tree[node*2],tree[node*2+1]);
}
void pushdown(int node,int l,int r) {
    int mid = (l + r) >> 1;
    if (l == r) return;
    tree[node * 2] += lz[node];
    tree[node * 2 + 1] += lz[node];
    lz[node * 2] += lz[node], lz[node * 2 + 1] += lz[node], lz[node] = 0;
}
void update(int node,int l,int r,int L,int R,long long v) {
    if(L>R) return;
    if (l >= L && r <= R) {
        tree[node] += v ;
        lz[node] += v;
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
    long long ans = LLONG_MAX;
    if (mid >= L) ans =min(ans, query(node * 2, l, mid, L, R));
    if (mid < R) ans =min(ans, query(node * 2 + 1, mid + 1, r, L, R));
    return ans;
}
int ans[200005];
int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) scanf("%lld", &a[i]);
    build(1, 1, n);
    for(int i=1;i<=n;i++){
        long long t=query(1,1,n,1,n);
        int pos=t%fac;
        pos=n-pos;
        //cout<<t<<" "<<pos<<endl;
        update(1,1,n,pos,pos,LLONG_MAX/10);
        ans[pos]=i;
        update(1,1,n,pos+1,n,-fac*i);
    }
    for(int i=1;i<=n;i++) printf("%d ",ans[i]);
    return 0;
}