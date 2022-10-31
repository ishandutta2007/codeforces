#include <bits/stdc++.h>
using namespace std;


int n,m,sz,x,y,z;
int tree[20000000];
int l[20000000];
int r[20000000];
int p[20000000];
int k;
bool q[20000000];
int a[100005];
int root;
void build(long long ll,long long rr,int x){
    if (ll==rr) {
        tree[x]=a[ll];
        return;
    }
    long long mid=(ll+rr)/2;
    l[x]=++sz;
    r[x]=++sz;
    build(ll,mid,l[x]);
    build(mid+1,rr,r[x]);
    tree[x]=min(tree[l[x]],tree[r[x]]);
}

inline int c(int x){
    ++sz;
    l[sz]=l[x];
    r[sz]=r[x];
    q[sz]=q[x];
    p[sz]=p[x];
    tree[sz]=tree[x];
    return sz;
}
inline void push (int x,long long ll,long long rr,int z){
    if (z!=1) {
    l[x]=c(l[x]);
    r[x]=c(r[x]);
    }
    if (q[x]==false || ll==rr) return;
    if (z==1) {
    l[x]=c(l[x]);
    r[x]=c(r[x]);
    }
    q[x]=false;
    q[l[x]]=true;
    q[r[x]]=true;
    p[l[x]]=p[x];
    p[r[x]]=p[x];
    tree[l[x]]=p[x];
    tree[r[x]]=p[x];
}
void update(long long l1,long long r1,long long ll,long long rr,int x,int z){
    if (l1>r1 || ll>r1 || l1>rr) return;
    if (l1>=ll && r1<=rr) {
        q[x]=true;
        p[x]=z;
        tree[x]=z;
        return;
    }
    push(x,l1,r1,0);
    long long mid=(l1+r1)/2;
    update(l1,mid,ll,rr,l[x],z);
    update(mid+1,r1,ll,rr,r[x],z);
    tree[x]=min(tree[l[x]],tree[r[x]]);
}
int get(long long l1,long long r1,long long ll,long long rr,int x){
    if (l1>r1 || ll>r1 || l1>rr) return 1e9;
    if (l1>=ll && r1<=rr) return tree[x];
    push(x,l1,r1,1);
    long long mid=(l1+r1)/2;
    int res=min(get(l1,mid,ll,rr,l[x]),get(mid+1,r1,ll,rr,r[x]));
    tree[x]=min(tree[l[x]],tree[r[x]]);
    return res;
}
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>k;
    for (int i=1;i<=n;++i)
        cin>>a[i];
    root=1;
    sz=1;
    build(1,n,1);
    int ss=1;
    while (ss<k) {
        ss*=2;
        ++sz;
        tree[sz]=tree[root];
        l[sz]=root;
        r[sz]=root;
        root=sz;
    }
    k=(ss*n);
    cin>>m;
    for (int i=1;i<=m;++i){
        cin>>x;
        if (x==1) {
                cin>>x>>y>>z;
                update(1,k,x,y,root,z);
        } else {
                cin>>x>>y;
                cout<<get(1,k,x,y,root)<<'\n';
        }
    }
}