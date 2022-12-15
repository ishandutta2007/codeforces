#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
struct nod{
    long long pre,suf,mx,sum;
}tree[1200005];
long long ans[300005];
int a[300005],ls[1200005],rs[1200005],cnt;
inline void pushup(int node){
    tree[node].pre=max(tree[ls[node]].pre,tree[ls[node]].sum+tree[rs[node]].pre);
    tree[node].suf=max(tree[rs[node]].suf,tree[ls[node]].suf+tree[rs[node]].sum);
    tree[node].mx=max({tree[ls[node]].mx,tree[rs[node]].mx,tree[ls[node]].suf+tree[rs[node]].pre});
    tree[node].sum=tree[ls[node]].sum+tree[rs[node]].sum;
}
void build(int &node,int l,int r){
    node=++cnt;
    if(l==r){
        tree[node].pre=tree[node].suf=tree[node].mx=max(0,a[l]);
        tree[node].sum=a[l];
        return;
    }
    int mid=(l+r)>>1;
    build(ls[node],l,mid),build(rs[node],mid+1,r);
    pushup(node);
}
void update(int node,int now,int lim){
    if(now==lim){
        swap(ls[node],rs[node]);
        pushup(node);
        return;
    }
    update(ls[node],now*2,lim^now),update(rs[node],now*2,lim^now);
    if(now&lim) swap(ls[node],rs[node]);
    pushup(node);
}
int main() {
    int T = 1, kase = 0;
    //cin >> T;
    while (T--) {
        int n,rt;
        cin>>n;
        for(int i=1;i<=(1<<n);i++) scanf("%d",&a[i]);
        for(int i=0;i<(1<<n);i++){
            if(i==0) build(rt,1,1<<n);
            else update(rt,1,i^(i-1));
            ans[i]=tree[1].mx;
        }
        int q,now=0;
        cin>>q;
        for(int i=1,x;i<=q;i++){
            scanf("%d",&x),x=n-x-1;
            now^=(1<<x);
            printf("%lld\n",ans[now]);
        }
    }
    return 0;
}