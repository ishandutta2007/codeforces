#include <bits/stdc++.h>
using namespace std;


int all;
int l[4000005],r[4000005],tree[4000005];
int n,m,x,y;
int sz;
int root[100005];
int a[100005];
int last[100005];

inline int vcopy(int x){
    ++all;
    l[all]=l[x];
    r[all]=r[x];
    tree[all]=tree[x];
    return all;
}
void update(int l1,int r1,int ll1,int x,int y){
    if (l1>r1 || ll1>r1 || l1>ll1) return;
    if (l1==r1) {
        tree[x]=y;
        return;
    }
    int mid=(l1+r1)/2;
    if (ll1<=mid) {
        l[x]=vcopy(l[x]);
        update(l1,mid,ll1,l[x],y);
    } else {
        r[x]=vcopy(r[x]);
        update(mid+1,r1,ll1,r[x],y);
    }
    tree[x]=tree[l[x]]+tree[r[x]];
}
int getsum(int l1,int r1,int ll1,int rr1,int x){
    if (l1>r1 || ll1>r1 || l1>rr1) return 0;
    if (l1>=ll1 && r1<=rr1) return tree[x];
    int mid=(l1+r1)/2;
    return getsum(l1,mid,ll1,rr1,l[x]) + getsum(mid+1,r1,ll1,rr1,r[x]);
}
int getk(int l1,int r1,int x,int y){
    if (l1==r1) return l1;
    int mid=(l1+r1)/2;
    if (tree[l[x]]>=y) return getk(l1,mid,l[x],y);
    else return getk(mid+1,r1,r[x],y-tree[l[x]]);
}
inline int getans(int k){
    int ans=0;
    int last=n;
    while (true) {
        if (last<1) break;
        int x=getsum(1,sz,1,last,root[last]);
        if (x<=k) {
            ++ans;
            last=-1;
            continue;
        }
        ++ans;
        last=getk(1,sz,root[last],x-k);
    }
    return ans;
}
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    for (int i=1;i<=n;++i)
        cin>>a[i];
    sz=1;
    while (sz<n) sz+=sz;
    for (int i=1;i<sz;++i){
        l[i]=i+i;
        r[i]=i+i+1;
    }
    all=sz+sz;
    root[0]=1;
    for (int i=1;i<=n;++i) {
        int x=a[i];
        root[i]=vcopy(root[i-1]);
        if (last[x]!=0) update(1,sz,last[x],root[i],0);
        last[x]=i;
        update(1,sz,last[x],root[i],1);
    }
    for (int i=1;i<=n;++i)
        cout<<getans(i)<<" ";
}