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
#include <time.h>
#include <map>
#include <stack>
#include <unordered_set>
#define hash hassh
using namespace std;
int tree[6500005], ls[6500005], rs[6500005],cnt,rt[200005],n;
int build(int l, int r) {
    int node = ++cnt, mid = (l + r) >> 1;
    if (l < r) {
        ls[node] = build(l, mid);
        rs[node] = build(mid + 1, r);
    }
    return node;
}
int add(int pre, int l, int r, int v) {
    int node = ++cnt, mid = (l + r) >> 1;
    ls[node] = ls[pre], rs[node] = rs[pre], tree[node] = tree[pre] + 1;
    if (l < r) {
        if (v <= mid) ls[node] = add(ls[node], l, mid, v);
        else rs[node] = add(rs[node], mid + 1, r, v);
    }
    return node;
}
int query(int x,int y,int l,int r,int v){
    if(l>r) return 0;
    if(l==r) return tree[x]-tree[y];
    int mid=(l+r)>>1;
    if(v<=mid) return query(ls[x],ls[y],l,mid,v);
    else return query(rs[x],rs[y],mid+1,r,v);
}
int a[200005],st[200005][20],pos[200005][20];
long long ans=0;
void solve(int l,int r){
    if(r-l<=1) return;
    int t=log2(r-l+1),p;
    if(st[l][t]>=st[r-(1<<t)+1][t]) p=pos[l][t];
    else p=pos[r-(1<<t)+1][t];
    if(p-l<=r-p){
        for(int i=l;i<p;i++) if(query(rt[p],rt[r],1,n,a[p]-a[i])) ans++;
    }
    else for(int i=p+1;i<=r;i++) if(query(rt[l-1],rt[p-1],1,n,a[p]-a[i])) ans++;
    //cout<<p<<" "<<l<<" "<<r<<" "<<ans<<endl;
    solve(l,p-1);
    solve(p+1,r);
}
int main() {
    int T = 1;
    //cin >> T;
    while (T--) {
        cin>>n;
        rt[0]=build(1,n);
        for(int i=1;i<=n;i++) scanf("%d",&a[i]),rt[i]=add(rt[i-1],1,n,a[i]),st[i][0]=a[i],pos[i][0]=i;
        for(int j=1;j<20;j++)
            for(int i=1;i<=n;i++){
                st[i][j]=max(st[i][j-1],st[min(n,i+(1<<(j-1)))][j-1]);
                if(st[i][j]==st[i][j-1]) pos[i][j]=pos[i][j-1];
                else pos[i][j]=pos[min(n,i+(1<<(j-1)))][j-1];
            }
        solve(1,n);
        cout<<ans<<endl;
    }
    return 0;
}
//
/// 
//01
// 
//
//dp